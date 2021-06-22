# Exercício 5   Faça um algorítimo que leia a data de nascimento de 10 pessoas,   
#               depois calcule a idade de cada uma e a exiba. Por último mostre
#               qual a pessoa mais velha e mais jovens do grupo.

class Pessoa :
    nome = ""
    dataNascimento = ""
    idade = ""

    def __init__(self, nome, dataNascimento, idade) :
        self.nome = nome
        self.dataNascimento = dataNascimento
        self.idade = idade

def calcularIdade(dataNascimento) :
    ano = int(dataNascimento.split("/")[2])
    idade = 2021 - ano 
    return idade


pessoas = []
for indice in range(1,11):
    print(f'Informe o nome da {indice}º pessoa')
    nome = input()
    print(f'Informe a data de nascimento da {indice}º pessoa')
    dataNascimento = input()

    print("\n")

    novaPessoa = Pessoa(nome, dataNascimento, calcularIdade(dataNascimento))
    pessoas.append(novaPessoa)

maisVelho = pessoas[0]
maisNovo = pessoas[0]
for pessoa in pessoas :
    print(f'{pessoa.nome} tem {pessoa.idade} anos de idade')
    if pessoa.idade > maisVelho.idade :
        maisVelho = pessoa

    if pessoa.idade < maisNovo.idade :
        maisNovo = pessoa

print("\n")    
print(f'{maisVelho.nome} é a pessoa mais velha')
print(f'{maisNovo.nome} é a pessoa mais nova')