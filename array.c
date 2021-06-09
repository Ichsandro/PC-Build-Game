/* File body: array.c */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyLokasi (Lokasi * B, int maxel) {
  /* KAMUS LOKAL */
  
  /* ALGORITMA */
  if (maxel > 0) {
    LI(*B) = (info_lokasi *) malloc ((maxel + 1)* sizeof(info_lokasi));
    MaxElL(*B) = maxel;
    NeffL(*B) = 0;
  }
}

void DealokasiLokasi(Lokasi * L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(LI(*L));
  MaxElL(*L) = 0;
  NeffL(*L) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtLok (Lokasi L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NeffL(L);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstLok (Lokasi L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return IdxMin;
}

IdxType GetLastLok (Lokasi L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NeffL(L);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyLok (Lokasi L) {
  return (NeffL(L) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFullLok (Lokasi L) {
  return (NeffL(L) == MaxElL(L));
}

Lokasi CopyLokasi (Lokasi L) {
  /* KAMUS LOKAL */
  Lokasi temp;
  int i;
  /* ALGORITMA */
  MakeEmptyLokasi(&temp, MaxElL(L));
  for (i = 1; i <= NbElmtLok(L); i++) {
    Name(ElmtLok(temp, i)) = Name(ElmtLok(L, i));
    Posisi(ElmtLok(temp, i)) = CopyPOINT(Posisi(ElmtLok(L, i)));
  }
  NeffL(temp) = NeffL(L);
  return temp;
}
