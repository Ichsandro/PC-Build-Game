#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"
#include "listlinier.h"

/* Konstruktor : create Graph kosong  */
void MakeEmptyGraph (Graph * G) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  FirstG(*G) = Nil;
}

/****************** Manajemen Memori ******************/
addrGraph AlokasiGraph1 (urutan X) {
  /* KAMUS LOKAL */
  addrGraph P;
  /* ALGORITMA */
  P = (addrGraph) malloc (sizeof(ElmtGraph));
  //P = malloc (sizeof(addrGraph));
  if (P != NULL) {
    InfoG(P) = X;     
    NextP(P) = Nil;
    FirstChild(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

addrGraph2 AlokasiGraph2 (urutan X) {
  /* KAMUS LOKAL */
  addrGraph2 P;

  /* ALGORITMA */
  P = (addrGraph2) malloc (sizeof(ElmtGraph2));
  //P = malloc (sizeof(addrGraph2));
  if (P != NULL) {
    InfoG2(P) = X;
    NextChild(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

void DealokasiGraph1 (addrGraph * G) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*G);
}

void DealokasiGraph2 (addrGraph2 * G2) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*G2);
}

/* ********** TEST GRAPH KOSONG ********** */
boolean IsEmptyGraph (Graph G) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstG(G) == Nil);
}

boolean IsEmptyParent (addrGraph P) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstChild(P) == Nil);
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaGraph (Graph * G);

void TulisGraph (Graph G) {
  /* KAMUS LOKAL */
  IdxType i, j;
  addrGraph P;
  addrGraph2 C;

  /* ALGORITMA */
  i = 1;

  while (i <= NbElmtGraph(G)) {
    P = SearchP(G, i);
    j = 1;

    while (j < NbElmtGraph(G)) {
      C = SearchChild(P, j);

      if (C != Nil) {
        printf("1 ");
      } else /* C == Nil */ {
        printf("0 ");
      }

      j++;
    }

    C = SearchChild(P, j);
    if (C != Nil) {
      printf("1\n");
    } else /* C == Nil */ {
      printf("0\n");
    }

    i++;
  }
}

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void AddParent (Graph * G, int N) {
  /* KAMUS LOKAL */
  int i;
  addrGraph P, Q;

  /* ALGORITMA */
  for (i = 1; i <= N; i++) {
    Q = AlokasiGraph1(i);

    if (Q != Nil) {
      if (IsEmptyGraph(*G)) {
        FirstG(*G) = Q;
        P = FirstG(*G);
      } else /* !IsEmptyGraph(*G) */ {
        NextP(P) = Q;
        P = NextP(P);
      }
    }
  }
}

void AddRelation (Graph * G, urutan X, urutan Y) {
  /* KAMUS LOKAL */
  addrGraph P;
  addrGraph2 C, Q;

  /* ALGORITMA */
  P = SearchP(*G, X);
  Q = AlokasiGraph2(Y);

  if (Q != Nil) {
    if (IsEmptyParent(P)) {
      FirstChild(P) = Q;

    } else /* !IsEmptyParent(P) */ {
      C = FirstChild(P);
      while (NextChild(C) != Nil) {
        C = NextChild(C);
      }
      NextChild(C) = Q;
    }
  }
}

/****************** PROSES SEMUA ELEMEN PARENT GRAPH ******************/
int NbElmtGraph (Graph G) {
  /* KAMUS LOKAL */
  addrGraph P;
  int total;

  /* ALGORITMA */
  if (IsEmptyGraph(G)) {
    return 0;
  } else /* !IsEmptyGraph(G) */ {
    P = FirstG(G);
    total = 0;
    while (P != Nil) {
      P = NextP(P);
      total++;
    }
    return total;
  }
}

/****************** PENCARIAN SEBUAH GRAPH ******************/
addrGraph SearchP (Graph G, urutan X) {
  /* KAMUS LOKAL */
  addrGraph P;

  /* ALGORITMA */
  P = FirstG(G);
  while ((P != Nil) && (InfoG(P) != X)) {
    P = NextP(P);
  }

  return P;
}

addrGraph2 SearchChild (addrGraph P, urutan X) {
  /* KAMUS LOKAL */
  addrGraph2 C;

  /* ALGORITMA */
  C = FirstChild(P);
  while ((C != Nil) && (InfoG2(C) != X)) {
    C = NextChild(C);
  }

  return C;
}

/******************* RELATION **********************/
boolean CheckRelation (Graph G, urutan X, urutan Y) {
  /* KAMUS LOKAL */
  addrGraph P;

  /* ALGORITMA */
  P = SearchP(G, X);

  return (SearchChild(P, Y) != Nil);
}

void PrintMove (Graph G, List L, Lokasi B, urutan X, int * Count) {
    /* KAMUS LOKAL */
    alamat P;
    addrGraph Q;
    addrGraph2 C;
    int i;
    int j; /*urutan pelanggan*/

    /* ALGORITMA */
    P = First(L);
    Q = SearchP(G, X);
    C = FirstChild(Q);
    i = 1;
    j = 1;


  while ((C != Nil) && (P != Nil)) {
    if (InfoG2(C) == Info(P)) {
      printf("%d. ", i);

      if (Name(ElmtLok(B, InfoG2(C))) == 'B') {
        printf("Base  ");
      } else if (Name(ElmtLok(B, InfoG2(C))) == 'S') {
        printf("Shop ");
      } else if (Name(ElmtLok(B, InfoG2(C))) == 'C') {
        int No_Pelanggan = (GetInfo(L,j)-2);
        printf("Pelanggan %d ", No_Pelanggan);
      }
      TulisPOINT(Posisi(ElmtLok(B, InfoG2(C))));
      printf("\n");

      i++;
      j++;
      C = NextChild(C);
      P = Next(P);

    } else /* InfoG2(C) != Info(P) */ {
      if (InfoG2(C) < Info(P)) {
        C = NextChild(C);
      } else /* InfoG2(C) > Info(P) */ {
        P = Next(P);
        j++;
      }
    }
  }
  *Count = i - 1;
}

int GetIdxMove (Graph G, List L, Lokasi B, urutan X, int pos) {
  // Fungsi untuk mendapatkan Idx bangunan move yang diinginkan

  /* KAMUS LOKAL */
  alamat P;
  addrGraph Q;
  addrGraph2 C;
  int i;

  /* ALGORITMA */
  P = First(L);
  Q = SearchP(G, X);
  C = FirstChild(Q);
  i = 1;

  while ((C != Nil) && (P != Nil)) {
    if (InfoG2(C) == Info(P)) {

      if (i == pos) {
        return InfoG2(C);
        break;
      } else /* i != pos */ {        
        i++;
        C = NextChild(C);
        P = Next(P);
      }

    } else /* InfoG2(C) != Info(P) */ {
        if (InfoG2(C) < Info(P)) {
      }
    }
  } 
}
