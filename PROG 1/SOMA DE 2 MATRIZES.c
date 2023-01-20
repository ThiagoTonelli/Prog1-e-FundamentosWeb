//Escreva um programa que leia duas matrizes bidimensionais reais MAT1 e MAT2 de dimensões 3x5
//cada, calcule e imprima a matriz soma MSOMA.

#include <stdio.h>

int main () {

const int tam1=3, tam2=5;
int mat1[tam1][tam2], mat2[tam1][tam2], msoma[tam1][tam2];


//MATRIZ 1
for (int i = 0; i < 3; i++) 
	for (int j = 0; j < 5; j++) {
		printf("Digite um valor para a posicao [%d][%d]: ", i, j);
		scanf("%d", &mat1[i][j]);
	} 


printf("\n\n+++++++++++++++++++++++++++++++++  MATRIZ 1:  +++++++++++++++++++++++++++++++++\n\n");

for (int i=0; i < 3; i++) 
    for (int j=0; j < 5; j++) {
    	printf("\nPOSICAO [%d][%d]: %d", i, j, mat1[i][j]);
	}
   
printf("\n\n\n");

// MATRIZ 2

for (int i = 0; i < 3; i++) 
	for (int j = 0; j < 5; j++) {
		printf("Digite um valor para a posicao [%d][%d]: ", i, j);
		scanf("%d", &mat2[i][j]);
	} 


printf("\n\n+++++++++++++++++++++++++++++++++  MATRIZ 2:  +++++++++++++++++++++++++++++++++\n\n");

for (int i=0; i < 3; i++) 
    for (int j=0; j < 5; j++) {
    	printf("\nPOSICAO [%d][%d]: %d", i, j, mat2[i][j]);
	}


//SOMA DAS MATRIZES:

for (int i = 0; i < 3; i++) 
	for (int j = 0; j < 5; j++) {
		msoma[i][j] = mat1[i][j] + mat2[i][j];
	} 


printf("\n\n+++++++++++++++++++++++++++++++++  SOMA DAS MATRIZES:  +++++++++++++++++++++++++++++++++\n\n");
for (int i=0; i < 3; i++) 
    for (int j=0; j < 5; j++) {
    	printf("\nSOMA DAS MATRIZES [%d][%d]: %d", i, j, msoma[i][j]); } }
