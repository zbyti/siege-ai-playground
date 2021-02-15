//-----------------------------------------------------------------------------

var
  KEY_PIO                            : byte absolute $fd30;
  JOY                                : byte absolute $ff08;
  BORDERCOLOR                        : byte absolute $ff15;
  BGCOLOR                            : byte absolute $ff19;
  t0b                                : byte absolute $58;
  alive                              : byte absolute $59;
  newDir                             : byte absolute $5a;
  availDir                           : byte absolute $5b;
  t0w                                : word absolute $5c;
  ply                                : ^Player absolute $5e;
  tmpPly                             : ^Player absolute $60;

//-----------------------------------------------------------------------------

  gameOver                           : boolean;

//-----------------------------------------------------------------------------

  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------