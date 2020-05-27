#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 5

typedef struct{
	char nome[50];
	char disciplina[3];
	float notas[3];
	float notas1[3];
	int codigo[6];
	int ativo;
} Aluno;
Aluno alunos[MAX_ALUNOS];
void menu();
void cadastrarEstudante();
void lancarNota();
void alterarNota();
void mostrarRelatorio();
int main(int argc, char const *argv[]){
	
	menu();
	
	return 0;
}
void menu(){
	system("cls");
	int op;
	do{
		printf("\n1 - Cadastrar Estudante");
	    printf("\n2 - Lancar Notas");
	    printf("\n3 - Alterar Nota");
	    printf("\n4 - Mostrar relatorio dos Estudantes");
	    printf("\n0 - Sair");
	    printf("\nDigite uma Opcao:");
	    scanf("%d",&op);
	    switch(op){
	    	case 1:
	    	    cadastrarEstudante();
			break;
			case 2:
			    lancarNota();
			break;
			case 3:
				alterarNota();
			break;	
			case 4:
			    mostrarRelatorio();
			break;	 	 	
		}
	}while(op!=0);
}
void cadastrarEstudante(){
	char nome[50];
	char disciplina[3];
	int codigo[50];
	float notas[3];
	int op;
	do{
		system("cls");
		getchar();
		printf("\nCADASTRO");
		printf("\nNome:");
		gets(nome);
		printf("\nCodigo:");
		scanf("%d",&codigo[0]);
		printf("\nDisciplina:");
		scanf("%s",&disciplina);
		for(int i = 0; i < MAX_ALUNOS; i++){
			if(alunos[i].ativo==0){
				alunos[i].codigo[0] = codigo[0];
				strcpy(alunos[i].nome, nome);
				strcpy(alunos[i].disciplina, disciplina);
				alunos[i].ativo=1;
				break;
			}
		}
	    printf("\n1 - Continuar \n0 - Sair\n");
	    scanf("%d",&op);
	    
	}while(op!=0);
	
}
void lancarNota(){
	float notas[3];
	int op, cod;
	do{
		printf("\nInforme o Codigo do Aluno:");
		scanf("%d",&cod);
		for(int i = 0; i < MAX_ALUNOS; i++){
			    if(cod==alunos[i].codigo[0]){
			    	printf("\nCodigo: %d | Nome: %s | Disciplina: %s ", alunos[i].codigo[0],alunos[i].nome, alunos[i].disciplina);
			        printf("\nPrimeira Avaliacao:");
                    scanf("%f",&notas[0]);
                    printf("\nSegunda Avaliacao::");
                    scanf("%f",&notas[1]);
                    printf("\nAvaliacao Final:");
                    scanf("%f",&notas[2]);
                    for(int i = 0; i < MAX_ALUNOS; i++){
			            if(alunos[i].ativo==1){
				            alunos[i].notas[0] = notas[0];
				            alunos[i].notas[1] = notas[1];
				            alunos[i].notas[2] = notas[2];
				            alunos[i].ativo=2;
				            break;
			            }
		            }
		        }
		}
	    
		printf("\n1 - Continuar \n0 - Sair\n");
	    scanf("%d",&op);	
	}while(op!=0);
	
}
void alterarNota(){
			float notas[3];
	int op, op2, op3, cod;
	do{
		printf("\nInforme o Codigo do Aluno:");
		scanf("%d",&cod);
		for(int i = 0; i < MAX_ALUNOS; i++){
			    if(cod==alunos[i].codigo[0]){
			    	//do{
			        	printf("\nCodigo: %d | Nome: %s | Disciplina: %s ", alunos[i].codigo[0],alunos[i].nome, alunos[i].disciplina);
			    	    printf("\nQual Avaliacao deseja mudar:");
			            printf("\n1 - Primeira Avaliacao:");
                        printf("\n2 - Segunda Avaliacao::");
                        printf("\n3 - Avaliacao Final:");
                        printf("\n0 - Voltar");
                        printf("\nDigite sua Opcao:");
                        scanf("%d",&op2);
                        if(op2==1){
                        
	    	                printf("\nPrimeira Avaliacao:");
	    	                scanf("%f",&alunos[i].notas[0]);
						}
						if(op2==2){
							
	    	                printf("\nPrimeira Avaliacao:");
	    	                scanf("%f",&alunos[i].notas[1]);
						}
						if(op2==3){
							
	    	                printf("\nPrimeira Avaliacao:");
	    	                scanf("%f",&alunos[i].notas[2]);
						}
						if(op2==0){
							break;
						}
            	      
                    for(int i = 0; i < MAX_ALUNOS; i++){
                    	if(alunos[i].ativo==1){
                    		alunos[i].notas[0] = notas[0];
		                alunos[i].notas[1] = notas[1];
			            alunos[i].notas[2] = notas[2];
			            alunos[i].ativo=1;
			            break;
						}
				        	            
		            }
		        }
		}
		printf("\n1 - Continuar \n0 - Sair\n");
	    scanf("%d",&op);	
	}while(op!=0);	

}
void mostrarRelatorio(){
	system("cls");
	float media;
	char conceito;
	for(int i=0;i<MAX_ALUNOS;i++){
		media = (alunos[i].notas[0]+alunos[i].notas[1]+alunos[i].notas[2])/3;
		if(media<3.9)
		conceito = 'F';
		if(media>=4.0&&media<=5.9)
		conceito = 'D';
		if(media<=6.9&&media>=6.0)
		conceito = 'C';
		if(media<=8.4&&media>=7.0)
		conceito = 'B';
		if(media<=10&&media>=8.5)
		conceito = 'A';
		if(alunos[i].ativo==2){
			printf("\nCodigo: %d | Nome: %s | Disciplina: %s ", alunos[i].codigo[0],alunos[i].nome, alunos[i].disciplina);
		    printf("\nAvalicao 1: %1.2f", alunos[i].notas[0]);
		    printf("\nAvalicao 2: %1.2f", alunos[i].notas[1]);
		    printf("\nAvalicao 3: %1.2f", alunos[i].notas[2]);
		    printf("\nMedia: %0.2f", media);
		    printf("\nNota: %c", conceito);
		    printf("\n-------------------------------------");
		}
	}
}
