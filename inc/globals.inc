//-----------------------------------------------------------------------------

var
  KEY_PIO                            : byte absolute $fd30;
  JOY                                : byte absolute $ff08;
  BORDERCOLOR                        : byte absolute $ff15;
  BGCOLOR                            : byte absolute $ff19;
  t0b                                : byte absolute $58;
  t1b                                : byte absolute $59;
  i0b                                : byte absolute $5a;
  i1b                                : byte absolute $5b;
  newDir                             : byte absolute $5c;
  availDir                           : byte absolute $5d;
  t0w                                : word absolute $5e;
  ply                                : ^Player absolute $60;

//-----------------------------------------------------------------------------

  alive, speed                       : byte;
  gameOver                           : boolean;

//-----------------------------------------------------------------------------

  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------