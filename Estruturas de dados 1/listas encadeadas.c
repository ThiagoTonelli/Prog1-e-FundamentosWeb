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
            printf("\n%d ", p->info); }
        printf("\n");
    }else {
        printf("a lista ta vazia");
    }    
}

int buscar(noLista **l, int v){
    
     for(noLista* p = *l; p != NULL; p=p->prox){
         if(p->info == v){
             printf("\nachei");
         }
       else{
     }
  }
}

void remover(noLista **l, int v){
    
    noLista *p, *ant=NULL;
    for(p = *l; p!=NULL && p->info!=v; p=p->prox){
        ant = p; }
        if (p == NULL){
            printf("Elemento n encontrado");
       }else {
            if (ant == NULL){
                *l = p->prox;}
            else 
            { ant->prox = p->prox;}
                free(p);
            
       }
}

void insereOrdenado(noLista** l, int v){
    noLista* p, *ant =NULL;
    for(p = *l; p!=NULL && p->info < v; p=p->prox){
        ant = p;}
        noLista *novo = (noLista*)malloc(sizeof(noLista));
        novo->info = v;
        novo->prox = p;
        if (ant == NULL) {
            *l= novo; }
        else {
            ant->prox = novo; }
        
}
int main(int argc, char** argv) {
    noLista *lista = criarLista();
    estaVazia(&lista);
    insere(&lista, 5);
    insere(&lista, 6);
    imprime(&lista);
    buscar(&lista, 5);
    remover(&lista, 5);
    imprime(&lista);
    insereOrdenado(&lista, 4);
    imprime(&lista);
    return (EXIT_SUCCESS);
}

