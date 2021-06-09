#include "queuelist.h"
#include <stdlib.h>


void AlokasiQueue (street *P, int nomor_order, int nomor_pelanggan, Order T, int invoice)
{
    *P = (street) malloc(sizeof(ElmtQueue));
    if (*P!=Nil){
        nomor_order(*P) = nomor_order;
	    nomor_pelanggan(*P) = nomor_pelanggan;
	    T(*P) = T;
        invoice(*P) = invoice;
        NextQ(*P) = Nil;
    }
}

void Dealokasi (street  P)
{
    free(P);
}

boolean IsEmptyQueue (Queue Q)
{
    return(Head(Q)==Nil && Tail(Q)==Nil);
}

int NbElmt(Queue Q)
{
    int count = 0;
    if (!IsEmptyQueue(Q)){
        street P = Head(Q);
        while(P!=Nil){
            count++;
            P = NextQ(P);
        }
    }
    return count;
}

void CreateEmptyQueue(Queue * Q)
{
    Head(*Q) = 0;
    Tail(*Q) = 0;
}

void Enqueue (Queue * Q, int nomor_order, int nomor_pelanggan, Order T, int invoice)
{
    street P;
    AlokasiQueue(&P, nomor_order, nomor_pelanggan, T, invoice);
    if (P!=Nil){
        if (IsEmptyQueue(*Q)){
            Head(*Q) = P;
            Tail(*Q) = P;
        } else {
            NextQ(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Dequeue(Queue * Q, infotype * X)
{
    *X = InfoHead(*Q);
    street P = Head(*Q);
    if (NbElmt(*Q)==1){
        Tail(*Q) = Nil;
    }
    Head(*Q) = NextQ(Head(*Q));
    Dealokasi(P);
}

void BacaId(int id, int *hargaKomponen){
    switch (id){
        case 11: 
            printf("Asus B150 PRO ");
            *hargaKomponen = 100;
            break;
        case 12: 
            printf("Gigabyte Z490 Aorus Elite ");
            *hargaKomponen = 250;
            break;
        case 13: 
            printf("Asus MAXIMUS VIII ");
            *hargaKomponen = 500;
            break;
        case 21:
            printf("AMD Ryzen 5 3500X ");
            *hargaKomponen = 100;
            break;
        case 22 :
            printf("Intel Core I7-1165G7\n");
            *hargaKomponen = 250;
            break;
        case 23 :
            printf("Intel Core I9-10850K ");
            *hargaKomponen = 500;
            break;
        case 31 :
            printf("Corsair DDR4 8GB ");
            *hargaKomponen = 100;
            break;
        case 32 :
            printf("Samsung DDR4 16GB ");
            *hargaKomponen = 250;
            break;
        case 33 :
            printf("HyperX Fury DDR4 32GB ");
            *hargaKomponen = 500;
            break;
        case 41 :
            printf("DeepCool Maxx 300 ");
            *hargaKomponen = 100;
            break;
        case 42 :
            printf("CoolerMaster Air 8 ");
            *hargaKomponen = 250;
            break;
        case 43 :
            printf("DeepCool Castle 320 ");
            *hargaKomponen = 500;
            break;
        case 51 :
            printf("CoolerMaster Lite 5 Case ");
            *hargaKomponen = 100;
            break;
        case 52 :
            printf("DeepCool Tesseract BF Case ");
            *hargaKomponen = 250;
            break;
        case 53 :
            printf("CoolerMaster Pro X9 Case ");
            *hargaKomponen = 500;
            break;
        case 61 :
            printf("Nvidia GTX 1660TI ");
            *hargaKomponen = 100;
            break;
        case 62 :
            printf("AMD Radeon RX 5700 XT ");
            *hargaKomponen = 250;
            break;
        case 63 :
            printf("Nvidia RTX 3080 Ti ");
            *hargaKomponen = 500;
            break;
        case 71 :
            printf("Seagate HDD 1TB ");
            *hargaKomponen = 100;
            break;
        case 72 :
            printf("WD SSD SATA 500GB ");
            *hargaKomponen = 250;
            break;
        case 73 : 
            printf("Samsung SSD M.2 1TB ");
            *hargaKomponen = 500;
            break;
        case 81 :
            printf("Corsair RM550x 550 Watt ");
            *hargaKomponen = 100;
            break;
        case 82 :
            printf("EVGA 1000G5 1000 Watt ");
            *hargaKomponen = 250;
            break;
        case 83 :
            printf("Corsair AX1600i 1600 Watt ");
            *hargaKomponen = 500;
            break;
        default :
            printf(" ");
            *hargaKomponen = 0;
            break;
    }
}

void MakeOrder (Queue * Q){
    int i;
    Order order;
    MakeEmptyOrder(&order);
    for (i = 1; i <= 5; i++) {
        ORDABARU(&order);
        Enqueue(Q, i, Pelanggan(order), order, Reward(order));
    }
}

void TulisIsiOrder(Queue Q){
    int hargaKomponen;
    int i;
    for (i = 0; i <= 7; i++){
        int id = ElmtBuild(T(Head(Q)), i);
        printf("%d. ", i+1);
        BacaId(id, &hargaKomponen);
        printf("\n");
    }
}
