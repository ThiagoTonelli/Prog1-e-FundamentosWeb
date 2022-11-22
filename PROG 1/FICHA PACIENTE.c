#include <stdio.h>
#include <stdlib.h>

typedef struct tPaciente{
   char nome[20];
   int idade;
   char sexo;
   float peso;


}Paciente;
int main()
{
    const int tam=2;
    Paciente vet[tam];

    for(int i=0; i < tam; i++)
    {
        printf("\nDigite o nome do paciente %d: ", i+1);
        scanf("\n%[^\n]s", &vet[i].nome);
        printf("Digite a idade do paciente %d: ", i+1);
        scanf("%d", &vet[i].idade);
        printf("Digite o sexo do paciente %d: ", i+1);
        scanf("\n%[^\n]c", &vet[i].sexo);
        printf("Digite o peso do paciente %d: ", i+1);
        scanf("%f", &vet[i].peso);
    }
    for(int i = 0; i < tam; i++)
    {
    printf("Paciente %d: \n", i+1);
    printf("Nome: %s\n", vet[i].nome);
    printf("Idade: %d\n", vet[i].idade);
    printf("Sexo: %c\n", vet[i].sexo);
    printf("Peso: %2.f\n", vet[i].peso);
    }




}
