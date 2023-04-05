#include <stdio.h>
 
/*
  Calcula o mdc(a, b) e retorna os coeficientes s e t da combinação linear s*a + t*b = mdc(a, b).
  Os coeficientes s e t são passados por referência, ou seja, a função altera os valores das variáveis
  s e t que são passadas como argumentos.
*/
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
 
int main() {
    int a, b, s, t;
    scanf("%d %d", &a, &b);
 
    int mdc = mdc_estendido(a, b, &s, &t);
 
    printf("%d = %d * %d + %d * %d\n", mdc, s, a, t, b);
 
    return 0;
}