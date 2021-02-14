procedure initPlayfield;
begin
  BORDERCOLOR := $1f; BGCOLOR := 0;
  FillChar(pointer(SCREEN_ADDR), 24 * 40, EMPTY);

  for t0b := 39 downto 0 do begin
    Poke(SCREEN_ADDR + t0b, WALL);
    Poke((SCREEN_ADDR + 24 * 40) + t0b, WALL);
    Poke(ATTRIBUTE_ADDR + t0b, WALL_COLOUR);
    Poke((ATTRIBUTE_ADDR + 24 * 40) + t0b, WALL_COLOUR);
  end;

  for t0b := 24 downto 1 do begin
    DPoke((SCREEN_ADDR - 1) + mul40[t0b], WALL * 256 + WALL);
    DPoke((ATTRIBUTE_ADDR - 1) + mul40[t0b], WALL_COLOUR * 256 + WALL_COLOUR);
  end;
end;

//-----------------------------------------------------------------------------

procedure initPlayers(p: pointer; x, y, dir, brain, head, colour: byte; isDead: boolean);
begin
  ply := p;
  ply.brain := brain; ply.x := x; ply.y := y; ply.dir := dir;
  ply.head := head; ply.colour := colour; ply.isDead := isDead;

end;

//-----------------------------------------------------------------------------