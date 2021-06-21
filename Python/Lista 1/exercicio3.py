# Exercício 3 Faça um algorítimo que leia um valor inteiro e verifica se o valor é par ou ímpar, 
# retornando um valor booleano

def parOuImpar(x):
    if x % 2 == 0:
        return True
    return False

print("Informe um número inteiro: ")
n = int(input())

if parOuImpar(n):
    print("O número digitado é par")
else:
    print("O número digitado é ímpar")