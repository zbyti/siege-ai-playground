//-----------------------------------------------------------------------------

procedure setLevel00; // test
begin
  setPlayer(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 30, 12, JOY_LEFT,  AI_STRAIGHT, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_SAPPER,   PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr(20,  2);
  obstacles[5] := calcObstacleAddr(20, 22);

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel01;
begin
  setPlayer(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,    PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 30, 12, JOY_LEFT,  AI_STRAIGHT, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,    PLY_HEAD, PLY3_COLOUR, false);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_SAPPER,   PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr(20,  2);
  obstacles[5] := calcObstacleAddr(20, 22);

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel02;
begin
  setPlayer(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 30, 12, JOY_LEFT,  AI_BULLY,  PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, false);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_SAPPER, PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr(20,  2);
  obstacles[5] := calcObstacleAddr(20, 22);

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel03;
begin
  setPlayer(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 30, 12, JOY_LEFT,  AI_SAPPER, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, false);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_BULLY,  PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel04;
begin
  setPlayer(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 22, 12, JOY_RIGHT, AI_MIRROR, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, false);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_BULLY,  PLY_HEAD, PLY4_COLOUR, false);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);
  obstacles[7] := calcObstacleAddr(20, 12); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel05;
begin
  setPlayer(@player1, 10, 12, JOY_RIGHT, PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 30, 12, JOY_LEFT,  AI_MIRROR, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 20,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, true);
  setPlayer(@player4, 20, 18, JOY_UP,    AI_SAPPER, PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel06;
begin
  setPlayer(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 22, 12, JOY_RIGHT, AI_SAPPER, PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3,  6,  6, JOY_DOWN,  AI_SAPPER, PLY_HEAD, PLY3_COLOUR, true);
  setPlayer(@player4, 36, 18, JOY_RIGHT, AI_BULLY,  PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);
  obstacles[7] := calcObstacleAddr(20, 12); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel07;
begin
  setPlayer(@player1, 18, 12, JOY_LEFT,  PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2,  1, 23, JOY_RIGHT, AI_BULLY,  PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 30,  4, JOY_DOWN,  AI_BULLY,  PLY_HEAD, PLY3_COLOUR, true);
  setPlayer(@player4, 36, 21, JOY_UP,    AI_SAPPER, PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);
  obstacles[7] := calcObstacleAddr(20, 12); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------

procedure setLevel08;
begin
  setPlayer(@player1,  1, 23, JOY_RIGHT, PLY_CTRL,  PLY_HEAD, PLY1_COLOUR, true);
  setPlayer(@player2, 38, 23, JOY_LEFT,  AI_BULLY,  PLY_HEAD, PLY2_COLOUR, true);
  setPlayer(@player3, 10,  1, JOY_DOWN,  AI_SAPPER, PLY_HEAD, PLY3_COLOUR, true);
  setPlayer(@player4, 38,  1, JOY_LEFT,  AI_MIRROR, PLY_HEAD, PLY4_COLOUR, true);

  obstacles[0] := calcObstacleAddr(10,  6);
  obstacles[1] := calcObstacleAddr(30,  6);
  obstacles[2] := calcObstacleAddr(10, 18);
  obstacles[3] := calcObstacleAddr(30, 18);
  obstacles[4] := calcObstacleAddr( 1, 12);
  obstacles[5] := calcObstacleAddr(20,  2);
  obstacles[6] := calcObstacleAddr(20, 22);
  obstacles[7] := calcObstacleAddr(20, 12); // center

  saveObstacles;
end;

//-----------------------------------------------------------------------------