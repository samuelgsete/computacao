# Exercício 3   A série fibonacci é formada pela seguinte sequência: 
#               1, 1, 2, 3, 5, 8, 13, 21, 34, 55, etc
#               Escreva um algorítimo que gere a série de Fibonacci
#               Até o 12º termo

serie = "1, 1, "
anterior1 = 1
anterior2 = 1

for n in range(2, 12) :
    n = anterior1 + anterior2
    serie += str(n) + ", "

    anterior2 = anterior1
    anterior1 = n

print(serie)