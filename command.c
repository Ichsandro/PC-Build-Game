#include "command.h"

int MOVE(Player *P, List L1, Lokasi B, Graph G){
  int N, X, Y, tujuan;
  List li;
  int jml;
  int Pemain = PPos(*P);

  printf ("Lokasi Pemain: %d\n", Pemain);
  printf("Daftar lokasi yang dapat dicapai:\n");
  PrintMove(G, L1, B, Pemain, &jml);

    // Move
  boolean found = false;
  int coba, sama;

  while (!found){
    printf("Pilih lokasi yang ingin dituju : ");
    scanf("%d", &tujuan);
    if ((tujuan < 1) || (tujuan > jml)){
      printf("Tujuan lokasi yang Anda pilih salah. Silahkan pilih ulang.\n");
    } else {
      found = true;
      coba = 0;
      sama = 1;
      while (coba <= 9){
        coba += 1;
          if ((CheckRelation(G, Pemain, coba)) && (sama == tujuan)){
            if (coba == 1){
              printf("Kamu telah mencapai lokasi Base!\n");
            } else if (coba == 2){
              printf("Kamu telah mencapai lokasi Shop!\n");
            } else{
              printf("Kamu telah mencapai lokasi Pelanggan %d!\n", coba-2);
            }
            break;
        } else if (CheckRelation(G, Pemain, coba)) {
            sama += 1;
        }
      }
    }
  }
  Pemain = coba;
  PPos(*P) = Pemain;
  return 0;
}

void STATUS(Player *P, Queue Order){
    printf("Uang tersisa: $%d\n", PMoney(*P));
    printf("Build yang sedang dikerjakan: Pesanan %d untuk Pelanggan %d\n", nomor_order(Head(Order)), nomor_pelanggan(Head(Order)));
    if (PPos(*P) == 1){
        printf("Pemain sedang berada pada Base.\n");
    }
    else if (PPos(*P) == 2){
        printf("Pemain sedang berada pada Shop.\n");
    }
    else{
        printf("Pemain sedang berada pada Pelanggan %d\n", PPos(*P)-2);
    }

    printf("Inventory anda: \n");
    TulisIsiTabKomponen(PInv(*P));
}

void CHECKORDER(Queue Q){
  int i = 0;
	printf("Nomor Order: %d\n", (nomor_order(Head(Q))));
	printf("Pemesan: Pelanggan %d\n", (nomor_pelanggan(Head(Q))));
	printf("Invoice: $%d\n", (invoice(Head(Q))));
	printf("Komponen: \n");
	TulisIsiOrder(Q);
}

void STARTBUILD(Stack *S, Queue *Q){
    CreateEmptyStack(S);
    printf("Kamu telah memulai pesanan %d untuk pelanggan %d\n", (nomor_order(Head(*Q))), (nomor_pelanggan(Head(*Q))));
}

void FINISHBUILD(Player *P,Stack *S, Queue *Q, boolean *F){
	int count = 0;
  int id;
	for (int i = 0; i < 8; i++){
    id = (*S).T[i];
		if (id == ElmtBuild((T((Head(*Q)))), i)){
			  count += 1;
		  }
	  }
	if (count == 8){
		printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", (nomor_order(Head(*Q))), (nomor_pelanggan(Head(*Q))));
    *F = true;
	}
	else{
		printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
	}	
}

int ADDCOMPONENT(Player *P, Stack *S){
    infotype y;
    char tambah, masukan;
    int komponen = 0;
    boolean found = false;
    int id;
    int hargaKomponen = 0;
    int harga, jumlah, barang;


    printf("Komponen yang telah terpasang:\n");
    if (IsEmptyStack(*S)) {
        printf("Belum ada komponen terpasang.\n");
    } 
    else{
        for (int i = 0; i < 8; i++){
          id = (*S).T[i];
          printf("%d. ", i+1);
          BacaId(id, &hargaKomponen);
          printf("\n");
        }
    }
    
    printf("Komponen yang tersedia: \n");
    TulisIsiTabKomponen(PInv(*P));
    if (IsEmptyKomponen(PInv(*P))){
      printf("Inventory Anda kosong, silahkan beli di shop.\n");
    }
    else{
      while (!found){
          printf("Komponen yang ingin dipasang: ");
          scanf("%d", &tambah); 
          int jmlh = NbElmtKomponen(PInv(*P));
          printf("\n");
          
          if ((tambah < 1) || (tambah > jmlh )){
              printf("Komponen yang Anda pilih salah. Silahkan pilih ulang.\n");
              scanf("%d", &tambah);
              break;
          } 
          else {
              id = id(elmt(PInv(*P), tambah));
              Push(S, id);
              jumlah(elmt(PInv(*P), tambah))--;
              if (jumlah(elmt(PInv(*P), tambah)) == 0){
                Del1UrutKomponen(&PInv(*P), id);
              }
              found = true;
          }
      }
      printf("Komponen berhasil dipasang!\n");
    }
    return (0);
}
    
int CHECKCOMPONENT (Stack *S){
     int komponen = 0;
     int id;
     int hargaKomponen = 0;
     int barang;

     printf("Komponen yang telah terpasang:\n");
     if (IsEmptyStack(*S)) {
         printf("Belum ada komponen terpasang.\n");
     } 
     else{
         for (int i = 0; i < 8; i++){
           id = (*S).T[i];
           printf("%d. ", i+1);
           BacaId(id, &hargaKomponen);
           printf("\n");
       }
    }
}

int REMOVECOMPONENT(Stack *S, Player *P){
    char input[25];
    int id, hargaKomponen, com, i;
    info_komponen X;
   	if (IsEmptyStack(*S)){
		  printf("Belum ada komponen terpasang.\n");
    }else{
        Pop(S, &id);
        printf("Komponen ");
        com = id;
        printf("%d\n", com);
        BacaId(id, &hargaKomponen);
        printf("berhasil dilepas\n");
        if (IsIdKomponen(PInv(*P),id,&i)){
          jumlah(elmt(PInv(*P),i))++;
        }else{
          id(X) = id;
          BacaId(id, &hargaKomponen);
          printf("\n");
          jumlah(X) = 1;
          harga(X) = hargaKomponen;
          AddAsLastElKomponen(&PInv(*P), X);
        }
    }
}

void DELIVER(Player *P, Queue *Q, Stack *S, boolean *F){
    if (PPos(*P) = nomor_pelanggan(Head(*Q))){
        infotype X;
        printf("Pesanan %d berhasil diantarkan kepada pelanggan %d!\n", nomor_order(Head(*Q)) , nomor_pelanggan(Head(*Q)));
        PMoney(*P) += invoice(Head(*Q));
        CreateEmptyStack(S);
        *F = false;
    }
}
        
int END_DAY(Player *P, Queue *Q){
    PDay(*P)++;
    MakeOrder(Q);
    printf("    HARI KE - %d\n", PDay(*P));
}

void MAP(Player *P, Lokasi B, MATRIKS M){
  PrintMap(M,B,PPos(*P));
}

void EXIT(){ 
 }
