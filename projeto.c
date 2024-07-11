# include <stdio.h>  // biblioteca de comunicacao com o usuario 
# include <stdlib.h> // biblioteca de alocacao de espaco em memoria 
# include <locale.h> // biblioteca de alocacao de texto por regiao 
# include <string.h> // biblioteca responsavel pela strings

int registro() // funcao responsavel por cadastrar ususarios 
{
	printf("Voce escolheu registro de nomes! \n\n"); // escolha feita pelo usuario
	system("pause");
	
	//inicio da criacao de variaiveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da criacao de variaiveis/string
	
	printf("Digite o CPF a ser Cadastrado: \n"); //Coletado informacao do usuario
	scanf("%s",cpf); // %s refere a string
	
	strcpy(arquivo,cpf); // responsavel por copiar o arquivo
	
	FILE *file; // resposavel por copiar o arquivo
	file= fopen(arquivo,"w"); // cria o arquivo e o w significa escrever
	fprintf(file,cpf); // responsavel salvar a variavel
	fclose(file); // fechar o arquivo
	
	file= fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado! \n");//Coletado informacao do usuario
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // responsavel por abrir arquivo
	fprintf(file,nome);
	fclose(file); //responsavel por fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file); responsavel por fechar arquivo
	
	printf("Digite o Sobrenome a ser cadastrado! \n");//Coletado informacao do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");// responsavel por abrir arquivo
	fprintf (file,sobrenome);
	fclose(file); // responsavel por fechar arquivo
	
	file = fopen(arquivo,"a");// responsavel por abrir arquivo
	fprintf(file,",");
	fclose(file); responsavel por fechar arquivo
	
	printf("Digite o cargo a ser cadastrado \n");//Coletado informacao do usuario
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");// responsavel por abrir arquivo
	fprintf(file,cargo);
	fclose(file); responsavel por fechar arquivo
	
	file = fopen(arquivo,"a"); // responsavel por abrir arquivo
	fprintf (file,",");
	fclose(file); responsavel por fechar arquivo
	
	system("pause");
	   
}
int consultar() // funcao responsavel por consultar ususarios 
{
		setlocale(LC_ALL, "PORTUGUESE"); //definindo a linguagem
	
		printf("Voce escolheu consultar nomes!\n\n"); // escolha feita pelo usuario
		system("pause");
	
		char cpf[40];
		char conteudo[200];
	
		printf("Digite o cpf a ser Consultado: \n "); // responsavel por escrever na tela
		scanf("%s",cpf ); // %s refere a string
	
		FILE *file;
		file = fopen (cpf,"r"); // responsavel por abrir arquivo
	
	if(file == NULL)
	{
		printf("Nao foi possivel encontrar o arquivo do usuario!\n");// responsavel por escrever na tela
	}
	
	while(fgets(conteudo,100,file)!= NULL)
	{
		printf("\n Essas sao as informacoes encontradas do usuario: \n\n"); // responsavel por escrever na tela
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar() // funcao responsavel por deletar ususarios 
{
 	printf("Voce escolheu a opcao deletar nomes!\n\n"); // escolha feita pelo usuario
	
	 //inicio da criacao de variaiveis/string
	 char cpf [40];
	 //fim da criacao de variaiveis/string
	 
	 printf("Digte o cpf do usuario a ser deletado!. \n"); // responsavel por consultar o usuario
	 scanf("%s", cpf); // %s refere a string
	 
	 remove(cpf); // refere-se a remover o usuario
	 
	 FILE *file;
	 file = fopen(cpf,"r");// responsavel por abrir arquivo
	 
	 if(file == NULL) 
	 {
	 	printf("o usuario nao se encontra no sistema. \n");// responsavel por dar a mensagem de usuario nao existe no sistema
	 	system("pause"); // // refere-se em dar tempo de leitura ao usuario 
	 }  
}

int main()
{
	int opcao=0; // definido variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");// comando limpar tela
	
		setlocale(LC_ALL, "PORTUGUESE"); // definindo linguagem
	
		printf ("Registro de nomes \n\n"); // inicio do menu
		printf ("Escolha a opçao desejada \n\n");
		printf ("\t1 - Registrar nomes \n");
		printf ("\t2 - Consultar nomes \n");
		printf ("\t3 - Deletar nomes \n\n");
		printf ("Escolha uma opcao: "); // fim do menu
	
		scanf("%d",&opcao);
	
		system("cls"); //comando para limpeza de tela
		
		switch(opcao)
		{
			case 1: 
			registro(); // chamando a funcao registro  
			break;
			
			case 2:
			consultar(); // chamando a funcao consultar 
			break;
			
			case 3:
			deletar(); // chamando a funcao deletar
			break;
			
			default:
			printf("Esta funcao nao esta disponivel \n\n");
			system("pause");
			break;	
				
		}		
    }	
}
