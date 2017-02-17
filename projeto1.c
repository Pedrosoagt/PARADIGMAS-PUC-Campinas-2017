
/* Nome: {Murilo Santana      RA: 12662185
         {Felipe Giorgetti    RA: 12020202
         
         Opcionais Funcionando: {OPCIONAL 1
         			{OPCIONAL 2
         			{OPCIONAL 3
         			{OPCIONAL 4
 */
	 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define azul "\033[0;34m"
#define fundo_branco "\033[0;40m"
#define vermelho "\033[0;35m"


typedef struct GERENCIAMENTO_DE_MUSICAS        
{ 
	char genero[30];
	char titulo[30];
	char interprete[30];
	struct tm criacao, alteracao;  
	int tm_min,tm_sec,tm_hour;
	struct GERENCIAMENTO_DE_MUSICAS *proximo; 
	int armazena,lixo; 
	 
}G_MUSICAS; 


//_______________________________________________________________________


void insere_ordenado(G_MUSICAS **lista, G_MUSICAS *nova)     
{ 
       G_MUSICAS *aux = (*lista); 
  
        if(aux == NULL)
  	{
    		(*lista) = nova;
        }
        else if (strcasecmp(aux->titulo, nova->titulo) == 1)   
  	{
    		nova->proximo = aux;
    		*lista = nova;    
  	}
        else
    		insere_ordenado(&(aux->proximo), nova);
}


//_______________________________________________________________________


void adiciona_musicas(G_MUSICAS **inicio)
{
    struct tm *local;
    time_t t;

    t = time(NULL); 
    local=localtime(&t); 

    local->tm_mon=local->tm_mon+1; 
    local->tm_year=local->tm_year+1900;   
 
    G_MUSICAS *aux, *list = (*inicio);
    
    if((aux = (G_MUSICAS*) malloc(sizeof(G_MUSICAS))) != NULL) 
    { 
    	      system("clear");	
    	      printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        CADASTRO DE MUSICAS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
		
		printf("Musica \n"); 
		__fpurge(stdin); 
		gets(aux->titulo);
		printf("Genero \n"); 
		__fpurge(stdin); 
		gets(aux->genero);
		printf("Interprete \n"); 
		__fpurge(stdin);
		gets(aux->interprete);
		aux -> armazena = 1;
		aux->criacao=(*local);
		aux->alteracao=(*local);
		
		aux -> proximo = NULL;  //aponto minha struct para o null para depois ordenar
		insere_ordenado(&(*inicio), aux); //chamo a recursão insere_ordenado
		
    
    }
	
}


//___________________________________________________________________________


void listar_musicas(G_MUSICAS **inicio) 
{
	
	G_MUSICAS *aux1;
	aux1=(*inicio);	
	system("clear");
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        MUSICAS CADASTRADAS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
               
              
	 while( aux1 != NULL) 
	  {
	        if(aux1 -> armazena==1)  
	        {
	        	
		printf("Titulo: %s \n", aux1-> titulo); 
		printf("Genero: %s \n", aux1-> genero ); 
		printf("Interprete: %s \n\n",aux1 -> interprete);      
		printf("Data de Criacao %d/%d/%d\n",aux1->criacao.tm_mday,aux1->criacao.tm_mon,aux1->criacao.tm_year);
		printf("Hora de Criacao: %02d:%02d:%02d\n\n", aux1->criacao.tm_hour, aux1->criacao.tm_min, aux1->criacao.tm_sec); 
		
		}
		
		aux1 = aux1 -> proximo;
		
		 
	   } 
	printf("\n\n\n<<<< ENTER>>>>> para voltar ao menu principal");
  	getchar();getchar();		 

}


//___________________________________________________________________________


void buscar(G_MUSICAS *inicio)
{
	char busca[30];		
	if((inicio)== NULL)
	{
		
		printf("\nImpossible de encontrar\n\n");
	}else{
		
	      int opcao2;
	      system("clear");
	      printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              		printf(" | ");printf("\t\t\t     Buscar por:");printf("\t\t\t              |\n");
              		printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	      
	      printf("[1] - Titulo \n");
	      printf("[2] - Interprete \n");
	      scanf("%d", &opcao2);
	      
	      if(opcao2 == 1)
	      {
	      printf("Introduza o nome do titulo para buscar: \n");		
	      __fpurge(stdin); 
	      gets(busca);
	      
	      while(inicio != NULL)
	      {
	      
		if((strcasecmp(inicio -> titulo,busca) == 0)&& (inicio->armazena==1))
		  {
		        
		        system("clear");
	      		printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              		printf(" | ");printf("\t\t\t     BUSCAR MUSICAS");printf("\t\t\t              |\n");
              		printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	      		
	      		printf("Titulo: %s \n", inicio-> titulo); 
			printf("Genero: %s \n", inicio-> genero ); 
			printf("Interprete: %s \n\n",inicio -> interprete);
			
			
		  }else
	               printf("");
		      inicio = inicio -> proximo;
	      }
      
		
  }
  printf("\n\n<<<< ENTER>>>>> para voltar ao menu principal");
  getchar();
  
  if(opcao2 == 2)
  {
      printf("Introduza o nome do Interprete para buscar: \n");		
      __fpurge(stdin); 
      gets(busca);
      
      while(inicio != NULL)
      {
         if((strcasecmp(inicio -> interprete,busca) == 0)&& (inicio->armazena==1))
	      {
	      		system("clear");	
	      		printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              		printf(" | ");printf("\t\t\t     BUSCAR MUSICAS");printf("\t\t\t                       |\n");
              		printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	      		
	      		printf("Titulo: %s \n", inicio-> titulo); 
			printf("Genero: %s \n", inicio-> genero ); 
			printf("Interprete: %s \n\n",inicio -> interprete);
	      
	      }else
	      
               printf("");
    	      inicio = inicio -> proximo;
    } 
  }
   printf("\n\n<<<< ENTER>>>>> para voltar ao menu principal");   
   getchar(); getchar();
    
 }
}


//________________________________________________________________________________________


void remover_elems(G_MUSICAS **inicio)
{
	G_MUSICAS *aux,*remove = NULL;;
	aux = (*inicio);

	char remocao[30];
	system("clear");
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
	printf(" | ");printf("\t\t\t REMOVER MUSICAS");printf("\t\t\t                       |\n");
	printf(" %c----------------------------------------------------------------------------%c\n",200,188);

	int opcao_remove;

	printf("[1] - Remover por Genero\n");
	printf("[2] - Remover por interprete \n");
	scanf("%d", &opcao_remove) ;

	if(opcao_remove == 1)
	{

		printf("Introduza o nome da musica para remocao: \n");
		__fpurge(stdin);
		gets(remocao);


	while((aux!=NULL) &&(strcasecmp(aux->titulo,remocao)!=0))
	{
		aux=aux->proximo;
	}

	aux->armazena=-1;


	}
	else
	{

	if(opcao_remove==2)

	{
		system("clear");
		printf(" %c----------------------------------------------------------------------------%c\n",201,187);
		printf(" | ");printf("\t\t\t REMOVER MUSICAS");printf("\t\t\t |\n");
		printf(" %c----------------------------------------------------------------------------%c\n",200,188);

		printf("Introduza o nome da musica para remocao: \n");
		__fpurge(stdin);
		gets(remocao);

		while((aux!=NULL) &&(strcasecmp(aux->interprete,remocao)!=0))
		{

			aux = aux-> proximo;
			

		}
		
		aux -> armazena=-1;

	        }
	
		
	}


}


//_____________________________________________________________________________________



void alterar_info(G_MUSICAS **inicio)
{
	G_MUSICAS *recebe;
	char alterar[30];
	system("clear");
	printf("Introduza o cadastro que deseja alterar: \n");
	__fpurge(stdin); 
	gets(alterar);
	recebe = (*inicio);
       
		       while(strcasecmp(recebe->titulo,alterar) !=0)
		       {
		       
				recebe= recebe->proximo;
		       
		       }
			if(inicio!= NULL)
		    	    {
		
				recebe->armazena=-1;
				adiciona_musicas(&(*inicio)); 
			    }
			else{
		     
				printf("\n  Nao encontrado \n");
			 
			    }
		   
		   printf("\n\n<<<< ENTER>>>>> para voltar ao menu principal");
		   getchar(); getchar(); 
		   
		    
}


//_________________________________________________________________________________________

void Recuperar (G_MUSICAS **inicio)
{
	G_MUSICAS *aux;
	aux = (*inicio);

	int w=0,opcao_recupera;
	char recuperar[30];
	system("clear");
	
	
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
	printf(" | ");printf("\t\t\t RECUPERAR MUSICAS");printf("\t\t\t |\n");
	printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	
	printf("Deseja recuperar por: \n");
	printf("[1] - Genero \n");
	printf("[2] - Interprete\n");
	scanf("%d",&opcao_recupera);
	
	if(opcao_recupera == 1){
	printf("Introduza o cadastro que deseja recuperar \n");
	__fpurge(stdin);
	gets(recuperar);

	while (aux!= NULL)
	{
		
		if ((strcasecmp(aux->titulo,recuperar) == 0) && (aux->armazena==-1))
		  {

			aux->armazena=1;
			w++;
		  }

		aux = aux->proximo;
	}
	if (w == 0)
	printf("O titulo digitado nao existe!\n");
	else
	printf("Musica recuperada com sucesso!\n");

	getchar();
	
}else{ 

	if(opcao_recupera==2)
	{
		
	printf("Introduza o cadastro que deseja recuperar \n");
	__fpurge(stdin);
	gets(recuperar);

	while (aux!= NULL)
	{
		
		if ((strcasecmp(aux->interprete,recuperar) == 0) && (aux->armazena==-1))
		  {

			aux->armazena=1;
			w++;
		  }

		aux = aux->proximo;
	}
	
	if (w == 0)
	printf("O titulo digitado nao existe!\n");
	else
	printf("Musica recuperada com sucesso!\n");

	getchar();
	
	
          }
          
      
      }


}



//____________________________________________________________________________________________

void lixeira(G_MUSICAS **inicio)
{
	
	G_MUSICAS *aux1;
	aux1=(*inicio);	
	system("clear");
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        MUSICAS CADASTRADAS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
               
              
	 while( aux1 != NULL) 
	  {
	        
	        if(aux1 -> armazena==-1)
	        
	        {
	        	
		printf("Titulo: %s \n", aux1-> titulo); 
		printf("Genero: %s \n", aux1-> genero ); 
		printf("Interprete: %s \n\n",aux1 -> interprete);      
		printf("Data de Criacao %d/%d/%d\n",aux1->criacao.tm_mday,aux1->criacao.tm_mon,aux1->criacao.tm_year);
		printf("Hora de Criacao: %02d:%02d:%02d\n\n", aux1->criacao.tm_hour, aux1->criacao.tm_min, aux1->criacao.tm_sec); 
		
		}
		
		aux1 = aux1 -> proximo;
		
		 
	   } 
	printf("\n\n\n<<<< ENTER>>>>> para voltar ao menu principal");
  	getchar();getchar();		 

} 





//_____________________________________________________________________________________________


int main() 
{ 
	G_MUSICAS *inicio = NULL;
	int opcao;
	char busca[30];		
 do 
     { 
		system("clear");
		    
      		printf("\t\t\t Eng. de Computação - Puc-campinas\n");
			  		printf("\t\t\t      By Murilo Santana e Bruno Pedroso\n\n");                                   
		printf(" %c############################################################################%c\n",201,187);
		printf(" |									      |\n");
      		printf(" | ");printf("\t\t\t     PROCESSO DE MATRICULA");printf("\t\t\t      |\n");
      		printf(" |									      |");
      		printf("\n %c############################################################################%c\n\n\n",200,188);
	
		  
	        printf("   %c####################################################################%c\n",200,188);
		printf("   | [1]  Cadastrar alunos 	             				|\n");                      
      		printf("   |####################################################################|\n");
      		printf("   | [2]  Cadastrar disciplinas              				|\n");           
      		printf("   |####################################################################|\n");
      		printf("   | [3]  Cadastrar professores              				|\n");      
      		printf("   |####################################################################|\n");
      		printf("   | [4]  Cancelar Disciplina                				|\n");
      		printf("   |####################################################################|\n");
      		printf("   | [5]  Listagem de alunos                 				|\n");
                printf("   |####################################################################|\n");
      		printf("   | [6]  Listagem de disciplinas            				|\n");
      		printf("   |####################################################################|\n");
      		printf("   | [7]  Listagem de professores            				|\n");
                printf("   |####################################################################|\n");
      		printf("   | [8]  Listagem de disciplinas de um aluno				|\n");
                printf("   |####################################################################|\n");
      		printf("   | [9]  Listagem de alunos em uma disciplina                          |\n ");
		printf("  | ###################################################################|\n");
      		printf("   | [10] Listagem de todas as disciplinas de um professor              |\n ");
		printf("  | ###################################################################|\n");
      		printf("   | [11] Listagem de todos os professores vinculados a uma disciplina. |\n ");          
      		printf("   %c####################################################################%c",200,188);

      		
		printf("\nEscolha a opcao desejada: "); 
		scanf("%d", &opcao); 
		switch(opcao) 
		{ 
			case  1: 
				adiciona_musicas(&inicio); 
				break; 
			case  2:
				remover_elems(&inicio); 
				break; 
			case 3:
				alterar_info(&inicio);
				break; 
			case 4: 
				buscar(inicio);
				break;
			case 5:
				listar_musicas(&inicio); 
				break;
			case 6:
				Recuperar(&inicio);
				break;
			case 7:
				lixeira(&inicio);
				break;
		} 
		 
	 }while(opcao!=8); 


getchar();
exit(0);
}







