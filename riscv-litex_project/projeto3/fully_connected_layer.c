#include <stdio.h>
#include "matrixes.h"

void fully_connected_layer(void);

void fully_connected_layer(void) {

    // 3. Executando os 3 Passos do Forward Pass:

    // Passo 1: Multiplicacao Matriz-Vetor (z = W * x)
    printf("Passo 1: Multiplicacao Matriz-Vetor (W * x)...\n");
    for (int i = 0; i < N; i++) { // Para cada neuronio de saida
        float sum = 0.0f;

        // Multiplica linha i de W por vetor x
        for (int j = 0; j < N; j++) { 
            sum += W[i][j] * x[j];
        }
        // Armazena o resultado em z[i]

        z[i] = sum;    
    }

    // Passo 2: Adicao do Bias (z = z + b)
    printf("Passo 2: Adicao do Bias (z + b)...\n");
    for (int i = 0; i < N; i++) {
        z[i] = z[i] + b[i]; // Adiciona o bias
    }

    // Passo 3: Funcao de Ativacao (a = ReLU(z))
    // Usando ReLU (Rectified Linear Unit) como exemplo: max(0, z)
    printf("Passo 3: Aplicacao da Funcao de Ativacao (ReLU)...\n");
    for (int i = 0; i < N; i++) {
        a[i] = (z[i] > 0.0f) ? z[i] : 0.0f;
    }

}
