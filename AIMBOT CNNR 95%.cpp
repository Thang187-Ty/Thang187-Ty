%55include%95%3Ccom.dts.freefireth%3E
%55include%95%3Ccom.dts.freefiremax%3E
%2F%2FCREADOR%95H44LAND%95G%95
class%95AutoAim%95%7B
public%3A
%95%95%95%95std%3A%3Astring%95enemyTag%95%3D%95%22Enemy%22%3B%95
%95%95%95%95float%95rotationSpeed%95%3D%95360.0f%3B%95%95%95
%95%95%95%95sf%3A%3ATransformable%95target%3B%95%95%95%95%95%95%95

%95%95%95%95void%95Start()%95%7B
%95%95%95%95%95%95%95%95FindClosestEnemy()%3B
%95%95%95%95%7D
%2F%2FCREADOR%95H44LAND%95G%95
%95%95%95%95void%95Update()%95%7B
%95%95%95%95%95%95%95%95if%95(target)%95%7B
%95%95%95%95%95%95%95%95%95%95%95%95sf%3A%3AVector2f%95direction%95%3D%95target.getPosition()%95-%95transformable.getPosition()%3B
%95%95%95%95%95%95%95%95%95%95%95%95float%95rotation%95%3D%95std%3A%3Aatan2(direction.y%2C%95direction.x)%95*%95180%95%2F%953.14159265f%3B

%95%95%95%95%95%95%95%95%95%95%95%95
%95%95%95%95%95%95%95%95%95%95%95%95float%95currentRotation%95%3D%95transformable.getRotation()%3B
%95%95%95%95%95%95%95%95%95%95%95%95float%95rotationStep%95%3D%95rotationSpeed%95*%95sf%3A%3ATime%3A%3AasSeconds(sf%3A%3AClock%3A%3AgetGlobalClock().getElapsedTime())%3B
%95%95%95%95%95%95%95%95%95%95%95%95if%95(rotationStep%95%3E%95std%3A%3Aabs(rotation%95-%95currentRotation))
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95transformable.setRotation(rotation)%3B
%95%95%95%95%95%95%95%95%95%95%95%95else%95%7B
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95if%95(rotation%95%3E%95currentRotation)
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95transformable.setRotation(currentRotation%95%2B%95rotationStep)%3B
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95else
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95transformable.setRotation(currentRotation%95-%95rotationStep)%3B
%95%95%95%95%95%95%95%95%95%95%95%95%7D
%95%95%95%95%95%95%95%95%7D
%95%95%95%95%7D
%2F%2FCREADOR%95H44LAND%95G%95
%95%95%95%95void%95FindClosestEnemy()%95%7B
%95%95%95%95%95%95%95%95std%3A%3Avector%3Csf%3A%3ATransformable*%3E%95enemies%3B%95

%95%95%95%95%95%95%95%95float%95closestDistance%95%3D%95std%3A%3Anumeric_limits%3Cfloat%3E%3A%3Ainfinity()%3B
%95%95%95%95%95%95%95%95sf%3A%3ATransformable*%95closestEnemy%95%3D%95nullptr%3B

%95%95%95%95%95%95%95%95for%95(sf%3A%3ATransformable*%95enemy%95%3A%95enemies)%95%7B
%95%95%95%95%95%95%95%95%95%95%95%95sf%3A%3AVector2f%95direction%95%3D%95transformable.getPosition()%95-%95enemy-%3EgetPosition()%3B
%95%95%95%95%95%95%95%95%95%95%95%95float%95distance%95%3D%95std%3A%3Asqrt(direction.x%95*%95direction.x%95%2B%95direction.y%95*%95direction.y)%3B

%95%95%95%95%95%95%95%95%95%95%95%95if%95(distance%95%3C%95closestDistance)%95%7B
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95closestDistance%95%3D%95distance%3B
%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95%95closestEnemy%95%3D%95enemy%3B
%95%95%95%95%95%95%95%95%95%95%95%95%7D
%95%95%95%95%95%95%95%95%7D

%95%95%95%95%95%95%95%95if%95(closestEnemy%95!%3D%95nullptr)%95%7B
%95%95%95%95%95%95%95%95%95%95%95%95target%95%3D%95*closestEnemy%3B
%95%95%95%95%95%95%95%95%7D
%95%95%95%95%7D
%95%2F%2FCREADOR%95H44LAND%95G%95
%95private%3A
%95%95%95%95sf%3A%3ATransformable%95transformable%3B
%95%7D%3B

%95int%95main()%95%7B
%95%95%95%95AutoAim%95autoAim%3B
%95%95%95%95autoAim.Start()%3B

%95%95%95%95while%95(true)%95%7B
%95%95%95%95
%95%95%95%95%95%95%95%95autoAim.Update()%3B
%95%95%95%95%7D

%95%95%95%return%950%3B
%7D