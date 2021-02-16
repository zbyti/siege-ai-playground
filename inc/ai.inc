//-----------------------------------------------------------------------------

procedure aiStraight; // brain = 1
begin
  if (availDir and ply.dir) <> 0 then newDir := ply.dir
  else begin
    if availDir = (JOY_UP or JOY_DOWN) then newDir := direction[Random(2)]
    else begin
      case availDir of
        JOY_UP    : newDir := JOY_UP;
        JOY_DOWN  : newDir := JOY_DOWN;
      end;
    end;
    if availDir = (JOY_LEFT or JOY_RIGHT) then newDir := direction[Random(2) + 2]
    else begin
      case availDir of
        JOY_LEFT   : newDir := JOY_LEFT;
        JOY_RIGHT  : newDir := JOY_RIGHT;
      end;
    end;
  end;
end;

//-----------------------------------------------------------------------------

procedure aiBully; // brain = 2
begin
  t0b := ply.dir;

  if player1.isAlive then tmpPly := @player1 else tmpPly := @player2;

  if ply.y > tmpPly.y then t0b := JOY_UP else t0b := JOY_DOWN;
  if (ply.y = tmpPly.y) or ((availDir and t0b) = 0) then
    if ply.x > tmpPly.x then t0b := JOY_LEFT else t0b := JOY_RIGHT;

  if (availDir and t0b) <> 0 then newDir := t0b
  else aiStraight;
end;

//-----------------------------------------------------------------------------

procedure aiMirror; // brain = 3
begin
  case player1.dir of
    JOY_UP    : t0b := JOY_DOWN;
    JOY_DOWN  : t0b := JOY_UP;
    JOY_LEFT  : t0b := JOY_RIGHT;
    JOY_RIGHT : t0b := JOY_LEFT;
  end;

  if (availDir and t0b) <> 0 then newDir := t0b
  else aiStraight;
end;

//-----------------------------------------------------------------------------
