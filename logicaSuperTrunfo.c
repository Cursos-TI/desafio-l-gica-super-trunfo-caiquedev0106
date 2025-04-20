#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao;             // Em milhões
    int area;                  // Em mil km²
    int densidade_demografica; // Pessoas por km²
    int pib;                   // Em bilhões de dólares
} Carta;

// Função para exibir os atributos disponíveis
void mostrarMenuAtributos(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1. População\n");
    if (ignorar != 2) printf("2. Área\n");
    if (ignorar != 3) printf("3. Densidade Demográfica\n");
    if (ignorar != 4) printf("4. PIB\n");
    printf("Opção: ");
}

// Função para obter o valor do atributo de uma carta
int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade_demografica;
        case 4: return c.pib;
        default: return -1;
    }
}

// Função para mostrar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213, 8516, 25, 1445};
    Carta carta2 = {"Japão", 126, 378, 334, 4937};

    int atributo1, atributo2;
    
    // Seleção do primeiro atributo
    mostrarMenuAtributos(0);
    scanf("%d", &atributo1);
    while (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida. Tente novamente.\n");
        mostrarMenuAtributos(0);
        scanf("%d", &atributo1);
    }

    // Seleção do segundo atributo
    mostrarMenuAtributos(atributo1);
    scanf("%d", &atributo2);
    while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida. Tente novamente.\n");
        mostrarMenuAtributos(atributo1);
        scanf("%d", &atributo2);
    }

    // Obter valores dos atributos
    int v1_attr1 = obterValorAtributo(carta1, atributo1);
    int v2_attr1 = obterValorAtributo(carta2, atributo1);
    int v1_attr2 = obterValorAtributo(carta1, atributo2);
    int v2_attr2 = obterValorAtributo(carta2, atributo2);

    // Mostrar valores dos atributos
    printf("\n--- Comparação de Cartas ---\n");
    printf("Cartas: %s vs %s\n\n", carta1.nome, carta2.nome);
    printf("%s:\n  %s: %d\n  %s: %d\n", carta1.nome, nomeAtributo(atributo1), v1_attr1, nomeAtributo(atributo2), v1_attr2);
    printf("%s:\n  %s: %d\n  %s: %d\n", carta2.nome, nomeAtributo(atributo1), v2_attr1, nomeAtributo(atributo2), v2_attr2);

    // Comparar cada atributo
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (atributo1 == 3) ? (v1_attr1 < v2_attr1) : (v1_attr1 > v2_attr1);
    pontos2 += (atributo1 == 3) ? (v2_attr1 < v1_attr1) : (v2_attr1 > v1_attr1);

    pontos1 += (atributo2 == 3) ? (v1_attr2 < v2_attr2) : (v1_attr2 > v2_attr2);
    pontos2 += (atributo2 == 3) ? (v2_attr2 < v1_attr2) : (v2_attr2 > v1_attr2);

    // Soma total dos atributos
    int soma1 = v1_attr1 + v1_attr2;
    int soma2 = v2_attr1 + v2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", carta1.nome, soma1);
    printf("%s: %d\n", carta2.nome, soma2);

    // Determinar vencedor
    printf("\nResultado da rodada:\n");
    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}