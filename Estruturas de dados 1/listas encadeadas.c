/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: thiago.silva.66
 *
 * Created on 20 de Abril de 2023, 16:47
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
typedef struct no{
    int info;
    struct no* prox;
}noLista;

noLista *criarLista(){
    noLista *l = NULL;
    return l;
}

int estaVazia(noLista **l){
    return (*l == NULL);
}

void insere(noLista **l, int v){
    noLista* novo = malloc(sizeof(noLista));
    if (novo != NULL){
        novo->info = v;
        novo->prox = *l;
        *l = novo;
   }else{
        printf("nao foi possivel alocar espaco");
        exit(1);
   }
}

void imprime (noLista **l){
    if(!estaVazia(l)){
        for(noLista* p = *l; p != NULL; p=p->prox){
            printf("%d ", p->info); }
        printf("\n");
    }else {
        printf("a lista ta vazia");
    }

    
}
int main(int argc, char** argv) {
    noLista *lista = criarLista();
    estaVazia(&lista);
    insere(&lista, 5);
    imprime(&lista);
    return (EXIT_SUCCESS);
}
