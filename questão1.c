#include <stdio.h>
#include <stdbool.h>
#include <math.h>
 
bool ehprimo(long long unsigned n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long unsigned i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
int main()
{
    long long unsigned numero_inteiro;
    scanf("%llu", &numero_inteiro);
    if (ehprimo(numero_inteiro))
        printf("É primo\n");
    else
        printf("Não é primo\n");
 
    return 0;
}