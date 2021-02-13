const
  ATTRIBUTE_ADDR      = $0800;
  SCREEN_ADDR         = $0c00;
  WALL                = $a0;
  WALL_COLOUR         = $41;
  EMPTY               = $20;
  PLY_HEAD            = $51;
  PLY_CRASH           = $57;
  PLY_TAIl_UD          = $42;
  PLY_TAIl_LR          = $40;
  PLY_TAIl_RD         = $7d;
  PLY_TAIl_RU         = $6e;
  PLY_TAIl_LD         = $6d;
  PLY_TAIl_LU         = $70;
  PLY1_COLOUR         = $5f;
  PLY2_COLOUR         = $5d;
  PLY3_COLOUR         = $71;
  PLY4_COLOUR         = $55;
  JOY_UP              = 1;
  JOY_DOWN            = 2;
  JOY_LEFT            = 4;
  JOY_RIGHT           = 8;

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
    x, y, colour, dir : byte;
    isDead            : boolean;
  end;

//-----------------------------------------------------------------------------

var
  BORDERCOLOR         : byte absolute $ff15;
  BGCOLOR             : byte absolute $ff19;
  t0b                 : byte absolute $58;
  t0n                 : boolean absolute $59;
  t0w                 : word absolute $5a;

//-----------------------------------------------------------------------------

var
  gameOver            : boolean;
  availDir, alive     : byte;

//-----------------------------------------------------------------------------

var
  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------

procedure initPlayfield;
begin
  alive := 3;

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

procedure initPlayers;
begin
  player1.x := 10; player1.y := 10; player1.colour := PLY1_COLOUR; player1.isDead := false; player1.dir := JOY_RIGHT;
  player2.x := 30; player2.y := 10; player2.colour := PLY2_COLOUR; player2.isDead := false; player2.dir := JOY_LEFT;
  player3.x := 20; player3.y := 6;  player3.colour := PLY3_COLOUR; player3.isDead := false; player3.dir := JOY_DOWN;
  player4.x := 20; player4.y := 18; player4.colour := PLY4_COLOUR; player4.isDead := false; player4.dir := JOY_UP;
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

procedure playerMove(p: pointer);
var
  ply : ^Player;
begin
  ply := p;

  if not ply.isDead then begin

    checkAvailDir(ply.x, ply.y);

    if availDir = 0 then begin
      ply.isDead := true; Dec(alive);
      putChar(ply.x, ply.y, PLY_CRASH, ply.colour + $80);
    end else begin
      //>>>>>>>>>>>>>>> ai code
      t0n := false;
      repeat
        t0b := direction[Random(4)];
        if (availDir and t0b) <> 0 then t0n := true;
      until t0n;
      //>>>>>>>>>>>>>>>

      if ply.dir = t0b then begin
        if (t0b and %1100) <> 0 then putChar(ply.x, ply.y, PLY_TAIl_LR, ply.colour)
        else putChar(ply.x, ply.y, PLY_TAIl_UD, ply.colour);
      end else begin
        if ((ply.dir and %1010) <> 0) and ((t0b and %0101) <> 0) then putChar(ply.x, ply.y, PLY_TAIl_RD, ply.colour);
        if ((ply.dir and %1001) <> 0) and ((t0b and %0110) <> 0) then putChar(ply.x, ply.y, PLY_TAIl_RU, ply.colour);
        if ((ply.dir and %0110) <> 0) and ((t0b and %1001) <> 0) then putChar(ply.x, ply.y, PLY_TAIl_LD, ply.colour);
        if ((ply.dir and %0101) <> 0) and ((t0b and %1010) <> 0) then putChar(ply.x, ply.y, PLY_TAIl_LU, ply.colour);
      end;


      ply.dir := t0b;

      case t0b of
        JOY_UP    : Dec(ply.y);
        JOY_DOWN  : Inc(ply.y);
        JOY_LEFT  : Dec(ply.x);
        JOY_RIGHT : Inc(ply.x);
      end;

      putChar(ply.x, ply.y, PLY_HEAD, ply.colour);
    end;

  end;

end;

//-----------------------------------------------------------------------------

begin

  gameOver := false;

  repeat
    initPlayers;
    initPlayfield;

    repeat
      pause(10);
      playerMove(@player1);
      playerMove(@player2);
      playerMove(@player3);
      playerMove(@player4);
    until alive = 0;

    pause(100);
  until gameOver;

end.
