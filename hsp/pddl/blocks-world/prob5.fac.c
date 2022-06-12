/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdio.h>
#include <string.h>
#include "planner.h"

int (*actionPreconditionsTable[MAXACTIONS])( register int *, register struct literal_s * );

char *problemName = "NINETEEN";
char *actionName[] = { "MOVETOBLOCK2", "MOVETOBLOCK1", "MOVETOTABLE", NULL };

char *objectName[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", NULL };

char *predicateName[] = { "CLEAR", "ON", "ON-TABLE", NULL };

int
actionPreconditions_MOVETOBLOCK2( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* ONaTABLE */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[2] == 0 )  goto label1;  else  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  return( 1 );
}

int
action_MOVETOBLOCK2( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_MOVETOBLOCK2( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 2;  /* ON */ 
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  p[0] = 3;  /* ONaTABLE */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

int
actionPreconditions_MOVETOBLOCK1( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  if( parameters[2] == 0 )  goto label0;  else  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[3] == 0 )  goto label1;  else  p[1] = parameters[3];  /* ?Z */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  return( 1 );
}

int
action_MOVETOBLOCK1( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_MOVETOBLOCK1( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 1;  /* CLEAR */ 
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  p[0] = 2;  /* ON */ 
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[3];  /* ?Z */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[3];  /* ?Z */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[3];  /* ?Z */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

int
actionPreconditions_MOVETOTABLE( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  if( parameters[2] == 0 )  goto label0;  else  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  return( 1 );
}

int
action_MOVETOTABLE( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_MOVETOTABLE( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 1;  /* CLEAR */ 
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  p[0] = 3;  /* ONaTABLE */ 
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  p[0] = 3;  /* ONaTABLE */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

void
setInitialSituation( void )
{
  situation[16].lit = 1;
  situation[17].lit = 1;
  situation[18].lit = 1;
  situation[19].lit = 1;
  situation[20].lit = 1;
  situation[21].lit = 1;
  situation[22].lit = 1;
  situation[23].lit = 1;
  situation[24].lit = 1;
  situation[25].lit = 1;
  situation[26].lit = 1;
  situation[27].lit = 1;
  situation[28].lit = 1;
  situation[29].lit = 1;
  situation[30].lit = 1;
  situation[31].lit = 1;
  situation[32].lit = 1;
  situation[33].lit = 1;
  situation[34].lit = 1;
  situation[35].lit = 1;
  situation[36].lit = 1;
  situation[37].lit = 1;
  situation[38].lit = 1;
}

int
goalSituation( struct literal_s *sit )
{
  return( sit[1].lit && sit[2].lit && sit[3].lit && sit[4].lit && sit[5].lit && sit[6].lit && sit[7].lit && sit[8].lit && sit[9].lit && sit[10].lit && sit[11].lit && sit[12].lit && sit[13].lit && sit[14].lit && sit[15].lit );
}

void
fillTableAux( void )
{
  actionTable[0] = &action_MOVETOBLOCK2;
  actionPreconditionsTable[0] = &actionPreconditions_MOVETOBLOCK2;
  actionTable[1] = &action_MOVETOBLOCK1;
  actionPreconditionsTable[1] = &actionPreconditions_MOVETOBLOCK1;
  actionTable[2] = &action_MOVETOTABLE;
  actionPreconditionsTable[2] = &actionPreconditions_MOVETOTABLE;
}

