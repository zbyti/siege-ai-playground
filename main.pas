// set Z flag to 2

{$i 'inc/const.inc'}
{$i 'inc/types.inc'}
{$i 'inc/globals.inc'}
{$i 'inc/tools.inc'}
{$i 'inc/init.inc'}
{$i 'inc/ai.inc'}

//-----------------------------------------------------------------------------

procedure human; // brain = 0
begin
  newDir := ply.dir;
  JOY := JOY_SELECT_1; KEY_PIO := $ff; t0b := JOY xor $ff;

  case t0b of
    JOY_UP    : if ply.dir <> JOY_DOWN  then newDir := JOY_UP;
    JOY_DOWN  : if ply.dir <> JOY_UP    then newDir := JOY_DOWN;
    JOY_LEFT  : if ply.dir <> JOY_RIGHT then newDir := JOY_LEFT;
    JOY_RIGHT : if ply.dir <> JOY_LEFT  then newDir := JOY_RIGHT;
  end;

  if (newDir and availDir) = 0 then begin
    ply.isDead := true; alive := 0; ply.head := PLY_CRASH;
  end;
end;

//-----------------------------------------------------------------------------

procedure playerMove(p: pointer);
begin
  ply := p;

  if not ply.isDead then begin

    checkAvailDir(ply.x, ply.y);

    if availDir = 0 then begin
      ply.isDead := true; Dec(alive);
      putChar(ply.x, ply.y, PLY_CRASH, ply.colour + $80);
    end else begin

      case ply.brain of
        0 : human;
        1 : ai_Straightforward;
        2 : ai_Mirror;
        3 : ai_Random;
      end;

      if ply.dir = newDir then begin
        if (newDir and %1100) <> 0 then t0b := PLY_TAIl_LR else t0b := PLY_TAIl_UD;
      end else begin
        if ((ply.dir and %1010) <> 0) and ((newDir and %0101) <> 0) then t0b := PLY_TAIl_RD;
        if ((ply.dir and %1001) <> 0) and ((newDir and %0110) <> 0) then t0b := PLY_TAIl_RU;
        if ((ply.dir and %0110) <> 0) and ((newDir and %1001) <> 0) then t0b := PLY_TAIl_LD;
        if ((ply.dir and %0101) <> 0) and ((newDir and %1010) <> 0) then t0b := PLY_TAIl_LU;
      end;
      putChar(ply.x, ply.y, t0b, ply.colour);

      ply.dir := newDir;

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

procedure mainLoop;
begin
  initPlayers(@player1, 10, 12, JOY_RIGHT, 0, PLY_HEAD, PLY1_COLOUR, false);
  initPlayers(@player2, 30, 12, JOY_LEFT,  2, PLY_HEAD, PLY2_COLOUR, false);
  initPlayers(@player3, 20,  6, JOY_DOWN,  1, PLY_HEAD, PLY3_COLOUR, false);
  initPlayers(@player4, 20, 18, JOY_UP,    3, PLY_HEAD, PLY4_COLOUR, false);

  alive := $ff;
  if not player1.isDead then Inc(alive);
  if not player2.isDead then Inc(alive);
  if not player3.isDead then Inc(alive);
  if not player4.isDead then Inc(alive);

  initPlayfield;

  repeat
    pause(3); // 2 fast; 3 normal; 4 slow
    playerMove(@player1);
    playerMove(@player2);
    playerMove(@player3);
    playerMove(@player4);
  until (alive = 0) or (alive = $ff);

  pause(100);
end;

//-----------------------------------------------------------------------------

begin
  repeat mainLoop until false;
end.
