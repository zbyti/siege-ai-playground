//-----------------------------------------------------------------------------

procedure setLevel01;
begin
  initPlayers(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 30, 12, JOY_LEFT,  AI_STRAIGHT,   PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_SAPPER,   PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := TRASH;
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := TRASH;

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel02;
begin
  initPlayers(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 30, 12, JOY_LEFT,  AI_BULLY,    PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_SAPPER,   PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := TRASH;
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := TRASH;

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel03;
begin
  initPlayers(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 30, 12, JOY_LEFT,  AI_SAPPER,   PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_BULLY,    PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := TRASH;

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel04;
begin
  initPlayers(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 22, 12, JOY_RIGHT, AI_MIRROR,   PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_BULLY,    PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := SCREEN_ADDR + 20 + (12 * 40); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel05;
begin
  initPlayers(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 30, 12, JOY_LEFT,  AI_MIRROR,   PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, true);
  initPlayers(@player4, 20, 18, JOY_UP,    AI_SAPPER,   PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := TRASH;

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel06;
begin
  initPlayers(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 22, 12, JOY_RIGHT, AI_SAPPER, PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3,  6,  6, JOY_DOWN,  AI_SAPPER, PLY_HEAD, PLY3_COLOUR, true);
  initPlayers(@player4, 36, 18, JOY_RIGHT, AI_BULLY,  PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := SCREEN_ADDR + 20 + (12 * 40); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel07;
begin
  initPlayers(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2,  1, 23, JOY_RIGHT, AI_BULLY,  PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 30,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, true);
  initPlayers(@player4, 36, 21, JOY_UP,    AI_SAPPER, PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := SCREEN_ADDR + 20 + (12 * 40); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel08;
begin
  initPlayers(@player1,  1, 23, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  initPlayers(@player2, 38, 23, JOY_LEFT,  AI_BULLY,    PLY_HEAD, PLY2_COLOUR, true);
  initPlayers(@player3, 10,  1, JOY_DOWN,  AI_SAPPER,   PLY_HEAD, PLY3_COLOUR, true);
  initPlayers(@player4, 38,  1, JOY_LEFT,  AI_MIRROR,   PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := SCREEN_ADDR + 10 + ( 6 * 40);
  obstacles[1] := SCREEN_ADDR + 30 + ( 6 * 40);
  obstacles[2] := SCREEN_ADDR + 10 + (18 * 40);
  obstacles[3] := SCREEN_ADDR + 30 + (18 * 40);
  obstacles[4] := SCREEN_ADDR +  1 + (12 * 40);
  obstacles[5] := SCREEN_ADDR + 20 + ( 2 * 40);
  obstacles[6] := SCREEN_ADDR + 20 + (22 * 40);
  obstacles[7] := SCREEN_ADDR + 20 + (12 * 40); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------