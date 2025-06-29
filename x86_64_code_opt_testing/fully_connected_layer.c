#include <stdio.h>
#include <time.h>
#include <stdint.h> // Para usar int32_t e int64_t
#include "matrixes.h"

// Define o número de bits para a parte fracionária
#define FRACTIONAL_BITS 16
// Calcula o fator de escala (2^FRACTIONAL_BITS)
#define SCALE_FACTOR (1 << FRACTIONAL_BITS)

int fully_connected_layer() {

    // 3. Executando os 3 Passos do Forward Pass:

    // Passo 1: Multiplicacao Matriz-Vetor (z = W * x)
    for (int i = 0; i < N; i++) { // Para cada neuronio de saida
        // Acumulador de 64 bits para a soma em ponto fixo.
        // É zerado para cada elemento 'z[i]' a ser calculado.
        int64_t sum_fx_64 = 0;

        // Loop interno para calcular o produto escalar da linha 'i' de W com o vetor x
        for (int j = 0; j < N; j++) {
            /* Passo 1: Converte W[i][j] e x[j] para ponto fixo na hora */
            int32_t w_ij_fx = (int32_t)(W[i][j] * SCALE_FACTOR);
            int32_t x_j_fx  = (int32_t)(x[j] * SCALE_FACTOR);

            /* Passo 2: Calcula o produto em ponto fixo e acumula */
            // O produto de dois números Q15.16 resulta em um Q30.32.
            // A soma é acumulada em um int64_t para evitar overflow.
            sum_fx_64 += (int64_t)w_ij_fx * x_j_fx;
        }

        /* Passo 3: Converte a soma final de volta para ponto flutuante */
        
        // Primeiro, re-escala a soma acumulada (que está em Q30.32) de volta para o nosso
        // formato base (Q15.16) com um shift para a direita.
        int32_t sum_final_fx = (int32_t)(sum_fx_64 >> FRACTIONAL_BITS);

        // Agora, converte o resultado final de ponto fixo para ponto flutuante
        // e armazena diretamente no vetor de saída 'z'.
        z[i] = (float)sum_final_fx / SCALE_FACTOR;
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
