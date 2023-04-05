#include <stdio.h>
 
int fatorar(int *numero1,int divisor){
    if((*numero1) % divisor == 0){
	  (*numero1) = (*numero1) / divisor;
      printf("%d\n",divisor);
      return 0;
    } 
    else fatorar(numero1,divisor + 1);
}
 
int main(){
    int numero1;
    scanf("%d",&numero1);
    printf("primos do numero %d: \n", numero1);
    while(numero1 != 1)
    {
        fatorar(&numero1,2);
    }
 
    return 0;
}