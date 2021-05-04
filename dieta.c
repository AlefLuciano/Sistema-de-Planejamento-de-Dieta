
///////////////////////////////////////////////////////////////////////////////
///								Módulo Dieta
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dieta.h"
#include "util.h"

void moduloDieta(void) {
	char opcao;
	do {
		opcao = menuDieta();
		switch(opcao) {
			case '1': 	cadastrarDieta();
						break;
			case '2': 	pesquisarDieta();
						break;
			case '3': 	atualizarDieta();
						break;
			case '4': 	excluirDieta();
						break;
		} 		
	} while (opcao != '0');
}

void cadastrarDieta(void) {
	Dieta *diet;

	diet = telaCadastrarDieta(); 

  gravarDieta(diet);

  free(diet);
}

void pesquisarDieta(void) {
  Dieta *diet;
  char* codDieta;

	// codDieta = telaPesquisarDieta();
  codDieta = telaPesquisarDieta();

  // pesquisa se o dieta estar no arquivo 
  diet= buscarDieta(codDieta);

  // exibe o Dieta
  exibirDieta(diet); 

  free(diet);
  free(codDieta);
}


void atualizarDieta(void) {
	Dieta* diet;
  char* codDieta;

codDieta =	telaAtualizarDieta();
//pesquisa o dieta no arquivo 
diet = buscarDieta(codDieta);
if(diet == NULL){
    printf("\n\n- - -Dieta não cadastrado- - -\n\n");
} else{
    diet = telaCadastrarDieta();
    strcpy (diet-> codDieta, codDieta);
    regravarDieta(diet);
    free(diet);
  }
free(codDieta);
}


void excluirDieta(void) {
	Dieta* diet;
  char* codDieta;

  codDieta = telaExcluirDieta();
  diet = (Dieta*) malloc(sizeof(Dieta));
  diet = buscarDieta(codDieta);

if(diet == NULL){
  printf("\n\n- - -Dieta não cadastrado- - -\n\n");
} else{
  diet->status = 0;
  regravarDieta(diet);
  free(diet);
  }
  free(codDieta);
}


char menuDieta(void) {
	char op;

    system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============            MÓDULO DE DIETAS           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Cadastrar nova dieta                                                |\n");
  printf("|      2. Pesquisar dieta                                                     |\n");
  printf("|      3. Atualizar dieta                                                     |\n");
  printf("|      4. Excluir dieta                                                       |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();                                                                       
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
    delay(1);
	return op;


}

// Dieta* telaCadastrarDieta(void)

Dieta* telaCadastrarDieta(void) {
  Dieta * diet;
	diet = (Dieta*) malloc ( sizeof (Dieta));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            CADASTRAR DIETA           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva um codigo para a dieta: ");
	scanf("%[0-9]", diet->codDieta);
	getchar();
  printf("|     Escreva o objetivo da dieta(EX: perder peso: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", diet->objetivo);
	getchar();
  printf("|     Escreva o cafe da manhã da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", diet->cafeDaManha );
  getchar();
  printf("|     Escreva o lanche da manhã da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 ]", diet->lanche1 );
  getchar();  
  printf("|     Escreva o almoço da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 ]", diet->almoco );
  getchar();
  printf("|     Escreva o lanche da tarde da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 ]", diet->lanche2 );
  getchar();
  printf("|     Escreva o jantar da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 ]", diet->jantar );
  getchar();
  printf("|     Escreva a ceia da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 ]", diet->ceia );
  getchar();
  diet->status = 1;
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return diet;
}

char* telaPesquisarDieta(void) {

	char* codDieta;

  codDieta = (char*) malloc(4*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            PESQUISAR DIETA            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o codigo da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", codDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return codDieta;
}

char* telaAtualizarDieta(void) {
	char* codDieta;
  codDieta = (char*) malloc(4*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            ATUALIZAR DIETA            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o codigo da dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return codDieta;
}


char* telaExcluirDieta(void) {
	char* codDieta;
  codDieta = (char*) malloc(4*sizeof(char));

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============             EXCLUIR DIETA             ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o codigo da dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return codDieta;
}

void gravarDieta(Dieta* diet) {
  FILE* fp;
  fp = fopen("dietas.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(diet, sizeof(Dieta), 1, fp);
  fclose(fp);
}

Dieta* buscarDieta(char* codDieta) {
  FILE* fp;
  Dieta* diet;

  diet = (Dieta*) malloc(sizeof(Dieta));
  fp = fopen("dietas.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(diet, sizeof(Dieta), 1, fp);
    if ((strcmp(diet->codDieta, codDieta) == 0) && (diet->status == 1)) {
      fclose(fp);
      return diet;
    }
  }
  fclose(fp);
  return NULL;
}


void exibirDieta(Dieta* diet) {
  if (diet == NULL) {
    printf("\n- - - Esse dieta não esta cadastrado - - -\n");
  } else {
    printf("\n - - - Dieta Cadastrado - - -\n");
    printf("Café da manhã: %s\n", diet->cafeDaManha);
    printf("lanche da manhã: %s\n",diet->lanche1);
    printf("almoço: %s\n", diet->almoco);
    printf("Lanche da tarde: %s\n", diet->lanche2);
    printf("Jantar: %s\n", diet->jantar);
    printf("Ceia: %s\n", diet->ceia);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}


void regravarDieta(Dieta* diet){
int achou;
FILE* fp;
Dieta* dietLido;

dietLido = (Dieta*) malloc(sizeof(Dieta));
fp = fopen("dietas.dat", "r+b");


if(fp == NULL) {
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Não é possível continuar este programa...\n");
  exit(1);
}

while (!feof(fp)) {
    
    break;
  (fread(dietLido, sizeof(Dieta), 1, fp) && !achou);
  if (strcmp(dietLido->codDieta, diet->codDieta) == 0) {
    fseek(fp, -1*sizeof(Dieta), SEEK_CUR);
    fwrite(diet, sizeof(Dieta), 1, fp);
    break;
  }
}

fclose(fp);
free(dietLido);
}
