#include <stdio.h>
#include <string.h>
#include "KonfigAwal.h"


void GetMoney(Player *P, Queue *Q)
{
    PMoney(*P) = PMoney(*P) + invoice(Head(*Q)); // X = reward
}

void StartGame(Player *P)
{
    int maxel;
    maxel = 999;
    PDay(*P) = 1;
    PPos(*P) = 1; /* Base = 1, Shop = 2 */
    PMoney(*P) = 5122020;
    MakeEmptyKomponen(&PInv(*P), maxel);
}

void NextDay(Player *P)
{
    PDay(*P) = PDay(*P) + 1;
}