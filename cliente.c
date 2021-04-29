#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "util.h"


void moduloCliente(void) {
	char opcao;
	do {
		opcao = menuCliente();
		switch(opcao) {
			case '1': 	cadastrarCliente();
						break;
			case '2': 	pesquisarCliente();
						break;
			case '3': 	atualizarCliente();
						break;
			case '4': 	excluirCliente();
						break;
		} 		
	} while (opcao != '0');
}

void cadastrarCliente(void) {
  Cliente *cli;

	cli = telaCadastrarCliente();

  gravarCliente(cli);

  free(cli);
}



void pesquisarCliente(void) {
	Cliente *cli;
  char* matr;

	matr = telaPesquisarCliente();

  // pesquisa se o cliente estar no arquivo 
  cli= buscarCliente(matr); 

  // exibe o cliente
  exibirCliente(cli); 

  free(cli);
  free(matr);
}



void atualizarCliente(void) {
	Cliente* cli;
  char* matr;

	// exibe a tela apenas para testes
matr =	telaAtualizarCliente();
//pesquisa o cliente no arquivo 
cli = buscarCliente(matr);
if(cli == NULL){
    printf("\n\n- - -Cliente não cadastrado- - -\n\n");
} else{
    cli = telaCadastrarCliente();
    strcpy(cli->matr, matr); 
    regravarCliente(cli);
    free(cli);
  }
free(matr);
}


void excluirCliente(void) {
  Cliente* cli;
  char* matr;


  matr = telaExcluirCliente();
  cli = buscarCliente(matr);
if(cli == NULL){
  printf("\n\n- - -Cliente não cadastrado- - -\n\n");
} else{
  cli->status = 0;
  regravarCliente(cli);
  free(cli);
  }
  free(matr);
}

char menuCliente(void) {
	char op;
  system("clear");
   printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("|                                                                           |\n");
  printf("|    ===================================================================    |\n");
  printf("|    ==============       SISTEMA DE PLANO DE DIETA       ==============    |\n");
  printf("|    ==============             MENU PRINCIPAL            ==============    |\n");
  printf("|    ==============        MÓDULO CLIENTE/PACIENTE        ==============    |\n");
  printf("|    ===================================================================    |\n");
  printf("|                                                                           |\n");
  printf("|      1. Cadastrar novo cliente                                            |\n");
  printf("|      2. Pesquisar um cliente                                              |\n");
  printf("|      3. Altualizar os dados de um cliente                                 |\n");
  printf("|      4. Excluir um cliente                                                |\n");
  printf("|      0. Voltar ao menu anterior                                           |\n");
  printf("|                                                                           |\n");
  printf("|      Escolha uma opção:                                                   |\n");
  scanf("%c", &op);
  printf("-----------------------------------------------------------------------------\n");
  printf("\n");
  delay(1);
	return op;
}

Cliente* telaCadastrarCliente(void) {

  Cliente *cli;

  int alturaValida = 0;
  int pesoValido = 0;
  int dataValida = 0;

  system("clear");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           CADASTRAR CLIENTE           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  cli = (Cliente*) malloc(sizeof(Cliente));
  do {
	    printf("|           Matrícula (apenas números): ");
      scanf("%[^\n]", cli->matr);
	    getchar();
    } while (!validarMatr(cli->matr));
  do {
	  printf("|     Nome completo: ");
	  scanf("%[^\n]", cli->nome);
	getchar();
  } while (!validarNome(cli->nome));
	do {
  printf("|     Digite o seu email: ");
  scanf("%[^\n]", cli->email);
  getchar();
  } while (!validaEmail(cli->email));
  printf("|     Email valido \n");
  printf("|     Celular  (apenas números): ");
	scanf("%[0-9]", cli->celular);
  getchar();
  while (!pesoValido) {
    printf("|     Peso(Ex. 60.0): ");
  scanf("%f", &cli->peso);
  getchar();
  pesoValido = validaPeso(cli->peso);
  if (!pesoValido){
    printf("%.2f não é um peso valido\n",cli->peso);
    printf("Tente novamente!!\n");
  }
  else {
    printf("|     Peso valido\n");
  }
  }
  while (!alturaValida) {
  printf("|     Altura(Ex. 1.75): ");
  scanf("%f", &cli->altura);
  getchar();
  alturaValida = validaAltura(cli->altura);
  if (!alturaValida) {
    printf("%.2f não é uma altura valida\n",cli->altura);
    printf("Tente de novo!!\n");
  }
  else {
  printf("Altura valida\n");
  }
  }
  cli->imc = calcularIMC(cli->peso, cli->altura);
  printf("Informe sua data de nascimento\n");
  while (!dataValida) {
  printf("Dia: ");
  scanf("%d", &cli->dia);
  getchar();
  printf("Mês: ");
  scanf("%d", &cli->mes);
  getchar();
  printf("Ano: ");
  scanf("%d", &cli->ano);
  getchar();
  dataValida = validadeDataDeNascimento(cli->dia, cli->mes, cli->ano);
  if (!dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", cli->dia, cli->mes, cli->ano);
    printf("Tente novamente!!!\n\n");
  }
  printf("A data de nascimento %02d/%02d/%d é válida\n", cli->dia, cli->mes, cli->ano);
	
  }
getchar();
cli->status = 1;
printf("\n");
	delay(1);
return cli;
}



char* telaPesquisarCliente(void) {
	Cliente* cli;

  cli = (Cliente*) malloc(sizeof(Cliente));

  system("clear");
  getchar();
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           PESQUISAR CLIENTE           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
	printf("|      Informe a matrícula do cliente (apenas números): ");
	scanf("%[0-9]",cli->matr);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return cli;
}


char* telaAtualizarCliente(void) {
	char* matr;
  matr = (char*) malloc(12*sizeof(char)); 

    system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           ATUALIZAR CLIENTE           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
	printf("|      Informe a matrícula do cliente (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr;
}

char* telaExcluirCliente(void) {
	char* matr;

  matr = (char*) malloc(12*sizeof(char));

  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            EXCLUIR CLIENTE            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
	printf("|      Informe a matrícula do cliente (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr; 
}

void gravarCliente(Cliente* cli) {
  FILE* fp;
  fp = fopen("clientes.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(cli, sizeof(Cliente), 1, fp);
  fclose(fp);
}


Cliente* buscarCliente(char* matr) {
  FILE* fp;
  Cliente* cli;

  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(cli, sizeof(Cliente), 1, fp);
    if ((strcmp(cli->matr, matr) == 0) && (cli->status == 1)) {
      fclose(fp);
      return cli;
    }
  }
  fclose(fp);
  return NULL;
}


void exibirCliente(Cliente* cli) {
  if (cli == NULL) {
    printf("\n- - - Esse cliente não esta cadastrado - - -\n");
  } else {
    printf("\n - - - Cliente Cadastrado - - -\n");
    printf("Matrícula: %s\n", cli->matr);
    printf("Nome do cliente: %s\n", cli->nome);
    printf("Email do cliente: %s\n", cli->email);
    // printf("Data de Nascimento: %s/%s/%s\n", cli->dia, cli->mes, cli->ano);
    printf("Celular: %s\n", cli->celular);
    printf("O peso do cliente é: %.2fKg\n", cli->peso);
    printf("A altura do cliente é: %.2fKg\n", cli->altura);
    printf("o IMC do cliente é %.1f\n", cli->imc);
    printf("Status: %d\n", cli->status);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}

void regravarCliente(Cliente* cli){
FILE* fp;
Cliente* cliLido;

cliLido = (Cliente*) malloc(sizeof(Cliente));
fp = fopen("clientes.dat", "r+b");
if(fp == NULL) {
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Não é possível continuar este programa...\n");
  exit(1);
}
while (!feof(fp)) {
  fread(cliLido, sizeof(Cliente), 1, fp);
  if (strcmp(cliLido->matr, cli->matr) == 0) {
    fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
    fwrite(cli, sizeof(Cliente), 1, fp);
    break;
  }
}
fclose(fp);
free(cliLido);
}
