#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memoria 
#include <locale.h> // biblioteca de alocação de texto by regiao
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()
{
	char arquivo[40];// pasta para armazenas as strings, criar historico.
	char cpf[40]; // char é caractere depois a especificação na string o numero para mensurar ao pc qtos caracteres usaremos, caso negativo ele trabalha com infinito
	char nome[40];// string precisa salvar cada caractere em algum lugar. uma pasta.
	char sobrenome [40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);// %S é percet string, para armazenar essa informação
		
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings, banco de dados
	
	FILE *file;// FILE ja é pronto, file é o nome da variavel, cria o arquivo na pasta onde salva o sistema
	file = fopen(arquivo, "w");	// cria o arquivo nome da variavel em descrição ao pc, file = abrir a variavel que é arquivo e esta em W write
	fprintf(file,cpf);// salva o valor da variavel ou seja copia o cpf no arquivo
	fclose(file);// fecha o comando
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o NOME a ser cadastrado:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");// na pasta file = abra o (arquivo , para que ? para atualization...
	fprintf(file, nome);// estando aberto a file , acrescente ... nome
	fclose(file);// fechar comando de atualização
	
	file = fopen(arquivo,"a");// na pasta file = abra o (arquivo) para atualização
	fprintf(file,",");// estando aberto a file , acrescente ... virgula 
	fclose(file);// fecha o comando
	
	
	printf("Digite o SOBRENOME a ser cadastrado:\n");
	scanf("%s", sobrenome); // "%s" referente a salvar na string
	
	file = fopen(arquivo, "a"); // "a" é referente a atualização atualization
	fprintf(file, sobrenome);// estando aberto a file , acrescente ... sobrenome
	fclose(file);// fecha o comando
	
	file = fopen(arquivo, "a");// na pasta file = abra o (arquivo , para que ? para atualization...
	fprintf(file, ",");// estando aberto a file , acrescente ... virgula
	fclose(file);// fecha o comando
	
	
	printf("Digite o CARGO a ser cadastrado:\n");// pergunte ao usuario o texto entre parenteses
	scanf("%s", cargo);// %S salve na string 
	
	file = fopen(arquivo, "a");// na pasta file, abra fopne o (arquivo) para atualization.
	fprintf(file, cargo);// estando aberto a file , acrescente ... cargo
	fclose(file);// fecha o comando
	
	file =fopen(arquivo,"a");
	fprintf(file, ",");// estando aberto a file , acrescente ... virgula
	fclose(file);// fecha o comando
	
	
	system("pause");
}




int consulta()
{
	setlocale (LC_ALL, "portuguese");
	char cpf[40];
	char conteudo[199];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, NÃO LOCALIZADO!\n");
	}
	
	while(fgets(conteudo, 199, file)!= NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n" );
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("\n O USUÁRIO NÃO EXISTE NO SISTEMA !!!\n");
		system("pause");
	}
	
	
	
}

int main() //instrução principal
{
	int opcao=0;// abre opção escolha		
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("##CARTÓRIO DA EBAC## \n\n");
	printf("Login do administrador!\nDigite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)// laço trabalha com variáveis, faça escolha entre variaveis abaixo....for precisa de variavel INT
		{
			system("cls");// comando de limpar a tela
		
			setlocale (LC_ALL, "portuguese"); 
		
			printf("##CARTÓRIO DA EBAC## \n\n"); 
			printf("Escolha a opção desejada no menu: \n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do sistema! \n\n");
		
			printf("Clique na Opção: ");//fim do menu.
			
		
			scanf("%d", &opcao);// %D armazenar na variavel opcao pausar o programa aguardando decisao
			system("cls");// comando limpar a tela 
		
		
			switch(opcao)//escolha entre variaveis, fica mais limpo e organizado que o for.
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
				printf("Obrigado por utilizar CARTORIOEBAC.\n");
				return 0;
				break;
				
				
				default:
				printf("Opção i n d i s p o n í v e l  !!\n");
				system("pause");
				break;	//fim da seleção
			}
		}
	}		
	else
	printf("senha INCORRETA!");
	
}

		
		
		    
	
