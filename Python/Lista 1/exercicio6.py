# Exercicio 6 Crie um algorítimo para para ler três valores float 
# e imprimir o quadrado do primeiro mais a adição dos outros dois

resultado = 0
index = 1

while index <= 3:
    print("Informe o ",index,"º valor numérico")
    n = float(input())

    if index == 1:
        resultado += n ** 2
    else:
        resultado += n;
    index += 1

print("O quadrado do primeiro mais adição dos outros dois = ", resultado)