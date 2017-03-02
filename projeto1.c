#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 2

struct cadastrarAlunos
{
    char nome_alunos[30];
};

struct cadastrarDisciplinas
{
    char nome_disciplinas[30];
};

struct cadastrarProfessores
{
    char nome_professores[30];
    struct cadastrarAlunos alunos;
    struct cadastrarDisciplinas disciplinas;
};

int contAlunos;
int contDisciplinas;
int contProfessores;

struct cadastrarProfessores professores[LIMITE];


void insercao()
{
    int escolha;
    do
    {
        printf("Voce deseja cadastrar o que?: \n\n");
        printf("[1] - Alunos\n");
        printf("[2] - Disciplinas\n");
        printf("[3] - Professores\n");
        printf("[0] - Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1)
        {
            contAlunos++;
            if(contAlunos>LIMITE)
            {
                printf("Quantidade de alunos excedida \n");
            }
            else
            {
                printf("introduza o nome do aluno: ");
                scanf("%s",professores[contAlunos].alunos.nome_alunos);
                fflush(stdin);
                printf("Aluno cadastro com sucesso \n");
            } 
            
        }

        if(escolha == 2)
        {
            contDisciplinas++;
            if(contDisciplinas>LIMITE)
            {

                printf("Quantidade de disciplinas excedida \n");
            }
            else
            {
                printf("introduza o nome da disciplina: ");
                scanf("%s",professores[contDisciplinas].disciplinas.nome_disciplinas);
                fflush(stdin);

                printf("Disciplina cadastrada com sucesso \n");
            }

        }

        if(escolha == 3)
        {
            contProfessores++;

            if(contProfessores>LIMITE)
            {
                printf("Quantidade de professores excedida \n");
            }
            else
            {
                
                printf("introduza o nome do professor\n");
                scanf("%s", professores[contProfessores].nome_professores);
                fflush(stdin);
                printf("Professor cadastrado com sucesso \n");
            }
             
        }
        
    }while(escolha!=0);
}


void listar()
{
    int escolha,i;
    do
    {
        printf("Voce deseja listar o que?: \n\n");
        printf("[1] - Alunos\n");
        printf("[2] - Disciplinas\n");
        printf("[3] - Professores\n");
        printf("[0] - Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1)
        {
           for(i=0; i<=contAlunos; i++)
           {
                printf("Aluno: %s \n", professores[i].alunos.nome_alunos);
           }
            
        }

        if(escolha == 2)
        {
           for(i=0; i<=contDisciplinas; i++)
           {
                printf("Disciplinas: %s \n", professores[i].disciplinas.nome_disciplinas);
           }
            
        }

        if(escolha == 3)
        {
           for(i=0; i<=contProfessores; i++)
           {
                printf("Professores: %s \n", professores[i].nome_professores);
           }
        }
        
    }while(escolha!=0);
}

int main() 
{ 
	int opcao;
	contAlunos=0;
	contDisciplinas=0;
	contProfessores=0;
 
    do 
     {
            printf("\n\n");
            printf("[1] - Cadastrar \n");
            printf("[2] - listar \n");
            printf("Escolha a opcao: "); 
            scanf("%d", &opcao); 

            switch(opcao) 
            { 
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
		 
	 }while(opcao!=8);
    getchar();
    exit(0);
    }
