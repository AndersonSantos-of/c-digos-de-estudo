#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// testando

typedef struct{
    char forma[2];
    int id;
} peça;

#define max 5

// --------------- FILA --------------

typedef struct{
    peça itens[max];
    int inicio;
    int fim;
    int total;
    int newID;
} fila;

int filaVazia(fila *f) {
    return f->total == 0;
}

void enqueue(fila *f, peça p){

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % max;
    f->total++;
}

void dequeue(fila *f, peça *p) {
    if (f->total == -1) {
        return;
    }
    
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % max;
    f->total--;
}

void mostrarfila(fila *f){
printf("Fila: ");
    for (int i = 0, j = f->inicio; i < f->total; i++, j = (j + 1) % max){
        printf("[%s, %d] ", f->itens[j].forma, f->itens[j].id);
    }
    printf("\n");
}

void inicializarfila(fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->newID=6;
}

// --------------- PILHA --------------

typedef struct{
    peça itens[max];
    int topo;
}pilha;

void inicializarpilha(pilha *p) {
    p->topo = -1;
}

void push(pilha *p, peça n){
    if (p->topo==max-1){
        printf("Pilha cheia.\n");
        return;
    }
    p->topo++;
    p->itens[p->topo]=n;
    printf("Peça [%s | %d] foi reservada.\n", n.forma, n.id);
}

void pop(pilha *p, peça *n){
    if (p->topo==-1){
        printf("Reserva vazia.\n");
        return;
    }
    *n=p->itens[p->topo];
    p->topo--;
    printf("Peça [%s | %d] movida para a fila.\n", n->forma, n->id);
}

void views(pilha p){
    printf("Reserva: ");
    for ( int i = p.topo; i>=0 ; i--){
        printf("[%s | %d] ", p.itens[i].forma, p.itens[i].id);
    } 
}

//------------------------------------------------

int main()
{
    srand(time(NULL)); 
    fila f;
    inicializarfila(&f);
    int op = 0;

    pilha reserva;
    inicializarpilha(&reserva);

    peça n1 ={"L", 1};
    peça n2 ={"I", 2};
    peça n3 ={"T", 3};
    peça n4 ={"O", 4};
    peça n5 ={"L", 5};

    enqueue(&f, n1);
    enqueue(&f, n2);
    enqueue(&f, n3);
    enqueue(&f, n4);
    enqueue(&f, n5);

    printf("\n\tINICIANDO O JOGO...\n");

    do{
        printf("\n----------------------------------------\n");
        printf("Sentido da fila/pilha: >>>\n");
        mostrarfila(&f);
        views(reserva);
        printf("\n----------------------------------------");

        printf("\n1. Jogar peça.\n");
        printf("2. Reservar peça.\n");
        printf("3. Usar peça da reserva.\n");
        printf("4. Adicionar nova peça\n");
        printf("0. Sair\n");
        printf(">> Digite sua escolha: ");
        scanf("%d", &op);

        switch (op){
            case 1:{
                if (!filaVazia(&f)){
                    peça jogada;
                    dequeue(&f, &jogada);
                    printf("Peça [%s | %d] jogada!\n", jogada.forma, jogada.id);
                }else{
                    printf("Fila vazia.\n");
                }
                break;
            }
            case 2:{
                peça removida;
                dequeue(&f, &removida);
                push(&reserva, removida);
                break;
            }
            case 3:{
                if ((reserva.topo >= 0) && (f.total<max)){
                    peça devolta;
                    pop(&reserva, &devolta);
                    enqueue(&f, devolta);
                }else{
                    printf("Não foi possivél realizar essa ação.\n");
                }
                break;
            }
            case 4:{
                if (f.total == max){
                    printf("Fila cheia. Nova peça descartada.\n");
                    break;
                }
 
                const char *formas[] = {"T", "O", "L", "I"};
                int escolha = rand() % 4;
                peça nova;
                nova.id = f.newID++;
                snprintf(nova.forma, sizeof(nova.forma), "%s", formas[escolha]);

                enqueue(&f, nova);
                printf("Nova peça [%s | %d] adicionada à fila!\n", nova.forma, nova.id);
                break;
            }
            case 0:{
                printf("Saindo do jogo...\n");
                break;
            }
            defaulf:{
                printf("Opção inválida.\n");
                break;
            }
        }

    } while (op != 0);

    return 0;
}