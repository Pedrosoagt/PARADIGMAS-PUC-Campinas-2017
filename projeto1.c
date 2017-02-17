// Murilo Santana RA: 12662185
// Felipe Giorgetti RA: 12020202

//Opcionais Funcionando: 1,2,3 !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct AGENDA
{
        double CPF;
        char nome[30];
        double TEL;
        struct AGENDA *esq,*dir;
        
        
        

}no;

void inserirNo(no **raiz, no dados)
{ 
	     if((*raiz) == NULL)
	     {
		        (*raiz) = (no *)malloc(sizeof(no));
		        (**raiz) = dados;
		        (*raiz)->dir = (*raiz)->esq = NULL; 
		        
	     return ;

	     }

	     if(dados.CPF < (*raiz)-> CPF)
	     {
		          
		        inserirNo (& (*raiz) -> esq,dados);
		        return;
		        
	     }
	     
	     else
	     {
	     
		 if(dados.CPF > (*raiz)->CPF)
		   {
		        
		        inserirNo(&(*raiz)->dir,dados);
		        return;
		        
		        
		   }
	      
	      
	       }



	}

void incluir(no **raiz)            
{
	
    

     int opcao=0;    
     no aux;
     
     printf("Nome: ");
     __fpurge(stdin);
     fgets(aux.nome, sizeof(aux.nome), stdin);
    
      printf("CPF: ");
     __fpurge(stdin);
     scanf("%lf", &aux.CPF);
     
     printf("Telefone: ");
     __fpurge(stdin);
     scanf("%lf", &aux.TEL);


     inserirNo(raiz,aux);
     

}


void Ordem(no *raiz)
{   
     	    
        if(raiz)
        {   
             Ordem(raiz -> esq);
             
             printf("Nome: %s", raiz -> nome);
             printf("CPF: %0.lf\n", raiz -> CPF);
             printf("Telefone: %0.lf\n\n", raiz -> TEL);
             
             Ordem(raiz -> dir);     
        }
             
             
}


int rem(no **raiz)    
{
	
	
		if((*raiz)->dir == NULL)
		{
			int n = (*raiz) -> CPF;
			(*raiz) = (*raiz) -> esq;
			return (n);
		}
	
		return (rem(&(*raiz)->dir));
	
	 	
}



void remover(no **raiz, double CPF_avulso)
{

	if ((*raiz)!=NULL)
	{
		
		printf("Remover CPF: ");
		scanf("%lf", &CPF_avulso);
		
		if (CPF_avulso == (*raiz)->CPF)
		{
			
			
			if((*raiz)->dir == NULL)
			(*raiz)=(*raiz)->esq;

			
			else if ((*raiz)->esq == NULL)
			(*raiz)=(*raiz)->dir;

		
		
		else
		(*raiz)->CPF=rem(&(*raiz));
		}

	
	else if ((*raiz)->CPF > CPF_avulso)
	remover(&(*raiz)->esq,CPF_avulso);


  else
  remover(&(*raiz)->dir,CPF_avulso);
 }
 
}

void remover_a(no **raiz, double CPF_avulso)
{
	if ((*raiz)!=NULL)
	{
	
		if (CPF_avulso == (*raiz)->CPF)
		{
			
			
			if((*raiz)->dir == NULL)
			(*raiz)=(*raiz)->esq;

			
			else if ((*raiz)->esq == NULL)
			(*raiz)=(*raiz)->dir;

		
		
		else
		(*raiz)->CPF=rem(&(*raiz));
		}

	
	else if ((*raiz)->CPF > CPF_avulso)
	remover(&(*raiz)->esq,CPF_avulso);


  else
  remover(&(*raiz)->dir,CPF_avulso);
 }
 
}



void buscar_n(no *raiz, char *String)
{
		clock_t start_time;
  		start_time = clock();
  			
		if (raiz)
		{
			
			
			if( strstr (raiz->nome,String))
			{
			
				printf("Nome: %s", raiz -> nome);
				printf("CPF: %0.lf\n", raiz -> CPF);
				printf("Telefone: %0.lf\n", raiz -> TEL);
				getchar();
			
			}
		}

		else{
			
			return;
		    }		


		buscar_n(raiz -> dir, String);
		buscar_n(raiz -> esq, String);
		
		double time_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
		printf(" TEMPO: %2.lf", time_in_seconds);
		
}
  

buscar_c(no *raiz, double CPF_avulso2)
{
	if(raiz)
	{
		
		
		if(CPF_avulso2 == raiz -> CPF )
		{
		      printf("Nome: %s", raiz -> nome);
		      printf("CPF: %0.lf\n", raiz -> CPF);
		      printf("Telefone: %0.lf\n", raiz -> TEL);
		      getchar();
				      
		}
					 
			if( CPF_avulso2 < raiz -> CPF )
				buscar_c (raiz -> esq, CPF_avulso2);
			
			if(CPF_avulso2 > raiz -> CPF)
				buscar_c (raiz -> dir, CPF_avulso2);
		
		
		
			 
	}
		     

}

int tamanho (no **raiz,double n)
{
	if((*raiz)!=NULL)
	{

		if((*raiz)->CPF == n) 
			return 1;

		if(n > (*raiz)->CPF) 
			return (1+ tamanho(&(*raiz)->dir,n));

		else if(n < (*raiz)->CPF) 
			return (1+ tamanho(&(*raiz)->esq,n));
		
	}
		
}		

void func(no **raiz,double n)
{
	
	printf("CPF Altura: ");
	scanf("%lf", &n);
	tamanho(&(*raiz), n);
	printf("Tamanho: %0.lf\n", n);
	getchar();
	

}

buscar_t(no *raiz, double tele)
{
	if(raiz)
	{
		if(tele == raiz -> TEL )
		{
		      printf("Nome: %s", raiz -> nome);
		      printf("CPF: %0.lf\n", raiz -> CPF);
		      printf("Telefone: %0.lf\n", raiz -> TEL);
		      getchar();
				      
		}
					 
			if( tele < raiz -> TEL )
				buscar_c (raiz -> esq, tele);
			
			if(tele > raiz -> TEL)
				buscar_c (raiz -> dir, tele);	 
	}
		     

}

void buscar(no *raiz, double CPF_avulso2,double tele)
{
	int choyce;
	char String[30];
	
	
	printf("Buscar por: \n");
	printf("[1] - CPF\n");
	printf("[2] - Nome\n");
	printf("[3] - Telefone\n");
	scanf("%d", &choyce);
		
	if(choyce == 1)
	{
	
		printf("\nBuscar CPF: ");
		scanf("%lf", &CPF_avulso2);
		buscar_c(raiz, CPF_avulso2);
	}
		
	if(choyce == 2)
	{ 
		printf("Buscar Nome: ");
		__fpurge(stdin);
		gets(String);
	  	buscar_n(raiz, String); 
	}
	
	if(choyce == 3)
	{
		
		printf("Buscar Telefone: ");
		scanf("%lf", &tele);
		buscar_t(raiz, tele);
	}
	     
}
void alterar(no **raiz, double CPF_avulso3)
{
	
	if( (*raiz)!= NULL)
	{
		printf("introduza o CPF a ser alterado \n");
		scanf("%lf", &CPF_avulso3);
		
		if(CPF_avulso3 == (*raiz) -> CPF )
		{
			remover_a(raiz,CPF_avulso3);
			incluir(raiz); 
		}
		else
		{
			printf("");
		}
		
	}
}
	    
  
main()
{

      no *raiz = NULL;
      int opcao=0;
      double CPF_avulso, CPF_avulso2, CPF_avulso3, tele,n;

do{
	  
          system("clear");
					          
          				printf("\t\t\t Eng. de Computação - Puc-campinas\n");
			  		printf("\t\t\t      By Murilo Santana e Bruno Pedroso\n\n");                                   
		printf(" %c############################################################################%c\n",201,187);
		printf(" |									      |\n");
      		printf(" | ");printf("\t\t\t     PROCESSO DE MATRICULA");printf("\t\t\t      	      |\n");
      		printf(" |									      |");
      		printf("\n %c############################################################################%c\n\n\n",200,188);
	
		  
	        printf("   %c###################################%c\n",200,188);
		printf("   | [1]  Cadastrar alunos 	       |\n");                      
      		printf("   |###################################|\n");
      		printf("   | [2]  Cadastrar disciplinas        |\n");           
      		printf("   |###################################|\n");
      		printf("   | [3]  Cadastrar professores        |\n");      
      		printf("   |###################################|\n");
      		printf("   | [4]  Cancelar Disciplina          |\n");
      		printf("   |###################################|\n");
      		printf("   | [5]  Listagem de alunos           |\n");
                printf("   |###################################|\n");
      		printf("   | [6]  Listagem de disciplinas      |\n");
      		printf("   |###################################|\n");
      		printf("   | [7]  Sair                         |\n ");      
      		printf("   %c###################################%c",200,188);
      		printf("\n\n");

		  printf("\tEscolha Opcao: ");
		  scanf("%d", &opcao);
		  __fpurge(stdin);
		  printf("\n");
		  
		  switch(opcao)
		  {
		           
		           case 1:
		           incluir(&raiz);
		           break;
		           
		           case 2:
		           remover(&raiz,CPF_avulso);getchar();
		           break;
		           
		           case 3:
		           alterar(&raiz, CPF_avulso3);
		           break;
		           
		           case 4:
		           buscar(raiz,CPF_avulso2,tele);getchar();
		           break;
		           
		           case 5:
		           Ordem(raiz);getchar();
		           break;
		           
		           case 6:
		           func(&raiz,n);getchar(); 
		           
		           
		  }
          
          
   }while(opcao!=7);
   

system("");
}
