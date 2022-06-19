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
heuristicActionPreconditions_DISEMBARK( register int *parameters )
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
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 2;  /* DRIVING */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?PERSON */
  if( parameters[3] == 0 )  goto label2;  else  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  p[0] = 3;  /* VEHICLE */ 
  if( parameters[3] == 0 )  goto label3;  else  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label3:

  p[0] = 4;  /* PERSON */ 
  if( parameters[1] == 0 )  goto label4;  else  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label4:

  return( 1 );
}

int
heuristicAction_DISEMBARK( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[1] == parameters[3] ) return( 0 );

  p[0] = 7;  /* AT */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 2;  /* DRIVING */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 3;  /* VEHICLE */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 4;  /* PERSON */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

int
heuristicActionPreconditions_BOARD( register int *parameters )
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
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 3;  /* VEHICLE */ 
  if( parameters[3] == 0 )  goto label2;  else  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  p[0] = 4;  /* PERSON */ 
  if( parameters[1] == 0 )  goto label3;  else  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label3:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label4;  else  p[1] = parameters[1];  /* ?PERSON */
  if( parameters[2] == 0 )  goto label4;  else  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label4:

  return( 1 );
}

int
heuristicAction_BOARD( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[1] == parameters[3] ) return( 0 );

  p[0] = 7;  /* AT */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 3;  /* VEHICLE */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 4;  /* PERSON */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[2];  /* ?PLACE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 2;  /* DRIVING */
  p[1] = parameters[1];  /* ?PERSON */
  p[2] = parameters[3];  /* ?VEHICLE */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[3];  /* ?VEHICLE */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

int
heuristicActionPreconditions_CROSS( register int *parameters )
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
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?THING */
  if( parameters[2] == 0 )  goto label2;  else  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  p[0] = 5;  /* BRIDGE */ 
  if( parameters[2] == 0 )  goto label3;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label3;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label3:

  return( 1 );
}

int
heuristicAction_CROSS( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[2] == parameters[3] ) return( 0 );

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[1];  /* ?THING */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 5;  /* BRIDGE */
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
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  costs[idx].cost = (sum < costs[idx].cost ? sum : costs[idx].cost);
  addlist[add++] = idx;

  if( !initialized ) addParents( idx, preconditions );

  memset( &addlist[add], 0, (MAXPARAMETERS - add) * sizeof( int ) );

  return( 1 );
}

int
heuristicActionPreconditions_DRIVE( register int *parameters )
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
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  p[0] = 7;  /* AT */ 
  if( parameters[1] == 0 )  goto label2;  else  p[1] = parameters[1];  /* ?THING */
  if( parameters[2] == 0 )  goto label2;  else  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label2:

  p[0] = 8;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label3;  else  p[1] = parameters[2];  /* ?FROM */
  if( parameters[3] == 0 )  goto label3;  else  p[2] = parameters[3];  /* ?TO */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label3:

  return( 1 );
}

int
heuristicAction_DRIVE( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  if( parameters[2] == parameters[3] ) return( 0 );

  p[0] = 6;  /* MOBILE */
  p[1] = parameters[1];  /* ?THING */
  p[2] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
  p[2] = parameters[2];  /* ?FROM */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 8;  /* ROAD */
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
  p[0] = 7;  /* AT */
  p[1] = parameters[1];  /* ?THING */
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
  heuristicActionTable[0] = &heuristicAction_DISEMBARK;
  heuristicActionPreconditionsTable[0] = &heuristicActionPreconditions_DISEMBARK;
  heuristicActionTable[1] = &heuristicAction_BOARD;
  heuristicActionPreconditionsTable[1] = &heuristicActionPreconditions_BOARD;
  heuristicActionTable[2] = &heuristicAction_CROSS;
  heuristicActionPreconditionsTable[2] = &heuristicActionPreconditions_CROSS;
  heuristicActionTable[3] = &heuristicAction_DRIVE;
  heuristicActionPreconditionsTable[3] = &heuristicActionPreconditions_DRIVE;
}

int goalAtoms[] = { 1 /* (AT JACK A) */, 2 /* (AT BULLDOZER G) */, 0 };

