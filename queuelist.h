#ifndef _QUEUELIST_H
#define _QUEUELIST_H

#include "boolean.h"
#include "Main.h"
#include <stdlib.h>
#include "order.h"


/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * street;
typedef struct tElmtQueue {
    int nomor_order;
    int nomor_pelanggan;
    Order T; 
    int invoice;
    infotype Info;
    street Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
    street HEAD;  /* alamat penghapusan */
    street TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define NextQ(P) (P)->Next
#define InfoQ(P) (P)->Info
#define Prio(P) (P)->Prio
#define nomor_order(P) (P)->nomor_order
#define nomor_pelanggan(P) (P)->nomor_pelanggan
#define T(P) (P)->T
#define invoice(P) (P)->invoice


void AlokasiQueue (street *P, int nomor_order, int nomor_pelanggan, Order T, int invoice);

void Dealokasi (street  P);

boolean IsEmptyQueue (Queue Q);

int NbElmt(Queue Q);

void CreateEmptyQueue(Queue * Q);

void Enqueue (Queue * Q, int nomor_order, int nomor_pelanggan, Order T, int invoice);

void Dequeue (Queue * Q, infotype * X);

void BacaId(int id, int * hargaKomponen);

void MakeOrder (Queue * Q);

void TulisIsiOrder(Queue Q);

#endif