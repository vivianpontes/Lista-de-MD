#include <stdio.h>
 
int inverso_modular(int a, int b);
int mdc_estendido(int a, int b, int *s, int *t);
 
int main() {
    int a, b, inverso;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);
 
    // Calcula o inverso de a mod b
    inverso = inverso_modular(a, b);
 
    return 0;
}
 
/* Calcula o mdc(a, b) e retorna os coeficientes s e t da combinação linear s*a + t*b = mdc(a, b).
  Os coeficientes s e t são passados por referência, ou seja, a função altera os valores das variáveis
  s e t que são passadas como argumentos.*/
int mdc_estendido(int a, int b, int *s, int *t) {
    // Caso base: se b é zero, então o mdc é a e s e t são 1 e 0, respectivamente
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }
 
    // Caso recursivo: chama a função recursivamente com os argumentos b e a % b
    int s1, t1, mdc = mdc_estendido(b, a % b, &s1, &t1);
 
    // Calcula os coeficientes s e t a partir dos coeficientes da chamada recursiva
    *s = t1;
    *t = s1 - (a / b) * t1;
 
    // Retorna o mdc de a e b
    return mdc;
}
 
/* Calcula o inverso de a mod b e retorna esse valor. Se o inverso não existir,
  a função retorna -1. */
int inverso_modular(int a, int b) {
    int s, t;
    int mdc = mdc_estendido(a, b, &s, &t);
    if (mdc != 1) {
        printf("O inverso de %d mod %d não existe\n", a, b);
        // a não tem inverso módulo b
        return -1;
    } else {
        int resultado = (s % b + b) % b;
        printf("O inverso de %d mod %d é %d\n", a, b, resultado);
        return resultado;
    }
}