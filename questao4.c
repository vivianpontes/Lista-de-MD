#include <stdio.h>
 
int eh_primo(int numero,int divisor){
    if(divisor == numero) return 1;
    else if(numero % divisor == 0  || numero == 1) return 0;  
    else eh_primo(numero,divisor + 1);
}
int f_mmc(int *numero,int divisor,int *numero2,int divisor2,int *mmc){
    if((*numero) % divisor == 0 && (*numero2) % divisor == 0){
	  (*numero) = (*numero) / divisor;
      (*numero2) = (*numero2) / divisor;
      (*mmc) *= divisor;
      return 0;
    }
    else if ((*numero) % divisor == 0 && (*numero2) % divisor != 0)
    {
        (*numero) = (*numero) / divisor;
        (*mmc) *= divisor;
    }
    else if ((*numero) % divisor != 0 && (*numero2) % divisor == 0)
    {
        (*numero2) = (*numero2) / divisor;
        (*mmc) *= divisor;
    } 
    else f_mmc(numero,divisor + 1,numero2,divisor2 + 1,mmc);
}
int f_mdc(int *numero,int divisor,int *numero2,int divisor2,int *mdc){
    if((*numero) % divisor == 0 && (*numero2) % divisor == 0){
	  (*numero) = (*numero) / divisor;
      (*numero2) = (*numero2) / divisor;
      (*mdc) *= divisor;
      return 0;
    }
    else if ((*numero) % divisor == 0 && (*numero2) % divisor != 0)
    {
        (*numero) = (*numero) / divisor;
    }
    else if ((*numero) % divisor != 0 && (*numero2) % divisor == 0)
    {
        (*numero2) = (*numero2) / divisor;
    }
 
    else f_mdc(numero,divisor + 1,numero2,divisor2 + 1,mdc);
}
int main(){
    int numero,numero2,n2r,n1r;
    int mdc = 1;
    int mmc = 1;
    scanf("%d",&numero);
    scanf("%d",&numero2);
    n1r = numero;
    n2r = numero2;
    while(numero != 1 || numero2 != 1)
    {
        f_mdc(&numero,2,&numero2,2,&mdc);
    }   
    while(n1r != 1 || n2r != 1)
    {
        f_mmc(&n1r,2,&n2r,2,&mmc);
    } 
    printf("MDC = %d\n",mdc);
    printf("MMC = %d\n",mmc);
    return 0;
}