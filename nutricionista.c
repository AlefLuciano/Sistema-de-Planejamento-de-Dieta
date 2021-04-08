//////////
//// MODO NUTRICIONISTA 
//////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nutricionista.h"
#include "util.h"

void moduloNutricionista(void) {
	char opcao;
	do {
		opcao = menuNutricionista();
		switch(opcao) {
			case '1': 	cadastrarNutricionista();
						break;
			case '2': 	pesquisarNutricionista();
						break;
			case '3': 	atualizarNutricionista();
						break;
			case '4': 	excluirNutricionista();
						break;
		} 		
	} while (opcao != '0');
}

void cadastrarNutricionista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaCadastrarNutricionista();
}


void pesquisarNutricionista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaPesquisarNutricionista();
}


void atualizarNutricionista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaAtualizarNutricionista();
}


void excluirNutricionista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaExcluirNutricionista();
}

char menuNutricionista(void) {
	char op;
    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============         MÓDULO NUTRICIONISTA          ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Cadastrar novo nutricionista                                        |\n");
  printf("|      2. Pesquisar nutriciosnista                                            |\n");
  printf("|      3. Atualizar nutriciosnista                                            |\n");
  printf("|      4. Excluir nutriciosnista                                              |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha a opção desejada: ");
	scanf("%c", &op);                                                                          
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}

void telaCadastrarNutricionista(void) {
	char cpf[12];
	char nome[51];
	char email[51];
	int dia, mes, ano;
  int dataValida;
	char celular[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        CADASTRAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  printf("|     CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|           Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
	printf("|           E-mail: ");
	scanf("%[a-z@.]", email);
	getchar();
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
	getchar();
	printf("|           Celular  (apenas números): ");
	scanf("%[0-9]", celular);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaPesquisarNutricionista(void) {
	char cpf[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        PESQUISAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Informe o CPF do Nutricionista (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaAtualizarNutricionista(void) {
	char cpf[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        ATUALIZAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Informe o CPF do Nutricionista (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaExcluirNutricionista(void) {
	char cpf[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============         EXCLUIR NUTRICIONISTA         ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Informe o CPF do nutricionista (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}