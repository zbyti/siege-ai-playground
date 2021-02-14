//-----------------------------------------------------------------------------

var
  KEY_PIO                            : byte absolute $fd30;
  JOY                                : byte absolute $ff08;
  BORDERCOLOR                        : byte absolute $ff15;
  BGCOLOR                            : byte absolute $ff19;
  t0b                                : byte absolute $58;
  newDir                             : byte absolute $59;
  availDir                           : byte absolute $5a;
  t0w                                : word absolute $5b;
  ply                                : ^Player absolute $5d;

//-----------------------------------------------------------------------------

  alive, speed                       : byte;
  gameOver                           : boolean;

//-----------------------------------------------------------------------------

  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------