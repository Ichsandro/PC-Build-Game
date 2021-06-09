#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order.h"

void MakeEmptyOrder (Order * X)
{
	ElmtBuild(*X, 0) = 0;
    ElmtBuild(*X, 1) = 0;
    ElmtBuild(*X, 2) = 0;
    ElmtBuild(*X, 3) = 0;
    ElmtBuild(*X, 4) = 0;
    ElmtBuild(*X, 5) = 0;
    ElmtBuild(*X, 6) = 0;
    ElmtBuild(*X, 7) = 0;
    Pelanggan(*X) = 0;
    Reward(*X) = 0;
}

void ORDABARU(Order *X){
    srand(time(NULL));
    int lower = 1, upper = 10;
    int Order = (rand() % (upper - lower + 1)) + lower; //lower = 0. upper = 10, count = 1
    switch (Order){
        case 1:
            Reward(*X) = 4200;
            ElmtBuild(*X, 0) = 13;
            ElmtBuild(*X, 1) = 21;
            ElmtBuild(*X, 2) = 31;
            ElmtBuild(*X, 3) = 42;
            ElmtBuild(*X, 4) = 53;
            ElmtBuild(*X, 5) = 61;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 83;
            Pelanggan(*X) = 5;
            break;
        case 2:
            Reward(*X) = 5000;
            ElmtBuild(*X, 0) = 11;
            ElmtBuild(*X, 1) = 22;
            ElmtBuild(*X, 2) = 23;
            ElmtBuild(*X, 3) = 41;
            ElmtBuild(*X, 4) = 52;
            ElmtBuild(*X, 5) = 62;
            ElmtBuild(*X, 6) = 71;
            ElmtBuild(*X, 7) = 83;
            Pelanggan(*X) = 6;
            break;
        case 3:
            Reward(*X) = 3800;
            ElmtBuild(*X, 0) = 12;
            ElmtBuild(*X, 1) = 23;
            ElmtBuild(*X, 2) = 32;
            ElmtBuild(*X, 3) = 41;
            ElmtBuild(*X, 4) = 52;
            ElmtBuild(*X, 5) = 63;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 82;
            Pelanggan(*X) = 7;
            break;
        case 4:
            Reward(*X) = 4700;
            ElmtBuild(*X, 0) = 13;
            ElmtBuild(*X, 1) = 21;
            ElmtBuild(*X, 2) = 33;
            ElmtBuild(*X, 3) = 42;
            ElmtBuild(*X, 4) = 51;
            ElmtBuild(*X, 5) = 62;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 81;
            Pelanggan(*X) = 8;
            break;
        case 5:
            Reward(*X) = 5100;
            ElmtBuild(*X, 0) = 13;
            ElmtBuild(*X, 1) = 22;
            ElmtBuild(*X, 2) = 31;
            ElmtBuild(*X, 3) = 42;
            ElmtBuild(*X, 4) = 52;
            ElmtBuild(*X, 5) = 61;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 81;
            Pelanggan(*X) = 4;
            break;
        case 6:
            Reward(*X) = 4700;
            ElmtBuild(*X, 0) = 11;
            ElmtBuild(*X, 1) = 21;
            ElmtBuild(*X, 2) = 32;
            ElmtBuild(*X, 3) = 41;
            ElmtBuild(*X, 4) = 53;
            ElmtBuild(*X, 5) = 63;
            ElmtBuild(*X, 6) = 71;
            ElmtBuild(*X, 7) = 83;
            Pelanggan(*X) = 4;
            break;
        case 7:
            Reward(*X) = 5400;
            ElmtBuild(*X, 0) = 12;
            ElmtBuild(*X, 1) = 23;
            ElmtBuild(*X, 2) = 31;
            ElmtBuild(*X, 3) = 43;
            ElmtBuild(*X, 4) = 51;
            ElmtBuild(*X, 5) = 62;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 82;
            Pelanggan(*X) = 9;
            break;
        case 8:
            Reward(*X) = 5400;
            ElmtBuild(*X, 0) = 12;
            ElmtBuild(*X, 1) = 23;
            ElmtBuild(*X, 2) = 31;
            ElmtBuild(*X, 3) = 43;
            ElmtBuild(*X, 4) = 51;
            ElmtBuild(*X, 5) = 62;
            ElmtBuild(*X, 6) = 73;
            ElmtBuild(*X, 7) = 83;
            Pelanggan(*X) = 3;
            break;
        case 9:
            Reward(*X) = 4700;
            ElmtBuild(*X, 0) = 11;
            ElmtBuild(*X, 1) = 21;
            ElmtBuild(*X, 2) = 32;
            ElmtBuild(*X, 3) = 41;
            ElmtBuild(*X, 4) = 53;
            ElmtBuild(*X, 5) = 63;
            ElmtBuild(*X, 6) = 71;
            ElmtBuild(*X, 7) = 83;
            Pelanggan(*X) = 4;
            break;
        default:
            Reward(*X) = 5000;
            ElmtBuild(*X, 0) = 13;
            ElmtBuild(*X, 1) = 23;
            ElmtBuild(*X, 2) = 31;
            ElmtBuild(*X, 3) = 42;
            ElmtBuild(*X, 4) = 52;
            ElmtBuild(*X, 5) = 61;
            ElmtBuild(*X, 6) = 71;
            ElmtBuild(*X, 7) = 81;
            Pelanggan(*X) = 5;
            break;
    }
}
