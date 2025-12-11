#include <stdio.h>

// criando uma função para inserir as habilidades no tabuleiro
void inserir_forma(int tabuleiro[10][10], int forma[3][5], int lin_inicio, int col_inicio)
{
    for (int x=0; x<3; x++)
    {
        for (int y=0; y<5; y++)
        {
            int lin = lin_inicio + x;
            int col = col_inicio + y;

            if (lin < 10 && col < 10) // aqui verifica se as coordenadas passadas são menores que 10
            {
                if (forma[x][y] == 1) // aqui o adiciona a matriz da habilidade
                {
                    if (tabuleiro[lin][col] == 3) // aqui verifica se o valor da coordenada é 3
                    {
                        tabuleiro[lin][col] = 5;
                    } else
                    {
                        tabuleiro[lin][col] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    // criando as habilidades
    int triangulo[3][5]=
    {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int cruz[3][5]=
    {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    int losango[3][5]=
    {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    // criando o tabuleiro
    int tabuleiro[10][10] = {0};// atribuindo o valor 0 para cada cordenada do tabuleiro
    char cabecalho[10] = {'a','b','c','d','e','f','g','h','i','j'};

    // aqui tô percorendo o tabuleiro e criando os valores
    for (int x=0; x<=9; x++)
    {
        for (int y=0; y<=9; y++)
        {
            if (x==9 && (y>1 && y<5)) //usando o if para colocar a localização dos 3s
            {
                tabuleiro[x][y] = 3;
            } else if ((x>1 && x<5) && y==2)
            {
                tabuleiro[x][y] = 3;
            } else if ((x>=0) && (x<3) && (x+y==9))
            {
                tabuleiro[x][y] = 3;
            } else if ((x==3 && y==4) || (x==4 && y==5) || (x==5 && y==6))
            {
                tabuleiro[x][y] = 3;
            }
        }
    }

    // aqui eu tô usando a função para colocar as formas das habilidades no tabuleiro 
    inserir_forma(tabuleiro, triangulo, 0, 0);
    inserir_forma(tabuleiro, cruz, 5, 4);
    inserir_forma(tabuleiro, losango, 7, 0);

    // aqui tô usando o for para imprimir o cabeçalho do tabuleiro
    printf("\t\tTABULEIRO\n   ");
    for (int x=0; x<=9; x++)
    {
        printf(" %c ", cabecalho[x]);
    }
    printf("\n");

    // aqui tô imprimindo os valores de cada indice do tabuleiro
    for (int x=0; x<=9; x++)
    {
        printf(" %d ", x); // aqui tô imprimindo os indices de cada linha
        for (int y=0; y<=9; y++)
        {
            printf(" %d ", tabuleiro[x][y]);
        }
        printf("\n");
    }
    return 0;
}