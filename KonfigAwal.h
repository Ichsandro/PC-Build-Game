#ifndef konfigAwal_h
#define konfigAwal_h


#include <stdio.h>
#include <string.h>
#include "matriks.h"
#include "point.h"
#include "Graph.h"
#include "queuelist.h"
#include "mesinkata.h"
#include "arraydin.h"

typedef struct {
    int day;
    int money;
    Komponen inventory;
    int posisi;
    Kata save;
} Player;
// int money, Komponen (eltype, int, int), POINT (x,y)

/* Not. Akses selektor pemain */
#define PMoney(P) (P).money
#define PPos(P) (P).posisi
#define PInv(P) (P).inventory
#define PDay(P) (P).day
#define SaveF(P) (P).save

void GetMoney(Player *P, Queue *Q);
/* Menambahkan uang kepada player */

void StartGame(Player *P);

void NextDay(Player *P);

#endif