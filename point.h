
/* File header: point.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;


#define Absis(P) (P).X
#define Ordinat(P) (P).Y


void MakePOINT (POINT * P, int X, int Y);

void TulisPOINT (POINT P);

POINT CopyPOINT(POINT P);

#endif
