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
  numActions = 3;

  /* vars */
  vars = (int **) calloc( numActions, sizeof( int * ) );
  for( i = 0; i < numActions; ++i )
    vars[i] = (int *) calloc( 4, sizeof( int ) );
  vars[0][0] = 1;
  vars[0][1] = 2;
  vars[1][0] = 1;
  vars[1][1] = 2;
  vars[1][2] = 3;
  vars[2][0] = 1;
  vars[2][1] = 2;

  /* values */
  values = (int **) calloc( numActions * 4, sizeof( int * ) );
  for( i = 0; i < numActions * 3; ++i )
    values[i] = (int *) calloc( 20, sizeof( int ) );
  values[numActions * 0 + 0][0] = 1;
  values[numActions * 0 + 0][1] = 2;
  values[numActions * 0 + 0][2] = 3;
  values[numActions * 0 + 0][3] = 4;
  values[numActions * 0 + 0][4] = 5;
  values[numActions * 0 + 0][5] = 6;
  values[numActions * 0 + 0][6] = 7;
  values[numActions * 0 + 0][7] = 8;
  values[numActions * 0 + 0][8] = 9;
  values[numActions * 0 + 0][9] = 10;
  values[numActions * 0 + 0][10] = 11;
  values[numActions * 0 + 0][11] = 12;
  values[numActions * 0 + 0][12] = 13;
  values[numActions * 0 + 0][13] = 14;
  values[numActions * 0 + 0][14] = 15;
  values[numActions * 0 + 0][15] = 16;
  values[numActions * 0 + 0][16] = 17;
  values[numActions * 0 + 0][17] = 18;
  values[numActions * 0 + 0][18] = 19;
  values[numActions * 1 + 0][0] = 1;
  values[numActions * 1 + 0][1] = 2;
  values[numActions * 1 + 0][2] = 3;
  values[numActions * 1 + 0][3] = 4;
  values[numActions * 1 + 0][4] = 5;
  values[numActions * 1 + 0][5] = 6;
  values[numActions * 1 + 0][6] = 7;
  values[numActions * 1 + 0][7] = 8;
  values[numActions * 1 + 0][8] = 9;
  values[numActions * 1 + 0][9] = 10;
  values[numActions * 1 + 0][10] = 11;
  values[numActions * 1 + 0][11] = 12;
  values[numActions * 1 + 0][12] = 13;
  values[numActions * 1 + 0][13] = 14;
  values[numActions * 1 + 0][14] = 15;
  values[numActions * 1 + 0][15] = 16;
  values[numActions * 1 + 0][16] = 17;
  values[numActions * 1 + 0][17] = 18;
  values[numActions * 1 + 0][18] = 19;
  values[numActions * 0 + 1][0] = 1;
  values[numActions * 0 + 1][1] = 2;
  values[numActions * 0 + 1][2] = 3;
  values[numActions * 0 + 1][3] = 4;
  values[numActions * 0 + 1][4] = 5;
  values[numActions * 0 + 1][5] = 6;
  values[numActions * 0 + 1][6] = 7;
  values[numActions * 0 + 1][7] = 8;
  values[numActions * 0 + 1][8] = 9;
  values[numActions * 0 + 1][9] = 10;
  values[numActions * 0 + 1][10] = 11;
  values[numActions * 0 + 1][11] = 12;
  values[numActions * 0 + 1][12] = 13;
  values[numActions * 0 + 1][13] = 14;
  values[numActions * 0 + 1][14] = 15;
  values[numActions * 0 + 1][15] = 16;
  values[numActions * 0 + 1][16] = 17;
  values[numActions * 0 + 1][17] = 18;
  values[numActions * 0 + 1][18] = 19;
  values[numActions * 1 + 1][0] = 1;
  values[numActions * 1 + 1][1] = 2;
  values[numActions * 1 + 1][2] = 3;
  values[numActions * 1 + 1][3] = 4;
  values[numActions * 1 + 1][4] = 5;
  values[numActions * 1 + 1][5] = 6;
  values[numActions * 1 + 1][6] = 7;
  values[numActions * 1 + 1][7] = 8;
  values[numActions * 1 + 1][8] = 9;
  values[numActions * 1 + 1][9] = 10;
  values[numActions * 1 + 1][10] = 11;
  values[numActions * 1 + 1][11] = 12;
  values[numActions * 1 + 1][12] = 13;
  values[numActions * 1 + 1][13] = 14;
  values[numActions * 1 + 1][14] = 15;
  values[numActions * 1 + 1][15] = 16;
  values[numActions * 1 + 1][16] = 17;
  values[numActions * 1 + 1][17] = 18;
  values[numActions * 1 + 1][18] = 19;
  values[numActions * 2 + 1][0] = 1;
  values[numActions * 2 + 1][1] = 2;
  values[numActions * 2 + 1][2] = 3;
  values[numActions * 2 + 1][3] = 4;
  values[numActions * 2 + 1][4] = 5;
  values[numActions * 2 + 1][5] = 6;
  values[numActions * 2 + 1][6] = 7;
  values[numActions * 2 + 1][7] = 8;
  values[numActions * 2 + 1][8] = 9;
  values[numActions * 2 + 1][9] = 10;
  values[numActions * 2 + 1][10] = 11;
  values[numActions * 2 + 1][11] = 12;
  values[numActions * 2 + 1][12] = 13;
  values[numActions * 2 + 1][13] = 14;
  values[numActions * 2 + 1][14] = 15;
  values[numActions * 2 + 1][15] = 16;
  values[numActions * 2 + 1][16] = 17;
  values[numActions * 2 + 1][17] = 18;
  values[numActions * 2 + 1][18] = 19;
  values[numActions * 0 + 2][0] = 1;
  values[numActions * 0 + 2][1] = 2;
  values[numActions * 0 + 2][2] = 3;
  values[numActions * 0 + 2][3] = 4;
  values[numActions * 0 + 2][4] = 5;
  values[numActions * 0 + 2][5] = 6;
  values[numActions * 0 + 2][6] = 7;
  values[numActions * 0 + 2][7] = 8;
  values[numActions * 0 + 2][8] = 9;
  values[numActions * 0 + 2][9] = 10;
  values[numActions * 0 + 2][10] = 11;
  values[numActions * 0 + 2][11] = 12;
  values[numActions * 0 + 2][12] = 13;
  values[numActions * 0 + 2][13] = 14;
  values[numActions * 0 + 2][14] = 15;
  values[numActions * 0 + 2][15] = 16;
  values[numActions * 0 + 2][16] = 17;
  values[numActions * 0 + 2][17] = 18;
  values[numActions * 0 + 2][18] = 19;
  values[numActions * 1 + 2][0] = 1;
  values[numActions * 1 + 2][1] = 2;
  values[numActions * 1 + 2][2] = 3;
  values[numActions * 1 + 2][3] = 4;
  values[numActions * 1 + 2][4] = 5;
  values[numActions * 1 + 2][5] = 6;
  values[numActions * 1 + 2][6] = 7;
  values[numActions * 1 + 2][7] = 8;
  values[numActions * 1 + 2][8] = 9;
  values[numActions * 1 + 2][9] = 10;
  values[numActions * 1 + 2][10] = 11;
  values[numActions * 1 + 2][11] = 12;
  values[numActions * 1 + 2][12] = 13;
  values[numActions * 1 + 2][13] = 14;
  values[numActions * 1 + 2][14] = 15;
  values[numActions * 1 + 2][15] = 16;
  values[numActions * 1 + 2][16] = 17;
  values[numActions * 1 + 2][17] = 18;
  values[numActions * 1 + 2][18] = 19;

  /* insert atoms in atomHashTable */
  p[0] = 2;  /* ON */
  p[1] = 12;  /* L */
  p[2] = 2;  /* B */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 2;  /* B */
  p[2] = 3;  /* C */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 3;  /* C */
  p[2] = 16;  /* P */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 16;  /* P */
  p[2] = 11;  /* K */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 11;  /* K */
  p[2] = 7;  /* G */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 15;  /* O */
  p[2] = 13;  /* M */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 13;  /* M */
  p[2] = 8;  /* H */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 8;  /* H */
  p[2] = 9;  /* I */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 9;  /* I */
  p[2] = 4;  /* D */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 17;  /* Q */
  p[2] = 18;  /* R */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 18;  /* R */
  p[2] = 19;  /* S */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 19;  /* S */
  p[2] = 14;  /* N */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 14;  /* N */
  p[2] = 1;  /* A */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 1;  /* A */
  p[2] = 5;  /* E */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 5;  /* E */
  p[2] = 10;  /* J */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 1;  /* CLEAR */
  p[1] = 19;  /* S */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 19;  /* S */
  p[2] = 18;  /* R */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 18;  /* R */
  p[2] = 17;  /* Q */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 17;  /* Q */
  p[2] = 16;  /* P */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 16;  /* P */
  p[2] = 3;  /* C */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 3;  /* C */
  p[2] = 2;  /* B */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ONaTABLE */
  p[1] = 2;  /* B */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 1;  /* CLEAR */
  p[1] = 9;  /* I */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 9;  /* I */
  p[2] = 8;  /* H */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 8;  /* H */
  p[2] = 7;  /* G */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 7;  /* G */
  p[2] = 6;  /* F */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ONaTABLE */
  p[1] = 6;  /* F */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 1;  /* CLEAR */
  p[1] = 11;  /* K */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 11;  /* K */
  p[2] = 10;  /* J */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 10;  /* J */
  p[2] = 5;  /* E */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 5;  /* E */
  p[2] = 4;  /* D */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 4;  /* D */
  p[2] = 14;  /* N */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 14;  /* N */
  p[2] = 15;  /* O */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ONaTABLE */
  p[1] = 15;  /* O */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 1;  /* CLEAR */
  p[1] = 1;  /* A */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 1;  /* A */
  p[2] = 12;  /* L */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 2;  /* ON */
  p[1] = 12;  /* L */
  p[2] = 13;  /* M */
  p[3] = -1;  /* end-marker */
  readAtomHash( p );
  p[0] = 3;  /* ONaTABLE */
  p[1] = 13;  /* M */
  p[2] = -1;  /* end-marker */
  readAtomHash( p );
}

