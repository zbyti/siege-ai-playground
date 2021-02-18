// set Z flag to 2

{$i 'inc/const.inc'}
{$i 'inc/types.inc'}
{$i 'inc/globals.inc'}
{$i 'inc/tools.inc'}
{$i 'inc/ai.inc'}
{$i 'inc/levels.inc'}
{$i 'inc/init.inc'}

//-----------------------------------------------------------------------------

procedure human; // brain = 0
begin
  checkJoyStatus; newDir := ply.dir;
  case joyStatus of
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
    end;

  end;

end;

//-----------------------------------------------------------------------------

procedure startScreen;
begin
  putChar(player1.x, player1.y, player1.head, player1.colour + $80);
  repeat checkJoyStatus until joyStatus = JOY_FIRE;
  putChar(player1.x, player1.y, player1.head, player1.colour);
end;

//-----------------------------------------------------------------------------

procedure mainLoop;
begin
  initArena; startScreen;

  repeat
    pause;
    ply := @player1; playerMove;

    animateObstacles;

    pause(2); // 1 fast; 2 normal; 3 slow
    ply := @player2; playerMove;
    ply := @player3; playerMove;
    ply := @player4; playerMove;
  until isAnybodyAlive;

  updateScore;

  pause(100);

  Inc(level); if level = 8 then level := 5;
end;

//-----------------------------------------------------------------------------

begin
  repeat
    initScore; gameOver := false; level := 1;

    repeat mainLoop until isGameOver;
    showScore;

    pause(200);
  until false;
end.
