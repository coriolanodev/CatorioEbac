
#include<stdio.h>                                     //biblioteca de comunicação com o usuário
#include<stdlib.h>                                    //bilbioteca de alocação de espaço em memória
#include<locale.h>                                    //biblioteca de alocações de texto por região
#include<string.h>                                    //biblioteca responsável por cuidar da string

int registro () // função reponsável por cadastrar os usuários no sistema
{            
            //inicio da criação de variáveis /strings
            char arquivo[40];
            char cpf[40];
            char nome[40];
            char sobrenome[40];
            char cargo[40];
            // final da criação criação de variáveis/string
            
            printf("digite o cpf a ser cadastrado:"); //coletando informação do usuário
            scanf("%s",cpf);   //%s refre-se à string
            
            strcpy(arquivo,cpf);                     // responsável por copiar a string digitada pelo usuário
            
            FILE *file;                             //possibilita criar o arquivo
            file=fopen(arquivo,"w");                //cria o arquivo e o "w" significa escrever
            fprintf(file,cpf);                      //salva o valor da variável
			fclose (file);                        //fecha o aqruivo
            
            file=fopen(arquivo,"a");      //atualizar (´por a virgula)
            fprintf(file, ",");
            fclose(file);
            
            printf("digite o nome a ser cadastrado:");
            scanf("%s",nome);
            
            file=fopen(arquivo,"a");
            fprintf(file, nome);
            fclose(file);
            
            file=fopen(arquivo,"a");
            fprintf(file,",");
            fclose(file);
            
            printf("digite o sobrenome a ser cadastrado:");
            scanf("%s",sobrenome);
            
            file=fopen(arquivo,"a");
            fprintf(file, sobrenome);
            fclose(file);
            
            file=fopen(arquivo,"a");
            fprintf(file,",");
            fclose(file);
            
            printf("digite o cargo a ser cadastrado:");
            scanf("%s",cargo);
            
            file=fopen(arquivo,"a");
            fprintf(file, cargo);
            fclose(file);
            
            file=fopen(arquivo,"a");
            fprintf(file,".");
            fclose(file);
            
            system("pause");
            
            
}

int consulta()
{ 
          setlocale(LC_ALL, "portuguese");
		  
		  char cpf[40];
		  char conteudo[200];
		  
		  printf("digite o cpf a ser consultado:");
		  scanf("%s",cpf);
		  
		  FILE *file;
		  file=fopen(cpf,"r");
		  
		  if(file==NULL)
		  {
		  	printf("Não foi possivel abrir o arquivo, não localizado!\n");
		  }
		  
		  while(fgets(conteudo,200,file)!=NULL){
		  	printf("\nEssas são as informações do usuário:\n");
		  	printf(" %s",conteudo);
		  	printf("\n\n");
		  }
		  
		  system("pause");
}



int deletar()
{ 
        char cpf[40];
		
		printf("Digite o cpf do usuário a ser deletado:");
		scanf("%s", cpf);
		
		remove(cpf);
		printf("cpf deletado com sucesso!\n");
		
		FILE*file;
		file=fopen(cpf, "r");
		
		if(file==NULL)
		{
			printf("Usuário não se encontra no sistema!\n");
			system("pause");
		}
         
}


int main ()
{
	int opcao=0; 
	int laco=1;                                              //definindo as variáveis
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	
	     setlocale(LC_ALL, "portuguese");                          //definindo a linguagem
	
    	printf("---CARTÓRIO DA EBAC---\n\n");                     //inicio do MENU
    	printf("Escolha a opção desejada no menu:\n\n");       
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n");
	    printf("opção:");                                        //fim do MENU
	
    	scanf("%d", &opcao);                                    //armazenando a aescolha do usuário
	    system("cls");  // responsável por limpar a tela
	    
	    switch(opcao) { // início da seleçaõ do menu	    {
	    	case 1:
	    	registro();  //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
				
			default:
			   printf("ESSA OPÇÃO NÃO ESTÁ DISPONÍVEL!\n");
			   system("pause");
			   break;	
				
		}
	
	    
	
    }
}





