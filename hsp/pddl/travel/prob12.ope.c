/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "planner.h"

int (*heuristicActionPreconditionsTable[MAXACTIONS])( register int * );
int (*heuristicActionTable[MAXACTIONS])( register int * );
static int preconditions[MAXPARAMETERS];
int preclist[MAXPARAMETERS], addlist[MAXPARAMETERS];
extern struct cost_s costs[], oldCosts[];

int
heuristicActionPreconditions_RUN( register int *parameters )
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
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 3;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label2;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label2;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  return( 1 );
}

int
heuristicAction_RUN( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[2] == parameters[3] ) return( 0 );

  p[0] = 2;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 3;  /* ROAD */
  p[1] = parameters[2];  /* ?FROM */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 2;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

void
setupHeuristic( void )
{
  heuristicActionTable[0] = &heuristicAction_RUN;
  heuristicActionPreconditionsTable[0] = &heuristicActionPreconditions_RUN;
}

int goalAtoms[] = { 1 /* (AT JACK ROCKWELL) */, 2 /* (AT JACK KI) */, 0 };

