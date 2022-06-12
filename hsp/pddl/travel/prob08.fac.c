/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdio.h>
#include <string.h>
#include "planner.h"

int (*actionPreconditionsTable[MAXACTIONS])( register int *, register struct literal_s * );

char *problemName = "JACK-BACK";
char *actionName[] = { "DISEMBARK", "BOARD", "CROSS", "DRIVE", NULL };

char *objectName[] = { "A", "G", "JACK", "BULLDOZER", NULL };

char *predicateName[] = { "=", "DRIVING", "VEHICLE", "PERSON", "BRIDGE", "MOBILE", "AT", "ROAD", NULL };

int
actionPreconditions_DISEMBARK( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[1] == 0 )  goto label0;
  if( parameters[3] == 0 )  goto label0;
  if( parameters[1] == parameters[3] ) return( 0 );
 label0:

  p[0] = 7;  /* AT */ 
  if( parameters[3] == 0 )  goto label1;  else  p[1] = parameters[3];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 2;  /* DRIVING */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?PERSON */
  if( parameters[3] == 0 )  goto label2;  else  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  p[0] = 3;  /* VEHICLE */ 
  if( parameters[3] == 0 )  goto label3;  else  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label3:

  p[0] = 4;  /* PERSON */ 
  if( parameters[1] == 0 )  goto label4;  else  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label4:

  return( 1 );
}

int
action_DISEMBARK( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_DISEMBARK( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 7;  /* AT */ 
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  p[0] = 6;  /* MOBILE */ 
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 2;  /* DRIVING */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

int
actionPreconditions_BOARD( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[1] == 0 )  goto label0;
  if( parameters[3] == 0 )  goto label0;
  if( parameters[1] == parameters[3] ) return( 0 );
 label0:

  p[0] = 7;  /* AT */ 
  if( parameters[3] == 0 )  goto label1;  else  p[1] = parameters[3];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 3;  /* VEHICLE */ 
  if( parameters[3] == 0 )  goto label2;  else  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  p[0] = 4;  /* PERSON */ 
  if( parameters[1] == 0 )  goto label3;  else  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label3:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label4;  else  p[1] = parameters[1];  /* ?PERSON */
  if( parameters[2] == 0 )  goto label4;  else  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label4:

  return( 1 );
}

int
action_BOARD( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_BOARD( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 2;  /* DRIVING */ 
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  p[0] = 6;  /* MOBILE */ 
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 2;  /* DRIVING */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

int
actionPreconditions_CROSS( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[2] == 0 )  goto label0;
  if( parameters[3] == 0 )  goto label0;
  if( parameters[2] == parameters[3] ) return( 0 );
 label0:

  p[0] = 6;  /* MOBILE */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?THING */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?THING */
  if( parameters[2] == 0 )  goto label2;  else  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  p[0] = 5;  /* BRIDGE */ 
  if( parameters[2] == 0 )  goto label3;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label3;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label3:

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
  p[0] = 7;  /* AT */ 
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[2];  /* ?FROM */
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
  if( parameters[2] == 0 )  goto label0;
  if( parameters[3] == 0 )  goto label0;
  if( parameters[2] == parameters[3] ) return( 0 );
 label0:

  p[0] = 6;  /* MOBILE */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?THING */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?THING */
  if( parameters[2] == 0 )  goto label2;  else  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  p[0] = 8;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label3;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label3;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label3:

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
  p[0] = 7;  /* AT */ 
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[2];  /* ?FROM */
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
  situation[1].lit = 1;
}

int
goalSituation( struct literal_s *sit )
{
  return( sit[1].lit && sit[2].lit );
}

void
fillTableAux( void )
{
  actionTable[0] = &action_DISEMBARK;
  actionPreconditionsTable[0] = &actionPreconditions_DISEMBARK;
  actionTable[1] = &action_BOARD;
  actionPreconditionsTable[1] = &actionPreconditions_BOARD;
  actionTable[2] = &action_CROSS;
  actionPreconditionsTable[2] = &actionPreconditions_CROSS;
  actionTable[3] = &action_DRIVE;
  actionPreconditionsTable[3] = &actionPreconditions_DRIVE;
}

