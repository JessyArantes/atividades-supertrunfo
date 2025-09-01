#include stdio.h

// Definição da estrutura para armazenar os dados da carta
typedef struct {
    char estado[3];           // Sigla do estado (ex: "SP")
    char codigo[10];          // Código da carta
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // População
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int pontosTuristicos;     // Número de pontos turísticos
    float densidadePop;       // Densidade populacional (população / área)
    float pibPerCapita;       // PIB per capita (pib / população)
} Carta;
// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(Carta *carta) {
    if (carta->area != 0) {
        carta->densidadePop = carta->populacao / carta->area;
    } else {
        carta->densidadePop = 0;
    }
    if (carta->populacao != 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}
int main() {
    // Definição das duas cartas com dados pré-definidos
    Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 700.0, 50, 0, 0
    };
    Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6000000, 1182.3, 300.0, 40, 0, 0
    };
    // Calcular densidade populacional e PIB per capita para ambas as cartas
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);
    // Escolha do atributo para comparação (alterar aqui para outro atributo)
    // Opções: "populacao", "area", "pib", "densidadePop", "pibPerCapita"
    const char atributoComparar[] = "populacao";
    // Variáveis para armazenar os valores dos atributos a comparar
    float valorCarta1 = 0, valorCarta2 = 0;
    // Obter os valores do atributo escolhido
    if (strcmp(atributoComparar, "populacao") == 0) {
        valorCarta1 = (float)carta1.populacao;
        valorCarta2 = (float)carta2.populacao;
    } else if (strcmp(atributoComparar, "area") == 0) {
        valorCarta1 = carta1.area;
        valorCarta2 = carta2.area;
    } else if (strcmp(atributoComparar, "pib") == 0) {
        valorCarta1 = carta1.pib;
        valorCarta2 = carta2.pib;
    } else if (strcmp(atributoComparar, "densidadePop") == 0) {
        valorCarta1 = carta1.densidadePop;
        valorCarta2 = carta2.densidadePop;
    } else if (strcmp(atributoComparar, "pibPerCapita") == 0) {
        valorCarta1 = carta1.pibPerCapita;
        valorCarta2 = carta2.pibPerCapita;
    } else {
        printf("Atributo para comparação inválido.\n");
        return 1;
    }
    // Exibir os valores calculados para densidade e PIB per capita
    printf("Carta 1 - %s (%s):\n", carta1.nomeCidade, carta1.estado);
    printf("  População: %d\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area);
    printf("  PIB: %.2f bilhões\n", carta1.pib);
    printf("  Pontos turísticos: %d\n", carta1.pontosTuristicos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta1.densidadePop);
    printf("  PIB per capita: %.6f bilhões por habitante\n\n", carta1.pibPerCapita);
    printf("Carta 2 - %s (%s):\n", carta2.nomeCidade, carta2.estado);
    printf("  População: %d\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area);
    printf("  PIB: %.2f bilhões\n", carta2.pib);
    printf("  Pontos turísticos: %d\n", carta2.pontosTuristicos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta2.densidadePop);
    printf("  PIB per capita: %.6f bilhões por habitante\n\n", carta2.pibPerCapita);
    // Exibir o atributo usado na comparação
    printf("Comparação de cartas (Atributo: %s):\n\n", atributoComparar);
    // Exibir os valores do atributo para as duas cartas
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valorCarta2);
    // Determinar o vencedor
    // Para densidade populacional, menor valor vence
    if (strcmp(atributoComparar, "densidadePop") == 0) {
        if (valorCarta1 < valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 < valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Para os demais atributos, maior valor vence
        if (valorCarta1 > valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 > valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    return 0

    }

    