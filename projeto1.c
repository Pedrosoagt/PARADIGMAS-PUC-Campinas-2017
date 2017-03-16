#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 5

struct cadastrarAlunos {
	char nome[30];
	int ra;
};

struct cadastrarDisciplinas {
	char nome[30];
	int codigo;
	int vetRaAluno[10]; //vincular aluno a disciplina 
	int vetCodigoProfessor[10];//vincular professor a disciplina
};

struct cadastrarProfessores {
	char nome[30];
	int codigoProfessor;
};

//assinaturas de funçoes
void cadAluno();
void cadProfessor();
void cadDisciplina();
void msgLimite();

//contadores  globais usados para cadastrar e par listar
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

		switch(escolha) {
			case 1:
				if(contAlunos >= LIMITE) {
					msgLimite();
				} else { cadAluno(); }
				break;
			case 2:
				if(contDisciplinas >= LIMITE) {
					msgLimite();
				} else { cadDisciplina(); } 
				break;
			case 3:
				if(contProfessores >= LIMITE) {
					msgLimite();
				} else { cadProfessor(); }
				break;
			case 4:
				printf("Digite o codigo da disciplina: ");
				scanf("%d", &codigoDisciplinaMatricula);
				printf("Digite o ra do aluno: ");
				scanf("%d", &raAlunoMatricula);

				for(i=0; i < contDisciplinas; i++) {
					if(disciplinas[i].codigo == codigoDisciplinaMatricula) {
						disciplinas[i].vetRaAluno[contRA] = raAlunoMatricula;
						contRA++;
					} 
				}
				break;
			case 5:
				printf("Digite o codigo da disciplina: ");
				scanf("%d", &codigoDisciplinaMatricula);
				printf("Digite o codigo do professor: ");
				scanf("%d", &codigoProfessorMatricula);

				for(i=0; i < contDisciplinas; i++) {
					if(disciplinas[i].codigo == codigoDisciplinaMatricula) {
						disciplinas[i].vetCodigoProfessor[contCodigo] = codigoProfessorMatricula;
						contCodigo++;
					}
				}
				break;
		}
	}while(escolha!=0);
}

void cadAluno() {
	printf("Digite o nome do aluno: ");
	scanf("%s", alunos[contAlunos].nome);
	printf("Digite o RA: ");
	scanf("%d", &alunos[contAlunos].ra);
	system("clear");
	printf("Aluno cadastro com sucesso! \n\n");
	contAlunos++;
}

  void cadDisciplina() {
  	printf("Digite o nome da disciplina: ");
	scanf("%s", disciplinas[contDisciplinas].nome);
	printf("Digite o codigo da disciplina: ");
	scanf("%d", &disciplinas[contDisciplinas].codigo);
	system("clear");\
	printf("Disciplina cadastrada com sucesso! \n\n");
	contDisciplinas++;
  }

  void cadProfessor() {
  	printf("Digite o nome do professor: ");
	scanf("%s", professores[contProfessores].nome);
	printf("Digite o codigo do professor: ");
	scanf("%d", &professores[contProfessores].codigoProfessor);
	fflush(stdin);
	system("clear");
	printf("Professor cadastrado com sucesso! \n\n");
	contProfessores++;
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

		switch(escolha) {
			case 1: 
				printf(" lista de Alunos:\n");
				for(i = 0; i < contAlunos; ++i) {
					printf("Aluno: %s ra: %d\n", alunos[i].nome, alunos[i].ra);
				}
				break;
			case 2:
				printf("Lista de Professores\n");
				for(i = 0; i < contDisciplinas; i++) {
					printf("Disciplina: %s código: %d\n", disciplinas[i].nome, disciplinas[i].codigo);
				}
				break;
			case 3:
				printf("Lista de Professores\n");
				for(i = 0; i < contProfessores; i++) {
					printf("Professor: %s código: %d\n", professores[i].nome, professores[i].codigoProfessor);
				}
				break;
		}
		if(escolha == 4) {   //lista disciplinas de um aluno
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
					if(disciplinas[i].vetCodigoProfessor[j] == codigoProfessorBusca) 
						printf("%s\n",disciplinas[i].nome);
				}
			}
		} else if(escolha == 6) {   //alunos que estão matriculados em uma disciplina
			printf("Digite o codigo da disciplina: ");
			scanf("%d", &codigoDisciplinaBusca);

			printf("Matriculados na Disciplina: \n");
			for(i=0; i<=contDisciplinas; i++) { 
				for(x=0; x<=contRA; x++) { 
					if(disciplinas[i].codigo == codigoDisciplinaBusca) {
						if((disciplinas[i].vetRaAluno[x] > 0) && (disciplinas[i].vetRaAluno[x] < 10)) 
							printf("%s \n", alunos[x].nome);
					}
				}     
			}
		}
	} while(escolha!=0);
}

void msgLimite(){
	printf("Você já tem 10 cadastros\n");
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