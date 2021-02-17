// set Z flag to 2

{$i 'inc/const.inc'}
{$i 'inc/types.inc'}
{$i 'inc/globals.inc'}
{$i 'inc/tools.inc'}
{$i 'inc/init.inc'}
{$i 'inc/ai.inc'}
{$i 'inc/levels.inc'}

//-----------------------------------------------------------------------------

procedure human; // brain = 0
begin
  newDir := ply.dir;
  JOY := JOY_SELECT_1; KEYSCAN := $ff; t0b := JOY xor $ff;

  case t0b of
    JOY_UP    : if ply.dir <> JOY_DOWN  then newDir := JOY_UP;
    JOY_DOWN  : if ply.dir <> JOY_UP    then newDir := JOY_DOWN;
    JOY_LEFT  : if ply.dir <> JOY_RIGHT then newDir := JOY_LEFT;
    JOY_RIGHT : if ply.dir <> JOY_LEFT  then newDir := JOY_RIGHT;
  end;

  if (newDir and availDir) = 0 then begin
    ply.isAlive := false; ply.head := PLY_CRASH; Dec(alive);
  end;
end;

//-----------------------------------------------------------------------------

procedure playerMove;
begin
  if ply.isAlive then begin
    checkAvailDir;

    if availDir = 0 then begin
      ply.isAlive := false; Dec(alive);
      putChar(ply.x, ply.y, PLY_BUSTED, ply.colour + $80);
    end else begin

      case ply.brain of
        PLY_CTRL    : human;
        AI_STRAIGHT : aiStraight;
        AI_SAPPER   : aiSapper;
        AI_BULLY    : aiBully;
        AI_MIRROR   : aiMirror;
      end;

      drawTail; ply.dir := newDir;

      case newDir of
        JOY_UP    : Dec(ply.y);
        JOY_DOWN  : Inc(ply.y);
        JOY_LEFT  : Dec(ply.x);
        JOY_RIGHT : Inc(ply.x);
      end;

      putChar(ply.x, ply.y, ply.head, ply.colour);

      //dirty workaround
      if not player1.isAlive then putChar(player1.x, player1.y, PLY_CRASH, player1.colour);
    end;

  end;

end;

//-----------------------------------------------------------------------------

procedure startScreen;
begin
  repeat
    JOY := JOY_SELECT_1; KEYSCAN := $ff; t0b := JOY xor $ff;
  until t0b = JOY_FIRE;
end;

//-----------------------------------------------------------------------------

procedure mainLoop;
begin
  alive := $ff;

  initPlayfield;

  case level of
    0 : setLevel01;
    1 : setLevel02;
    2 : setLevel03;
    3 : setLevel04;
    4 : setLevel05;
    5 : setLevel06;
    6 : setLevel07;
    7 : setLevel08;
  end;

  animateObstacles; showScore; startScreen;

  repeat
    pause(3); // 1 for AI; 2 fast; 3 normal; 4 slow
    ply := @player1; playerMove;
    ply := @player2; playerMove;
    ply := @player3; playerMove;
    ply := @player4; playerMove;
    animateObstacles;
  until (alive = 0) or (alive = $ff);

  if player1.isAlive then Inc(player1.score);
  if player2.isAlive then Inc(player2.score);
  if player3.isAlive then Inc(player3.score);
  if player4.isAlive then Inc(player4.score);

  pause(100);
end;

//-----------------------------------------------------------------------------

begin
  repeat
    player1.score := ZERO; player2.score := ZERO;
    player3.score := ZERO; player4.score := ZERO;
    level := 0;

    gameOver := false;
    repeat
      mainLoop;
      Inc(level); if level = 8 then level := 4;
      if player1.score = ZERO + VICTORIES then gameOver := true;
      if player2.score = ZERO + VICTORIES then gameOver := true;
      if player3.score = ZERO + VICTORIES then gameOver := true;
      if player4.score = ZERO + VICTORIES then gameOver := true;
    until gameOver;

    showScore;

    pause(200);
  until false;
end.
