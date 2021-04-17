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
	Nutricionista *nutri;

	nutri = telaCadastrarNutricionista();

  gravarNutricionista(nutri);

  free(nutri);
}


void pesquisarNutricionista(void) {
  Nutricionista *nutri;
	// função ainda em desenvolvimento

	nutri = telaPesquisarNutricionista();
  
  free(nutri); 
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

Nutricionista* telaCadastrarNutricionista(void) {
  Nutricionista *nutri;
	

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        CADASTRAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  nutri = (Nutricionista*) malloc(sizeof(Nutricionista));
  do {
	  printf("|           Matrícula (apenas números): ");
    scanf("%[^\n]", nutri->mtr);
	  getchar();
  } while (!validarMatr(nutri->mtr));
	do {
	  printf("|     Nome completo: ");
	  scanf("%[^\n]", nutri->nome);
	  getchar();
  } while (!validarNome(nutri->nome));
	do {
  printf("|     Digite o seu email: ");
  scanf("%[^\n]", nutri->email);
  getchar();
  } while (!validaEmail(nutri->email));
	printf("Informe sua data de nascimento\n");
  while (!nutri->dataValida) {
  printf("Dia: ");
  scanf("%d", &nutri->dia);
  printf("Mês: ");
  scanf("%d", &nutri->mes);
  printf("Ano: ");
  scanf("%d", &nutri->ano);
  getchar();
  nutri->dataValida = validadeDataDeNascimento(nutri->dia, nutri->mes, nutri->ano);
  if (!nutri->dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", nutri->dia, nutri->mes, nutri->ano);
    printf("Tente novamente!!!\n\n");
  }
  printf("A data de nascimento %02d/%02d/%d é válida\n", nutri->dia, nutri->mes, nutri->ano);
	getchar();
  }
	printf("|           Celular  (apenas números): ");
	scanf("%[0-9]", nutri->celular);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return nutri;
}

Nutricionista* telaPesquisarNutricionista(void) {
	Nutricionista *nutri;

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        PESQUISAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  nutri = (Nutricionista*) malloc(sizeof(Nutricionista));
  printf("|     Informe a matrícula do Nutricionista (apenas números): ");
	scanf("%[0-9]", nutri->mtr);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return nutri;
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

void gravarNutricionista(Nutricionista* nutri) {
  FILE* fp;
  fp = fopen("nutricionista.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(nutri, sizeof(Nutricionista), 1, fp);
  fclose(fp);
}