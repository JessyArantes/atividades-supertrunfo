#include <stdio.h>
#include <string.h>

// Estrutura para armazenar dados da carta
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // já calculada: populacao / area
} Carta;
// Função para calcular densidade demográfica
void calcularDensidade(Carta *carta) {
    if (carta->area != 0) {
        carta->densidadeDemografica = carta->populacao / carta->area;
    } else {
        carta->densidadeDemografica = 0;
    }
}
int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1800.0, 100, 0};
    Carta carta2 = {"Argentina", 45000000, 2780400.0, 450.0, 80, 0};
    // Calcular densidade demográfica para ambas
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);
    int opcao;
    // Menu interativo
    printf("=== Super Trunfo - Comparação de Países ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    // Variáveis para armazenar valores comparados e nome do atributo
    float valor1 = 0, valor2 = 0;
    char nomeAtributo[30];
    // Obter valores conforme opção escolhida
    switch (opcao) {
        case 1:
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            strcpy(nomeAtributo, "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nomeAtributo, "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nomeAtributo, "PIB");
            break;
        case 4:
            valor1 = (float)carta1.pontosTuristicos;
            valor2 = (float)carta2.pontosTuristicos;
            strcpy(nomeAtributo, "Número de pontos turísticos");
            break;
        case 5:
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            strcpy(nomeAtributo, "Densidade demográfica");
            break;
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 1;
    }
    // Exibir dados das cartas e atributo escolhido
    printf("\nComparação de cartas (Atributo: %s):\n\n", nomeAtributo);
    printf("Carta 1 - %s: %.2f\n", carta1.nomePais, valor1);
    printf("Carta 2 - %s: %.2f\n\n", carta2.nomePais, valor2);
    // Lógica de comparação com if-else aninhados
    if (opcao == 5) {
        // Para densidade demográfica, menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Para os demais atributos, maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    return 0;
}
