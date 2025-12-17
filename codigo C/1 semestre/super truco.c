#include <stdio.h>
// att
int main() {
    
    // fiz um pequeno titulo
    printf("\n    CRIANDO AS CARTAS DO JOGO\n");
    printf("\n  Montando a carta número 1\n");
    printf("\n");

    // definindo as variaveis numero 1
    char estado;
    char codigo[50];
    char cidade[50];
    int populacao;
    float area, pib, densidade, pib_percapita;
    int p_turistico;

    printf("Digite o estado da carta com uma letra de A-H: ");
    scanf("%c",&estado);
    printf("Digite a letra do estado seguido por um número entre 01, 02, 03 e 04: ");
    scanf("%s",&codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s",&cidade);
    printf("Qual a população da cidade escolhida? ");
    scanf("%d",&populacao);
    printf("Qual a área da cidade em km²? ");
    scanf("%f",&area);
    printf("Qual é o pib da cidade? ");
    scanf("%f",&pib);
    printf("Quantos pontos turisticos tem nessa cidade? ");
    scanf("%d",&p_turistico);
    printf("\n");

    //calculando o valor da densidade e pib per capita pra carta 1
    densidade= (float) populacao/area;
    pib_percapita= (float) pib/populacao;

    // mostrando o resultado da numero 1
    printf("O estado da sua carta é: %c\n", estado);
    printf("Seu código é: %c%s\n", estado, codigo);
    printf("A cidade escolhida foi: %s\n", cidade);
    printf("A população da sua cidade é: %d pessoas\n", populacao);
    printf("Sua cidade tem uma de área de: %.3f km²\n",area);
    printf("A cidade escolhida tem um PIB de: %.3f reais\n", pib);
    printf("O número de pontos turisticos na cidade é: %d\n", p_turistico);
    printf("Sua cidade tem uma densidade de: %.3f pessoas por km²\n", densidade);
    printf("O PIB per capita é: %.3f reais por pessoa\n", pib_percapita);
    
    // aqui começa a montagem da carta 2
    printf("\n  Montando a carta número 2\n");
    printf("\n");

    // é basicamente o mesmo codigo que na primeira so mudei o nome das variaveis
    char estado2;
    char codigo2[50];
    char cidade2[50];
    int populacao2;
    float area2, pib2, densidade2, pib_percapita2;
    int p_turistico2;

    printf("Digite o estado da carta com uma letra de A-H: ");
    scanf(" %c",&estado2);
    printf("Digite a letra do estado seguido por um número entre 01, 02, 03 e 04: ");
    scanf("%s",&codigo2);
    printf("Digite o nome da cidade: ");
    scanf("%s",&cidade2);
    printf("Qual a população da cidade escolhida? ");
    scanf("%d",&populacao2);
    printf("Qual a área da cidade em km²? ");
    scanf("%f",&area2);
    printf("Qual é o pib da cidade? ");
    scanf("%f",&pib2);
    printf("Quantos pontos turisticos tem nessa cidade? ");
    scanf("%d",&p_turistico2);
    printf("\n");

    // calculando densidade e pib per capita pra carta 2
    densidade2= (float) populacao2/area2;
    pib_percapita2= (float) pib2/populacao2;
    
    // exibindo o resultado da carta 2
    printf("O estado da sua carta é: %c\n", estado2);
    printf("Seu código é: %c%s\n", estado2, codigo2);
    printf("A cidade escolhida foi: %s\n", cidade2);
    printf("A população da sua cidade é de: %d pessoas\n", populacao2);
    printf("Sua cidade tem uma de área de: %.3f km²\n",area2);
    printf("A cidade escolhida tem um PIB de: %.3f reais\n", pib2);
    printf("O número de pontos turisticos na cidade é: %d\n", p_turistico2);
    printf("Sua cidade tem uma densidade de: %.3f pessoas por km²\n", densidade2);
    printf("O PIB per capita é: %.3f reais por pessoa\n", pib_percapita2);
    printf("\n");

    // definindo mais variaveis
    float super_poderC1,super_poderC2, inverso_densidade, inverso_densidade2;//super_poderC1= super poder da carta 1, o mesmo vale pra C2

    inverso_densidade=1/densidade;
    inverso_densidade2=1/densidade2;// eu não entendi bem oq seria o inverso da densidade, na matematica o inverso de uma conta é 1 dividido por ela, então fiz isso

    super_poderC1= (float) populacao+area+pib+pib_percapita+p_turistico+inverso_densidade;// somando os super poderes
    super_poderC2= (float) populacao2+area2+pib2+pib_percapita2+p_turistico2+inverso_densidade2;
    printf("O super poder da carta 1 é: %f\n", super_poderC1);
    printf("O super poder da carta 2 é: %f\n", super_poderC2);// exibindo o super poder
    printf("\n");

    int escolha1, escolha12, escolha2, escolha22;
    float valor1, valor12, valor2, valor22; // para armazenar os valores escolhidos

    // criando o primeiro menu e passando as orientações
    printf("\nDIGITE UM NÚMERO DE 1 A 6 PARA SELECIONAR O PRIMEIRO ATRIBUTO DA CARTA 1 QUE DESEJA COMPARAR\n");
    printf("1: População\n2: Área\n3: PIB\n4: Densidade\n5: PIB per capita\n6: Pontos turisticos\n");
    
    printf("Digite aqui: ");
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1:
            printf("Você escolheu o atributo população: %d\n", populacao);
            valor1 = populacao;
        break;
        case 2:
            printf("Você escolheu o atributo área: %f\n", area);
            valor1 = area;
        break;
        case 3:
            printf("Você escolheu o atributo PIB: %f\n", pib);
            valor1 = pib;
        break;
        case 4:
            printf("Você escolheu o atributo densidade: %f\n", densidade);
            valor1 = densidade;
        break;
        case 5:
            printf("Você escolheu o atributo PIB per capita: %f\n", pib_percapita);
            valor1 = pib_percapita;
        break;
        case 6:
            printf("Você escolheu o atributo pontos turísticos: %d\n", p_turistico);
            valor1 = p_turistico;
        break;
        default:
             printf("Opção inválida\n");
    }

    printf("\nDIGITE UM NÚMERO DE 1 A 6 PARA SELECIONAR O SEGUNDO ATRIBUTO DA CARTA 1 QUE DESEJA COMPARAR\n");
    printf("1: População\n2: Área\n3: PIB\n4: Densidade\n5: PIB per capita\n6: Pontos turisticos\n");

    printf("Digite aqui: ");
    scanf("%d", &escolha12);

    
    switch (escolha12) {
        case 1:
            printf("Você escolheu o atributo população: %d\n", populacao);
            valor12 = populacao;
        break;
        case 2:
            printf("Você escolheu o atributo área: %f\n", area);
            valor12 = area;
        break;
        case 3:
            printf("Você escolheu o atributo PIB: %f\n", pib);
            valor12 = pib;
        break;
        case 4:
            printf("Você escolheu o atributo densidade: %f\n", densidade);
            valor12 = densidade;
        break;
        case 5:
            printf("Você escolheu o atributo PIB per capita: %f\n", pib_percapita);
            valor12 = pib_percapita;
        break;
        case 6:
            printf("Você escolheu o atributo pontos turísticos: %d\n", p_turistico);
            valor12 = p_turistico;
        break;
        default:
             printf("Opção inválida\n");
    }


    // criando o segundo menu switch
    printf("\nDIGITE UM NÚMERO DE 1 A 6 PARA SELECIONAR O PRIMEIRO ATRIBUTO DA CARTA 2 QUE DESEJA COMPARAR\n");
    printf("\n1: População\n2: Área\n3: PIB\n4: Densidade\n5: PIB per capita\n6: Pontos turisticos\n");
    
    printf("Digite aqui: ");
    scanf("%d", &escolha2);

    switch (escolha2) {
        case 1:
             printf("Você escolheu o atributo população: %d\n", populacao2);
             valor2 = populacao2;
        break;
        case 2:
            printf("Você escolheu o atributo área: %f\n", area2);
            valor2 = area2;
        break;
        case 3:
            printf("Você escolheu o atributo PIB: %f\n", pib2);
            valor2 = pib2;
        break;
        case 4:
            printf("Você escolheu o atributo densidade: %f\n", densidade2);
            valor2 = densidade2;
        break;
        case 5:
        printf("Você escolheu o atributo PIB per capita: %f\n", pib_percapita2);
        valor2 = pib_percapita2;
        break;
        case 6:
            printf("Você escolheu o atributo pontos turísticos: %d\n", p_turistico2);
            valor2 = p_turistico2;
        break;
        default:
             printf("Opção inválida\n");
    }

    printf("\nDIGITE UM NÚMERO DE 1 A 6 PARA SELECIONAR O SEGUNDO ATRIBUTO DA CARTA 2 QUE DESEJA COMPARAR\n");
    printf("\n1: População\n2: Área\n3: PIB\n4: Densidade\n5: PIB per capita\n6: Pontos turisticos\n");
    
    printf("Digite aqui: ");
    scanf("%d", &escolha22);

    switch (escolha22) {
        case 1:
             printf("Você escolheu o atributo população: %d\n", populacao2);
             valor22 = populacao2;
        break;
        case 2:
            printf("Você escolheu o atributo área: %f\n", area2);
            valor22 = area2;
        break;
        case 3:
            printf("Você escolheu o atributo PIB: %f\n", pib2);
            valor22 = pib2;
        break;
        case 4:
            printf("Você escolheu o atributo densidade: %f\n", densidade2);
            valor22 = densidade2;
        break;
        case 5:
        printf("Você escolheu o atributo PIB per capita: %f\n", pib_percapita2);
        valor22 = pib_percapita2;
        break;
        case 6:
            printf("Você escolheu o atributo pontos turísticos: %d\n", p_turistico2);
            valor22 = p_turistico2;
        break;
        default:
             printf("Opção inválida\n");
    }

    if ((escolha1 == escolha12) || (escolha2==escolha22)){
        printf("Atributos iguais.\n");
        printf("O atributo de uma carta escolhido na primeira vez não pode ser escolhido na segunda vez pela mesma carta\n");
    }else{
        //  fazendo a comparação dos valores
        printf("\nO estado escolhido foi: %c\n", estado);
        printf("O outro estado escolhido foi: %c\n", estado2);

        printf("\nComparando os primeiros atributos escolhidos\n");

        if((valor1==densidade) && (valor2==densidade2)) { // aqui estou verificando se as duas opções escolhidas foram a densidade
            if (valor1<valor2){
                 printf("Carta 1 venceu!");
            }else if(valor1>valor2){
                printf("Carta 2 venceu!");
            }else{
                printf("Empate!");
            }

        } else if (valor1 > valor2) {
        printf("A carta 1 tem o atributo maior!\n");
        } else if (valor2 > valor1) {
        printf("A carta 2 tem o atributo maior!\n");
        } else  {
        printf("Os dois atributos são iguais!\n");
        }

        printf("Comparando os segundos atributos escolhidos\n");

        if((valor12==densidade) && (valor22==densidade2)) { // aqui estou verificando se as duas opções escolhidas foram a densidade
            if (valor12<valor22){
                 printf("Carta 1 venceu!");
            }else if(valor12>valor22){
                printf("Carta 2 venceu!");
            }else{
                printf("Empate!");
            }

        } else if (valor12 > valor22) {
        printf("A carta 1 tem o atributo maior!\n");
        } else if (valor22 > valor12) {
        printf("A carta 2 tem o atributo maior!\n");
        } else  {
        printf("Os dois atributos são iguais!\n");
        }

        float soma1, soma2;

        soma1 = valor1 + valor12;
        soma2 = valor2 + valor22;

        printf("\nSoma dos atributos da carta 1: %f\n", soma1);
        printf("Soma dos atributos da carta 2: %f\n", soma2);


        soma1 > soma2 ? printf("Carta 1 venceu!\n") : printf("Carta 2 venceu!\n");
        soma1 == soma2 ? printf("Houve empate") : printf("Sem empate na soma dos atributos");
    }

    return 0;

}