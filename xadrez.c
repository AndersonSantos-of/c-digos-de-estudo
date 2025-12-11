#include <stdio.h>
// att
void rainha(int move)
{
    if(move>8)
    {
        printf("Quantidade de casas inválidas");
    }else
    {
         if(move>0)
        {
            printf("A Rainha se moveu uma casa para BAIXO\n");
            rainha(move-1);
        }
    }
   
}

void torre(int move)
{
    if(move>8)
    {
        printf("Quantidade de casas inválidas");
    }else
    {
        if(move>0)
        {
            printf("A Torre se moveu uma casa para CIMA\n");
            torre(move-1);
        }
    }
}

void bispo(int move)
{
    if(move>8)
    {
        printf("Quantidade de casas inválidas");
    }else
    {   
        if(move>0)
        {
            printf("O Bispo se moveu uma casa para BAIXO\n");
            printf("O Bispo se moveu uma casa para a ESQUERDA\n");
            bispo(move-1);
        }
    
    }
}

int main(){
    
    int mov, x, escolha;

    printf("    Escolha qual peça mover\n");
    printf("1.Bispo\n2.Torre\n3.Rainha\n4.Cavalo\n");
    printf("Digite aqui: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:

        printf("\nDigite quantas vezes quer mover a peça: ");
        scanf("%d", &mov);

         for (x=1; x<=mov; x++)
        {
            for(int i=1; i==1; i++)
            {
                printf("O Bispo se moveu uma casa para a DIREITA\n");
            }
            printf("O Bispo se moveu uma casa para CIMA\n");
            
        }
        
    break;
    case 2:

        printf("\nDigite quantas vezes quer mover a peça: ");
        scanf("%d", &mov);

        torre(mov);

    break;
    case 3:
    
        printf("\nDigite quantas vezes quer mover a peça: ");
        scanf("%d", &mov);

        rainha(mov);

    break;
    case 4:

         for (x=1; x==1; x--)
        {

            for ( int i=1, j= 1; i<=2, j<=2; i++,j++)
            {
                printf("O Cavalo se moveu uma casa para cima\n");
            }
            
            printf("O Cavalo se moveu uma casa para a direita\n");
            
        }
        
        
    break;
    default:
        printf("Peça invalida");
    break;
    }

    return 0;
}