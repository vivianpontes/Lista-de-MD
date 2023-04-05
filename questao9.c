/*Escrever um programa para encontrar a solução única de três congruências usando
o Teorema Chinês do Resto. (Lembre-se de verificar se os módulos são coprimos).*/

/*PASSO A PASSO:
PASSO 1: Saber quais são as tres congruências
PASSO 2: Calcular o Mo utilizando os modulos das congruencias
        Mo = m1 * m2 *m3
PASSO 3: Achar o novo 'M' para cada congruência
        M(x) = Mo / m(x)
PASSO 4: Colocar o M(x) encontrado para cada congruência como "M(x) * x ≡ 1 mod m" e achar o valor para X
        m | M(x) - 1 ou M(x) % m * x = 1
PASSO 5: Calcular o Xo
        Xo = M1*b1*x1 + M2*b2*x2 + M3*b3*x3 
PASSO 6: Calcular o X final com 'Xo mod Mo'
        X = Xo % Mo

*/

#include <stdio.h>

// Função para achar o 'x' de  "M(x) * x ≡ 1 mod m" (passo 4)
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

int Mo = m1 * m2 *m3; // Calcular o Mo utilizando os 'm' das congruencias

// Achar o novo 'M' para cada congruência
int novo_m1 = Mo / m1;
int novo_m2 = Mo / m2;
int novo_m3 = Mo / m3;

// Printando para certificar que os valores estão corretos
printf("%d\n", novo_m1);
printf("%d\n", novo_m2);
printf("%d\n", novo_m3);

// Criando memorias para salvar o 'x' encontrado na função
int x1 = achar_x (novo_m1, m1, 1);
int x2 = achar_x (novo_m2, m2, 1);
int x3 = achar_x (novo_m3, m3, 1);

// Printando para certificar que os valores estão corretos
printf("O x1 = %d\n", x1);
printf("O x2 = %d\n", x2);
printf("O x3 = %d\n", x3);

// Passo 5
int Xo = (novo_m1 * b1 * x1) + (novo_m2 *b2 *x2) + (novo_m3 * b3 * x3);
printf("O valor de Xo = %d\n", Xo);

// Passo 6
int resultado = Xo % Mo;

printf("O resultado é %d\n", resultado);

return 0;
}