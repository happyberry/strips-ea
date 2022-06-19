/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdio.h>
#include <string.h>
#include "planner.h"

int (*actionPreconditionsTable[MAXACTIONS])( register int *, register struct literal_s * );

char *problemName = "ROAD-TEST";
char *actionName[] = { "CROSS", "DRIVE", NULL };

char *objectName[] = { "A", "D", "G", "CAR", "BULLDOZER", NULL };

char *predicateName[] = { "VEHICLE", "PLACE", "BRIDGE", "ROAD", "AT", NULL };

int
actionPreconditions_CROSS( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* BRIDGE */ 
  if( parameters[2] == 0 )  goto label0;  else  p[1] = parameters[2];  /* ?LOCATION1 */
  if( parameters[3] == 0 )  goto label0;  else  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label0:

  p[0] = 5;  /* AT */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  return( 1 );
}

int
action_CROSS( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_CROSS( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 5;  /* AT */ 
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

int
actionPreconditions_DRIVE( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 4;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label0;  else  p[1] = parameters[2];  /* ?LOCATION1 */
  if( parameters[3] == 0 )  goto label0;  else  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label0:

  p[0] = 5;  /* AT */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  return( 1 );
}

int
action_DRIVE( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_DRIVE( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 5;  /* AT */ 
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

void
setInitialSituation( void )
{
  situation[3].lit = 1;
  situation[4].lit = 1;
  situation[5].lit = 1;
  situation[6].lit = 1;
  situation[7].lit = 1;
  situation[8].lit = 1;
  situation[9].lit = 1;
  situation[10].lit = 1;
  situation[11].lit = 1;
  situation[12].lit = 1;
  situation[13].lit = 1;
}

int
goalSituation( struct literal_s *sit )
{
  return( sit[1].lit && sit[2].lit );
}

void
fillTableAux( void )
{
  actionTable[0] = &action_CROSS;
  actionPreconditionsTable[0] = &actionPreconditions_CROSS;
  actionTable[1] = &action_DRIVE;
  actionPreconditionsTable[1] = &actionPreconditions_DRIVE;
}

