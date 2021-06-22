# Exercício 6   Faça um algorítimo para calcular e imprimir a média aritimética de 
#               10 alunos, tendo como dados de entrada 3 notas simestrais
#               Depois imprimir a situação do aluno que deve obedecer ao seguinte critério
#               * média maior ou igual a 7 "Aprovado"
#               * entre 4 e 6.9 "AF", menor que 4 "REPROVADO"
#               * Por último imprimir a média final da turma

def calcularMediaAluno(n1, n2, n3) :
    media = (n1 + n2 + n3) / 3
    return media

def imprimirSituacao(media) : 
    if media >= 7.0 :
        print("APROVADO")
    elif media >= 4.0 and media <= 6.9 :
        print("AF")
    elif media < 4.0 :
        print("REPROVADO")
    else :
        print("MÉDIA INVÁLIDA")

somatorio = 0.0

for indice in range(1, 11) :
    print(f'Informe a primeira nota do {indice}º aluno: ')
    nota1 = float(input())

    print(f'Informe a segunda nota do {indice}º aluno: ')
    nota2 = float(input())

    print(f'Informe a terceira nota do {indice}º aluno: ')
    nota3 = float(input())

    print("\n")

    media = calcularMediaAluno(nota1, nota2, nota3)
    print(f'Média: {media}')
    imprimirSituacao(media)
   
    print("\n")

    somatorio += media

mediaGeral = somatorio / 10
print(f'Media da turma: {mediaGeral}')