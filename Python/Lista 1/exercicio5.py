# Exercício 5 Escreva um algorítimo para ler dois valores numéricos 
# e apresentar a diferença do maior pelo menor

print("Informe o primeiro valor numérico: ")
n = float(input())

print("Informe o segundo valor numérico: ")
m = float(input())

if n > m:
    print("Diferença do maior pelo menor: ", n - m)
else:
    print("Diferença do maior pelo menor: ", m - n)