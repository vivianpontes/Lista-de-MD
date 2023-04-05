/* QUESTÃO 8: Escrever um programa para encontrar a solução de uma congruência do tipo ax ≡ b mod m.

PASSO 1: Fazer o MDC de 'a' e 'm' 
PASSO 2: Ver se o MDC de 'a' e 'm' dividir o 'b'
    - se dividir: o problema tem solução
    - se não dividir: não tem solução
PASSO 3: Se o MDC de 'a' e 'm' for:
    - igual a 1: o problema tem apenas uma solução
    - maior que 1: o valor do mdc é a quantidade de soluções
        -   divide a expressão pelo valor do MDC
PASSO 4: Achar o inverso de 'a mod m' pelo algoritmo de euclides 
PASSO 5: Pegar o 'a inverso' e calcular x = (inverso * b) % 9. O resultado é a solução */

#include <stdio.h>

// Função para encontrar todas as soluções da congruência
// 'quant_solucoes' é o mdc entre 'a' e 'm'
void encontrando_k (int x, int m, int k, int quant_solucoes, int chamada)
{
    if (chamada > quant_solucoes)
    {
        return;
    }
   
    printf("Solução %d: %d\n", chamada, x + (m * k));

    encontrando_k(x, m, k + 1, quant_solucoes, chamada + 1);
}

// Função para achar o 's' pelo algoritmo de euclides
int mdc_estendido(int a, int m, int *s, int *t)
{
    // Caso base: se b é zero, então o mdc é a e s e t são 1 e 0, respectivamente
    if (m == 0) {
        *s = 1;
        *t = 0;
        return a;
    }
 
    // Caso recursivo: chama a função recursivamente com os argumentos b e a % b
    int s1, t1, mdc = mdc_estendido(m, a % m, &s1, &t1);
 
    // Calcula os coeficientes s e t a partir dos coeficientes da chamada recursiva
    *s = t1;
    *t = s1 - (a / m) * t1;
 
    // Retorna o mdc de a e b
    return mdc;
}

// Função para achar o mdc entre 'a' e 'm'
int mdc (int numero1, int numero2)
{
    if (numero2 == 0) // condição de parada: quando um número for 0, o mdc é o outro número
    {
        return numero1;
    }
    else // caso nenhum numero não seja 0, ainda, faço o mdc do menor numero com o resto da divisão anterior (maior - menor)
    {
        return mdc (numero2, numero1 % numero2);
    }
}

int main ()
{
    int a, b, m;
    int s, t;

    printf("Escreva a congruência que quer encontrar a solução!\n");
    
    printf("Digite o 'a': ");
    scanf("%d", &a);
    
    printf("Digite o 'b': ");
    scanf("%d", &b);
    
    printf("Digite o 'm': ");
    scanf("%d", &m);

    printf("A congruência é %dx ≡ %d mod %d\n", a, b, m);

    int resultado_mdc = mdc(a, m); // memoria para a função mdc

    printf("O MDC(a,m) = %d\n", resultado_mdc);

    // Ver se a congruencia tem solucao
    if (b % resultado_mdc == 0) // Se o MDC(a,m) | b, tem solução
    {
        printf("A congruência tem %d solução / soluções\n", resultado_mdc);
    }
    else // Se não divide, não tem solução
    {
        printf("A congruência não tem solução\n");
        return 0;
    }
    
    if (resultado_mdc > 1) // Se o MDC(a,m) for maior que 1, precisa dividir a congruência
    {
        int novo_a = a / resultado_mdc;
        int novo_b = b / resultado_mdc;
        int novo_m = m / resultado_mdc;

        printf("A nova congruência, divida pelo MDC(a,m) é %dx ≡ %d mod %d\n", novo_a, novo_b, novo_m);

        int euclides = mdc_estendido(novo_a, novo_m, &s, &t); // Chamando a função para saber o 's'
        printf("%d = %d * %d + %d * %d\n", euclides, s, novo_a, t, novo_m);

        if (s < 0) // Se o 's', que é o inverso, for negativo, eu tenho que somar ele com o 'm'
        {
            s = s + novo_m;
            printf("Como o s é negativo, somando com m, o novo s fica %d\n", s);
        }
        
        int x = (s * novo_b) % novo_m; // Calculando o 'X'
        printf("O 'x' é %d\n", x);

        encontrando_k (x, novo_m, 0, resultado_mdc, 1); // Chamando a função para encontrar todas as soluções
    }
    else // se o mdc for 1, faz direto
    {
        int euclides = mdc_estendido(a, m, &s, &t);
        printf("%d = %d * %d + %d * %d\n", euclides, s, a, t, m);
        
        if (s < 0) // o 's', que é o inverso, não pode ser negativo
        {
            s = s + m;
            printf("Como o s é negativo, somando com m, o novo s fica %d\n", s); 
        }
        
        int x = (s * b) % m;
        printf("O 'x' é %d\n", x);
        encontrando_k (x, m, 0, resultado_mdc, 1);
    }
    
    return 0;
}