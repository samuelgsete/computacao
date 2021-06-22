# Questão 8     Construa um algorítmo para ler salários de 10 funcionários  e depois calcular e informar: 
#               * maior salário
#               * menor salário
#               * média salarial
#               * imposto de renda, levando em consideração (até R$ 1500 - insento; maior que R$ 1500
#               * e menor ou igual R$ 2000 - descontar 10%; maior que R$ 2000 - descontar 15%)
#               * Salario líquido a receber

def calcularImposto(salario) :
    if salario <= 1500 :
        return 0.0 # insento
    elif salario > 1500 and salario <= 2000 :
        return 0.10 # 10%
    elif salario > 2000 :
        return 0.15 # 15%

def calcularSalarioLiquido(salario, imposto) :
    desconto = salario * imposto
    salarioLiquido = salario - desconto
    return salarioLiquido

maiorSalario = 0.0
menorSalario = 0.0
somatorioSalarial = 0.0

for indice in range(1,11) :
    print(f'\nInforme o salário do {indice}º funcionário: ')
    salario = float(input())

    imposto = calcularImposto(salario)
    salarioLiquido = calcularSalarioLiquido(salario, imposto)

    print(f'Imposto de renda: {imposto * 100}%')
    print(f'Salário Liquído a receber: R$ {salarioLiquido}')

    if indice == 1 :
        maiorSalario = salario
        menorSalario = salario
    
    if salario >= maiorSalario :
        maiorSalario = salario

    if salario <= menorSalario :
        menorSalario = salario

    somatorioSalarial += salario

mediaSalarial = somatorioSalarial / 10

print("\n")
print(f'Maior Salário: R$ {maiorSalario}')
print(f'Menor Salário: R$ {menorSalario}')
print(f'Média Salarial: R$ {mediaSalarial}')