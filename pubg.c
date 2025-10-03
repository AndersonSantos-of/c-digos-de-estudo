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
    item *cadastro = NULL; // mochila dinâmica
    int ic = 0;            // quantidade atual de itens
    int opc;

    printf("\tIniciando o jogo...");

    do
    {
        printf("\n1. Colocar item na mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Visualizar itens da mochila\n");
        printf("0. Sair\n");
        printf(">> Selecione uma opção: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        {
            cadastro = realloc(cadastro, (ic + 1) * sizeof(item));
            if (cadastro == NULL)
            {
                printf("Erro de memória!\n");
                return 1;
            }

            printf("Qual o nome do item? ");
            scanf("%s", cadastro[ic].nome);

            printf("Qual o tipo de item? ");
            scanf("%s", cadastro[ic].tipo);

            printf("Qual a quantidade? ");
            scanf("%d", &cadastro[ic].quantidade);

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

            printf("É esse item %s que deseja remover?(Y/N): ", cadastro[a].nome);
            scanf(" %c", &c); // espaço antes de %c para ignorar \n pendente

            if (c == 'Y' || c == 'y')
            {
                // "puxa" os elementos seguintes
                for (int j = a; j < ic - 1; j++)
                {
                    cadastro[j] = cadastro[j + 1];
                }
                ic--;

                cadastro = realloc(cadastro, ic * sizeof(item));
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
                           j, cadastro[j].nome, cadastro[j].tipo, cadastro[j].quantidade);
                }
            }
            break;
        }
        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (opc != 0);

    free(cadastro);
    return 0;
}