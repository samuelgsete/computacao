# Exercício 2   Fazer um algoritimo para calcular e imprimir o fatorial 
#               de um número qualquer fornecido pelo usuário

# Método Recursivo
# 4! = 4 x 3!
# 3! = 3 x 2! 
# 2! = 2 x 1! 
# 1! = 1
# 0! = 1
def fatorialRecursivo(x) : 
    if x == 0 or x == 1 :
        return 1
    else :
        return x * fatorialRecursivo(x - 1)
    

# Método Iterativo
# 4! = 4 x 3 x 2 x 1
# 4! = (4-0) x (4-1) x (4-2) x (4-3)
def fatorialIterativo(x) :
    if x == 0 or x == 1 :
        return 1

    resultado = 1;
    
    for indice in range(x):
        resultado = resultado * (x - indice)

    return resultado;

print("Inform um número inteiro positivo: ")
n = int(input())

print("Fatorial resursivo: ", fatorialRecursivo(n))
print("Fatorial iterativo: ", fatorialIterativo(n))