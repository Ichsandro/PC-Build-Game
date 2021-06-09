#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "Shop.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyKomponen(Komponen *T, int maxel ){
    XI(*T) = (info_komponen *)malloc((maxel + 1) * sizeof(info_komponen));
    NeffK(*T) = 0;
    MaxElK(*T) = maxel;
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void DealokasiKomponen(Komponen *T){
    free(XI(*T));
    NeffK(*T) = 0;
    MaxElK(*T) = 0;
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtKomponen(Komponen T){
    return NeffK(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElementKomponen(Komponen T){
    return MaxElK(T);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxKomponen(Komponen T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdxKomponen(Komponen T){
    return NeffK(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidKomponen(Komponen T, IdxType i){
    return ((i >= IdxMin) && (i <= MaxElK(T)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffKomponen(Komponen T, IdxType i){
    return ((i >= GetFirstIdxKomponen(T)) && (i <= GetLastIdxKomponen(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyKomponen(Komponen T){
    return (NeffK(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullKomponen(Komponen T){
    return (NeffK(T) == MaxElK(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsiKomponen(Komponen *T){
    int N;
    info_komponen inp;

    do{
        scanf("%d", &N);
    } while (!((N >= 0) && (N <= MaxElementKomponen(*T))));

    if (N == 0){
        MakeEmptyKomponen(T, MaxElK(*T));
    }else{
        MakeEmptyKomponen(T, MaxElK(*T));
        NeffK(*T) = N;
        for (IdxType i = GetFirstIdxKomponen(*T); i <= GetLastIdxKomponen(*T); i++)
        {
            scanf("%d", &inp);
            elmt(*T, i) = inp;
        }
    }
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTabKomponen(Komponen T){
    int hargaKomponen;
    if (IsEmptyKomponen(T)){
        printf("Inventory Kosong.\n");
    }else{
        for (IdxType i = GetFirstIdxKomponen(T); i <= GetLastIdxKomponen(T); i++){
            printf("%d. ", i);
            int id = id(elmt(T, i));
            BacaId(id, &hargaKomponen);
            printf(" (%d)", jumlah(elmt(T, i)));
            printf("\n");
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */

/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */

/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

boolean IsIdKomponen(Komponen T, int id, IdxType * i){
    boolean Found = false;
    IdxType j = 1;
    while ((!Found) && (j <= GetLastIdxKomponen(T))){
        if (id(elmt(T, j)) == id){
            *i = j;
            Found = true;
        }
        else{
            j++;
        }   
    }
    return Found;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */

/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
    Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
Komponen CopyKomponen (Komponen K) {
  /* KAMUS LOKAL */
  Komponen temp;
  int i;
  /* ALGORITMA */
  MakeEmptyKomponen(&temp, MaxElK(K));
  for (i = 1; i <= NbElmtKomponen(K); i++) {
    (elmt(temp, i)) = (elmt(K, i));
  }
  NeffK(temp) = NeffK(K);
  return temp;
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* Menghasilkan hasil penjumlahan semua elemen T */
 /* Jika T kosong menghasilkan 0 */

/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */

/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */

/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastElKomponen(Komponen *T, info_komponen X){
    NeffK(*T)++;
    elmt(*T, GetLastIdxKomponen(*T)) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastElKomponen(Komponen *T, info_komponen *X){
    *X = elmt(*T, GetLastIdxKomponen(*T));
    NeffK(*T)--;
}
/*Kl berkurang satu */
/*Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */

/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTabKomponen(Komponen *T){
    MaxElK(*T) = NeffK(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
// F.S. Ukuran MaxEl = Neff 

void Del1UrutKomponen (Komponen * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
        int found_index = Search1Komponen(*T, X);

        if (found_index != IdxUndef){
            DelEliKomponen(T, found_index, &X);
        }
}

IdxType Search1Komponen (Komponen T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    int i;
    for ( i = IdxMin;(i<= NeffK(T));i++){
            if (id(elmt(T,i)) == X){
                /* if X is found */
                return i;
            }
        }

    /* only execute if X is not found */
    return IdxUndef;
}

void DelEliKomponen (Komponen *T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    int j;

    NeffK(*T) -= 1;
    for ( j = i; (j <= NeffK(*T)); j++){
        elmt(*T, j) = elmt(*T, j+1);
        }
}