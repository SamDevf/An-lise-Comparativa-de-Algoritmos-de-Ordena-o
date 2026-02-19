#include <stdio.h>
#include <time.h>

#define TAM1 100
#define TAM2 1000
#define TAM3 10000

long long comparacoes;
long long movimentacoes;

void criarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int vetor[], int tamanho) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                movimentacoes++;
            }
        }
    }
}

void selectionSort(int vetor[], int tamanho) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            comparacoes++;
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            movimentacoes++;
        }
    }
}

void testarAlgoritmo(void (*algoritmo)(int[], int), char nome[], int tamanho) {
    int vetor[tamanho];
    clock_t inicio, fim;
    double tempo_ms;

    criarVetor(vetor, tamanho);

    inicio = clock();
    algoritmo(vetor, tamanho);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("%-15s | %-6d | %-10.2f | %-15lld | %-15lld\n",
           nome, tamanho, tempo_ms, comparacoes, movimentacoes);
}

int main() {

    printf("Algoritmo       | Tamanho | Tempo (ms) | Comparacoes     | Movimentacoes\n");
    printf("--------------------------------------------------------------------------\n");

    testarAlgoritmo(bubbleSort, "Bubble Sort", TAM1);
    testarAlgoritmo(bubbleSort, "Bubble Sort", TAM2);
    testarAlgoritmo(bubbleSort, "Bubble Sort", TAM3);

    testarAlgoritmo(selectionSort, "Selection Sort", TAM1);
    testarAlgoritmo(selectionSort, "Selection Sort", TAM2);
    testarAlgoritmo(selectionSort, "Selection Sort", TAM3);

    return 0;
}
