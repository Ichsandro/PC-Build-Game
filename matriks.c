#include <stdlib.h>
#include <stdio.h>
#include "matriks.h"


void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    M->NBrsEff = NB;
    M->NKolEff = NK;
    
    int i,j;
    for (i = 0; i < NB; i++){
        for (j = 0; j < NK; j++){
            M->Mem[i][j] = 0;
        }
    }
}

boolean IsIdxValid (int i, int j){
    return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M){
    return M.NKolEff-1;
}

void BacaMATRIKS (MATRIKS * M, Lokasi L){
    IdxType i;
    ElType X, Y;

    for (i = GetFirstLok(L); i <= GetLastLok(L); i++) {
        X = Absis(Posisi(ElmtLok(L, i)));
        Y = Ordinat(Posisi(ElmtLok(L, i)));

    ElmtM(*M, X, Y) = i;
  }
}

void TulisMATRIKS (MATRIKS M){
     IdxType i, j;
    for (i = 1; i <= NBrsEff(M); i++) {
        for (j = 1; j < NKolEff(M); j++) {
            printf("%d ", ElmtM(M, i, j));
        }
        printf("%d\n", ElmtM(M, i, j));
    }
}
                              
int NBElmtMatriks (MATRIKS M) {
/* Mengirimkan banyaknya elemen M */

  /* KAMUS LOKAL */
  int total;
  int i, j;

  /* ALGORITMA */
  total = 0;

  for (i = 1; i <= NBrsEff(M); i++) {
    for (j = 1; j <= NKolEff(M); j++) {
      if (ElmtM(M, i, j) != 0) {
        total += 1;
      }
    }
  }

  return total;
}

// $ ******* MAP PRINTING FUNCTION ********
void PrintMap(MATRIKS M, Lokasi B, urutan Pemain) {
    /* KAMUS LOKAL */
    int i, j;

    /* ALGORITMA */
    for (i = 1; i <= (NBrsEff(M) + 2); i++) {
        for (j = 1; j < (NKolEff(M) + 3); j++) {
            //printf("%d%d",i,j);
            if (i == 1) {
                printf("*");
                if(j == (NKolEff(M) + 2)) {
                    printf("**\n");
                }
            }
            else if (i == (NBrsEff(M) + 2)) {
                printf("*");
                if(j == (NKolEff(M) + 2)) printf("**\n");
            }
            else if (j == 1) {
                printf("* ");
            }
            else if (j == (NKolEff(M) + 2)) {
                printf(" *\n");
            }
            else if ((ElmtM(M,(i-1),(j-1))) == 0) {
                printf(" ");
            }
            else {
                ElType Mem = ElmtM(M,(i-1),(j-1));
                char C = Name(ElmtLok(B,Mem));
                if (Mem == Pemain){
                    printf("P");
                }
                else{
                    if (C == ('C')){
                        int No_Pelanggan = (Mem-2);
                        printf("%d", No_Pelanggan);
                    }
                    else{
                        printf("%c", C);
                    }
                }
            }   
        }
    }
    printf("\n");
}
