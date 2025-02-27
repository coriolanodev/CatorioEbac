
#include<stdio.h>                                     //biblioteca de comunica��o com o usu�rio
#include<stdlib.h>                                    //bilbioteca de aloca��o de espa�o em mem�ria
#include<locale.h>                                    //biblioteca de aloca��es de texto por regi�o
#include<string.h>                                    //biblioteca respons�vel por cuidar da string

int registro () // fun��o repons�vel por cadastrar os usu�rios no sistema
{            
            //inicio da cria��o de vari�veis /strings
            char arquivo[40];
            char cpf[40];
            char nome[40];
            char sobrenome[40];
            char cargo[40];
            // final da cria��o cria��o de vari�veis/string
            
            printf("digite o cpf a ser cadastrado:"); //coletando informa��o do usu�rio
            scanf("%s",cpf);   //%s refre-se � string
            
            strcpy(arquivo,cpf);                     // respons�vel por copiar a string digitada pelo usu�rio
            
            FILE *file;                             //possibilita criar o arquivo
            file=fopen(arquivo,"w");                //cria o arquivo e o "w" significa escrever
            fprintf(file,cpf);                      //salva o valor da vari�vel
			fclose (file);                        //fecha o aqruivo
            
            file=fopen(arquivo,"a");      //atualizar (�por a virgula)
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
		  	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
		  }
		  
		  while(fgets(conteudo,200,file)!=NULL){
		  	printf("\nEssas s�o as informa��es do usu�rio:\n");
		  	printf(" %s",conteudo);
		  	printf("\n\n");
		  }
		  
		  system("pause");
}



int deletar()
{ 
        char cpf[40];
		
		printf("Digite o cpf do usu�rio a ser deletado:");
		scanf("%s", cpf);
		
		remove(cpf);
		printf("cpf deletado com sucesso!\n");
		
		FILE*file;
		file=fopen(cpf, "r");
		
		if(file==NULL)
		{
			printf("Usu�rio n�o se encontra no sistema!\n");
			system("pause");
		}
         
}


int main ()
{
	int opcao=0; 
	int laco=1;                                              //definindo as vari�veis
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	
	     setlocale(LC_ALL, "portuguese");                          //definindo a linguagem
	
    	printf("---CART�RIO DA EBAC---\n\n");                     //inicio do MENU
    	printf("Escolha a op��o desejada no menu:\n\n");       
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n");
	    printf("op��o:");                                        //fim do MENU
	
    	scanf("%d", &opcao);                                    //armazenando a aescolha do usu�rio
	    system("cls");  // respons�vel por limpar a tela
	    
	    switch(opcao) { // in�cio da sele�a� do menu	    {
	    	case 1:
	    	registro();  //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
				
			default:
			   printf("ESSA OP��O N�O EST� DISPON�VEL!\n");
			   system("pause");
			   break;	
				
		}
	
	    
	
    }
}





