const
  ATTRIBUTE_ADDR   = $0800;
  SCREEN_ADDR      = $0c00;
  WALL             = $a0;
  WALL_COLOUR      = $31;
  EMPTY            = $20;
  PLY_HEAD         = $57;
  PLY_TAIL         = $a0;
  PLY1_COLOUR      = $7f;
  PLY2_COLOUR      = $4e;

const
  mul40: array [0..24] of word = (
     0 * 40,  1 * 40,  2 * 40,  3 * 40,  4 * 40,  5 * 40,
     6 * 40,  7 * 40,  8 * 40,  9 * 40, 10 * 40, 11 * 40,
    12 * 40, 13 * 40, 14 * 40, 15 * 40, 16 * 40, 17 * 40,
    18 * 40, 19 * 40, 20 * 40, 21 * 40, 22 * 40, 23 * 40,
    24 * 40
  );

type
  TPlayer = record
    x,y: byte;
  end;

var
  BORDERCOLOR      : byte absolute $ff15;
  BGCOLOR          : byte absolute $ff19;

var
  i0b              : byte absolute $58;
  t0w              : word absolute $59;

var
  player1, player2 : TPlayer;


procedure init;
begin
  BORDERCOLOR := 0; BGCOLOR := 0;
  FillChar(pointer(SCREEN_ADDR), 24 * 40, EMPTY);

  for i0b := 39 downto 0 do begin
    Poke(SCREEN_ADDR + i0b, WALL);
    Poke((SCREEN_ADDR + 24 * 40 ) + i0b, WALL);
    Poke(ATTRIBUTE_ADDR + i0b, WALL_COLOUR);
    Poke((ATTRIBUTE_ADDR + 24 * 40) + i0b, WALL_COLOUR);
  end;

  for i0b := 24 downto 1 do begin
    DPoke((SCREEN_ADDR - 1) + mul40[i0b], WALL * 256 + WALL);
    DPoke((ATTRIBUTE_ADDR - 1) + mul40[i0b], WALL_COLOUR * 256 + WALL_COLOUR);
  end;

  player1.x := 10; player1.y := 10;
end;

procedure putChar(x, y, v, c : byte);
begin
  t0w := ATTRIBUTE_ADDR + mul40[y] + x;
  Poke(t0w, c); Poke(t0w + (SCREEN_ADDR - ATTRIBUTE_ADDR), v);
end;

begin
  init;
  putChar(player1.x, player1.x, PLY_HEAD, PLY1_COLOUR);
  repeat
    pause;
  until false;
end.
