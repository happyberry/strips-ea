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
  numActions = 4;

  /* vars */
  vars = (int **) calloc( numActions, sizeof( int * ) );
  for( i = 0; i < numActions; ++i )
    vars[i] = (int *) calloc( 4, sizeof( int ) );
  vars[0][0] = 1;
  vars[0][1] = 3;
  vars[0][2] = 2;
  vars[1][0] = 1;
  vars[1][1] = 3;
  vars[1][2] = 2;
  vars[2][0] = 2;
  vars[2][1] = 3;
  vars[2][2] = 1;
  vars[3][0] = 2;
  vars[3][1] = 3;
  vars[3][2] = 1;

  /* values */
  values = (int **) calloc( numActions * 4, sizeof( int * ) );
  for( i = 0; i < numActions * 3; ++i )
    values[i] = (int *) calloc( 5, sizeof( int ) );
  values[numActions * 0 + 0][0] = 3;
  values[numActions * 2 + 0][0] = 4;
  values[numActions * 1 + 0][0] = 1;
  values[numActions * 1 + 0][1] = 2;
  values[numActions * 1 + 0][2] = 3;
  values[numActions * 1 + 0][3] = 4;
  values[numActions * 0 + 1][0] = 3;
  values[numActions * 2 + 1][0] = 4;
  values[numActions * 1 + 1][0] = 1;
  values[numActions * 1 + 1][1] = 2;
  values[numActions * 1 + 1][2] = 3;
  values[numActions * 1 + 1][3] = 4;
  values[numActions * 0 + 2][0] = 1;
  values[numActions * 0 + 2][1] = 2;
  values[numActions * 0 + 2][2] = 3;
  values[numActions * 0 + 2][3] = 4;
  values[numActions * 1 + 3][0] = 2;
  values[numActions * 1 + 3][1] = 1;
  values[numActions * 2 + 3][0] = 2;
  values[numActions * 2 + 3][1] = 1;
  values[numActions * 0 + 3][0] = 1;
  values[numActions * 0 + 3][1] = 2;
  values[numActions * 0 + 3][2] = 3;
  values[numActions * 0 + 3][3] = 4;

  /* insert atoms in atomHashTable */
  p[0] = 7;  /* AT */
  p[1] = 4;  /* BULLDOZER */
  p[2] = 2;  /* G */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 8;  /* ROAD */
  p[1] = 1;  /* A */
  p[2] = 2;  /* G */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 4;  /* PERSON */
  p[1] = 3;  /* JACK */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 6;  /* MOBILE */
  p[1] = 3;  /* JACK */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* VEHICLE */
  p[1] = 4;  /* BULLDOZER */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 7;  /* AT */
  p[1] = 4;  /* BULLDOZER */
  p[2] = 1;  /* A */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 7;  /* AT */
  p[1] = 3;  /* JACK */
  p[2] = 1;  /* A */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
}

