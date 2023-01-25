//Crie um tipo para representar um aluno. Esse tipo deverá ser capaz de armazenar o nome
//do aluno, asnotas de quatro provas, a média e o conceito final (A, B ou C).

#include <stdio.h>

typedef struct {
	
	char nome[50];
	float media=0;
	float vet_soma[4];
	char conceito;

}aluno;


void soma_nota (aluno *a) {
	
for (int i = 1; i < 5; i++) {
	
	printf("Digite sua %d nota: ", i);
	scanf("%f", &a->vet_soma[i]); }

     a->media = (a->vet_soma[1] + a->vet_soma[2] + a->vet_soma[3] + a->vet_soma[4])/4;
	
}

void conceito (aluno *a)  {
	
	if (a->media >= 7.0){
		printf("Voce passou direto!!");
	}
	if  (a->media < 7.0 && a->media > 5.0){
		printf("Voce ganhou B!!");
	}
	if (a->media <= 5.0){
		printf("ganhou um C");
	}
}


int main () {

aluno b;
soma_nota (&b);
printf("A sua media e %2.f\n", b.media);	
conceito(&b);
}
