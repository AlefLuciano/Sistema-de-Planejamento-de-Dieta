///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///                Developed by  @lefLuciano - Jan, 2021                    ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void menuSobre(void);
char menuPrincipal(void);

void moduloCliente(void);
char menuCliente(void);
void telaCadastrarCliente(void);
void telaPesquisarCliente(void);
void telaAtualizarCliente(void);
void telaExcluirCliente(void);
void cadastrarCliente(void);
float calcularIMC(float, float);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);

void moduloNutricionista(void);
char menuNutricionista(void);
void telaCadastrarNutricionista(void);
void telaPesquisarNutricionista(void);
void telaAtualizarNutricionista(void);
void telaExcluirNutricionista(void);
void cadastrarNutricionista(void);
void pesquisarNutricionista(void);
void atualizarNutricionista(void);
void excluirNutricionista(void);

void moduloDieta(void);
char menuDieta(void);
void telaCadastrarDieta(void);
void telaPesquisarDieta(void);
void telaAtualizarDieta(void);
void telaExcluirDieta(void);
void cadastrarDieta(void);
void pesquisarDieta(void);
void atualizarDieta(void);
void excluirDieta(void);

void telaSobre(void) {
    system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|               Universidade Federal do Rio Grande do Norte                   |\n");
  printf("|                   Centro de Ensino Superior do Seridó                       |\n");
  printf("|                 Departamento de Computação e Tecnologia                     |\n");
  printf("|                    Disciplina DCT1106 -- Programação                        |\n");
  printf("|                    Projeto Sistema de Planejamento de Dieta                 |\n");
  printf("|                  Developed by  @lefLuciano - Jan, 2021                      |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|            = = = = = Sistema de Planejamento de Dieta = = = = =             |\n");
  printf("|                                                                             |\n");
  printf("|  Programa utilizado para a disciplina DCT1106 - Programação, consite em     |\n");
  printf("|  em um projeto que propõe um sistema capaz de auxiliar o(a) nutricionista   |\n");
  printf("|  na sugestão de cardápios, alternando os tipos de alimentos a serem         |\n");
  printf("|  consumidos, de forma que os cardápios da dieta não se tornem repetitivos   |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
}

void delay(int segundos) {
  int tempo = 500000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
}



/// INICIO DO PROGRAMA PRINCIPAL 

int main(void) {
	char opcao;
	do {
		opcao = menuPrincipal();
		switch(opcao) {
			case '1': 	moduloCliente();
						break;
			case '2': 	moduloNutricionista();
						break;
//			case '3': 	moduloDieta();
//						break;
		} 		
	} while (opcao != '0');
	return 0;    
}

char menuPrincipal(void) {
	char op;
    system("clear");
	printf("\n");
   printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Módulo cliente/paciente                                             |\n");
  printf("|      2. Módulo nutricionista                                                |\n");
  printf("|      3. Módulo de dietas                                                    |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha uma opção:                                                     |\n");
  scanf("%c", &op);
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}


/// MENU ALUNO 


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
  float peso, altura, imc;

  system("clear");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           CADASTRAR CLIENTE           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Matrícula (apenas números): ");
	scanf("%[0-9]", matr);
	getchar();
	printf("|     Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
	printf("|     E-mail: ");
	scanf("%[a-z@.]", email);
	getchar();
  printf("Informe sua data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &dia);
  printf("Mês: ");
  scanf("%d", &mes);
  printf("Ano: ");
  scanf("%d", &ano);
  dataValida = validaDataDeNascimento(dia, mes, ano);
  if (!dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", dia, mes, ano);
    printf("Tente novamente!!!\n\n");
  }
	getchar();
	printf("|     Celular  (apenas números): ");
	scanf("%[0-9]", celular);
  getchar();
  printf("|     Peso(Ex. 60.0): ");
  scanf("%f", &peso);
  printf("|     Altura(Ex. 1.75): ");
  scanf("%f", &altura);
  imc = calcularIMC(peso, altura);
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");

printf("\n");
	delay(1);
}

float calcularIMC(float p, float a) {
  float a2, imc;
  a2 = a * a;
  imc = p / a2;
  printf("Seu IMC é %.1f", imc);
  return imc;

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

//////////
//// MODO NUTRICIONISTA 
//////////

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
	getchar();                                                                            
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
	char nasc[11];
	char celular[12];

    system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============        CADASTRAR NUTRICIONISTA        ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|           Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
	printf("|           E-mail: ");
	scanf("%[a-z@.]", email);
	getchar();
	printf("|           Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", nasc);
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

///////////////////////////////////////////////////////////////////////////////
///								Módulo Dieta
///////////////////////////////////////////////////////////////////////////////
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
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaCadastrarDieta();
}

void pesquisarDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaPesquisarDieta();
}


void atualizarDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaAtualizarDieta();
}


void excluirDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaExcluirDieta();
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

void telaCadastrarDieta(void) {
	char codDieta[4];
  char focoDaDieta[20];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            CADASTRAR DIETA           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva um codigo para a dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|     Escreva o foco da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", focoDaDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaPesquisarDieta(void) {
  char focoDaDieta[20];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            PESQUISAR DIETA            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o foco da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", focoDaDieta);
	getchar();
printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaAtualizarDieta(void) {
	char codDieta[4];

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
}


void telaExcluirDieta(void) {
	char codDieta[4];

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
}
