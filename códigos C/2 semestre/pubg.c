#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// vendo no que dá

typedef struct
{
    char nome[30];
    char tipo[30];
    int quantidade;
    int prioridade;
} item;

// Ordena por NOME (ordem alfabética)
void orgnome(item *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (strcmp(vetor[j].nome, vetor[menor].nome) < 0)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            item temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

// Ordena por TIPO (ordem alfabética)
void orgtip(item *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (strcmp(vetor[j].tipo, vetor[menor].tipo) < 0)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            item temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

// Ordena por PRIORIDADE (menor → maior)
void orgprio(item *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (vetor[j].prioridade < vetor[menor].prioridade)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            item temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

void buscar_item(item *vetor, int tamanho, int ordNome)
{
    if (!ordNome)
    {
        printf("\n Erro: a busca só funciona se os itens estiverem organizados por nome!\n");
        return;
    }

    if (tamanho == 0)
    {
        printf("A mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    int inicio = 0, fim = tamanho - 1;
    int encontrado = -1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(vetor[meio].nome, nomeBusca);

        if (cmp == 0)
        {
            encontrado = meio;
            break;
        }
        else if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    if (encontrado != -1)
    {
        printf("\nItem encontrado!\n");
        printf("[%d] Nome: %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n",
               encontrado,
               vetor[encontrado].nome,
               vetor[encontrado].tipo,
               vetor[encontrado].quantidade,
               vetor[encontrado].prioridade);
    }
    else
    {
        printf("\nItem não encontrado.\n");
    }
}

int main()
{
    int ordNome = 0;
    item *mochila = NULL; // mochila dinâmica
    int ic = 0;            // quantidade atual de itens
    int opc;

    printf("\tIniciando o jogo...");

    do
    {
        printf("\nQuantidade de itens na mochila %d/10", ic);
        printf("\n1. Colocar item na mochila.\n");
        printf("2. Remover item da mochila.\n");
        printf("3. Visualizar itens.\n");
        printf("4. Ordenar itens.\n");
        printf("5. Buscar um item.\n");
        printf("0. Sair.\n");
        printf(">> Selecione uma opção: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        {
            mochila = realloc(mochila, (ic + 1) * sizeof(item));
            if (mochila == NULL)
            {
                printf("Erro de memória!\n");
                return 1;
            }

            if (ic>=10)
            {
                printf("\nMochila lotada!");
                break;
            }

            printf("\nQual o nome do item? ");
            scanf("%s", mochila[ic].nome);
            printf("Qual o tipo de item? ");
            scanf("%s", mochila[ic].tipo);
            printf("Qual a quantidade? ");
            scanf("%d", &mochila[ic].quantidade);
            printf("Qual a prioridade?(1-3) ");
            scanf("%d", &mochila[ic].prioridade);

            ic++;
            printf("Item adicionado!\n");
            break;
        }
        case 2:
        {
            if (ic == 0)
            {
                printf("Mochila vazia.\n");
                break;
            }

            int a;
            char c;
            printf("Digite o índice do item que deseja remover (0 a %d): ", ic - 1);
            scanf("%d", &a);

            if (a < 0 || a >= ic)
            {
                printf("Índice inválido.\n");
                break;
            }

            printf("É esse item %s que deseja remover?(Y/N): ", mochila[a].nome);
            scanf(" %c", &c); // espaço antes de %c para ignorar \n pendente

            if (c == 'Y' || c == 'y')
            {
                // "puxa" os elementos seguintes
                for (int j = a; j < ic - 1; j++)
                {
                    mochila[j] = mochila[j + 1];
                }
                ic--;

                mochila = realloc(mochila, ic * sizeof(item));
                printf("Item removido!\n");

            } else if (c == 'N' || c == 'n')
            {
                printf("Remoção cancelada.\n");
            } else
            {
                printf("Resposta inválida.\n");
            }
            break;
        }
        case 3:
        {
            if (ic == 0)
            {
                printf("Mochila vazia.\n");
            } else
            {
                printf("\nItens na mochila:\n");
                for (int j = 0; j < ic; j++)
                {
                    printf("[%d] Nome: %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n",
                           j, mochila[j].nome, mochila[j].tipo, mochila[j].quantidade, mochila[j].prioridade);
                }
            }
            break;
        }
        case 4:
        {
            int torg = 0;
            printf("\nComo deseja organizar os itens?\n");
            printf("1. Por nome.\n");
            printf("2. Por tipo.\n");
            printf("3. Por prioridade.\n");
            printf(">> Digite aqui: ");
            scanf("%d", &torg);

            switch (torg)
            {
            case 1:
                orgnome(mochila, ic);
                ordNome=1;
                printf("Itens organizados por nome!\n");
                break;
            case 2:
                orgtip(mochila, ic);
                ordNome=0;
                printf("Itens organizados por tipo!\n");
                break;
            case 3:
                orgprio(mochila, ic);
                ordNome=0;
                printf("Itens organizados por prioridade!\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
            }

            break;
        }
        case 5:
        {
            buscar_item(mochila, ic, ordNome);
            break;
        }
        case 0:
        {
            printf("Saindo...\n");
            break;
        }
        default:
            printf("Opção inválida!\n");
        }  
    } while (opc != 0);

    free(mochila);
    return 0;
}