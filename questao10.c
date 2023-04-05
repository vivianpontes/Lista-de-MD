#include <stdio.h>

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
    int n;

    scanf("%d", &n);
    
    int array_b[n];
    int array_m[n];

    int Mo = 1;

    int i = 0;
    while (i < n)
    {
        scanf("%d,%d", &array_b[i], &array_m[i]);

        printf("X = %d mod %d\n", array_b[i], array_m[i]);

        Mo *= array_m[i];

        i += 1;
    }

    printf("Mo = %d\n", Mo);
    
    int array_m_novo[n];
    int array_x[n];

    int Xo = 0;

    i = 0;
    while (i < n)
    {
        array_m_novo[i] = Mo / array_m[i];

        printf("M[%d] = %d\n", i, array_m_novo[i]);

        array_x[i] = achar_x(array_m_novo[i], array_m[i], 1);

        if (array_x[i] == -1)
        {
            printf("Não foi possível encontrar o valor de x para a congruência %d * x ≡ 1 mod %d\n", array_m_novo[i], array_m[i]);
            return 1;
        }

        printf("x[%d] = %d\n", i, array_x[i]);

        Xo += array_m_novo[i] * array_b[i] * array_x[i];

        i += 1;
    }

    printf("Xo = %d\n", Xo);

    int resultado = Xo % Mo;

    printf("O resultado é %d\n", resultado);

    return 0;
}