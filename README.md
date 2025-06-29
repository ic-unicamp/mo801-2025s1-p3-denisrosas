# Repositório base para o Projeto 3

Aluno: Dênis Baptista Rosas - 032184

## Breve descrição dos objetivos

<p>O objetivo deste projeto foi otimizar o algoritmo Fully Connected Layers, um componente essencial em inteligência artificial, para melhorar seu desempenho em ambientes embarcados, especificamente o LiteX com processador VexRiscV. 
<p>Isso incluiu a identificação de gargalos de desempenho através de profiling e a aplicação de diversas estratégias de otimização.
<p>
<p>Embora algumas otimizações (como o uso de ponto fixo e instruções vetoriais) não tenham sido eficazes devido a limitações de hardware ou penalidades de conversão, as otimizações aplicadas demonstraram um ganho substancial de desempenho para um sistema embarcado com recursos limitados.


## Desafios encontrados

<p> - Erros de dependencias no litex
<p> - Erro de pouco espaço de SRAM para execução do processo.
<p> - Aprendizado de uso das ferramentas de profiling para identificar gargalos no código
<p> - Otimizações que não resultaram em ganho de desempenho, como uso de ponto fixo ou de funções inline.
<p> - Medição de tempo de execução no litex_sim

## Barreiras alcançadas

<p>Otimização 1 - Trocar as variáveis de ponto flutuante por ponto fixo: Resultou em uma piora de 30% no tempo de execução, provavelmente devido às constantes conversões entre ponto fixo e ponto flutuante dentro do loop principal.
<p>Otimização 3 - Tentar reduzir a quantidade de cache miss: Não foi possível aplicar, pois os cache misses estavam mais relacionados a instruções do sistema operacional (`rep movsq`) do que a acessos à matriz do algoritmo, e o código já seguia a melhor prática de acesso a matrizes (linhas por fora, colunas por dentro).
<p>Otimização 4 - Uso de inline: Não gerou nenhuma redução no tempo de execução (0% de ganho), indicando que o overhead da chamada da função `fully_connected_layer()` era desprezível.
<p>Otimização 6 - Uso de instruções vetoriais: Não foi possível aplicar devido à falta de suporte a essa extensão no processador VexRiscV, resultando em um erro de compilação.

## Comentários gerais e conclusões

<p>Código-fonte:
<br>A pasta x86_64_code_opt_testing contém o código para ser executado em um processador x86_64.
<p>Basta compilar com:
<br>gcc fully_connected_layer.c -o fully_connected_layer

<p>As otimizações foram implementadas nos branches:
<br> -  cache_miss
<br> -  combine_optimizations
<br> -  fixed_point
<br> -  inline
<br> -  loop_unrolling
<br> -  otimização_int

<p>A pasta riscv-litex_project contem o projeto para ser executado no ambiente liteX com o litex_sim.
<p>Para executar o projeto no litex_sim use os parametros para selecionar 128KB de RAM e o processador vexriscv:
--integrated-main-ram-size=0x20000 --integrated-sram-size=0x20000 --cpu-type=vexriscv
