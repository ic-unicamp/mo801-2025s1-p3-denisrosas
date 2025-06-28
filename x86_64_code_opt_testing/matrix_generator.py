import random

def gerar_matriz_c(linhas, colunas, min_valor, max_valor):
    """
    Gera uma matriz de números aleatórios e a imprime no formato de declaração C.

    Args:
        linhas (int): Número de linhas da matriz.
        colunas (int): Número de colunas da matriz.
        min_valor (int): Valor mínimo para os números aleatórios.
        max_valor (int): Valor máximo para os números aleatórios.
    """
    print(f"float minha_matriz[{linhas}][{colunas}] = {{")

    for i in range(linhas):
        print("  {", end="")
        for j in range(colunas):
            # Gera um número aleatório com duas casas decimais
            num_aleatorio = round(random.uniform(min_valor, max_valor), 2)
            print(f"{num_aleatorio:.2f}", end="")
            if j < colunas - 1:
                print(", ", end="")
        print("}" + ("," if i < linhas - 1 else ""))
    print("};")

# Definindo as dimensões da matriz e o intervalo dos números
gerar_matriz_c(36, 32, 0, 100)