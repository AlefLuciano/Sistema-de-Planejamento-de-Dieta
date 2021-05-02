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
  char* matr;
	// função ainda em desenvolvimento

	matr = telaPesquisarNutricionista();
  
  nutri = buscarNutricionista(matr);

  exibirNutricionista(nutri);
  free(nutri); 
  free(matr);
}

void atualizarNutricionista(void) {
  Nutricionista* nutri;
  char* matr;

	matr = telaAtualizarNutricionista();
  nutri = buscarNutricionista(matr);
  if(nutri == NULL){
    printf("\n\n- - -Nutricionista não cadastrado- - -\n\n");
  } else {
    nutri = telaCadastrarNutricionista();
    strcpy (nutri-> matr, matr);
    regravarNutricionista(nutri);
    free(nutri);
  }
  free(matr);
}

void excluirNutricionista(void) {
  Nutricionista* nutri;
  char* matr;

	matr = telaExcluirNutricionista();
  nutri = (Nutricionista*) malloc(sizeof(Nutricionista));
  nutri = buscarNutricionista(matr);

  if(nutri == NULL){
    printf("\n\n- - -Nutricionista não cadastrado- - -\n\n");
  } else {
    nutri->status = 0;
    regravarNutricionista(nutri);
    free(nutri);
  }
  free(matr);
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
    scanf("%[^\n]", nutri->matr);
	  getchar();
  } while (!validarMatr(nutri->matr));
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
  nutri->status = 1;
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return nutri;
}


char* telaPesquisarNutricionista(void) {
	char* matr;

  matr = (char*) malloc(12*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        PESQUISAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  getchar();
  printf("|     Informe a matrícula do Nutricionista (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr;
}


char* telaAtualizarNutricionista(void) {
	char* matr;
  matr = (char*) malloc(12*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        ATUALIZAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Informe a matricula do Nutricionista (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr;
}

char* telaExcluirNutricionista(void) {
	char* matr;
  matr = (char*) malloc(12*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============         EXCLUIR NUTRICIONISTA         ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Informe a matricula do nutricionista (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();                                                                        
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr;
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

Nutricionista* buscarNutricionista(char* matr) {
  FILE* fp;
  Nutricionista* nutri;

  nutri = (Nutricionista*) malloc(sizeof(Nutricionista));
  fp = fopen("nutricionista.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(nutri, sizeof(Nutricionista), 1, fp);
    if ((strcmp(nutri->matr, matr) == 0) && (nutri->status == 1)) {
      fclose(fp);
      return nutri;
    }
  }
  fclose(fp);
  return NULL;
}

void exibirNutricionista(Nutricionista* nutri) {
  if (nutri == NULL) {
    printf("\n- - - Esse nutricionista não esta cadastrado - - -\n");
  } else {
    printf("\n- - - Nutricionista Cadastrado- - -\n");
    printf("Matricula: %s", nutri->matr);
    printf("Nome do nutricionista: %s\n", nutri->nome);
    printf("Email do nutricionista: %s\n", nutri->email);
    printf("Celular: %s\n", nutri->celular);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}

void regravarNutricionista(Nutricionista* nutri){
int achou;
FILE* fp;
Nutricionista* nutriLido;

nutriLido = (Nutricionista*) malloc(sizeof(Nutricionista));
fp = fopen("nutricionista.dat", "r+b");


if(fp == NULL) {
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Não é possível continuar este programa...\n");
  exit(1);
}

while (!feof(fp)) {
  (fread(nutriLido, sizeof(Nutricionista), 1, fp) && !achou);
  if (strcmp(nutriLido->matr, nutri->matr) == 0) {
    fseek(fp, -1*sizeof(Nutricionista), SEEK_CUR);
    fwrite(nutri, sizeof(Nutricionista), 1, fp);
    break;
  }
}

fclose(fp);
free(nutriLido);
}
