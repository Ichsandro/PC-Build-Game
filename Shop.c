#include "boolean.h"
#include "Shop.h"
#include <stdio.h>
#include <string.h>
/* ID = XX, {Id tipe, id barang
cont. 13 = Asus Maximus VIII}*/

void shop(Player *P)
{
    int harga, jumlah, barang, id;
    IdxType i = 0;
    int hargaKomponen = 0;
    info_komponen X;
    printf("List Komponen:\n");
    printf("1. Motherboard\n");
    printf("2. CPU\n");
    printf("3. Memory\n");
    printf("4. CPU Cooler\n");
    printf("5. Case\n");
    printf("6. GPU\n");
    printf("7. Storage\n");
    printf("8. PSU\n");
    printf("Komponen yang ingin dibeli: ");
    scanf("%d", &id);
    printf("\n");
    switch(id){
        case 1:
            printf("1. Asus B150 PRO- $100\n");
            printf("2. Gigabyte Z490 Aorus Elite - $250\n");
            printf("3. Asus MAXIMUS VIII - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 11;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 12;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 13;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
                
            }
        case 2:
            printf("1. AMD Ryzen 5 3500X - $100\n");
            printf("2. Intel Core I7-1165G7 - $250\n");
            printf("3. Intel Core I9-10850K - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 21;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                 id = 22;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 23;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 3:
            printf("1. Corsair DDR4 8GB - $100\n");
            printf("2. Samsung DDR4 16GB - $250\n");
            printf("3. HyperX Fury DDR4 32GB- $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 31;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 32;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 33;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 4:
            printf("1. DeepCool Maxx 300 - $100\n");
            printf("2. CoolerMaster Air 8 - $250\n");
            printf("3. DeepCool Castle 320 - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 41;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 42;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 43;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 5:
            printf("1. CoolerMaster Lite 5 Case - $100\n");
            printf("2. DeepCool Tesseract BF Case - $250\n");
            printf("3. CoolerMaster Pro X9 Case - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 51;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 52;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 53;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id,  &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 6:
            printf("1. Nvidia GTX 1660TI - $100\n");
            printf("2. AMD Radeon RX 5700 XT - $250\n");
            printf("3. Nvidia RTX 3080 Ti - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");
            if (barang == 1){
                harga = 100 * jumlah;
                id = 61;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 62;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 63;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 7:
            printf("1. Seagate HDD 1TB - $100\n");
            printf("2. WD SSD SATA 500GB - $250\n");
            printf("3. Samsung SSD M.2 1TB- $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");  
            if (barang == 1){
                harga = 100 * jumlah;
                id = 71;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 72;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 73;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else{
                printf("Uang tidak mencukupi!\n");
                break;
            }
        case 8:
            printf("1. Corsair RM550x 550 Watt - $100\n");
            printf("2. EVGA 1000G5 1000 Watt  - $250\n");
            printf("3. Corsair AX1600i 1600 Watt - $500\n");
            printf("Pilih barang yang ingin dibeli: ");
            scanf("%d", &barang);
            printf("\n");
            printf("Masukan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            printf("\n");    
            if (barang == 1){
                harga = 100 * jumlah;
                id = 81;
            }  
            else if (barang == 2) {
                harga = 250 * jumlah;
                id = 82;
            }
            else if (barang == 3) {
                harga = 500 * jumlah;
                id = 83;
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
            if (PMoney(*P) >= harga){
                PMoney(*P) = PMoney(*P) - harga;
                if (IsIdKomponen(PInv(*P),id,&i)){
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(elmt(PInv(*P),i))++;
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
                else{
                    id(X) = id;
                    BacaId(id, &hargaKomponen);
                    printf("\n");
                    jumlah(X) = jumlah;
                    harga(X) = hargaKomponen;
                    AddAsLastElKomponen(&PInv(*P), X);
                    printf("Barang berhasil dibeli.\n");
                    break;
                }
            }
            else {
                printf("Barang tidak terdefinisi.\n");
                break;
            }
    }
}
