#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação em espaço de memória
#include <locale.h> //biblioteca de alocação de textos
#include <stdbool.h> //biblioteca de valores booleanos
#include <string.h> //Biblioteca de strings

int registro()
{	
	//Declarando variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int registrar_novo_aluno;
	bool registrando = true;
	
	
	while(registrando)//Iniciando o processo de registro
	{
	
		printf("Digite o CPF do usuário a ser cadastrado: (Digite 's' para voltar ao menu principal)\n"); //Coletando informação do usuário
		scanf("%s", cpf);
		
		if(strcmp(cpf, "s") == 0)//Validando resposta do usuário
		{
			break;
		}
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
		
		FILE *file; //Cria o arquivo file
		file = fopen(arquivo, "w"); //Abre o arquivo em modo de escrita
		fprintf(file, cpf); //Insere o valor da variavel cpf
		fclose(file);// Fecha o arquivo 
		
		file = fopen(arquivo, "a"); //Abre o arquivo em modo para atualizar arquivo existente
		fprintf(file,","); //Insere uma virgula no arquivo
		fclose(file);// Fecha o arquivo 
			
		printf("Digite o nome: \n");//Coletando informação do usuário
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); 
		fprintf(file, nome); //Insere o valor da variavel nome
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,","); 
		fclose(file);
		
		printf("Digite o sobrenome: \n");//Coletando informação do usuário
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a"); 
		fprintf(file, sobrenome); //Insere o valor da variavel sobrenome
		fclose(file); 
		
		file = fopen(arquivo, "a"); 
		fprintf(file,","); 
		fclose(file);
		
		printf("Qual cargo que ocupa atualmente: \n");//Coletando informação do usuário
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a"); 
		fprintf(file, cargo); //Insere o valor da variavel cargo
		fclose(file);
		
		printf("Deseja registrar um novo usuário? Digite 0 para 'não' ou  1 para 'sim'\n");//Valida a decisão do usuário
		scanf("%d", &registrar_novo_aluno);
		
		if(registrar_novo_aluno == 0)//Validando resposta do usuário
		{
			registrando = false;
		}
	}	
}

int consultar()
{
	//Declarando variáveis
	char cpf[40];
	char conteudo[200];
	bool consultando = true;
	int consultar_novo_aluno;
	
	while(consultando)//Iniciando o processo de consulta
	{
	
		printf("Digite o CPF do usuário a ser consultado: (Digite 's' para voltar ao menu principal)\n"); //Coletando informação do usuário
		scanf("%s", cpf);
		
		if(strcmp(cpf, "s") == 0)//Validando resposta do usuário
		{
			break;
		}
		
		FILE *file;//Cria o arquivo file
		file = fopen(cpf, "r"); //Abrindo arquivo em modo de leitura
		
		if(file == NULL)//Verifica se o arquivo existe
		{
			printf("Não foi possivel encontrar o registro\n");
			printf("Deseja consultar um novo usuário? Digite 0 para 'não' ou  1 para 'sim'\n");
			scanf("%d", &consultar_novo_aluno);

			if(consultar_novo_aluno == 0)//Validando resposta do usuário
			{
				break;
			}
		}
		
		while (fgets(conteudo, 200, file) != NULL) //Verificando se o conteudo do arquivo é nulo
		{
			printf("\nEssas são as informações do usuário:\n\n");
			printf("%s", conteudo); //Printando informações do usuário
			printf("\n\n");
		}
		
		printf("Deseja consultar um novo usuário? Digite 0 para 'não' ou  1 para 'sim'\n");
		scanf("%d", &consultar_novo_aluno);

		if(consultar_novo_aluno == 0)//Validando resposta do usuário
		{	
			break;
		}
		
	}
	
}

int deletar()
{	
	//Declarando variáveis
	char cpf[40];
	char conteudo[200];
	bool deletando = true;
	int deletar_novo_aluno;
	int confirmar_exclusao;
	int tentar_deletar_novamente;
	

	while(true)//Iniciando a função de deletar
	{
		
		printf("Digite o CPF do usuário a ser deletado: (Digite 's' para voltar ao menu principal)\n"); //Coletando informação do usuário
		scanf("%s", cpf);
		
		if(strcmp(cpf, "s") == 0)//Validando resposta do usuário
		{
			break;
		}
					
			while(deletando)//Iniciando o processo de exclusão
			{	
				FILE *file;//Cria o arquivo file
				file = fopen(cpf, "r"); //Abrindo arquivo em modo de leitura
						
				if(file == NULL) //Verificando se o arquivo existe
				{
					printf("Não foi possivel encontrar o registro\n");
					break;
				}

				if (fgets(conteudo, 200, file) != NULL) //Verificando se o conte�do do arquivo � nulo
				{
					printf("O registro foi encontrado.");
					printf("\nEssas são as informações do usuário:\n\n"); //Imprime as informações do arquivo na tela
					printf("%s", conteudo);
					printf("\n\n");
					fclose(file);//Fecha o arquivo file
					printf("Deseja prosseguir com a exclusão? Digite 0 para 'não' ou  1 para 'sim'\n"); //Valida se o usuario quer deletar o registro
					scanf("%d", &confirmar_exclusao);

					if (confirmar_exclusao == 1)//Validando resposta do usuário
					{
						remove(cpf); //Deletando arquivo com dados do usuário
					}

					FILE *file;// Cria o arquivo
					file = fopen(cpf, "r"); //Abrindo arquivo em modo de leitura
							
					if(file == NULL)//Verifica se o arquivo ainda existe
					{
						printf("Usuario deletado com sucesso.\n");
						break;
					}
					else
					{
						printf("O usuario não foi deletado.\n");
						printf("Deseja tentar deletar este usuario novamente? Digite 0 para 'não' ou  1 para 'sim'\n");//Validando opção do usuário
						scanf("%d", &tentar_deletar_novamente);
						
						if (tentar_deletar_novamente == 0)//Validando resposta do usuário
						{
							break;
						}

					}

				}
			}

		printf("Deseja deletar um novo usuário? Digite 0 para 'não' ou  1 para 'sim'\n");
		scanf("%d", &deletar_novo_aluno);

		if(deletar_novo_aluno == 0)//Validando resposta do usuário
		{
			break;
		}
	}
	
}

int main ()
{
	//Declarando variaveis
	bool iniciar_programa = true;
	int opcao = 0;
	
	while (iniciar_programa)//Iniciando o menu principal
	{
		system("cls"); //Deletando informações da tela
		
		setlocale(LC_ALL, "Portuguese");
		
		
		//Descrevendo o titulo e o menu de opções na tela
		printf("### Cartório da EBAC ### \n\n");//Inicio do menu
		printf("Escolha a Opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do programa\n\n"); 
		printf("Opção: ");// Fim do menu
		
		scanf("%d", &opcao); //Solicitando e armazenando a escolha do usuario		
		system("cls");
	
		//Validando resposta do usuário
		switch(opcao)
		{	
		
			case 1:
				registro();//Chama a função registro
			break;
			
			case 2:
				consultar();//Chama a função consultar
			break;
			
			case 3:
				deletar();//Chama a função deletar
			break;

			case 4:	
				printf("Obrigado por utilizar o programa!!\n\n");
				system("pause");
				iniciar_programa = false;
			break;
			
			default:
				printf("Esta opção não está disponível\n");
				printf("Digite apenas um número de 1 a 3\n\n");
			break;
			//Fim da seleção
		}
		
	}

} 