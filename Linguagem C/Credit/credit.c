#include <stdio.h>

/* Número para teste:
		Visa: 4532416280856839
		Mastercard: 5444193967279056
		American Express: 345560221415471
 */
int main() {
	/* Declaracao das variaveis */
	long long numeroCartao; long long copiaCartao; long long divisor = 10;
	int soma1 = 0; int soma2 = 0; int somaFinal = 0; int contador = 0;
	int i = 0;

	/* Faz a leitura do número */
	do {
		printf("\nInforme um numero de cartao: ");
		scanf("%lld", &numeroCartao);
	} while(numeroCartao <= 0);

	/* 1º Passo => Soma os dígitos do cartão começando pelo último dígito */
	copiaCartao = numeroCartao;
	while(copiaCartao > 0) {
		int ultimoDigito = copiaCartao % 10;
		soma1 = soma1 + ultimoDigito;
		copiaCartao = copiaCartao / 100;
	}

	/* 2º Passo => Pega o último digito e multiplica por 2 */
	copiaCartao = numeroCartao / 10;
	while(copiaCartao > 0) {
		int ultimoDigito = copiaCartao % 10;
		int dobro = ultimoDigito * 2;
		soma2 = soma2 + (dobro % 10) + (dobro / 10);
		copiaCartao = copiaCartao / 100;
	}

	/* 3º Passo => Junta os somatórios */
	somaFinal = soma1 + soma2;
	copiaCartao = numeroCartao;

	/* Conta a quantidade de dígitos do cartão */
	while(copiaCartao != 0) {
		copiaCartao = copiaCartao / 10;
		contador++;
	}

	for(i=0; i<contador-2; i++) {
		divisor = divisor * 10;
	}

	int primeiroDigito = numeroCartao / divisor;
	int doisPrimeiros = numeroCartao / (divisor / 10);

	/* Verifica a bandeira do cartão e exibe na tela */
	if(somaFinal % 10 == 0) {
		if(primeiroDigito == 4 && (contador == 13 || contador == 16)) {
			printf("VISA\n");
		}

		else if((doisPrimeiros == 34 || doisPrimeiros == 37) && contador == 15) {
			printf("AMEX\n");
		}

		else if((doisPrimeiros > 50 && doisPrimeiros < 56) && contador == 16) {
			printf("MASTERCARD\n");
		}

		else {
			printf("INVALID\n");
		}
	}
	else {
		printf("INVALID\n");
	}

	return 0;
}