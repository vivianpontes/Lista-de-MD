#include <stdio.h>
 
long long unsigned mdc(int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    return mdc(b, a%b);
}
 
int main()
{
    long long unsigned a, b, resultado_mdc;
    scanf("%llu%llu", &a, &b);
    resultado_mdc = mdc(a, b);
    printf("O mdc entre %llu e %llu é %llu\n", a, b, resultado_mdc);
    return 0;
}