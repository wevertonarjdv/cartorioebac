#include<stdio.h> //biblioteca de comunica��o com o usuartio
#include <stdlib.h> //biblioteca de aloca��o de espa�o por mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salva o arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s" ,nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s" ,sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s" ,cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
        
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
    {
	    printf("\nEssas s�o as informa��es do usuario: ");
	    printf("%s", conteudo);
	    printf("\n\n");
    }

    system("pause");


}

int deletar()
{
    char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main()
   {
    int opcao=0; //definindo vari�veis
    int laco=1;

    for(laco=1;laco=1;)	
	{

        system("cls");
        
    	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    	
    	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n"); 
        printf("\t4 - Sair do sistema\n\n");
	    printf("op��o: ");//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");
	
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
	
		
		case 2:
       consulta();
    	break;
	
	
	    case 3:
	  deletar();
	    break;
	    
	   case 4:
	   printf("Obrigado ppor ultilizar o sistema!\n");
	   return 0;
	   break;    
	
	    
	    default:
	     printf("Essa op��o n�o est� dispponivel!\n");
		  system("pause");
	    }   	  
	}	
}
