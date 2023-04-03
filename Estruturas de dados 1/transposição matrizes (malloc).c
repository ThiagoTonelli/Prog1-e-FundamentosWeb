/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: thiago.silva.66
 *
 * Created on 3 de Abril de 2023, 14:13
 */

#include <stdio.h>
#include <stdlib.h>

int trans(int **mat, int m, int n) {
    
    int ** matriz = (int**)malloc(n * sizeof(int*));
   for(int a=0; a<m; a++) {
        matriz[a] = (int *) malloc(m * sizeof(int)); }
   for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t", mat[j][i]); }
    printf("\n");}
}


void preenche(int **mat, int m, int n){
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = i;
            printf("%d\t", mat[i][j]); }
        printf("\n");
    }        
    printf("\n");
}

int main(int argc, char** argv) {
   int m=2, n=2; 
    
   int ** mat = (int**)malloc(m * sizeof(int*));
   for(int a=0; a<m; a++) {
        mat[a] = (int *) malloc(n * sizeof(int)); }
   
   preenche(mat, m, n);
   trans(mat, m, n);
 
  return (EXIT_SUCCESS);
}
