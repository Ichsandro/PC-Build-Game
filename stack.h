
#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "queuelist.h"

#define false 0
#define true 1
#define NilS 1
#define MaxElS 10

typedef int bool;

typedef int infotype;
typedef int address;

typedef struct
{
    infotype T[MaxElS];
    address TOP;
} Stack;

#define InfoS(P) (P)->info
#define Top(S) (S).TOP
#define Tab(S) (S).T[MaxEl]
#define InfoTop(S) (S).T[(S).TOP]
#define NextS(P) (P)->next

void CreateEmptyStack(Stack *S);

bool IsEmptyStack(Stack S);

bool IsFull(Stack S);

void dealokasi(address P);

int peek(Stack S);

void Push(Stack *S, infotype Y);

void Pop(Stack *S, infotype * Y);

void ForcePush(Stack *S, infotype Y);

void InverseStack(Stack *S);

void TulisStack (Stack S) ;

Stack CopyStack (Stack S) ;

#endif
