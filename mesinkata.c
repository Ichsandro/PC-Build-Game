/* State Mesin Kata */
#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;    
Kata CKata;        

void IgnoreBlank()
{
   while ((CC == BLANK) || (CC == ENTER))
   {
       ADV();
   }
}

void STARTKATA(char * C)
{
    START(C);
    IgnoreBlank();
    SalinKata();
}

void ADVKATA()
{
    IgnoreBlank();
    SalinKata();
    IgnoreBlank();
}

void SalinKata()
{
    int i = 1;
    while ((CC != BLANK) && (CC != ENTER) && (i <= NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

void PrintKata (Kata K)
{
    int i = 1;
    while (i<K.Length)
    {
        printf("%c", K.TabKata[i]);
        i++;
    }
}

void CopyKata(Kata K1,Kata *K2)
{
    (*K2).Length = K1.Length;
    int i;
    int len = K1.Length;
    for (i = 0;i<len;++i)
    {
        (*K2).TabKata[i] = K1.TabKata[i];
    }
}

char KataToChar (Kata K)
{
    return (K.TabKata[1]);
}

int KataToInt (Kata K)
{
    int val = 0;
    int i = 0;
    while (i<K.Length)
    {
        val = val * 10;
        switch (K.TabKata[i]){
        case '0' : val += 0; break;
        case '1' : val += 1; break;
        case '2' : val += 2; break;
        case '3' : val += 3; break;
        case '4' : val += 4; break;
        case '5' : val += 5; break;
        case '6' : val += 6; break;
        case '7' : val += 7; break;
        case '8' : val += 8; break;
        case '9' : val += 9; break;
        };
        i++;
    }
    return val;
}

Lokasi KataToLokasi(int MaxEl)
{
    Lokasi L;
    int i;
    Kata Ka, Kb, Kc;
    MakeEmptyLokasi(&L, MaxEl);
    for (i = 1; i <= MaxEl; i++) 
    {
        Ka = CKata;
        ADVKATA();
        Kb = CKata;
        ADVKATA();
        Kc = CKata;
        ElmtLok(L, i) = KataToInfo(Ka, Kb, Kc);
        ADVKATA();
    }
    NeffL(L) = MaxEl;
    return L;
}

info_lokasi KataToInfo(Kata K1, Kata K2, Kata K3)
{
    info_lokasi info;
    Name(info) = KataToChar(K1);
    MakePOINT(&Posisi(info),KataToInt(K2), KataToInt(K3));
    return info;
}

MATRIKS KataToMatriks(int MaxNB, int MaxNK, Lokasi L)
{
    MATRIKS M;
    int i;
    MakeMATRIKS(MaxNB, MaxNK, &M);
    BacaMATRIKS(&M, L);
    return M;
}

Graph KataToGraph(int MaxEl)
{
    Graph G;
    int i, j;
    MakeEmptyGraph(&G);
    AddParent(&G,MaxEl);
    for (i = 1; i <= MaxEl; i++) {
        for (j = 1; j <= MaxEl; j++) {
        if (KataToInt(CKata) == 1) {
            AddRelation(&G, i, j);
        }
            ADVKATA();
        }
    }
    return G;
}
