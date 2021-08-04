#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validarChave(string chave) {

    /* Verifica se a chave possui 26 caracteres */
    if(strlen(chave) != 26) {
        return false;
    }

    /* Verifica se a chave contém somente caracteres alfabéticos */
    int i = 0;
    while(chave[i] != '\0') {
        if(!isalpha(chave[i])) {
            return false;
        }
        i++;
    }

    /* Verifica se não há letras repetidas */
    i = 0;
    int j;
    for (i = 0; i < 26; i++) {
        for (j = i + 1; j < 26; j++) {
            if (chave[i] == chave[j]) {
                return false;
            }
        }
    }

    return true;
}

char substituir(char c, string chave) {

    string alfabetoMaiusculo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfabetoMinusculo = "abcdefghijklmnopqrstuvwxyz";
    int c_i = '\0';

    printf("Testando: %c \n", c);

    for(int i=0; i < 26; i++) {
        if(c == alfabetoMaiusculo[i]) {
            c_i = chave[i];
            break;
        }
        if(c == alfabetoMinusculo[i]) {
            c_i = chave[i] + 32; // convertendo para minúsculo
            break;
        }

    }
    return c_i;
}

string converterParaMaiuscula(string chave) {
    int n = strlen(chave);
    for(int i = 0; i < n; i++) {
        chave[i] = (chave[i] >= 'a' && chave[i] <= 'z') ? chave[i] - 32 : chave[i];
    }
    return chave;
}

int main(int argc, char *argv[]) {

    if(argc == 1) {
        printf("Não foi encontrado o parâmetro esperado ou mais de um parâmetro foi informado!\n");
        return 1;
    }

    string chave = argv[1];
    chave = converterParaMaiuscula(chave);
    printf("Key: ");
    fputs(chave, stdout);
    printf("\n");

    if(!validarChave(chave)) {
        printf("Chave inválida!\n");
        return 1;
    }

    string p = get_string("plaintext: ");
    int n = strlen(p);
    int i = 0;

    while(i < n) {
        if(isalpha(p[i])) {
            p[i] = substituir(p[i], chave);
        }
        else {
            p[i] = p[i];
        }
        i++;
    }

    printf("ciphertext: ");
    i = 0;
    while(i < n) {
        printf("%c", p[i]);
        i++;
    }
    printf("\n");

    return 0;
}