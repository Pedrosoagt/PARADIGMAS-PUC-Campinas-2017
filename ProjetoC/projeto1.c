#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 2

struct cadastrarAlunos {
	char nome[30];
	int ra;
};

struct cadastrarDisciplinas {
	char nome[30];
	int codigo;
	int vetRaAluno[1]; //vincular aluno a disciplina 
};

struct cadastrarProfessores {
	char nome[30];
	int codigoProfessor;
	int vetCodigoProfessor[20];//vincular professor a disciplina
};

int contAlunos=0;
int contDisciplinas=0;
int contProfessores=0;
int contRA=0;
int contCodigo=0;

struct cadastrarProfessores professores[LIMITE];
struct cadastrarAlunos alunos[LIMITE];
struct cadastrarDisciplinas disciplinas[LIMITE];

void insercao() {
	int escolha=0,i,j,x;
	int codigoDisciplinaMatricula=0;
	int raAlunoMatricula=0;
	int codigoProfessorMatricula=0;

	do {
		printf("Voce deseja cadastrar o que?: \n\n");
		printf("[1] - Alunos\n");
		printf("[2] - Disciplinas\n");
		printf("[3] - Professores\n");
		printf("[4] - Realizar Matricula do aluno\n");
		printf("[5] - Realizar Matricula do professor\n");
		printf("[0] - Voltar para o menu anterior\n");
		printf("Escolha: ");
		scanf("%d", &escolha);
		system("clear");

		if(escolha == 1) {
			contAlunos++;
			if(contAlunos>LIMITE) {
				printf("Quantidade de alunos excedida \n\n");
			} else {
				printf("introduza o nome do aluno: ");
				scanf("%s",alunos[contAlunos].nome);
				printf("Introduza o RA: ");
				scanf("%d", &alunos[contAlunos].ra);
				system("clear");
				printf("Aluno cadastro com sucesso! \n\n");
			} 
		} else if(escolha == 2) {
			contDisciplinas++;	
			if(contDisciplinas>LIMITE) {
				printf("Quantidade de disciplinas excedida \n\n");
			} else {
				printf("introduza o nome da disciplina: ");
				scanf("%s", disciplinas[contDisciplinas].nome);
				printf("Introduza o codigo da disciplina: ");
				scanf("%d", &disciplinas[contDisciplinas].codigo);
				system("clear");\
				printf("Disciplina cadastrada com sucesso! \n\n");
			}
		} else if(escolha == 3) {
			contProfessores++;
			if(contProfessores>LIMITE) {
			printf("Quantidade de professores excedida \n\n");
			} else {
				printf("introduza o nome do professor: ");
				scanf("%s", professores[contProfessores].nome);
				printf("Introduza o codigo do professor: ");
				scanf("%d", &professores[contProfessores].codigoProfessor);
				fflush(stdin);
				system("clear");
				printf("Professor cadastrado com sucesso! \n\n");
			}   
		} else if(escolha == 4) {
			printf("Introduza o codigo da disciplina: ");
			scanf("%d", &codigoDisciplinaMatricula);
			printf("Introduza o ra do aluno: ");
			scanf("%d", &raAlunoMatricula);

			for(i=1; i<=contDisciplinas; i++) {
				if(disciplinas[i].codigo == codigoDisciplinaMatricula) {
					disciplinas[i].vetRaAluno[contRA] = raAlunoMatricula;
					contRA++;
				} 
			} 
		} else if(escolha == 5) { //realizar cadastro 
			printf("Introduza o codigo da disciplina: ");
			scanf("%d", &codigoDisciplinaMatricula);

			printf("Introduza o codigo do professor: ");
			scanf("%d", &codigoProfessorMatricula);

			for(i=1; i<=contDisciplinas; i++) {
				if(professores[i].codigoProfessor == codigoProfessorMatricula) {
					professores[i].vetCodigoProfessor[contCodigo] = codigoProfessorMatricula;
					contCodigo++;
				}
			} 
		} else {
			printf("Opção Inválida! \n");
		}
	}while(escolha!=0);
}

void listar() {
	int escolha,i,x,j;
	int raAlunoBusca=0;
	int codigoProfessorBusca=0;
	int codigoDisciplinaBusca=0;

	do {
		printf("Voce deseja listar o que?: \n\n");
		printf("[1] - Alunos\n");
		printf("[2] - Disciplinas\n");
		printf("[3] - Professores\n");
		printf("[4] - Listar disciplinas de um aluno\n");
		printf("[5] - Listar disciplinas de um professor\n");
		printf("[6] - Alunos matriculados em disciplinas\n");
		printf("[0] - Voltar para o menu anterior\n");
		printf("Escolha: ");
		scanf("%d", &escolha);
		system("clear");

		if(escolha == 1) {
			printf("Lista de Alunos\n");
			for(i=1; i<=contAlunos; i++) {
				printf("%s ra: %d\n", alunos[i].nome, alunos[i].ra);
			}
		} else if(escolha == 2) {
			printf("Lista de Disciplinas\n");
			for(i=1; i<=contDisciplinas; i++) {
				printf("%s codigo: %d \n", disciplinas[i].nome, disciplinas[i].codigo);
			}
		} else if(escolha == 3) {
			printf("Lista de Professores\n");
			for(i=1; i<=contProfessores; i++) {
				printf("%s codigo: %d \n", professores[i].nome, professores[i].codigoProfessor);
			}
		} else if(escolha == 4) {   //lista disciplinas de um aluno
			printf("RA do aluno que deseja buscar: ");
			scanf("%d", &raAlunoBusca);

			printf("Disciplinas: \n");
			for(i=0; i<=contDisciplinas; i++) {
				for(j=0; j<=contRA; j++) {
					if(disciplinas[i].vetRaAluno[j] == raAlunoBusca) 
						printf("%s\n",disciplinas[i].nome);
				}
			}
		} else if(escolha == 5) {   //lista disciplinas de um professor
			printf("RA do professor que deseja buscar: ");
			scanf("%d", &codigoProfessorBusca);

			printf("Disciplinas de um professor: \n");
			for(i=0; i<=contDisciplinas; i++) {
				for(j=0; j<=contCodigo; j++) {
					if(professores[i].vetCodigoProfessor[j] == codigoProfessorBusca) 
						printf("%s\n",disciplinas[j].nome);
				}
			}
		} else if(escolha == 6) {   //alunos que estão matriculados em uma disciplina
			printf("Introduza o codigo da disciplina: ");
			scanf("%d", &codigoDisciplinaBusca);

			printf("Matriculados na Disciplina: \n");
			for(i=0; i<=contDisciplinas; i++) { 
				for(x=0; x<=contRA; x++) { 
					if(disciplinas[i].codigo == codigoDisciplinaBusca) {
						if((disciplinas[i].vetRaAluno[x] > 0) && (disciplinas[i].vetRaAluno[x] < 800)) 
							printf("%d \n", disciplinas[i].vetRaAluno[x]);
					}
				}     
			}
		} else {
			printf("Opção inválida! \n");
		}
	} while(escolha!=0);
}

int main() { 
	int opcao;
	contAlunos=0;
	contDisciplinas=0;
	contProfessores=0;
	do {
		printf("SISTEMA DE MATRÍCULA\n\n");
		printf("[1] - Cadastrar \n");
		printf("[2] - listar \n");
		printf("[0] - Sair \n");
		printf("Escolha: "); 
		scanf("%d", &opcao);
		system("clear");

		switch(opcao) { 
			case  1: 
				insercao();
				break; 
			case  2:
				listar();
				break; 
		}  
	} while(opcao!=0);
	getchar();
	exit(0);
}