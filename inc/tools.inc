//-----------------------------------------------------------------------------

procedure putChar(x, y, v, c: byte);
begin
  t0w := ATTRIBUTE_ADDR + mul40[y] + x;
  Poke(t0w, c); Poke(t0w + (SCREEN_ADDR - ATTRIBUTE_ADDR), v);
end;

//-----------------------------------------------------------------------------

procedure showScore;
begin
  putChar(30, 0, player1.score, player1.colour);
  putChar(32, 0, player2.score, player2.colour);
  putChar(34, 0, player3.score, player3.colour);
  putChar(36, 0, player4.score, player4.colour);
end;

//-----------------------------------------------------------------------------

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

procedure animateObstacles;
var
  counter, obst: byte;
begin
  Inc(counter);
  if (counter and 1) <> 0 then obst := OBSTACLE_1 else obst := OBSTACLE_2;
  putChar(10, 6, obst, OBST_COLOUR);
  putChar(30, 6, obst, OBST_COLOUR);
  putChar(10, 18, obst, OBST_COLOUR);
  putChar(30, 18, obst, OBST_COLOUR);
end;

