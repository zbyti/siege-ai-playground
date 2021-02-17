//-----------------------------------------------------------------------------

var
  KEYSCAN                            : byte absolute $fd30;
  JOY                                : byte absolute $ff08;
  BACKGROUND                         : byte absolute $ff15;
  BOREDER                            : byte absolute $ff19;

//-----------------------------------------------------------------------------

  t0b                                : byte absolute $58;
  i0b                                : byte absolute $59;
  alive                              : byte absolute $5a;
  newDir                             : byte absolute $5b;
  availDir                           : byte absolute $5c;
  t0w                                : word absolute $5d;
  ply                                : ^Player absolute $5f;
  tmpPly                             : ^Player absolute $61;

//-----------------------------------------------------------------------------

  gameOver                           : boolean;

//-----------------------------------------------------------------------------

  player1, player2, player3, player4 : Player;

//-----------------------------------------------------------------------------

  obstacles                          : array [0..7] of word;

//-----------------------------------------------------------------------------