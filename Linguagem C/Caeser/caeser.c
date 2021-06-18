#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isNumber(char s[]) {
    bool b = false;

    for(int i = 0; i < strlen(s); i++) {
        if(!atoi(&s[i])) {
            b = true;
        }
        else {
            b = false;
        }
    }

    return b;
}

int main(int argc, char *argv[]) {

    if(argc == 1 || argc > 2) {
        printf("Não foi encontrado o parâmetro esperado ou mais de um parâmetro foi informado!\n");
        return 1;
    }

    if(isNumber(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string p = get_string("plaintext: ");
    int n = strlen(p);
    char c[n];


    for(int i=0; i<n; i++) {
        if(p[i] >= 'A' && p[i] <= 'Z') {
            c[i] = ((p[i] + k) <= 90) ? (p[i] + k) : (p[i] + k - 26);
        }

        else if(p[i] >= 'a' && p[i] <= 'z') {
            c[i] = ((p[i] + k) <= 122) ? (p[i] + k) : (p[i] + k - 26);
        }

        else {
            c[i] = p[i];
        }
    }

    printf("ciphertext: ");
    int i = 0;
    while(c[i] != '\0') {
        printf("%c", c[i]);
        i++;
    }
    printf("\n");

    return 0;
}