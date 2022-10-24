#include <stdio.h>
#include <stdlib.h>


//Elabore um algoritmo que gera e escreve os números ímpares entre 100 e 200


int main()
{

int n = 1;

while (n <= 200)
{
printf ("%d\n", n);
n= n+2;
}
}

[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
  #include <stdio.h>
//Faça um algoritmo que conte de 1 a 100 e a cada múltiplo de 10 emita a mensagem „Múltiplo de 10"
int main ()
{
int numero=0, resto;
for (numero = 0; numero <= 100; numero++)
 {
  printf ("\n%i", numero);
  if ((numero%10)==0)
  { 
   printf (" seu nnmr e multiplo de 10");
  }
 }
}
