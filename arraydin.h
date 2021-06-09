#ifndef arraydin_h
#define arraydin_h

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; 
typedef int ElType;  

typedef struct {
    int id;
    int jumlah;
    int harga;          
}  info_komponen;

typedef struct
{
   info_komponen *XI;
   int Neff;   
   int MaxEl; 
} Komponen;
#define NeffK(T) (T).Neff
#define XI(T) (T).XI
#define elmt(T, i) (T).XI[(i)]
#define MaxElK(T) (T).MaxEl


/* e adalah info_komponen */
#define id(e)     (e).id
#define jumlah(e)     (e).jumlah
#define harga(e)     (e).harga

void MakeEmptyKomponen(Komponen *T, int maxel);

void DealokasiKomponen(Komponen *T);

int NbElmtKomponen(Komponen T);

int MaxElementKomponen(Komponen T);

IdxType GetFirstIdxKomponen(Komponen T);

IdxType GetLastIdxKomponen(Komponen T);

ElType GetElmt (Komponen T, IdxType i);

boolean IsIdxValidKomponen(Komponen T, IdxType i);

boolean IsIdxEffKomponen(Komponen T, IdxType i);

boolean IsEmptyKomponen(Komponen T);

boolean IsFullKomponen(Komponen T);

void BacaIsiKomponen(Komponen *T);

void TulisIsiTabKomponen(Komponen T);

Komponen PlusMinusTabKomponen(Komponen T1, Komponen T2, boolean plus);

boolean IsIdKomponen(Komponen T, int id, IdxType * i);

Komponen CopyKomponen (Komponen K);

void SortKomponen(Komponen *T, boolean asc);

void AddAsLastElKomponen(Komponen *T, info_komponen X);

void DelLastElKomponen(Komponen *T, info_komponen *X);

void CompactTabKomponen(Komponen *T);

void Del1UrutKomponen (Komponen * T, ElType X);

IdxType Search1Komponen (Komponen T, ElType X);

void DelEliKomponen (Komponen * T, IdxType i, ElType * X);

#endif 
