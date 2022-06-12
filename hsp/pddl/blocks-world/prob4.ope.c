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
heuristicActionPreconditions_MOVETOBLOCK2( register int *parameters )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* ONaTABLE */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[2] == 0 )  goto label1;  else  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  return( 1 );
}

int
heuristicAction_MOVETOBLOCK2( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* ONaTABLE */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 1;  /* CLEAR */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

int
heuristicActionPreconditions_MOVETOBLOCK1( register int *parameters )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  if( parameters[2] == 0 )  goto label0;  else  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[3] == 0 )  goto label1;  else  p[1] = parameters[3];  /* ?Z */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  return( 1 );
}

int
heuristicAction_MOVETOBLOCK1( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 1;  /* CLEAR */
  p[1] = parameters[3];  /* ?Z */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 1;  /* CLEAR */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[3];  /* ?Z */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

int
heuristicActionPreconditions_MOVETOTABLE( register int *parameters )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */ 
  if( parameters[1] == 0 )  goto label0;  else  p[1] = parameters[1];  /* ?X */
  if( parameters[2] == 0 )  goto label0;  else  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label0:

  p[0] = 1;  /* CLEAR */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  return( 1 );
}

int
heuristicAction_MOVETOTABLE( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 2;  /* ON */
  p[1] = parameters[1];  /* ?X */
  p[2] = parameters[2];  /* ?Y */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 1;  /* CLEAR */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 1;  /* CLEAR */
  p[1] = parameters[2];  /* ?Y */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  p[0] = 3;  /* ONaTABLE */
  p[1] = parameters[1];  /* ?X */
  p[2] = -1;  /* end-marker */
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
  heuristicActionTable[0] = &heuristicAction_MOVETOBLOCK2;
  heuristicActionPreconditionsTable[0] = &heuristicActionPreconditions_MOVETOBLOCK2;
  heuristicActionTable[1] = &heuristicAction_MOVETOBLOCK1;
  heuristicActionPreconditionsTable[1] = &heuristicActionPreconditions_MOVETOBLOCK1;
  heuristicActionTable[2] = &heuristicAction_MOVETOTABLE;
  heuristicActionPreconditionsTable[2] = &heuristicActionPreconditions_MOVETOTABLE;
}

int goalAtoms[] = { 1 /* (ON L B) */, 2 /* (ON B C) */, 3 /* (ON C K) */, 4 /* (ON K G) */, 5 /* (ON O M) */, 6 /* (ON M H) */, 7 /* (ON H I) */, 8 /* (ON I D) */, 9 /* (ON N A) */, 10 /* (ON A E) */, 11 /* (ON E J) */, 0 };

