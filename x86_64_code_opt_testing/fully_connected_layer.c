#include <stdio.h>
#include <time.h>
#include "matrixes.h"

int fully_connected_layer() {

    // 3. Executando os 3 Passos do Forward Pass:

    // Passo 1: Multiplicacao Matriz-Vetor (z = W * x)
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
    // for (int i = 0; i < N; i++) {
    //     z[i] = z[i] + b[i]; // Adiciona o bias
    // }

    // // Passo 3: Funcao de Ativacao (a = ReLU(z))
    // for (int i = 0; i < N; i++) {
    //     a[i] = (z[i] > 0.0f) ? z[i] : 0.0f;
    // }

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
