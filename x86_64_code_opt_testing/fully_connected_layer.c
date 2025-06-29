#include <stdio.h>
#include <time.h>
#include "matrixes.h"

int fully_connected_layer() {

    // 3. Executando os 3 Passos do Forward Pass:

    // Passo 1: Multiplicacao Matriz-Vetor (z = W * x)
    // printf("Passo 1: Multiplicacao Matriz-Vetor (W * x)...\n");
    for (int i = 0; i < N; i++) { // Para cada neuronio de saida
        float sum[4] = {0.0f, 0.0f, 0.0f, 0.0f}; // Inicializa a soma para cada grupo de 4 elementos
        for (int j = 0; j < N; j=j+4) { // Multiplica linha i de W por vetor x
            sum[0] += W[i][j] * x[j];
            sum[1] += W[i][j+1] * x[j+1];
            sum[2] += W[i][j+2] * x[j+2];
            sum[3] += W[i][j+3] * x[j+3];
        }
        z[i] = sum[0] + sum[1] + sum[2] + sum[3]; // Soma os produtos
    }

    // Passo 2: Adicao do Bias (z = z + b)
    for (int i = 0; i < N; i++) {
        z[i] = z[i] + b[i]; // Adiciona o bias
    }

    // Passo 3: Funcao de Ativacao (a = ReLU(z))
    for (int i = 0; i < N; i++) {
        a[i] = (z[i] > 0.0f) ? z[i] : 0.0f;
    }

    return 0;
}

int main(){
   // get the start time
   clock_t start_time = clock();

   for(int i=0; i < 250000; i++) {
       fully_connected_layer();
   }

   // get the end time
   clock_t end_time = clock();
  
   // calculate the elapsed time in seconds
   double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
   printf("Tempo total de execucao: %.2f segundos\n", elapsed_time);
}
