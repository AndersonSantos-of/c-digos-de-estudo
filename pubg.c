#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    char tipo[30];
    int quantidade;
} item;

int main()
{
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
        printf("4. Selecionar um item.\n");
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
                    printf("[%d] Nome: %s | Tipo: %s | Quantidade: %d\n",
                           j, mochila[j].nome, mochila[j].tipo, mochila[j].quantidade);
                }
            }
            break;
        }
        case 4:
        {
            if (ic == 0)
            {
                printf("Mochila vazia\n");
                break;
            }

            char slc[30];
            int encontrado = 0;

            printf("\nDigite o nome do item que deseja selecionar: ");
            scanf("%s", slc);

            for (int i = 0; i < ic; i++)
            {
                if (strcmp(mochila[i].nome, slc) == 0)
                {
                    printf(">>> %s selecionado!\n", mochila[i].nome);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
                printf("Item não encontrado!\n");
            
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