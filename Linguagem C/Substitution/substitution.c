#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validarChave(string chave) {
    int n = strlen(chave);
    /* Verifica se a chave possui exatamente 26 caracteres */
    if(n != 26) {
        return false;
    }

    /* Verifica se a chave contém somente caracteres alfabéticos */
    for(int i = 0; i < n; i++) {
        if(!isalpha(chave[i])) {
            return false;
        }
    }

    /* Verifica se não há letras repetidas */
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(chave[i] == chave[j]) {
                return false;
            }
        }
    }

    return true;

}

string converterParaMaiuscula(string chave) {
    int n = strlen(chave);
    for(int i = 0; i < n; i++) {
        chave[i] = (chave[i] >= 'a' && chave[i] <= 'z') ? chave[i] - 32 : chave[i];
    }
    return chave;
}

char substituir(char c, string chave) {
    string alfabetoMaiusculo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfabetoMinusculo = "abcdefghijklmnopqrstuvwxyz";
    char c_i = '\0';

    for(int i = 0; i < 26; i++) {
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
        printf("Chave inválida\n");
        return 1;
    }

    string p = get_string("plaintext: ");
    int n = strlen(p);
    char c[n];

    int i = 0;
    while(p[i] != '\0') {
        if(isalpha(p[i])) {
            c[i] = substituir(p[i], chave);
        }
        else {
            c[i] = p[i];
        }
        i++;
    }

    printf("ciphertext: ");
    i = 0;
    while(c[i] != '\0') {
        printf("%c", c[i]);
        i++;
    }
    printf("\n");

    return 0;
}