/* File header: graph.h */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"

typedef struct tElmtGraph *addrGraph;
typedef struct tElmtGraph2 *addrGraph2;

typedef struct tElmtGraph {
  int infoG;
  addrGraph NextParent;
  addrGraph2 FirstChild;
} ElmtGraph;

typedef struct tElmtGraph2 {
  int infoG2;
  addrGraph2 NextChild;
} ElmtGraph2;

typedef struct {
  addrGraph FirstG;
} Graph;


#define InfoG(P)      (P)->infoG
#define NextP(P)      (P)->NextParent
#define FirstChild(P) (P)->FirstChild
#define InfoG2(P2)    (P2)->infoG2
#define NextChild(P2) (P2)->NextChild
#define FirstG(L)     ((L).FirstG)

void MakeEmptyGraph (Graph * G);

addrGraph AlokasiGraph1 (urutan X);

addrGraph2 AlokasiGraph2 (urutan X);

void DealokasiGraph1 (addrGraph * G);

void DealokasiGraph2 (addrGraph2 * G2);

boolean IsEmptyGraph (Graph G);

boolean IsFullGraph (Graph G);

boolean IsEmptyParent (addrGraph P);

void BacaGraph (Graph * G);

void TulisGraph (Graph G);

void AddParent (Graph * G, int N);

void AddRelation (Graph * G, urutan X, urutan Y);

addrGraph SearchP (Graph G, urutan X);

int NbElmtGraph (Graph G);

addrGraph2 SearchChild (addrGraph P, urutan X);

boolean CheckRelation (Graph G, urutan X, urutan Y);

void PrintMove (Graph G, List L, Lokasi B, urutan X, int * Count);

int GetIdxMove (Graph G, List L, Lokasi B, urutan X, int pos);

#endif
