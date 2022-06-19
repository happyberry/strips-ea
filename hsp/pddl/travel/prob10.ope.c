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
heuristicActionPreconditions_CROSS( register int *parameters )
{
  register int idx;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* BRIDGE */ 
  if( parameters[2] == 0 )  goto label0;  else  p[1] = parameters[2];  /* ?LOCATION1 */
  if( parameters[3] == 0 )  goto label0;  else  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label0:

  p[0] = 5;  /* AT */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  return( 1 );
}

int
heuristicAction_CROSS( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 3;  /* BRIDGE */
  p[1] = parameters[2];  /* ?LOCATION1 */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
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
  p[0] = 4;  /* ROAD */ 
  if( parameters[2] == 0 )  goto label0;  else  p[1] = parameters[2];  /* ?LOCATION1 */
  if( parameters[3] == 0 )  goto label0;  else  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label0:

  p[0] = 5;  /* AT */ 
  if( parameters[1] == 0 )  goto label1;  else  p[1] = parameters[1];  /* ?VEHICLE */
  if( parameters[2] == 0 )  goto label1;  else  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  if( oldCosts[idx].cost == INT_MAX ) return( 0 );
 label1:

  return( 1 );
}

int
heuristicAction_DRIVE( register int *parameters )
{
  register int idx, sum = 1, prec = 0, add = 0;
  static int p[MAXPARAMETERS];

  /* preconditions */
  p[0] = 4;  /* ROAD */
  p[1] = parameters[2];  /* ?LOCATION1 */
  p[2] = parameters[3];  /* ?LOCATION2 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[2];  /* ?LOCATION1 */
  p[3] = -1;  /* end-marker */
  idx = readAtomHash( p )->idx;
  preclist[prec] = idx;
  preconditions[prec++] = idx;
  assert( oldCosts[idx].cost != INT_MAX );
  sum += oldCosts[idx].cost;

  memset( &preclist[prec], 0, (MAXPARAMETERS - prec) * sizeof( int ) );

  /* add-list */
  p[0] = 5;  /* AT */
  p[1] = parameters[1];  /* ?VEHICLE */
  p[2] = parameters[3];  /* ?LOCATION2 */
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
  heuristicActionTable[0] = &heuristicAction_CROSS;
  heuristicActionPreconditionsTable[0] = &heuristicActionPreconditions_CROSS;
  heuristicActionTable[1] = &heuristicAction_DRIVE;
  heuristicActionPreconditionsTable[1] = &heuristicActionPreconditions_DRIVE;
}

int goalAtoms[] = { 1 /* (AT BULLDOZER G) */, 2 /* (AT CAR G) */, 0 };

