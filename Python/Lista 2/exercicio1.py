# Exercício 1   Fazer um algorítimo para ler 10 números digitados pelo usuário
#               e depois informar qual o maior e qual o menor valor informado

maior = 0
menor = 0
for indice in range(1,11) :
    print(f'Digite o {indice}º número inteiro: ')
    n = int(input())

    if indice == 1 :
        maior = n
        menor = n

    if n >= maior :
        maior = n

    if n <= menor :
        menor = n

print("\n")
print("Maior valor digitado: ", maior)
print("Menor valor digitado: ", menor)