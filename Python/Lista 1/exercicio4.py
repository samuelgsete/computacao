# Exercício 4 crie um algorítimo que leia 3 números e imprima o maior valor

maior = 0
index = 1

while index <= 3:
    print("Informe o ",index, "º número inteiro: ")
    n = int(input())
    if index == 1:
        maior = n

    if n >= maior:
        maior = n;
    
    index += 1

print("O maior valor é: ", maior)