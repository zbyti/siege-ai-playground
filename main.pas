const
  ATTRIBUTE_ADDR      = $0800;
  SCREEN_ADDR         = $0c00;
  WALL                = $a0;
  WALL_COLOUR         = $41;
  EMPTY               = $20;
  PLY_HEAD            = $57;
  PLY_TAIL            = $2a;
  PLY_CRASH           = $51;
  PLY1_COLOUR         = $5f;
  PLY2_COLOUR         = $5d;
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

//-----------------------------------------------------------------------------

type
  Direction = (up = 8, down = 4, left = 2, right = 1);
  Player = record
    x, y, colour, dir : byte;
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
  gameOver, playerDie : boolean;
  availDir            : byte;

//-----------------------------------------------------------------------------

var
  player1, player2 : Player;

//-----------------------------------------------------------------------------

procedure initPlayfield;
begin
  playerDie := false;

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
  player1.x := 10; player1.y := 10; player1.colour := PLY1_COLOUR;
  player2.x := 30; player2.y := 10; player2.colour := PLY2_COLOUR;
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
  checkAvailDir(ply.x, ply.y);
  if availDir = 0 then begin
    playerDie := true;
    putChar(ply.x, ply.y, PLY_CRASH, ply.colour + $80);
  end else begin
    t0n := false;
    repeat
      t0b := 1 shl Random(4);
      if (availDir and t0b) <> 0 then t0n := true;
    until t0n;

    ply.dir := t0b;

    putChar(ply.x, ply.y, PLY_TAIL, ply.colour);

    case t0b of
      JOY_UP    : Dec(ply.y);
      JOY_DOWN  : Inc(ply.y);
      JOY_LEFT  : Dec(ply.x);
      JOY_RIGHT : Inc(ply.x);
    end;

    putChar(ply.x, ply.y, PLY_HEAD, ply.colour);
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
    until playerDie;

    pause(100);
  until gameOver;

end.
