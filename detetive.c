#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ponto{
    char valor[50];
    char pista[50];
    int cooldown;
    struct ponto* esquerda;
    struct ponto* direita;
} ponto;

char* pistaQuarto[2]={
    "Tapete bagunçado",
    "Traveseiros no chão"
};

char* pistaBiblioteca[1]={
    "Tinta de caneta deramada na mesa"
};

char* pisaSala[2]={
    "Ração pela casa",
    "Marcas de garras no carpete"
};

ponto* CriarPonto(char* valor){
    ponto *novo = (ponto*) malloc(sizeof(ponto));
    if (novo == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(novo->valor, valor);
    novo->pista[0] = '\0';
    novo->cooldown = 0;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void liberar(ponto* raiz){
    if (raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

ponto* andarEsquerda(ponto* atual){
    if (atual->esquerda != NULL){
        atual = atual->esquerda;
        printf("\nVocê foi para: %s\n", atual->valor);
    }else{
        printf("\nNão há caminho à esquerda!\n");
    }
    return atual;
}

ponto* andarDireita(ponto* atual){
    if (atual->direita != NULL){
        atual = atual->direita;
        printf("\nVocê foi para: %s\n", atual->valor);
    }else{
        printf("\nNão há caminho à direita!\n");
    }
    return atual;
}

void atribuirPista(ponto* local, char* pista){
    if(local != NULL && pista != NULL)
        strcpy(local->pista, pista);
    return;
}

ponto* inserir(ponto* raiz, char* valor){
    if (raiz == NULL) 
        return CriarPonto(valor);
    
        if (strcmp(valor, raiz->valor) < 0)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else if (strcmp(valor, raiz->valor) > 0)
            raiz->direita = inserir(raiz->direita, valor);
        
        return raiz;
}

void atribuirNovaPista(ponto* local){
    if (strcmp(local->valor, "Quarto") == 0) {
        static int indiceQuarto = 0;
        if (indiceQuarto < 2) {
            strcpy(local->pista, pistaQuarto[indiceQuarto]);
            indiceQuarto++;
        } else {
            local->pista[0] = '\0';
        }
    } else if (strcmp(local->valor, "Biblioteca") == 0) {
        static int indiceBiblioteca = 0;
        if (indiceBiblioteca < 1) {
            strcpy(local->pista, pistaBiblioteca[indiceBiblioteca]);
            indiceBiblioteca++;
        } else {
            local->pista[0] = '\0';
        }
    } else if (strcmp(local->valor, "Sala de estar") == 0) {
        static int indiceSala = 0;
        if (indiceSala < 2) {
            strcpy(local->pista, pisaSala[indiceSala]);
            indiceSala++;
        } else {
            local->pista[0] = '\0';
        }
    }
}

void capturarPista(ponto** arvoreBST, ponto* local){
    if (local->pista[0] != '\0'){
        printf("--------------------------------------\n");
        printf("Pista [ %s ] encontrada.\n", local->pista);
        printf("--------------------------------------\n");
        *arvoreBST = inserir(*arvoreBST, local->pista);
        local->pista[0] = '\0';
        local->cooldown = 2;
        printf("Uma nova pista irá aparecer em certos lugares.\n");
        printf("--------------------------------------\n");
    } else {
        printf("--------------------------------------\n");
        printf("Não tem nenhuma pista aqui.\n");
        printf("--------------------------------------\n");
    }
}

void inOrder(ponto* raiz){
    if (raiz != NULL)
    {
       inOrder(raiz->esquerda);
       printf("[ %s ]¬\n", raiz->valor);
       inOrder(raiz->direita);
    }
}

void atualizarPistas(ponto* raiz){
    if (raiz == NULL)
        return;

    atualizarPistas(raiz->esquerda);

    if (raiz->cooldown > 0){
        raiz->cooldown--;
        if (raiz->cooldown == 0 && raiz->pista[0] == '\0'){
            atribuirNovaPista(raiz);
        }
    }

    atualizarPistas(raiz->direita);
}

int main()
{
    int opcao;
    ponto *raiz = CriarPonto("Entrada");
    ponto *atual = raiz; // jogador começa na raiz
    ponto *arvoreBST = NULL;

    // Montagem da árvore
    raiz->esquerda = CriarPonto("Biblioteca");
    atribuirPista(raiz->esquerda, "Livros com folhas rasgadas");
    raiz->direita = CriarPonto("Sala de estar");
    atribuirPista(raiz->direita, "Sofá com marcas de pegadas");
    raiz->direita->esquerda = CriarPonto("Quarto");
    atribuirPista(raiz->direita->esquerda, "Cama cheia de pelos");
    raiz->direita->direita = CriarPonto("Varanda");
    atribuirPista(raiz->direita->direita, "Vaso de plantas quebrado");

    printf("\n\tINICIANDO JOGO...\n");

    do{
        printf("\n_____________ÁRVORE_______________\n");
        printf("~~ Raiz: %s\n", raiz->valor);
        printf(">> Esquerda: %s\n", raiz->esquerda->valor);
        printf(">> Direita: %s\n", raiz->direita->valor);
        printf(">> Direita >> Esquerda: %s\n", raiz->direita->esquerda->valor);
        printf(">> Direita >> Direita: %s\n", raiz->direita->direita->valor);
        printf("__________________________________\n");

        printf("\n-- Você está em: %s\n", atual->valor);
        printf("-- Tempo para novas: %d\n", atual->cooldown);
        printf("1. Ir para esquerda\n");
        printf("2. Ir para direita\n");
        printf("3. Voltar para o início\n");
        printf("4. Procura pista.\n");
        printf("5. Vizualizar pistas.\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                atual = andarEsquerda(atual);
                atualizarPistas(atual);
                break;
            }
            case 2:{
                atual = andarDireita(atual);
                atualizarPistas(atual);
                break;
            }
            case 3:{
                atual = raiz;
                printf("\nVocê voltou para: %s\n", atual->valor);
                atualizarPistas(atual);
                break;
            }
            case 4:{
                capturarPista(&arvoreBST, atual);
                break;
            }
            case 5:{
                if(arvoreBST != NULL)
                    inOrder(arvoreBST);
                else
                    printf("Vazio.");
                break;
            }
            case 0:{
                printf("\nSaindo do jogo...\n");
                break;
            }
            default:{
                printf("\nOpção inválida.\n");
                break;
            }
        }
    } while (opcao != 0);

    liberar(raiz);
    free(arvoreBST);
    return 0;
}