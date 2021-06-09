/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "listlinier.h"


/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
   int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

void MakeMATRIKS (int NB, int NK, MATRIKS * M); 

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ElmtM(M,i,j) (M).Mem[(i)][(j)]


boolean IsIdxValid (int i, int j);

indeks GetFirstIdxBrs (MATRIKS M);

indeks GetFirstIdxKol (MATRIKS M);

indeks GetLastIdxBrs (MATRIKS M);

indeks GetLastIdxKol (MATRIKS M);


void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);

void BacaMATRIKS (MATRIKS * M, Lokasi L);

void TulisMATRIKS (MATRIKS M);

int NBElmtMatriks (MATRIKS M);

void PrintMap(MATRIKS M, Lokasi B, urutan Pemain);

#endif
