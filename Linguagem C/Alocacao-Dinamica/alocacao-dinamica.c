#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int* ordenarCrescente(int *v, int n) {
    int aux = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;
}

int* ordenarDecrescente(int *v, int n) {
    int aux = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;
}

int maiorValor(int *v, int n) {
    int maior = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int menorValor(int *v, int n) {
    int menor = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] < menor) {
            menor = v[i];
        }
    }
    return menor;
}

void imprimir(int *v, int n) {
    printf("\nVetor = { ");
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            printf("%d, ", v[i]);
        }
        else {
            printf("%d", v[i]);
        }
    }
    printf(" }\n");
}

int main(int argc, char *argv[]) {

    int *vetor;
    int n;

    printf("Informe quantidade de ítens do vetor: ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        printf("Informe o %dº número inteiro: ", (i + 1));
        scanf("%d", &vetor[i]);
    }

    imprimir(vetor, n);

    vetor = ordenarCrescente(vetor, n);

    imprimir(vetor, n);

    vetor = ordenarDecrescente(vetor, n);

    imprimir(vetor, n);

    int maior = maiorValor(vetor, n);
    int menor = menorValor(vetor, n);

    printf("\nMaior valor: %d", maior);
    printf("\nMenor valor: %d\n", menor);

    free(vetor);

    return 0;
}