/* File header: listlinier.h */

/* urutan adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "array.h"
#include "Main.h"

typedef int urutan;
typedef struct tElmtlist *alamat;
typedef struct tElmtlist {
	urutan info;
	alamat next;
} ElmtList;
typedef struct {
	alamat First;
} List;


#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

boolean IsEmptyList (List L);

void CreateEmptyList (List *L);

alamat Alokasi (urutan X);

void DealokasiList (alamat *P);

alamat Search (List L, urutan X);

urutan GetInfo(List L, int i);

void InsVPrio(List * L, urutan X);

void InsertAfter(List * L, alamat P, alamat Prec);

void InsertPrio(List * L, alamat P);

void DelP(List * L, urutan X);

List CopyList(List L); 

void PrintInfo(List L, Lokasi B);

int NbElmtList(List L);


#endif
