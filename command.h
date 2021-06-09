#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydin.h"
#include "boolean.h"
#include "graph.h"
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stack.h"
#include "queuelist.h"
#include "Shop.h"
#include "Main.h"
#include "KonfigAwal.h"

int MOVE(Player *P, List L1, Lokasi B, Graph G);

void STATUS(Player *P, Queue Order);

void CHECKORDER(Queue Q);

void STARTBUILD(Stack *S, Queue *Q);

int ADDCOMPONENT(Player *P, Stack *S);

void FINISHBUILD(Player *P,Stack *S, Queue *Q, boolean *F);

int REMOVECOMPONENT(Stack *S, Player *P);

int CHECKCOMPONENT (Stack *S);

void DELIVER(Player *P, Queue *Q, Stack *S, boolean *F);

int END_DAY(Player *P, Queue *Q);

void MAP(Player *P, Lokasi B, MATRIKS M);

void EXIT();