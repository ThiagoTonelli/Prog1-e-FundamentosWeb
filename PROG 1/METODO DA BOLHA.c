#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int tam = 4;
    int vet[tam];

    for (int i = 0; i < tam; i++)
        vet [i] = rand()&tam;
    printf("ANTES: ", vet[i]);

    int aux;
    for(int i = 0; i < tam-1; i++ )
        for(int j = i+1; j < tam; j++)
        if(vet[j] > vet[i])
        {
         aux = vet[j];
         vet[j] = vet[i];
         vet[i] = aux;
        }
        printf("\n\nDEPOIS: ");
        for (int i =0; i < tam; i++)
            printf("%d", vet[i]);
    return 0;
}
