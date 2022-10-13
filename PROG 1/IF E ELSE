#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que determine o grau de obesidade de uma pessoa, sendo fornecido o peso e a
altura da pessoa. O grau de obesidade é determinado pelo índice da massa corpórea - IMC (Massa =
Peso/Altura2
) através dos seguintes índices:
a. Abaixo de 19.9: Você está abaixo do peso ideal.
b. Entre 20.0 e 24.9: Parabéns! você está em seu peso normal!
c. Entre 25.0 e 29.9: Você está acima de seu peso (sobrepeso).
d. Entre 30.0 e 34.9: Obesidade moderada (grau I).
e. Entre 35.0 e 39.9: Obesidade severa (grau II).
f. 40.0 e acima: Obesidade mórbida (grau III).*/

int main ()
{

float massa, peso, altura;

printf ("Digite sua altura: ");
scanf("%f", &altura);
printf("\nDigite seu peso: ");
scanf("%f", &peso);

massa = peso/(altura*altura);

if (massa < 19.9)
{
   printf("Voce esta abaixo do peso ideal.");
}
if (massa >= 20.0 && massa <= 24.9)
{
    printf("Seu peso esta ideal");
}
if (massa >= 25.0 && massa <= 29.9)
{
    printf("Seu peso esta acima do ideal");
}
if (massa >= 30.0 && massa <= 34.9)
{
    printf("Obesidade grau I");
}
if (massa >= 35.0 && massa <= 39.9)
{
    printf("Obesidade grau II");
}
else
{
    printf("Obesidade grau III");
}

}
