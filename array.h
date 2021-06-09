
/* File header: array.h */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "point.h"

/* Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */ 

typedef struct {
  char name;            
  POINT posisi;         
} info_lokasi;

typedef struct {
  info_lokasi *LI; /* memori tempat penyimpan elemen (container) */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} Lokasi;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika L adalah Lokasi, cara deklarasi dan akses: */
/* Deklarasi : Lokasi L */
/* Maka cara akses:
   L.Neff  untuk mengetahui banyaknya elemen
   L.LI    untuk mengakses seluruh nilai elemen tabel
   L.LI[i] untuk mengakses elemen ke-i */
/* Definisi :
   Tabel kosong: L.Neff = 0
   Definisi elemen pertama : L.LI[i] dengan i=1
   Definisi elemen terakhir yang terdefinisi: L.LI[i] dengan i= L.Neff */


/* ********** SELEKTOR ********** */
/* L adalah Lokasi     */
#define NeffL(L)       (L).Neff
#define LI(L)         (L).LI
#define ElmtLok(L,i)  (L).LI[(i)]
#define MaxElL(L)      (L).MaxEl

/* e adalah info_Lokasi */
#define Name(e)       (e).name
#define Posisi(e)     (e).posisi

// $ ********** KONSTRUKTOR **********

// $ Konstruktor : create tabel kosong
// * I.S. L sembarang, maxel > 0
// * F.S. Terbentuk tabel L kosong dengan kapasitas maxel + 1
void MakeEmptyLokasi (Lokasi * L, int maxel);

// * I.S. L terdefinisi;
// * F.S. LI(L) dikembalikan ke system, MaxEl(L)=0; Neff(L)=0
void DealokasiLokasi(Lokasi *L);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

/* Mengirimkan banyaknya elemen efektif tabel */
int NbElmtLok (Lokasi L);

/* *** Selektor INDEKS *** */

/* Prekondisi : Tabel L tidak kosong */
/* Mengirimkan indeks elemen L pertama */
IdxType GetFirstLok (Lokasi L);

/* Prekondisi : Tabel L tidak kosong */
/* Mengirimkan indeks elemen L terakhir */
IdxType GetLastLok (Lokasi L);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */

/* Mengirimkan true jika tabel L kosong, mengirimkan false jika tidak */
boolean IsEmptyLok(Lokasi L);

/* *** Test tabel penuh *** */

/* Mengirimkan true jika tabel L penuh, mengirimkan false jika tidak */
boolean IsFullLok(Lokasi L);

/* Me-copy data Lokasi */
Lokasi CopyLokasi(Lokasi L);

#endif
