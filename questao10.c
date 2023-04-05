#include <stdio.h>

/* Função para achar o 'x' de  "M(x) * x ≡ 1 mod m" (passo 4) */

int achar_x(int m, int modulo, int x)
{
    if (x > m) {
        return -1;
    }

    if ((m * x) % modulo == 1)
    {
        return x;
    }
    else
    {
        return achar_x(m, modulo, x + 1);
    }
}

int main()
{
    /* Declarando variável para salvar o tamanho do array */
    int n;

    /* Lendo o tamanho do array */
    scanf("%d", &n);
    
    /* Declarando os arrays */
    int array_b[n];
    int array_m[n];

    /* Declarando o inteiro Mo */
    int Mo = 1;

    /* Lendo os n valores */
    int i = 0;
    while (i < n)
    {
        /* Lendo os valores de b e m */
        scanf("%d,%d", &array_b[i], &array_m[i]);

        /* Imprimindo os valores de b e m */
        printf("X = %d mod %d\n", array_b[i], array_m[i]);

        /* Multiplicando Mo por m */
        /* Mesma coisa de Mo = Mo * array_m[i] */
        Mo *= array_m[i];

        /* Mesma coisa de i = i + 1 */
        i += 1;
    }

    /* Printando o valor de Mo */
    printf("Mo = %d\n", Mo);
    
    /* Declarando array para os novos m; "M[x] = Mo / m[x]" */
    int array_m_novo[n];

    /* Atribuindo valores para os novos m */
    i = 0;
    while (i < n)
    {
        /* Mesma coisa de array_m_novo[i] = Mo / array_m[i] */
        array_m_novo[i] = Mo / array_m[i];

        printf("M[%d] = %d\n", i, array_m_novo[i]);

        i += 1;
    }

    /* Declarando array para os valores de x; "m | M(x) - 1 ou M(x) % m * x = 1" */
    int array_x[n];

    /* Atribuindo valores para os novos x */
    i = 0;
    while (i < n)
    {
        array_x[i] = achar_x(array_m_novo[i], array_m[i], 1);

        if (array_x[i] == -1)
        {
            printf("Não foi possível encontrar o valor de x para a congruência %d * x ≡ 1 mod %d\n", array_m_novo[i], array_m[i]);
            return 1;
        }

        printf("x[%d] = %d\n", i, array_x[i]);

        i += 1;
    }

    /* Declarando variável para salvar o valor de Xo */
    int Xo = 0;
    
    /* Atribuindo valor para Xo */
    i = 0;
    while (i < n)
    {
        /* Passo 5 */
        /* int Xo = (novo_m1 * b1 * x1) + (novo_m2 *b2 *x2) + ... + (novo_mn * bn * xn) */

        Xo += array_m_novo[i] * array_b[i] * array_x[i];

        i += 1;
    }

    /* Printando o valor de Xo */
    printf("Xo = %d\n", Xo);

    /* Calculando resultado */
    int resultado = Xo % Mo;

    printf("O resultado é %d\n", resultado);

    return 0;
}