# Exercício 1: Utilize uma estrutura de controle em um algorítimo que imprime a tabuada de 1 a 3

numeros = [1, 2, 3]

print("Adição")
for x in numeros:
    for n in range(10): 
        print(x, " + ", n, " = ", x + n)
    print("\n")

print("Subtração")
for x in numeros:
    for n in range(10): 
        print(x, " - ", n, " = ", x - n)
    print("\n")

print("Multiplicação")
for x in numeros:
    for n in range(10): 
        print(x, " x ", n, " = ", x * n)
    print("\n")

print("Divisão")
for x in numeros:
    for n in range(10): 
        if n != 0:
            print(x, " / ", n, " = ", x / n)
    print("\n")