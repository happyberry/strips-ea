/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdio.h>
#include <string.h>
#include "planner.h"

int (*actionPreconditionsTable[MAXACTIONS])( register int *, register struct literal_s * );

char *problemName = "RUN-JACK";
char *actionName[] = { "RUN", NULL };

char *objectName[] = { "JACK", "MICROSOFT", "ROCKWELL", "KI", NULL };

char *predicateName[] = { "=", "AT", "ROAD", NULL };

int
actionPreconditions_RUN( register int *parameters, register struct literal_s *sit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[2] == 0 )  goto label0;
  if( parameters[3] == 0 )  goto label0;
  if( parameters[2] == parameters[3] ) return( 0 );
 label0:

  p[0] = 2;  /* AT */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?PERSON */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label1:

  p[0] = 3;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label2;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label2;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( !sit[idx].lit ) return( 0 );
 label2:

  return( 1 );
}

int
action_RUN( register int *parameters, register struct literal_s *sit, register struct literal_s *newSit )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( !actionPreconditions_RUN( parameters, sit ) ) return( 0 );

  /* relevantAtoms testing */
  p[0] = 2;  /* AT */ 
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  if( relevantAtoms[readAtomHash( p )->idx] ) goto end;

  return( 0 );
 end:

  /* add-list */
  p[0] = 2;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 1;

  /* del-list */
  p[0] = 2;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  newSit[idx].lit = 0;

  return( 1 );
}

void
setInitialSituation( void )
{
  situation[2].lit = 1;
  situation[3].lit = 1;
  situation[4].lit = 1;
}

int
goalSituation( struct literal_s *sit )
{
  return( sit[1].lit );
}

void
fillTableAux( void )
{
  actionTable[0] = &action_RUN;
  actionPreconditionsTable[0] = &actionPreconditions_RUN;
}

