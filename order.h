#include <stdio.h>
#include <string.h>

typedef int ElType;

typedef struct Pesanan {
    ElType Build[8];
    int Reward;
    int Pelanggan;
} Order;

#define NoPel(X) (X).no_pelanggan
#define Reward(X) (X).Reward
#define Build(X)  (X).Build
#define ElmtBuild(X,i)  (X).Build[(i)]
#define Pelanggan(X) (X).Pelanggan
 
void MakeEmptyOrder (Order * X); 

void ORDABARU(Order * X);
/*Enak jaman ku toh?*/
