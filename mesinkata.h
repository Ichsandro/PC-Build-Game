/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"
#include "matriks.h"
#include "graph.h"
#include "string.h"


#define NMax 100
#define BLANK ' '
#define ENTER '\n'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
   int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();

void STARTKATA(char * C);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintKata (Kata K);
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */

void CopyKata(Kata K1, Kata *K2);
/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan salinan dari K1, berisi sama dengan K1 */

int KataToInt (Kata K);
/* Kata K berisi integer, lalu dikonversikan ke int */

char KataToChar (Kata K);
/* Mengkonversikan Kata ke char */

Lokasi KataToLokasi (int maxel);
/* Membaca kata dan disimpan menjadi array lokasi */

info_lokasi KataToInfo (Kata K1, Kata K2, Kata K3);
/* Membaca kata dan disimpan menjadi info dari array lokasi */

MATRIKS KataToMatriks (int NB, int NK, Lokasi L);
/* Membaca kata dan disimpan menjadi matriks */

Graph KataToGraph (int maxel);
/* Membaca kata dan disimpan menjadi graph */

#endif