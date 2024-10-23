#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao=0;
	int laco=1;
	//fim da criação de variáveis/string
	
	printf("Digite o CPF à ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s - refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abertura do arquivo para alteração/adição de informações
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome à ser cadastrado: "); //coleta de informações do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//abertura do arquivo para alteração/adição de informações
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para alteração/adição de informações
	fprintf(file, ","); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome à ser cadastrado: ");//coleta de informações do usuário
	scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a"); //abertura do arquivo para alteração/adição de informações
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para alteração/adição de informações
	fprintf(file, ","); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo à ser cadastrado: ");//coleta de informações do usuário
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a");//abertura do arquivo para alteração/adição de informações
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("\nGostaria de cadastrar outro usuário?\n");
	printf("\nDigite '1' para SIM e '2' para NAO: ");
	
	scanf("%d", opcao);
		
	system("cls");

	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		system("pause");
		break;
			
		default:
		printf("Essa opção não está disponível!\n");
		system("pause"); 
		break;
	}
	system("pause"); 
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200]; 
	//fim da criação de variáveis/string	
	
	printf("Digite o CPF a ser consultado: ");//coleta de informações do usuário
	scanf("%s", cpf);
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//abre o arquivo. "r" para leitura das informações
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. Arquivo não localizado.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n"); 
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n"); 

		printf("Opção:");
	
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
			
			case 4:
			printf("Obrigado por utilizado o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	
	}
}
