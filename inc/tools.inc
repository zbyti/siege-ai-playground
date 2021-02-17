//-----------------------------------------------------------------------------

procedure putChar(x, y, v, c: byte); overload;
begin
  t0w := ATTRIBUTE_ADDR + mul40[y] + x;
  Poke(t0w, c); Poke(t0w + (SCREEN_ADDR - ATTRIBUTE_ADDR), v);
end;

procedure putChar(x, y, v: byte); overload;
begin
  t0w := SCREEN_ADDR + mul40[y] + x; Poke(t0w, v);
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

procedure checkAvailDir;
begin
  availDir := 0;
  t0w := SCREEN_ADDR + mul40[ply.y] + ply.x;

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
  for i0b := 7 downto 0 do Poke(obstacles[i0b], obst);
end;

//-----------------------------------------------------------------------------

procedure saveObstacles;
begin
  for i0b := 7 downto 0 do begin
    if obstacles[i0b] <> TRASH then begin
      Poke(obstacles[i0b], OBSTACLE_1);
      Poke(obstacles[i0b] - $400, OBST_COLOUR);
    end;
  end;
end;

//-----------------------------------------------------------------------------

procedure drawTail;
begin
  if ply.dir = newDir then begin
    if (newDir and %1100) <> 0 then t0b := PLY_TAIL_LR else t0b := PLY_TAIL_UD;
  end else begin
    if ((ply.dir and %1010) <> 0) and ((newDir and %0101) <> 0) then t0b := PLY_TAIL_RD;
    if ((ply.dir and %1001) <> 0) and ((newDir and %0110) <> 0) then t0b := PLY_TAIL_RU;
    if ((ply.dir and %0110) <> 0) and ((newDir and %1001) <> 0) then t0b := PLY_TAIL_LD;
    if ((ply.dir and %0101) <> 0) and ((newDir and %1010) <> 0) then t0b := PLY_TAIL_LU;
  end;
  putChar(ply.x, ply.y, t0b);
end;

//-----------------------------------------------------------------------------

procedure checkJoyStatus;
begin
  JOY := JOY_SELECT_1; KEYSCAN := $ff;
  joyStatus := JOY xor $ff;
end;
