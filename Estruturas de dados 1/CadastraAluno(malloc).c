#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 3

/* Crie um tipo estruturado “aluno”. Um aluno deve possuir nome (cadeia com até 80 caracteres) e matrícula (número inteiro). 
Defina o novo nome “Aluno” para sua estrutura.*/
typedef struct aluno{
    char nome[80];
    int matricula;
}Aluno;

//implemente as seguintes funcoes:

/*atribui NULL a todos os elementos do vetor tab de alunos de tamanho n | void inicializa (int n, Aluno** tab);*/
void inicializa(int n, Aluno** tab){
    for(int i = 0; i < n; i++){
        tab[i] = NULL;
    }
}

// armazena os dados de um novo aluno em uma posição i do vetor de tamanho n | void leAluno (int n, Aluno** tab, int i);
void leAluno(int n, Aluno** tab){
	for(int i = 0; i < n; i++){
		if(tab[i] == NULL){
			tab[i] = (Aluno*) malloc(sizeof(Aluno));
			printf("Digite o nome do aluno: ");
			scanf("%s", &tab[i]->nome);
			printf("Digite a matricula: ");
			scanf("%d", &tab[i]->matricula);
		}
	}
}

/* imprime os dados de um aluno armazenado em uma posição i do vetor |void imprimeAluno(int n, Aluno** tab, int i);*/
void imprimeAluno(int n, Aluno** tab){
	for(int i = 0; i < n; i++){
		printf("%s\n%d\n", tab[i]->nome, tab[i]->matricula);
	}
}

/* remove os dados de um aluno. A posição i do aluno é passada como parâmetro void retiraAluno(int n, Aluno** tab, int i);*/
void retiraAluno(int n, Aluno** tab){
	int b; //receber a resposta
	int ret;
	do{
		printf("Voce deseja retirar os dados de algum aluno?\n Digite 1 para sim\n Digite 0 para nao: ");
		scanf("%d", &b);
		if (b == 1){
			printf("Qual aluno voce deseja retirar? ");
			scanf("%d", &ret);
			free(tab[ret-1]);
			tab[ret-1] = NULL;
		}
	}while(b != 0);
}

/*imprime os dados de todos os alunosarmazenados na tabela chamando a função imprimeAluno | void imprime_tudo(int n, Aluno** tab);*/
void imprime_tudo(int n, Aluno** tab){
	for (int i = 0; i < n; i++){
		if(tab[i] == NULL){
			
		}
		else{
			printf("%s\n%d\n", tab[i]->nome, tab[i]->matricula);
		}
	}
}

void cadastraAluno(int n, Aluno** tab){
	int r;
	int p;
	
	do{
	printf("Voce quer cadastrar um aluno?\n Digite 1 para sim\n Digite 0 para nao");
	scanf("%d", &r);
		if(r == 1){
			for(int i = 0; i < n; i++){
				if(tab[i] == NULL){
					printf("A posicao %d esta disponivel\n", i+1);
				}
			}
			printf("Em qual posicao voce deseja cadastrar? ");
			scanf("%d", &p);
			
	
			tab[p-1] = (Aluno*) malloc(sizeof(Aluno));
			printf("Digite o nome do aluno: ");
			scanf("%s", &tab[p-1]->nome);
			printf("Digite a matricula: ");
			scanf("%d", &tab[p-1]->matricula);
		}
	}while(r != 0);
		
}


int main(int argc, char** argv) {
/* Na funcao main crie um vetor de ponteiros para a estrutura+aluno (chamado tab com 3 posiÃ§Ãµes).*/
    Aluno* tab[tam];
// chamando funcao inicializa
    inicializa(tam, tab);
//chamando funcao leAluno
	leAluno(tam, tab);
//chamando funcao imprimeAlunno
	imprimeAluno(tam, tab);
//chamando funcao retiraAluno
	retiraAluno(tam, tab);
//chamando cadastraAluno
        for(int i = 0; i < tam; i++){
            if (tab[i] == NULL){
                cadastraAluno(tam, tab);
            }
            else{
                break;
            }
        }
//chamando funcao imprimetudo
	imprime_tudo(tam, tab);
    return (EXIT_SUCCESS);
}
