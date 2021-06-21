# Exercício 2 Faça um algorítimo que recebe uma raio R de uma esfera 
# e calcule o seu volume

print("Informe o valor do raio da esfera: ")
raio = float(input())

PI = 3.14
v = (4 * PI * (raio ** 3)) / 3

print("Volume da esfera: ", v)