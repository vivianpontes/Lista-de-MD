#include <stdio.h>

int achar_x (int m, int modulo, int x)
{
        if ((m * x) % modulo == 1)
        {
                return x;
        }
        else
        {
                return achar_x(m, modulo, x + 1);
        }
}

int main ()
{

int b1, m1, b2, m2, b3, m3;

printf("Escreva o 'b' e o 'm' das três congruências\n");

scanf("%d%d%d%d%d%d", &b1, &m1, &b2, &m2, &b3, &m3);

printf("X = %d mod %d\n", b1, m1);
printf("X = %d mod %d\n", b2, m2);
printf("X = %d mod %d\n", b3, m3);

int Mo = m1 * m2 *m3;

int novo_m1 = Mo / m1;
int novo_m2 = Mo / m2;
int novo_m3 = Mo / m3;

int x1 = achar_x (novo_m1, m1, 1);
int x2 = achar_x (novo_m2, m2, 1);
int x3 = achar_x (novo_m3, m3, 1);

int Xo = (novo_m1 * b1 * x1) + (novo_m2 *b2 *x2) + (novo_m3 * b3 * x3);

int resultado = Xo % Mo;

printf("O resultado é %d\n", resultado);

return 0;
}