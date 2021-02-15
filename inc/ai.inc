//-----------------------------------------------------------------------------

procedure aiStraight; // brain = 1
begin
  if (availDir and ply.dir) <> 0 then newDir := ply.dir
  else begin
    if availDir = (JOY_UP or JOY_DOWN) then newDir := direction[Random(0) and 1]
    else begin
      case availDir of
        JOY_UP    : newDir := JOY_UP;
        JOY_DOWN  : newDir := JOY_DOWN;
      end;
    end;
    if availDir = (JOY_LEFT or JOY_RIGHT) then newDir := direction[(Random(0) and 1) + 2]
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

  if ply.y > player1.y then t0b := JOY_UP else t0b := JOY_DOWN;
  if (ply.y = player1.y) or ((availDir and t0b) = 0) then begin
    if ply.x > player1.x then t0b := JOY_LEFT else t0b := JOY_RIGHT;
  end;

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

procedure aiRandom; // brain = 4
begin
  t0b := ply.dir;
  if (Random(0) and 3) = 0 then t0b := direction[Random(4)];

  if (availDir and t0b) <> 0 then newDir := t0b
  else aiStraight;
end;

//-----------------------------------------------------------------------------

procedure aiMad; // brain = 7
begin
  t0b := (Random(4) + 1);
  case t0b of
    AI_STRAIGHT : aiStraight;
    AI_BULLY    : aiBully;
    AI_MIRROR   : aiMirror;
    AI_RANDOM   : aiRandom;
  end;
end;

//-----------------------------------------------------------------------------