/* File body: listlinier.c */

#include <stdlib.h>
#include <stdio.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List * L) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
alamat Alokasi (urutan X) {
  /* KAMUS LOKAL */
  alamat P;

  /* ALGORITMA */
  P = (alamat) malloc (sizeof(ElmtList));
  //P = malloc (sizeof(alamat));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}

void DealokasiList (alamat * P) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
alamat Search (List L, urutan X) {
  /* KAMUS LOKAL */
  alamat P;

  /* ALGORITMA */
  if (IsEmptyList(L)) {
    return Nil;
  } else /* !IsEmpty(L) */ {
    P = First(L);
    while ((Next(P) != Nil) && (Info(P) != X)) {
      P = Next(P);
    }

    if (Info(P) == X) {
      return P;
    } else /* Info(P) != X */ {
      return Nil;
    }
  }
}

urutan GetInfo(List L, int i) {
	alamat P = First(L);
	i--;
	while (i>0) {
		P = Next(P);
		i--;
	}
	return Info(P);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVPrio (List * L, urutan X) {
// ! Tambah bangunan selalu pakai prosedur ini
  /* KAMUS LOKAL */
  alamat P;

  /* ALGORITMA */
  P = Alokasi(X);
  if (P != Nil) {
    InsertPrio(L, P);
  }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertAfter (List *L, alamat P, alamat Prec) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertPrio (List * L, alamat P) {
  /* KAMUS LOKAL */
  alamat PrecLast, Last;

  /* ALGORITMA */
  if (IsEmptyList(*L)) {
    First(*L) = P;
    Next(P) = Nil;
  } else /* !IsEmpty(*L) */ {
    PrecLast = Nil;
    Last = First(*L);
    while ((Next(Last) != Nil) && (Info(P) >= Info(Last))) {
      PrecLast = Last;
      Last = Next(Last);
    }

    if (Info(P) < Info(Last)) {
      if (PrecLast == Nil) {
        Next(P) = First(*L);
        First(*L) = P;
      } else /* PrecLast != Nil */ {
        InsertAfter(L, P, PrecLast);
      }
    } else /* Info(P) >= Info(Last) */ {
      InsertAfter(L, P, Last);
    }
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelP (List * L, urutan X) {
  /* KAMUS LOKAL */
  alamat P, Prec, PDel;

  /* ALGORITMA */
  P = First(*L);
  Prec = Nil;

  while (Info(P) != X) {
    Prec = P;
    P = Next(P);
  }

  if (Prec == Nil) {
    First(*L) = Next(P);
  } else /* Prec != Nil */ {
    Next(Prec) = Next(P);
  }
} 

List CopyList(List L) {
  List ret;
  CreateEmptyList(&ret);
  alamat P = First(L);
  while (P != Nil) {
    InsVPrio(&ret, Info(P));
    P = Next(P);
  }
  return ret;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L, Lokasi B) {
  /* KAMUS LOKAL */
  alamat P;
  int i;

  /* ALGORITMA */
  P = First(L);
  i = 1; //inisialisasi
  while (P != Nil) {
    printf("%d. ", i);

    if (Name(ElmtLok(B, Info(P))) == 'B') {
      printf("Base  ");
    } else if (Name(ElmtLok(B, Info(P))) == 'S') {
      printf("Shop ");
    } else if (Name(ElmtLok(B, Info(P))) == 'C') {
      int No_Pelanggan = (GetInfo(L,i)-2);
      printf("Pelanggan %d ", No_Pelanggan);
    }

    TulisPOINT(Posisi(ElmtLok(B, Info(P))));
    printf("\n");

    i++;
    P = Next(P);
  }
}

int NbElmtList (List L) {
  /* KAMUS LOKAL */
  alamat P;
  int total;

  /* ALGORITMA */
  if (IsEmptyList(L)) {
    return 0;
  } else /* !IsEmpty(L) */ {
    P = First(L);
    total = 0;
    while (P != Nil) {
      P = Next(P);
      total++;
    }
    return total;
  }
}

