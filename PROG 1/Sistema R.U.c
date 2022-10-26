/*Escreva um algoritmo que calcule a receita diária do Restaurante Universitário (RU). Para
cada pessoa que chega ao restaurante, basta o funcionário da recepção digitar o tipo de ticket entregue. Cada
ticket tem seu valor conforme a tabela abaixo. O número de pessoas que chegam ao RU é imprevisível.
Portanto, para encerrar o programa, deve-se utilizar o número 0 (zero) como tipo de ticket. Ao encerrar, o
sistema deve exibir o total de pessoas que almoçaram no restaurante e a receita diária. Caso uma opção
“inválida” de ticket seja digitada, o sistema deverá exibir uma mensagem, e continuar sua execução.*/

#include <stdio.h>

int main ()
{

int pessoas=0, opcao;
float valor=0, soma=0;

do
{
printf("Digite uma opcao: ");
scanf("%d", &opcao);
switch (opcao)
 {
    case 0:
	    printf("\nEncerrando programa...") ;
	break;
	
	case 1:
		valor += 0;
        pessoas++;
	break;

	case 2:

        valor += 5.00;
        pessoas++;
	break;
	
	case 3:
	
        valor += 9.00;
        pessoas++;
	break;
	
	case 4:
	    
        valor += 10.00;
        pessoas++;
	   break;
	
	case 5:
        valor += 15.00;
        pessoas++;
	break;
   
    default:
	printf("Digite um numero valido!\n");   
    break; 
  }
soma = valor;
 } 
while (opcao != 0);
printf ("\nprograma encerrou");
printf("\na soma e de %.2f reais \n", soma);
printf("O numero de pessoas e de %d", pessoas);

return 0;
}
