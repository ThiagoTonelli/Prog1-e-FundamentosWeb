//Crie um tipo para representar um aluno. Esse tipo deverá ser capaz de armazenar o nome
//do aluno, asnotas de quatro provas, a média e o conceito final (A, B ou C).
// Considerando o tipo criado na Questão 2, faça um procedimento que receba um parâmetro
//desse tipo e o nome de um arquivo, e grave os dados recebidos no arquivo.
#include <stdio.h>

typedef struct {
	
	char nome[50];
	float media;
	float vet_soma[4];
	char conceito;

}aluno;

int main () {
void soma_nota (aluno *a);  
void salvar_arquivo(aluno *a, char* ponteiro);
void conceito (aluno *a); 
    aluno b;
    soma_nota (&b);
    printf("A sua media e %2.f\n", b.media);  
    conceito(&b);
    printf("\nDigite o nome do aluno: ");
    scanf("%s", b.nome);
    b.conceito = (b.media >= 7.0) ? 'A' : (b.media > 5.0) ? 'B' : 'C';
    salvar_arquivo(&b, "atividade22.txt");
}

void salvar_arquivo(aluno *a, char* ponteiro) {
    FILE* file = fopen(ponteiro, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Nome: %s\n", a->nome);
    fprintf(file, "Media: %.2f\n", a->media);
    fprintf(file, "Notas: %.2f, %.2f, %.2f, %.2f\n", a->vet_soma[1], a->vet_soma[2], a->vet_soma[3], a->vet_soma[4]);
    fprintf(file, "Conceito: %c\n", a->conceito);
    fclose(file);
}


void soma_nota (aluno *a) {
	
for (int i = 1; i < 5; i++) {
	printf("Digite sua %d nota: ", i);
	scanf("%f", &a->vet_soma[i]); 
        } 
 a->media = (a->vet_soma[1] + a->vet_soma[2] + a->vet_soma[3] + a->vet_soma[4])/4;
	
}

void conceito (aluno *a)  {
	
	if (a->media >= 7.0) {
		printf("Voce passou direto!!");
	}
	if  (a->media < 7.0 && a->media > 5.0) {
		printf("Voce ganhou B!!");
	}
	if (a->media <= 5.0) {
		printf("ganhou um C");
	}
}

