#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Função responsável por contar a quantidade de letras do texto */
int contadorDeLetras(string texto) {
	int contador = 0;
	for(int i = 0; i < strlen(texto); i++) {
		if(isalpha(texto[i])) {
			contador++;
		}
	}
	return contador;
}

/* Função responsável por contar a quantidade de palavras do texto */
int contadorDePalavras(string texto) {
	int contador = 1;
	for(int i = 0; i < strlen(texto); i++) {
		if((texto[i] == ' ') || (texto[i] == '\n')) {
			contador++;
		}
	}
	return contador;
}

/* Função responsável por contar a quantidade de sentenças do texto */
int contadorDeSentencas(string texto) {
	int contador = 0;
	char delimitadores[] = { '.', '?', '!' };
	for(int i = 0; i < strlen(texto); i++) {
		for(int j = 0; j < strlen(delimitadores); j++) {
			if(delimitadores[j] == texto[i]) {
				contador++;
			}
		}
	}
	return contador;
}

/* Função responsável por retornar o resultado da função de Coleman-Liau */
int calcularGrade(float qtdLetras, float qtdPalavras, float qtdSentencas) {
	/* Número médio de letras a cada 100 palavras*/
	float L = (qtdLetras / qtdPalavras) * 100;

	/* Número médio de sentenças a cada 100 palavras */
	float S = (qtdSentencas / qtdPalavras) * 100;

	/* Aplicando a fórmula de Coleman-Liau */
	float I = 0.0588 * L - 0.296 * S - 15.8;

	/* retornando o resultado do cálculo arredondado */
	return floor(I);
}

int main(int argc, char *argv[]) {

    string text = get_string("text: ");

    int letter = contadorDeLetras(text);
    int word = contadorDePalavras(text);
    int sentence = contadorDeSentencas(text);

    int grau = calcularGrade(letter, word, sentence);

    printf("%d leter(s)\n", letter);
    printf("%d word(s)\n", word);
    printf("%d sentence(s)\n", sentence);

    if(grau >= 16) {
        printf("Grade 16+");
    }

    else if(grau < 1) {
        printf("Before grade 1");
    }

    else {
        printf("Grau %d", grau);
    }

    printf("\n");

    return 0;
}