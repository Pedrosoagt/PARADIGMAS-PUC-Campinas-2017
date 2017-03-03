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
};

struct cadastrarProfessores {
    char nome[30];
    int codigo;
    struct cadastrarAlunos alunos;
    struct cadastrarDisciplinas disciplinas;
};

int contAlunos;
int contDisciplinas;
int contProfessores;

struct cadastrarProfessores professores[LIMITE];

void insercao() {
    int escolha;
    do {
        printf("Voce deseja cadastrar o que?: \n\n");
        printf("[1] - Alunos\n");
        printf("[2] - Disciplinas\n");
        printf("[3] - Professores\n");
        printf("[0] - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        system("clear");

        if(escolha == 1) {
            contAlunos++;
            if(contAlunos>LIMITE) {
                printf("Quantidade de alunos excedida \n\n");
            } else {
                printf("introduza o nome do aluno: ");
                scanf("%s",professores[contAlunos].alunos.nome);
                fflush(stdin);
                system("clear");
                printf("Aluno cadastro com sucesso! \n\n");
            } 
        } else if(escolha == 2) {
            contDisciplinas++;
            if(contDisciplinas>LIMITE) {
                printf("Quantidade de disciplinas excedida \n\n");
            } else {
                printf("introduza o nome da disciplina: ");
                scanf("%s",professores[contDisciplinas].disciplinas.nome);
                fflush(stdin);
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
                fflush(stdin);
                system("clear");
                printf("Professor cadastrado com sucesso! \n\n");
            }   
        } else {
            printf("Opção Inválida! \n");
        }
    } while(escolha!=0);
}

void listar() {
    int escolha,i;
    do {
        printf("Voce deseja listar o que?: \n\n");
        printf("[1] - Alunos\n");
        printf("[2] - Disciplinas\n");
        printf("[3] - Professores\n");
        printf("[0] - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        system("clear");

        if(escolha == 1) {
           for(i=0; i<=contAlunos; i++) {
                printf("Lista de Alunos %s \n", professores[i].alunos.nome);
           }
        } else if(escolha == 2) {
           for(i=0; i<=contDisciplinas; i++) {
                printf("Lista de Disciplinas %s \n", professores[i].disciplinas.nome);
           }
        } else if(escolha == 3) {
           for(i=0; i<=contProfessores; i++) {
                printf("Lista de Professores %s \n", professores[i].nome);
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
                case 3:
                    break; 
                case 4: 
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
            }  
	 } while(opcao!=0);
    getchar();
    exit(0);
}
