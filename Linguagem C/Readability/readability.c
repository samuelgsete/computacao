#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
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

/* Função responsavel por contar a quantidade de sentenças do texto */
int contadorDeSentencas(string texto) {
    int contador = 0;
    string delimitadores = ".!?";
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

    float L = (qtdLetras / qtdPalavras) * 100;

    float S = (qtdSentencas / qtdPalavras) * 100;

    float I = 0.0588 * L - 0.296 * S - 15.8;

    return floor(I);
}

int main(int argc, char *argv[]) {

    string text = get_string("text: ");

    int letters = contadorDeLetras(text);
    int words = contadorDePalavras(text);
    int sentences = contadorDeSentencas(text);

    int grade = calcularGrade(letters, words, sentences);

    printf("%d letter(s)\n", letters);
    printf("%d word(s)\n", words);
    printf("%d sentece(s)\n", sentences);

    if(grade >= 16) {
        printf("Grade 16+");
    }

    else if(grade < 1) {
        printf("Before Grade 1");
    }

    else {
        printf("Grade %d\n", grade);
    }

    return 0;
}