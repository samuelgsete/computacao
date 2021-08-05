#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T_ALF 26
#define DL_MAI 90
#define DL_MIN 122

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

char cifrar(c, k, delimitador) {
	if((c + k) <= delimitador) {
		return c + k;
	}

	else {
	    if(k <= T_ALF) {
			return c + k - T_ALF;
		}

		k = (k % T_ALF);
        return cifrar(c, k, delimitador);
	}
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
    int d = k % 26;

    string p = get_string("plaintext: ");
    int n = strlen(p);

    for(int i = 0; i < n; i++) {
        if(p[i] >= 'A' && p[i] <= 'Z') {
            p[i] = cifrar(p[i], k, DL_MAI);
        }

        else if(p[i] >= 'a' && p[i] <= 'z') {
            p[i] = cifrar(p[i], k, DL_MIN);
        }
    }

    printf("ciphertext: ");
    for(int i = 0; i < n; i++) {
        printf("%c", p[i]);
    }
    printf("\n");

    return 0;
}