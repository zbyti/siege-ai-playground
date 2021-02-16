//-----------------------------------------------------------------------------

procedure initPlayers(p: pointer; x, y, dir, brain, head, colour: byte; isAlive: boolean);
begin
  ply := p;
  ply.brain := brain; ply.x := x; ply.y := y; ply.dir := dir;
  ply.head := head; ply.colour := colour; ply.isAlive := isAlive;
  if isAlive then begin
    Inc(alive); putChar(x, y, head, colour);
  end;
end;

//-----------------------------------------------------------------------------

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

  // H Vs.AI_STRAIGHT - very easy
  // H Vs. AI_BULLY   - easy
  // H Vs. AI_SAPER   - moderate
  // H Vs. AI_MIRROR  - hard
  // h Vs. 3 bots     - hard hard (2x AI_BULLY, AI_BULLY & AI_SAPER)
  initPlayers(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 30, 12, JOY_LEFT,  AI_MIRROR,   PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, true);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_SAPER,    PLY_HEAD, PLY4_COLOUR, true);

  putChar(10,  6, OBSTACLE_1, OBST_COLOUR);
  putChar(30,  6, OBSTACLE_1, OBST_COLOUR);
  putChar(10, 18, OBSTACLE_1, OBST_COLOUR);
  putChar(30, 18, OBSTACLE_1, OBST_COLOUR);
  putChar( 1, 12, OBSTACLE_1, OBST_COLOUR);
  //putChar(38, 12, OBSTACLE_1, OBST_COLOUR);
  putChar(20,  2, OBSTACLE_1, OBST_COLOUR);
  putChar(20, 22, OBSTACLE_1, OBST_COLOUR);

  showScore;
end;

//-----------------------------------------------------------------------------