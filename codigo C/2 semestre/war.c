#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
    int tropasIniciais;
} Territorio;

// Função para atacar com rolagem de dados
void atacar(Territorio* atacante, Territorio* defensor, int* vitoriasSeguidas)
{
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\nDado do atacante (%s): %d | Dado do defensor (%s): %d\n",
           atacante->nome, dadoAtacante, defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor)
    {
        printf("\t--- %s conquistou o território! ---\n", atacante->nome);

        atacante->tropas = defensor->tropas / 2;
        defensor->tropas = defensor->tropas / 2;
        atacante->tropas -= 1;

        strcpy(defensor->cor, atacante->cor); // território muda de cor
        *vitoriasSeguidas += 1;
    } else
    {
        printf("\t--- %s resistiu ao ataque! ---\n", defensor->nome);
        atacante->tropas -= 1;
        *vitoriasSeguidas = 0; // quebra sequência de vitórias
    }
}

// Missões
char* missoes[6] ={
    "Conquistar pelo menos 1 território inimigo.",
    "Eliminar todas as tropas de um território inimigo.",
    "Dobrar as tropas de pelo menos um território.",
    "Reduzir um território inimigo para apenas 1 tropa.",
    "Vencer duas batalhas seguidas.",
    "Somar mais 5 tropas às tropas iniciais."
};

// Atribui missão
void atribuirMissao(char** destino)
{
    int sorteio = rand() % 6; // usando rand para gerar um número aleatório
    *destino = (char*) malloc(strlen(missoes[sorteio]) + 1); // usando memória dinâmica para as missões
    strcpy(*destino, missoes[sorteio]);
}

// função de exibir a missão
void exibirMissao(char* missao)
{
    printf("\n>>> Sua missão é: %s\n", missao);
}

// função que verifica se a missão foi cumprida
int verificarMissao(char* missao, Territorio* mapa, int tamanho, int vitoriasSeguidas)
{
    if (strcmp(missao, missoes[0]) == 0)
    {
        // Conquistar pelo menos 1 território inimigo
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas < mapa[i].tropasIniciais) return 1;
        }
    }
    else if (strcmp(missao, missoes[1]) == 0)
    {
        // Eliminar todas as tropas de um território inimigo
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas == 0) return 1;
        }
    }
    else if (strcmp(missao, missoes[2]) == 0)
    {
        // Dobrar tropas
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas >= mapa[i].tropasIniciais * 2) return 1;
        }
    }
    else if (strcmp(missao, missoes[3]) == 0)
    {
        // Reduzir inimigo a 1 tropa
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas == 1) return 1;
        }
    }
    else if (strcmp(missao, missoes[4]) == 0)
    {
        // Duas vitórias seguidas
        if (vitoriasSeguidas >= 2) return 1;
    }
    else if (strcmp(missao, missoes[5]) == 0)
    {
        // Mais 5 de tropas
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas > mapa[i].tropasIniciais + 5) return 1;
        }
    }
    return 0;
}

// Exibir mapa
void exibirMapa(Territorio* territorios, int n)
{
    printf("\n--- Situação atual dos territórios ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Território %d = Nome: %s | Cor: %s | Tropas: %d\n",
               i+1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
    // toda vez após uma rodada vai ser exibido a situação do mapa
}

// Liberar memória
void liberarMemoria(Territorio* territorios, char* missao)
{
    free(territorios);
    free(missao);
}

int main()
{
    srand(time(NULL));

    printf("\n\t[ Iniciando o jogo War...]\n");

    int n;
    printf("Crie no mínimo 3 territórios"); // pedindo um número mínimo de territórios
    printf("\nQuantos territórios o jogo terá? ");
    scanf("%d", &n);

    if (n<3) //verificando se a condição foi atendida
    {
        printf("Quantidade de territórios inválida");
        return 0;
    }
    
    // criando uma memória dinâmica para os territórios
    Territorio* territorios = (Territorio*) calloc(n, sizeof(Territorio));
    if (territorios == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // iniciando o cadastro
    printf("\n\t|| Criação dos territórios ||\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n--- Território %d ---\n", i+1);
        printf("Nome do exército: ");
        scanf("%s", territorios[i].nome);
        printf("Cor do exército: ");
        scanf("%s", territorios[i].cor);
        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        // criando uma váriavel para a verificação das missões
        territorios[i].tropasIniciais = territorios[i].tropas;
    }

    // atribuindo a missão
    char* missaoJogador = NULL;
    atribuirMissao(&missaoJogador);
    exibirMissao(missaoJogador);

    int vitoriasSeguidas = 0; // outra váriavel para missão
    // váriavel usada para manter o loop ativo
    // enquanto for 1(true) o while tá rodando
    int jogoAtivo = 1;

    while (jogoAtivo)
    {
        int atc, def;
        exibirMapa(territorios, n);

        printf("\nEscolha o território atacante (1-%d): ", n);
        scanf("%d", &atc);
        printf("Escolha o território defensor (1-%d): ", n);
        scanf("%d", &def);

        // verificando se o território para ataque e defesa estão corretos
        if (atc < 1 || atc > n || def < 1 || def > n || atc == def)
        {
            printf("Movimento inválido!\n");
            continue;
        }

        atacar(&territorios[atc-1], &territorios[def-1], &vitoriasSeguidas);

        // verifica se a missão foi cumprinda
        if (verificarMissao(missaoJogador, territorios, n, vitoriasSeguidas))
        {
            printf("\n>>> Você cumpriu sua missão: %s <<<\n", missaoJogador);
            jogoAtivo = 0; // se foi cumprinda, atribui 0(false) e encerra o loop
        }
    }

    // liberando a memória
    liberarMemoria(territorios, missaoJogador);
    return 0;
}