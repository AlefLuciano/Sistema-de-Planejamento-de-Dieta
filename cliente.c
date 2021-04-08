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
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaCadastrarCliente();
}


void pesquisarCliente(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaPesquisarCliente();
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

void telaCadastrarCliente(void) {
  char matr[12];
	char nome[51];
	char email[51];
	char celular[12];
  int dia, mes, ano;
  int dataValida;
  int alturaValida = 0;
  int pesoValido = 0;
  float peso, altura, imc;

  system("clear");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           CADASTRAR CLIENTE           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  printf("|     Matrícula (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
	printf("|     Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
	printf("|     E-mail: ");
	scanf("%[a-záéíóúâêôçàãõ A-ZÁÉÍÓÚÂÊÔÇÀÃÕ 0-9 @.]", email);
	getchar(); 
  printf("|     Celular  (apenas números): ");
	scanf("%[0-9]", celular);
  getchar();
  while (!pesoValido) {
    printf("|     Peso(Ex. 60.0): ");
  scanf("%f", &peso);
  pesoValido = validaPeso(peso);
  if (!pesoValido){
    printf("%.2f não é um peso valido\n",peso);
    printf("Tente novamente!!\n");
  }
  printf("Peso valido\n");
  getchar();
  }
  while (!alturaValida) {
  printf("|     Altura(Ex. 1.75): ");
  scanf("%f", &altura);
  alturaValida = validaAltura(altura);
  if (!alturaValida) {
    printf("%.2f não é uma altura valida\n",altura);
    printf("Tente de novo!!\n");
  }
  printf("Altura valida\n");
  getchar();
  }
  imc = calcularIMC(peso, altura);
  printf("Seu IMC é %.1f\n", imc);
  printf("Informe sua data de nascimento\n");
  while (!dataValida) {
  printf("Dia: ");
  scanf("%d", &dia);
  printf("Mês: ");
  scanf("%d", &mes);
  printf("Ano: ");
  scanf("%d", &ano);
  dataValida = validadeDataDeNascimento(dia, mes, ano);
  if (!dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", dia, mes, ano);
    printf("Tente novamente!!!\n\n");
  }
  printf("A data de nascimento %02d/%02d/%d é válida\n", dia, mes, ano);
	getchar();
  }

printf("\n");
	delay(1);
}


void telaPesquisarCliente(void) {
	char matr[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           PESQUISAR CLIENTE           ==============     |\n");
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