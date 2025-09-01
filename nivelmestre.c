#include <stdio.h>
#include <string.h>

// Estrutura para armazenar dados da carta
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // populacao / area
} Carta;

// Função para calcular densidade demográfica
void calcularDensidade(Carta *carta) {
    if (carta->area != 0) {
        carta->densidadeDemografica = carta->populacao / carta->area;
    } else {
        carta->densidadeDemografica = 0;
    }
}

// Função para exibir o menu de atributos, ignorando o atributo já escolhido
void exibirMenu(int atributoExcluido) {
    printf("\nEscolha o atributo para comparar:\n");
    if (atributoExcluido != 1) printf("1 - População\n");
    if (atributoExcluido != 2) printf("2 - Área\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Número de pontos turísticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade demográfica\n");
    printf("Digite a opção desejada: ");
}

// Função para obter o valor do atributo da carta conforme código do atributo
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para obter o nome do atributo conforme código
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de pontos turísticos";
        case 5: return "Densidade demográfica";
        default: return "Atributo desconhecido";
    }
}

// Função para comparar dois valores conforme regra do atributo
// Retorna 1 se carta1 vence, 2 se carta2 vence, 0 se empate
int compararValores(float val1, float val2, int atributo) {
    if (atributo == 5) { // Densidade demográfica: menor vence
        if (val1 < val2) return 1;
        else if (val2 < val1) return 2;
        else return 0;
    } else { // Demais atributos: maior vence
        if (val1 > val2) return 1;
        else if (val2 > val1) return 2;
        else return 0;
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1800.0, 100, 0};
    Carta carta2 = {"Argentina", 45000000, 2780400.0, 450.0, 80, 0};

    // Calcular densidade demográfica para ambas
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1 = 0, atributo2 = 0;
    int valido = 0;

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        if (scanf("%d", &atributo1) != 1) {
            printf("Entrada inválida! Por favor, digite um número.\n");
            while(getchar() != '\n'); // limpar buffer
            continue;
        }
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
        } else {
            valido = 1;
        }
    } while (!valido);

    // Escolha do segundo atributo (diferente do primeiro)
    valido = 0;
    do {
        exibirMenu(atributo1);
        if (scanf("%d", &atributo2) != 1) {
            printf("Entrada inválida! Por favor, digite um número.\n");
            while(getchar() != '\n'); // limpar buffer
            continue;
        }
        if (atributo2 < 1 || atributo2 > 5) {
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
        } else if (atributo2 == atributo1) {
            printf("Você já escolheu esse atributo. Escolha outro diferente.\n");
        } else {
            valido = 1;
        }
    } while (!valido);

    // Obter valores dos atributos para as duas cartas
    float val1_atrib1 = obterValorAtributo(carta1, atributo1);
    float val2_atrib1 = obterValorAtributo(carta2, atributo1);
    float val1_atrib2 = obterValorAtributo(carta1, atributo2);
    float val2_atrib2 = obterValorAtributo(carta2, atributo2);

    // Comparar individualmente os atributos
    int vencedor_atrib1 = compararValores(val1_atrib1, val2_atrib1, atributo1);
    int vencedor_atrib2 = compararValores(val1_atrib2, val2_atrib2, atributo2);

    // Calcular soma dos valores para cada carta
    float soma_carta1 = val1_atrib1 + val1_atrib2;
    float soma_carta2 = val2_atrib1 + val2_atrib2;

    // Exibir resultado detalhado
    printf("\n=== Resultado da Comparação ===\n");
    printf("Cartas: %s x %s\n\n", carta1.nomePais, carta2.nomePais);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("  %s: %.2f\n", carta1.nomePais, val1_atrib1);
    printf("  %s: %.2f\n", carta2.nomePais, val2_atrib1);
    if (vencedor_atrib1 == 1) printf("  Vencedor do atributo 1: %s\n\n", carta1.nomePais);
    else if (vencedor_atrib1 == 2) printf("  Vencedor do atributo 1: %s\n\n", carta2.nomePais);
    else printf("  Empate no atributo 1\n\n");

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("  %s: %.2f\n", carta1.nomePais, val1_atrib2);
    printf("  %s: %.2f\n", carta2.nomePais, val2_atrib2);
    if (vencedor_atrib2 == 1) printf("  Vencedor do atributo 2: %s\n\n", carta1.nomePais);
    else if (vencedor_atrib2 == 2) printf("  Vencedor do atributo 2: %s\n\n", carta2.nomePais);
    else printf("  Empate no atributo 2\n\n");

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nomePais, soma_carta1);
    printf("  %s: %.2f\n\n", carta2.nomePais, soma_carta2);

    // Determinar vencedor final pela soma usando operador ternário
    const char* resultadoFinal = (soma_carta1 > soma_carta2) ? carta1.nomePais :
                                 (soma_carta2 > soma_carta1) ? carta2.nomePais : "Empate";

    if (strcmp(resultadoFinal, "Empate") == 0) {
        printf("Resultado final: Empate!\n");
    } else {
        printf("Resultado final: %s venceu!\n", resultadoFinal);
    }

    return 0;
}