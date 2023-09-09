#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string // conjunto de variaveis 

int registro() // função responsavel por cadastrar os usuarios no sistema
{
	// inicio criaçao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criaçao de variaveis/strings
	
	printf("Digite o Cpf a ser cadastrado: "); // coletando informação do usuario
	scanf("%s", cpf) //%s refere-se a strings
	
	;strcpy(arquivo, cpf);  //responsavel por copiar valores das string
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo e o "w" siginifica escrever 
	fprintf(file, "\nCpf:");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file);  // fecho o arquivo ( imoportante sempre fechar )
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome:");
	fclose(file);
	
	printf("Digite o Nome a ser Cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome:");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // "a" Ele adiciona as informação dentro do arquivo e inclue tudo oque voce digitou
	fprintf(file,sobrenome); // Esse comando salva a variavel "sobrenome" dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); //FOPEN serve para abrir o arquivo
	fprintf(file, "\nCargo:"); 
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,".\n\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fclose(file);

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem // Sempre colocar esse comando quando for criar funçoes com assento
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado\n\n");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	printf("\nEssas são as informaçoes do usuario:\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem // Sempre colocar esse comando quando for criar funçoes com assento
	
	char cpf[40];
	
	printf("digite o cpf a ser deletado\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("Usuario Deletado!.\n");
		system("pause");
	}
	
}

int main()
{
   int opcao=0; // definindo a variavel
   int x=1;
   
   for(x=1;x=1;)
	{
 		system ("cls"); // responsavel por limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
   
   		printf("$$$ Cartório do Gui $$$\n\n"); // inicio do menu
   		printf("Escolha a opção desejada do menu:\n\n");
   		printf("\t1- Registrar nomes\n"); 
   		printf("\t2- consultar nomes\n");
   		printf("\t3- Deletar nomes\n\n");
   		printf("\t4- Sair do sistema\n");
		printf("opção:"); // final de menu
   
   		scanf("%d", &opcao); // armazenando a esocolha do usuario
   
   		system("cls");
   	
   		switch(opcao) // inicio da seleção de menus
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta();
   			break;
   			
			case 3: 
   			deletar();
			break;
			
			case 4
			:printf("Obrigado por utilizar o sistema!");
			return 0; // "Return 0" Server para quabrar uma função e sair do sistema
			break;
			
			default:
			printf("Éssa opção não está disponivel\n");
   			system("pause");
   			break;
		}
	}
}
