#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "FileEksternal.h"

boolean FileExist(char *save)
/* mengeluarkan true jika file bernama save ada*/
{
    return (access(save, F_OK)) != -1;
}

void SaveGame(Player P, Queue Order, Stack S)
//YANG DI SAVE: DAY, MONEY, POSISI PLAYER, INVENTORY, NO ORDER, CURRENTBUILD
{
    FILE *F = fopen("save_file.txt", "w"); //lokasi file harus di C:\User\Documents\save_file.txt
    int day, pos, money, que, add, rew;
    day= PDay(P);
    pos = PPos(P);
    money = PMoney(P);
    que = nomor_order(Head(Order));
    add = nomor_pelanggan(Head(Order));
    rew = invoice(Head(Order));
    fprintf(F, "%d, %d, %d", day, pos, money);
    fprintf(F,"\n");
    fprintf(F, "%d, %d, %d", que, add, rew);
    fprintf(F,"\n");
    for (int i = 0; i <= 7; i++){
        int inv = ElmtBuild(T(Head(Order)), i);
        fprintf(F,"%d\n", inv);
    }
    if (IsEmptyKomponen(PInv(P))){ // INI SAVEGAME BUKAN LOADGAME
        fprintf(F,"%d", 999);
    }
    else{ //Inventory
        for (IdxType i = GetFirstIdxKomponen(PInv(P)); i <= GetLastIdxKomponen(PInv(P)); i++){
            int j;
            int inv = id(elmt(PInv(P), i));
            int sum = jumlah(elmt(PInv(P), i));
            for (j = 1; j <= sum; j++){
                fprintf(F, "%d\n", inv);
            }
        }
        fprintf(F,"%d", 999);
        fprintf(F,"\n");
    }
    if (!IsEmptyStack(S)) //stack
    {
        for (int i = 0; i < 8; i++){
            int inv = (S).T[i];
            fprintf(F,"%d\n", inv);
        }
        fprintf(F,"%s", "-0");
        fprintf(F,"\n");
    }
    fprintf(F, "\n");
    fprintf(F, "-1");
    printf("Save berhasil!\n");
    fclose(F);
}

void LoadGame(Player *P, Queue *Q, Stack *S){
    int day, pos, money, que, add, rew, inv, ord, id;
    Kata temp;
    Order To;
    if(!FileExist("save_file.txt"))
    {
        printf("Anda belum pernah menyimpan permainan\n");
    }
    else
    {
        FILE *F = fopen("save_file.txt","r");
        fscanf(F, "%d, %d, %d", &day, &pos, &money);
        fscanf(F, "%d, %d, %d", &que, &add, &rew);
        MakeEmptyOrder(&To);
        fscanf(F,"%d",&ord);
        for (int i = 0; i <= 7; i++){
            ElmtBuild(To, i) = ord;
            fscanf(F,"%d",&ord);
        }
        Enqueue(Q, que, add, To, rew);
        PDay(*P) = day;
        PPos(*P) = pos;
        PMoney(*P) = money;
        int maxel = 999;
        int i = 0;
        int inv, hargaKomponen, com;
        char sinv[16];
        info_komponen X;
        fscanf(F, "%d", &inv);
        MakeEmptyKomponen(&PInv(*P), maxel);
        while (inv != 999){
            int jumlah = 1;
            id = inv;
            if (IsIdKomponen(PInv(*P),id,&i)){
                jumlah(elmt(PInv(*P),i))++;
            }
            else{
                id(X) = id;
                jumlah(X) = jumlah;
                harga(X) = hargaKomponen;
                AddAsLastElKomponen(&PInv(*P), X);
            }
            fscanf(F, "%d", &inv);
        }
        CreateEmptyStack(S);
        fscanf(F, "%d", &com);
        for (int i = 0; i <= 7; i++){
            Push(S, com);
            fscanf(F, "%d", &com);     
        } 
        fclose(F);
    }
    printf("Load berhasil!\n");
    return;
}