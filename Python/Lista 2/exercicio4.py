
# Exercício 4   Faça um algorítimo para ler 10 números inteiros quaisquer 
#               e informar quantos e quais são os número primos

def primo(x) :
    contador = 0;
   
    for n in range(1, x + 1) :
        if x % n == 0 :
            contador += 1
    
    if contador == 2 :
        return True
    return False

lista = []

for n in range(1, 11) :
    print(f'Informe o {n}º número inteiro: ')
    numero = int(input()) 

    if primo(numero) :
        lista.append(numero)

print("\n")
print("Total de números primos encontrados: ", len(lista))
print("Lista de número primos: ")
for numero in lista :
    print(numero)