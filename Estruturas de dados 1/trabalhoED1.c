//versao nao comentada nam identada e sem o makefile.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 50

struct noDup;

typedef struct filme{
	int ano, id;
	char nome[tam];
	struct noDup *seq;
}Filme;

typedef struct no{
	struct no *prox;
	Filme *info;
}NoLista;

typedef struct noDup{
    struct noDup *ant, *prox;
    Filme *info;
}NoListaDup;

typedef struct descritor{
	int n;
	NoLista *prim, *ult;
}Descritor;

Filme* leFilme(){
	Filme* f = (Filme*) malloc(sizeof(Filme));
  	f->seq = NULL;
    int static aux = 1;

	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("Qual o nome do filme? ");
    scanf(" %49[^\n]", &f->nome);
    fflush(stdin);

    printf("Qual o ano de lancamento do filme? ");
    scanf("%d", &f->ano);

    f->id = aux++;
    printf("\nFilme adicionado com sucesso! O ID do filme e: %d\n", f->id);
    printf("--------------------------------------------------------------------------------------------------------------------\n");

    return f;
}

void alterarNome(Filme* f){
		printf("Qual o novo nome? ");
		scanf(" %49[^\n]", &f->nome);
		fflush(stdin);
}

void alterarAno(Filme* f){
		printf("Qual o novo ano? ");
		scanf("%d", &f->ano);
		fflush(stdin);
}

int retornaAno(Filme* f){
	int aux;

	printf("\nQual ID do filme que deseja ver o ano? ");
	scanf("%d", &aux);

	if(aux == f->id){
	    return f->ano;
	}
    else {
		printf("\nDigite um ID valido. ");
	}
}

void imprimeFilme(Filme* f){
	printf("| Nome: %s | Ano de Lancamento: %d | ID unico: %d |", f->nome, f->ano, f->id);
}

Descritor criarLista(){
    Descritor l;
    l.n = 0;
    l.prim = l.ult = NULL;
    return l;
}

int verifica_id(Descritor *l, int v){
	NoLista *aux;
	NoListaDup* temp;
	int cont = 0;
	for(aux = l->prim; aux != NULL; aux = aux->prox){
		if(aux->info->id == v){
			cont++;
			break;
		}
		else{
			for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
				if (temp->info->id == v){
					cont++;
					break;
				}
			}
		}
	}
	return cont;
}
void insere(Descritor *l, Filme *f) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    NoLista *aux, *ant;

    novo->info = f;
    novo->prox = NULL;

    if (l->n == 0) {
        l->prim = novo;
        l->ult = novo;
    }
	else {
        int result = strcmp(f->nome, l->prim->info->nome);

		if (result <= 0) {
            novo->prox = l->prim;
            l->prim = novo;
        }
		else {
            aux = l->prim;
            ant = NULL;

			while (aux != NULL && result > 0) {
                ant = aux;
                aux = aux->prox;
                if (aux != NULL){
                    result = strcmp(f->nome, aux->info->nome);
                }
            }

            ant->prox = novo;
            novo->prox = aux;

            if (aux == NULL){
                l->ult = novo;
            }
        }
    }

    l->n++;
}

void removeFilme(Descritor *l, Filme *f, int v){
	NoLista *ant = NULL, *aux;
	NoListaDup *temp;
	int cont = 1;

	for(aux= l->prim; aux != NULL  && aux->info->id != v; aux=aux->prox){
		ant = aux;
	}

	if(aux == NULL){
		printf("Digite um ID valido!\n");
	}
	else{
		if(ant == NULL){
			l->prim = aux->prox;
			if(l->prim == NULL){
				l->ult == NULL;
			}
		}
		else{
			if(aux->prox == NULL){
				l->ult = ant;
				ant->prox = NULL;
			}
			else{
				ant->prox = aux->prox;
				if(aux->prox == NULL){
                    l->ult=ant;
                }
			}
		}


		for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
			cont++;
		}
		free(aux);
		l->n = l->n-cont;
	}
}

void imprimeFilmes(Descritor *l){
	NoLista *aux;
	if(l->n == 0){
		printf("A lista de filmes esta vazia!\n");
	}
	else{
		for(aux = l->prim; aux != NULL; aux = aux->prox){
			imprimeFilme(aux->info);

			if(aux->info->seq != NULL){
				NoListaDup *temp;
				for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
					printf(" --> ");
					imprimeFilme(temp->info);
				}
			}

			printf("\n");
		}
	}
}

void insereSequencia(Filme *f, Descritor *l, int v){
	NoListaDup *novo = (NoListaDup*)malloc(sizeof(NoListaDup));
	NoLista *aux = NULL;
	NoListaDup *temp, *ant = NULL;

    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->info->id == v){
           break; 
        }
    } 

    if(novo != NULL){
        if(aux->info->seq == NULL){
                novo->info = f;
                novo->ant = novo->prox = NULL;
                aux->info->seq = novo;
        }
        else{
            for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
                ant = temp;
            }

            novo->info = f;
            ant->prox = novo;
            novo->prox = NULL;
            novo->ant = ant;
        }
            
        l->n++;
    }  
}


void imprimeSequencia(Descritor *l, int v){
	NoLista *aux = NULL;
	NoListaDup *temp = NULL;

		for(aux = l->prim; aux != NULL; aux = aux->prox){
			if(aux->info->id == v){
				if(aux->info->seq == NULL){
					printf("Nao possui sequencia!\n");
					break;
				}
				for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
					printf("\n| Nome: %s | Ano de Lancamento: %d | ID unico: %d | \n", temp->info->nome, temp->info->ano, temp->info->id);
				}
				break;
			}
		}

		if(aux == NULL){
			printf("O ID nao foi encontrado!\n");
			return;
		}
}

void removeSequencia(Descritor *l, int v){
	NoLista *aux;
	NoListaDup *ant, *temp = NULL;
	for(aux = l->prim; aux != NULL; aux = aux->prox){
		if(aux->info->id == v){
			temp = aux->info->seq;
			break;
		}
	}

	int id_seq;
	printf("Qual ID da sequencia que voce deseja remover? ");
	scanf("%d", &id_seq);
	if (verifica_id(l, id_seq) == 1){
    	for(temp = aux->info->seq; temp != NULL && temp->info->id != id_seq; temp = temp->prox){
		ant = temp;
	}
	if(temp->ant == NULL){
		aux->info->seq = temp->prox;
		if(temp->prox != NULL){
			temp->prox->ant = NULL;
		}
	}

	else{
		if(temp->prox == NULL){
		ant->prox = NULL;
		}
		else{
			ant->prox = temp->prox;
			temp->prox->ant = ant;
		}
	}

	free(temp);
	temp = NULL;
	l->n--;
    } else {
    	printf("\ndigite um id valido!\n");
    }


}

void antecede(Descritor *l, int v){
	NoLista *aux = NULL;
	NoListaDup *temp = NULL;

	for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->info->id == v){
			printf("Nao possui antecessor!\n");
			break;
		}

		for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
			if(temp->info->id == v){
				if(temp->ant == NULL){
					printf("%s\n", aux->info->nome);
					break;
				}
				else{
					printf("%s\n", temp->ant->info->nome);
					break;
				}
			}
		}
		if(aux == NULL && temp == NULL){
			printf("ID n encontrado!\n");
		}
	}
}

void sucede(Descritor *l, int v){
	NoLista *aux = NULL;
	NoListaDup *temp;

	for(aux = l->prim; aux != NULL; aux = aux->prox){
		if(aux->info->id == v){
				if(aux->info->seq == NULL){
					printf("Nao existe sucessor!\n");
					break;
				}
				else{
					printf("O sucessor eh: %s\n", aux->info->seq->info->nome);
					break;
				}
		}
		else{
			for(temp = aux->info->seq; temp != NULL; temp = temp->prox){
				if(temp->info->id == v){
					if(temp->prox == NULL){
						printf("Nao existe sucessor!\n");
						break;
					}
					else{
						printf("O sucessor eh: %s\n", temp->prox->info->nome);
						break;
					}
				}
			}
		}
		if(aux == NULL && temp == NULL){
			printf("ID n encontrado!\n");
		}
	}


}


void imprime(Descritor *l){
	NoLista *aux;
	for(aux = l->prim; aux != NULL; aux = aux->prox){
		printf("\n%s", aux->info->nome);
		fflush(stdin);
	}
}


int main () {
	Filme *filme;
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	novo = NULL;
	Descritor l = criarLista();
	Descritor *x = &l;
	int opcao, id_teste;
	NoLista *temp;



  do {
	printf ("Escolha a opcao desejada:\n1 - Inserir um novo filme\n2 - Alterar os dados de um filme \n3 - Remover um filme \n4 - Imprimir a lista de filmes \n5 - Inserir sequencia de um filme \n6 - Imprimir sequencia de um filme \n7 - Remover sequencia de um filme \n8 - Imprimir filme que antecede um outro \n9 - Imprimir filme que sucede um outro \n10 - Sair\n");
  	scanf("%d", &opcao);
  	switch ( opcao ){

    case 1 :
    filme = leFilme();
	insere(&l, filme);
    break;

    case 2:
	printf("Qual o ID do filme que deseja alterar? ");
    scanf("%d", &id_teste);

    for (temp = x->prim; temp != NULL; temp = temp->prox){
    	if (temp->info->id == id_teste) {
            alterarNome(temp->info);
            alterarAno(temp->info);
        	insere(&l, temp->info);
        	removeFilme(&l, filme, id_teste);
            printf("Filme alterado com sucesso!\n");
            break;
        }
        if(temp->prox == NULL){
        	printf("Digite um ID valido!\n");
		}

	}
	break;

    case 3:
    	printf("Qual ID do filme que  deseja remover? ");
    	scanf("%d", &id_teste);

    	removeFilme(&l, filme, id_teste);
    	break;

    case 4 :
		imprimeFilmes(&l);
    break;

    case 5:
    	printf("Qual ID do filme que deseja inserir sequencia? ");
    	scanf("%d", &id_teste);
	if (verifica_id(&l, id_teste) == 1){
    	filme = leFilme();
    	insereSequencia(filme, &l, id_teste);
    } else {
    	printf("\ndigite um id valido!\n");
    }

    break;

    case 6 :
    	printf("Qual ID do filme que deseja imprimir a sequencia? ");
    	scanf("%d", &id_teste);
		imprimeSequencia(&l, id_teste);
    break;

    case 7 :
    	printf("Qual ID do filme que deseja remover? ");
    	scanf("%d", &id_teste);
    	if (verifica_id(&l, id_teste) == 1){
    	removeSequencia(&l, id_teste);
    } else {
    	printf("\ndigite um id valido!\n");
    }

    break;

	case 8:
    	printf("Qual ID do filme que deseja saber o antecessor? ");
    	scanf("%d", &id_teste);
    	if (verifica_id(&l, id_teste) == 1){
    	antecede(&l, id_teste);
    } else {
    	printf("\ndigite um id valido!\n");
    }
    break;

	case 9 :
    	printf("Qual ID do filme que deseja saber o sucessor? ");
    	scanf("%d", &id_teste);
    	if (verifica_id(&l, id_teste) == 1){
    		sucede(&l, id_teste);
    } else {
    	printf("\ndigite um id valido!\n");
    }

    break;

	case 10:
	break;

    default:
    	printf("\nPor favor, digite uma opcao valida!");
	}

  } while (opcao != 10);


	//imprime(&l);
	//printf("\n%d", l.n);
}
