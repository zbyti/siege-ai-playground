// set Z flag to 2

const
  ATTRIBUTE_ADDR = $0800; SCREEN_ADDR = $0c00;

  EMPTY = $20; WALL = $a0; WALL_COLOUR = $41;

  PLY_HEAD = $51; PLY_CRASH = $57; PLY_TAIl_UD = $42; PLY_TAIl_LR = $40;
  PLY_TAIl_RD = $7d; PLY_TAIl_RU = $6e; PLY_TAIl_LD = $6d; PLY_TAIl_LU = $70;
  PLY1_COLOUR = $5f; PLY2_COLOUR = $5d; PLY3_COLOUR = $71; PLY4_COLOUR = $55;

  JOY_UP = 1; JOY_DOWN = 2; JOY_LEFT = 4; JOY_RIGHT = 8; JOY_FIRE = 64;
  JOY_SELECT_1 = %00000010; JOY_SELECT_2 = %00000100;

//-----------------------------------------------------------------------------

const
  mul40: array [0..24] of word = (
     0 * 40,  1 * 40,  2 * 40,  3 * 40,  4 * 40,  5 * 40,
     6 * 40,  7 * 40,  8 * 40,  9 * 40, 10 * 40, 11 * 40,
    12 * 40, 13 * 40, 14 * 40, 15 * 40, 16 * 40, 17 * 40,
    18 * 40, 19 * 40, 20 * 40, 21 * 40, 22 * 40, 23 * 40,
    24 * 40
  );
  direction: array [0..3] of byte = (
    JOY_UP, JOY_DOWN, JOY_LEFT, JOY_RIGHT
  );

//-----------------------------------------------------------------------------

type
  Player = record
    x, y, head, colour, dir, brain : byte;
    isDead                   : boolean;
  end;

//-----------------------------------------------------------------------------

var
  KEY_PIO             : byte absolute $fd30;
  JOY                 : byte absolute $ff08;
  BORDERCOLOR         : byte absolute $ff15;
  BGCOLOR             : byte absolute $ff19;
  t0b                 : byte absolute $58;
  newDir              : byte absolute $59;
  t0n                 : boolean absolute $5a;
  t0w                 : word absolute $5b;

//-----------------------------------------------------------------------------

var
  gameOver            : boolean;
  availDir, alive     : byte;
  ply                 : ^Player;

//-----------------------------------------------------------------------------

var
  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------

procedure initPlayfield;
begin
  BORDERCOLOR := $1f; BGCOLOR := 0;
  FillChar(pointer(SCREEN_ADDR), 24 * 40, EMPTY);

  for t0b := 39 downto 0 do begin
    Poke(SCREEN_ADDR + t0b, WALL);
    Poke((SCREEN_ADDR + 24 * 40 ) + t0b, WALL);
    Poke(ATTRIBUTE_ADDR + t0b, WALL_COLOUR);
    Poke((ATTRIBUTE_ADDR + 24 * 40) + t0b, WALL_COLOUR);
  end;

  for t0b := 24 downto 1 do begin
    DPoke((SCREEN_ADDR - 1) + mul40[t0b], WALL * 256 + WALL);
    DPoke((ATTRIBUTE_ADDR - 1) + mul40[t0b], WALL_COLOUR * 256 + WALL_COLOUR);
  end;
end;

procedure initPlayers(p: pointer; x, y, dir, brain, head, colour: byte);
begin
  ply := p;
  ply.brain := brain; ply.x := x; ply.y := y; ply.dir := dir;
  ply.head := head; ply.colour := colour; ply.isDead := false;

end;

//-----------------------------------------------------------------------------

procedure putChar(x, y, v, c: byte);
begin
  t0w := ATTRIBUTE_ADDR + mul40[y] + x;
  Poke(t0w, c); Poke(t0w + (SCREEN_ADDR - ATTRIBUTE_ADDR), v);
end;

procedure checkAvailDir(x, y: byte);
begin
  availDir := 0;
  t0w := SCREEN_ADDR + mul40[y] + x;

  if Peek(t0w - 40) = EMPTY then availDir := availDir or JOY_UP;
  if Peek(t0w + 40) = EMPTY then availDir := availDir or JOY_DOWN;
  if Peek(t0w - 1)  = EMPTY then availDir := availDir or JOY_LEFT;
  if Peek(t0w + 1)  = EMPTY then availDir := availDir or JOY_RIGHT;
end;

//-----------------------------------------------------------------------------

// brain = 0
procedure human;
begin
  newDir := ply.dir;
  JOY := JOY_SELECT_1; KEY_PIO := $ff; t0b := JOY xor $ff;

  case t0b of
    JOY_UP    : if ply.dir <> JOY_DOWN  then newDir := JOY_UP;
    JOY_DOWN  : if ply.dir <> JOY_UP    then newDir := JOY_DOWN;
    JOY_LEFT  : if ply.dir <> JOY_RIGHT then newDir := JOY_LEFT;
    JOY_RIGHT : if ply.dir <> JOY_LEFT  then newDir := JOY_RIGHT;
  end;

  if (newDir and availDir) = 0 then begin
    ply.isDead := true; alive := 0; ply.head := PLY_CRASH;
  end;
end;

// brain = 1
procedure ai_Straightforward;
begin
  if (availDir and ply.dir) <> 0 then newDir := ply.dir
  else begin
    if availDir = (JOY_UP or JOY_DOWN) then newDir := direction[Random(2)]
    else begin
      case availDir of
        JOY_UP    : newDir := JOY_UP;
        JOY_DOWN  : newDir := JOY_DOWN;
      end;
    end;
    if availDir = (JOY_LEFT or JOY_RIGHT) then newDir := direction[Random(2) + 2]
    else begin
      case availDir of
        JOY_LEFT   : newDir := JOY_LEFT;
        JOY_RIGHT  : newDir := JOY_RIGHT;
      end;
    end;
  end;
end;

//-----------------------------------------------------------------------------

procedure playerMove(p: pointer);
begin
  ply := p;

  if not ply.isDead then begin

    checkAvailDir(ply.x, ply.y);

    if availDir = 0 then begin
      ply.isDead := true; Dec(alive);
      putChar(ply.x, ply.y, PLY_CRASH, ply.colour + $80);
    end else begin

      case ply.brain of
        0 : human;
        1 : ai_Straightforward;
      end;

      if ply.dir = newDir then begin
        if (newDir and %1100) <> 0 then t0b := PLY_TAIl_LR else t0b := PLY_TAIl_UD;
      end else begin
        if ((ply.dir and %1010) <> 0) and ((newDir and %0101) <> 0) then t0b := PLY_TAIl_RD;
        if ((ply.dir and %1001) <> 0) and ((newDir and %0110) <> 0) then t0b := PLY_TAIl_RU;
        if ((ply.dir and %0110) <> 0) and ((newDir and %1001) <> 0) then t0b := PLY_TAIl_LD;
        if ((ply.dir and %0101) <> 0) and ((newDir and %1010) <> 0) then t0b := PLY_TAIl_LU;
      end;
      putChar(ply.x, ply.y, t0b, ply.colour);

      ply.dir := newDir;

      case newDir of
        JOY_UP    : Dec(ply.y);
        JOY_DOWN  : Inc(ply.y);
        JOY_LEFT  : Dec(ply.x);
        JOY_RIGHT : Inc(ply.x);
      end;

      putChar(ply.x, ply.y, ply.head, ply.colour);
    end;

  end;

end;

//-----------------------------------------------------------------------------

begin

  gameOver := false;
  repeat
    alive := 3;

    initPlayers(@player1, 10, 12, JOY_RIGHT, 1, PLY_HEAD, PLY1_COLOUR);
    initPlayers(@player2, 30, 12, JOY_LEFT,  1, PLY_HEAD, PLY2_COLOUR);
    initPlayers(@player3, 20,  6, JOY_DOWN,  1, PLY_HEAD, PLY3_COLOUR);
    initPlayers(@player4, 20, 18, JOY_UP,    1, PLY_HEAD, PLY4_COLOUR);

    initPlayfield;

    repeat
      pause(1); playerMove(@player1);
      pause(1); playerMove(@player2);
      pause(1); playerMove(@player3);
      pause(1); playerMove(@player4);
    until (alive = 0) or (alive = $ff);

    pause(100);
  until gameOver;

end.
