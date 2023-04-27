/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: thiago.silva.66
 *
 * Created on 27 de Abril de 2023, 16:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
typedef struct no{
    
    int info;
    struct no *prox;
}noLista;
    

typedef struct descritor{
    int n;
    noLista *prin, *ult;
}Descritor;

Descritor criarLista(){
    Descritor l;
    l.n = 0;
    l.prin = l.ult = NULL;
    return l;
}

void insereNoInicio(Descritor *l, int v){
    noLista *novo = (noLista*)malloc(sizeof(noLista));
    if(novo != NULL){
    novo->info = v;
    novo->prox = l->prin;
    l->prin = novo;
    if (l->n == 0){
        l->ult = novo; }
    l->n++;
    }    
}

int estaVazia(Descritor *l){
    return (l->n == 0);
}

void imprime(Descritor *l){
    
    if (!estaVazia(l)) {
    noLista *p;
    for (p=l->prin; p != NULL; p=p->prox){
        printf("\n%d", p->info);
    }}
    else {
        printf("Lista vazia");
}    
}  
    int main(int argc, char** argv) {
    
    noLista l;    
    criarLista();
    insereNoInicio(&l, 5);
    insereNoInicio(&l, 7);
    estaVazia(&l);
    imprime(&l);
    
    return (EXIT_SUCCESS);
}

