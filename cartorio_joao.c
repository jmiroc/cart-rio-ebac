#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF � ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s - refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome � ser cadastrado: "); //coleta de informa��es do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, ","); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome � ser cadastrado: ");//coleta de informa��es do usu�rio
	scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a"); //abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, ","); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo � ser cadastrado: ");//coleta de informa��es do usu�rio
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a");//abertura do arquivo para altera��o/adi��o de informa��es
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
		
	system("pause"); //congelamento da tela ap�s a inser��o das informa��es antes de voltar para o menu principal
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200]; 
	//fim da cria��o de vari�veis/string	
	
	printf("Digite o CPF a ser consultado: ");//coleta de informa��es do usu�rio
	scanf("%s", cpf);
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abre o arquivo. "r" para leitura das informa��es
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
		
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); 

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL); 
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
}
int main ()
{ 
	int opcao=0; 
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
		
	
		setlocale(LC_ALL, "Portuguese"); 
	
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n"); 
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:");
	
		scanf ("%d", &opcao); 
	
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
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}
	
	}
}
