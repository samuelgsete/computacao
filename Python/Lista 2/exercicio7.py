# Exercicio 7   Faça um algorítimo para ler o peso e a altura de 10 pessoas,
#               em seguida deve-se exibir o resultado conforme
#               a tabela abaixo:
#               Classificação       IMC
#               Abaixo do peso      Abaixo 18.5
#               Peso normal         18.5 - 24.9
#               Sobrepeso           25 - 29.9
#               Obesidade Grau I    30 - 34.9
#               Obedidade Grau II   35 - 39.9
#               Obesidade Grau II   Maior ou igual a 40

def calcularIMC(peso, altura) :
    return peso / (altura * altura)

def classificar(imc) :
    if imc < 18.5 :
        print("Abaixo do peso")
    elif imc >= 18.5 and imc <= 24.9 :
        print("Peso normal")
    elif imc >= 25 and imc <= 29.9 :
        print("Sobrepeso")
    elif imc >= 30 and imc <= 34.9 :
        print("Obesidade Grau I")
    elif imc >= 35 and imc <= 39.9 :
        print("Obesidade Grau II")
    elif imc > 40 :
        print("Obesidade Morbida (Grau III)")

for indice in range(1, 11) :
    print(f'Informe o peso da {indice}ª pessoa: ')
    peso = float(input())

    print(f'Informe a altura da {indice}ª pessoa: ')
    altura = float(input())

    print("\n")

    imc = calcularIMC(peso, altura)
    print(f'IMC = {imc}')
    classificar(imc)
    print("\n")