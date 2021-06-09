#include "FileEksternal.h"

int main (){
    char input[80];
    int pil, i, NB, NK, MaxEl;
    boolean akhir = false;
    boolean F = false;
    MATRIKS M;
    Order X, orda;
    Queue Q;
    Stack S;
    Player P;
    info_komponen I;
    Komponen K;
    List L;
    Lokasi B;
    Graph G;

    printf("    _|_|_|                        _|                    _|_|_|_|_|                                                   \n");
    printf(" _|          _|_|_|  _|_|_|    _|_|_|_|    _|_|            _|      _|    _|    _|_|_|    _|_|      _|_|    _|_|_|    \n");
    printf("   _|_|    _|    _|  _|    _|    _|      _|    _|          _|      _|    _|  _|        _|    _|  _|    _|  _|    _|  \n");
    printf("       _|  _|    _|  _|    _|    _|      _|    _|          _|      _|    _|  _|        _|    _|  _|    _|  _|    _|  \n");
    printf(" _|_|_|      _|_|_|  _|    _|      _|_|    _|_|            _|        _|_|_|    _|_|_|    _|_|      _|_|    _|    _|  \n");
    printf("                                                                         _|                                          \n");
    printf("                                                                     _|_|                                            \n");

    printf("1. START NEW GAME\n");
    printf("2. LOAD SAVED GAME\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &pil);
    char C[20] = "fileconfig.txt";
    switch (pil){
        case 1:
            StartGame(&P);
            MakeOrder(&Q);
            STARTKATA(C);
            NB = KataToInt(CKata);
            ADVKATA();
            NK = KataToInt(CKata);
            ADVKATA();
            MaxEl = KataToInt(CKata);
            ADVKATA(); 
            B = KataToLokasi(MaxEl);
            M = KataToMatriks(NB, NK, B);
            G = KataToGraph(MaxEl);
            CreateEmptyList(&L);
            for (i = 1; i <= MaxEl; i++){
                InsVPrio(&L, i);
            }
            break;
        case 2:
            LoadGame(&P, &Q, &S);
            STARTKATA(C);
            NB = KataToInt(CKata);
            ADVKATA();
            NK = KataToInt(CKata);
            ADVKATA();
            MaxEl = KataToInt(CKata);
            ADVKATA(); 
            B = KataToLokasi(MaxEl);
            M = KataToMatriks(NB, NK, B);
            G = KataToGraph(MaxEl);
            CreateEmptyList(&L);
            for (i = 1; i <= MaxEl; i++){
                InsVPrio(&L, i);
            }
            break;
        default:
            printf("COMMAND IS WRONG. TRY ANOTHER COMMAND.\n");
            printf("ENTER COMMAND: ");
            scanf("%d", &pil);
    }
    while (!akhir){
        printf("  +-------------------------------+\n");
        printf("  |         ENTER COMMAND :       |\n");
        printf("  +-------------------------------+\n");
        printf("  |    MOVE   |  STATUS |   SHOP  |\n");
        printf("  +-------------------------------+\n");
        printf("  |   CHECK   |   ADD   |  REMOVE |\n");
        printf("  | COMPONENT |COMPONENT|COMPONENT|\n");
        printf("  +-------------------------------+\n");
        printf("  |   CHECK   |  START  | FINISH  |\n");
        printf("  |   ORDER   |  BUILD  |  BUILD  |\n");
        printf("  +-------------------------------+\n");
        printf("  |  DELIVER  |         | END_DAY |\n");
        printf("  +-------------------------------+\n");
        printf("  |    MAP    |   SAVE  |   EXIT  |\n");
        printf("  +-------------------------------+\n");

        printf("    ENTER COMMAND : ");
        scanf("%79s",input);
        printf("\n");

        if (strcmp(input, "MOVE") == 0){
            MOVE(&P, L, B, G);
        }   
        else if (strcmp(input, "STATUS") == 0){
            STATUS(&P, Q);
        }
        else if (strcmp(input, "CHECKORDER") == 0){
            CHECKORDER(Q);
        }
        else if (strcmp(input, "STARTBUILD") == 0){
            STARTBUILD(&S, &Q);
        }
        else if (strcmp(input, "FINISHBUILD") == 0){
            FINISHBUILD(&P, &S, &Q, &F);
        }
        else if (strcmp(input, "CHECKCOMPONENT") == 0){
            CHECKCOMPONENT(&S);
        }
        else if (strcmp(input, "ADDCOMPONENT") == 0){
            ADDCOMPONENT(&P, &S); 
        }
        else if (strcmp(input, "REMOVECOMPONENT") == 0){
            REMOVECOMPONENT(&S,&P);
        }
        else if (strcmp(input, "SHOP") == 0){
            if (PPos(P) == 2){
                shop(&P);
            } else {
                printf("Anda belum berada di Shop. Silahkan pergi ke Shop terlebih dahulu.\n");
            }
        }
        else if (strcmp(input, "DELIVER") == 0){
            if (F){
                DELIVER(&P, &Q, &S, &F);
            } else {
                printf("Anda belum menyelesaikan build. Silahkan ADDCOMPONENT terlebih dahulu.\n");
            }
        }
        else if (strcmp(input, "END_DAY") == 0){
            END_DAY(&P, &Q);
        }
        else if (strcmp(input, "SAVE") == 0){
             SaveGame(P, Q, S);
        }
        else if (strcmp(input, "MAP") == 0){
            MAP(&P, B, M);
        }
        else if (strcmp(input, "EXIT") == 0){
            EXIT();
            akhir = true;
        }
    }
    return 0;
}