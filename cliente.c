#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "util.h"


// Cliente* cli;

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

	cli = telaPesquisarCliente();

  free(cli);
}


void atualizarCliente(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaAtualizarCliente();
}


void excluirCliente(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaExcluirCliente();
}

char menuCliente(void) {
	char op;
  system("clear");
   printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============        MÓDULO CLIENTE/PACIENTE        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Cadastrar novo cliente                                              |\n");
  printf("|      2. Pesquisar um cliente                                                |\n");
  printf("|      3. Altualizar os dados de um cliente                                   |\n");
  printf("|      4. Excluir um cliente                                                  |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha uma opção:                                                     |\n");
  scanf("%c", &op);
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  delay(1);
	return op;
}

Cliente* telaCadastrarCliente(void) {

  Cliente *cli;

  int alturaValida = 0;
  int pesoValido = 0;
  float imc;
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
  imc = calcularIMC(cli->peso, cli->altura);
  printf("Seu IMC é %.1f\n", imc);
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
printf("\n");
	delay(1);
return cli;
}



Cliente* telaPesquisarCliente(void) {
	Cliente* cli;

  cli = (Cliente*) malloc(sizeof(Cliente));

  system("clear");
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

void telaAtualizarCliente(void) {
	char matr[12];

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
}

void telaExcluirCliente(void) {
	char matr[12];

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