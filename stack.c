#include "stack.h"

void CreateEmptyStack(Stack *S){
    S->TOP = NilS;
}

bool IsEmptyStack(Stack S){
    return S.TOP == NilS;
}

/*void dealokasi(address P){
    free(P);
}
void popValue(Stack *S, infotype *X){
    address p;
    
    if(!IsEmptyStack(*S)){
        p=Top(*S);
        Top(*S)=NextS(p);
        *X=InfoS(p);
        dealokasi(p);
    }else{ 
        printf("Stack ini masih kosong.\n");
    }
}
void deleteAll(Stack *S){
    infotype x;
    
    while(!IsEmptyStack(*S)){
        popValue(S,&x);
    }
}
*/
bool IsFull(Stack S){
    return S.TOP == MaxElS;
}

void Push(Stack *S, infotype Y){
    S->T[S->TOP] = Y;
    S->TOP++;
}
void Pop(Stack *S, infotype *Y){
    *Y = InfoTop(*S);
    Top(*S)--;
}

void ForcePush(Stack *S, infotype Y){
    int idx;
    if (!IsFull(*S))
    {
        Push(S, Y);
    }
    else
    {
        for (idx = 0; idx < S->TOP - 1; idx++)
        {
            S->T[idx] = S->T[idx + 1];
        }
        S->T[S->TOP - 1] = Y;
    }
}

void InverseStack(Stack *S) {
	infotype x;	
	if(!IsEmptyStack(*S)) {
		Pop(S,&x);
		InverseStack(S);
		Push(S,x);
	}
}

void TulisStack (Stack S) {
	int x;
	Stack R;
    int hargaKomponen;
	CreateEmptyStack(&R);
	while(!IsEmptyStack(S)) {
		Pop(&S,&x);
		BacaId(x, &hargaKomponen);
        printf("alloooo\n");
		Push(&R,x);
	} //R inverse S
	while(!IsEmptyStack(R)) {
		Pop(&R,&x);
		Push(&S,x);
	}	
}

Stack CopyStack (Stack S) {
	int x;
	Stack R;
    int hargaKomponen;
	CreateEmptyStack(&R);
	while(!IsEmptyStack(S)) {
		Pop(&S,&x);		
		Push(&R,x);
	} //R inverse S
    InverseStack(&R);
    return R;
	while(!IsEmptyStack(R)) {
		Pop(&R,&x);
		Push(&S,x);
	}	
}