/* automatically generated code -- DO NOT EDIT BY HAND! */

#include <stdlib.h>
#include <string.h>
#include "planner.h"

extern void fillTableAux( void );

void
fillTable( void )
{
  register int i;
  static int p[MAXPARAMETERS];

  fillTableAux();
  numActions = 1;

  /* vars */
  vars = (int **) calloc( numActions, sizeof( int * ) );
  for( i = 0; i < numActions; ++i )
    vars[i] = (int *) calloc( 4, sizeof( int ) );
  vars[0][0] = 2;
  vars[0][1] = 3;
  vars[0][2] = 1;

  /* values */
  values = (int **) calloc( numActions * 4, sizeof( int * ) );
  for( i = 0; i < numActions * 3; ++i )
    values[i] = (int *) calloc( 5, sizeof( int ) );
  values[numActions * 1 + 0][0] = 3;
  values[numActions * 1 + 0][1] = 2;
  values[numActions * 1 + 0][2] = 4;
  values[numActions * 2 + 0][0] = 3;
  values[numActions * 2 + 0][1] = 2;
  values[numActions * 2 + 0][2] = 4;
  values[numActions * 0 + 0][0] = 1;
  values[numActions * 0 + 0][1] = 2;
  values[numActions * 0 + 0][2] = 3;
  values[numActions * 0 + 0][3] = 4;

  /* insert atoms in atomHashTable */
  p[0] = 2;  /* AT */
  p[1] = 1;  /* JACK */
  p[2] = 2;  /* MICROSOFT */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ROAD */
  p[1] = 4;  /* KI */
  p[2] = 2;  /* MICROSOFT */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ROAD */
  p[1] = 3;  /* ROCKWELL */
  p[2] = 4;  /* KI */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* AT */
  p[1] = 1;  /* JACK */
  p[2] = 3;  /* ROCKWELL */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
}

