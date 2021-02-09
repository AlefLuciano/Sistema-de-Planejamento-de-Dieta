///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///                Developed by  @lefLuciano - Jan, 2021                    ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

void menuSobre(void);

int main(void) {
    menuSobre();
    return 0;

}


void menuSobre(void) {
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
  printf("###############################################################################\n\n");
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
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  printf("###############################################################################\n");
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
  printf("|      2. Visualizar os dados                                                 |\n");
  printf("|      3. Alterar os dados                                                    |\n");
  printf("|      4. Excluir um cliente                                                  |\n");
  printf("|      5. Vizualizar a evolução                                               |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  printf("###############################################################################\n");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============         MÓDULO NUTRICIONISTA          ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Cadastrar uma nova dieta                                            |\n");
  printf("|      2. Excluir uma dieta                                                   |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  printf("###############################################################################\n");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============            MÓDULO DE DIETAS           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Ver dietas para ganho de massa muscular                             |\n");
  printf("|      2. Ver dietas para emagrecer                                           |\n");
  printf("|      3. Ver dietas para manter o peso                                       |\n");
  printf("|      4. Ver dieta personalizada                                             |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");

	char matr[12];
	char nome[51];
	char email[51];
	char nasc[11];
	char celular[12];
  char altura[4];
  char peso[4];

  
  printf("###############################################################################\n\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============           CADASTRAR CLIENTE           ==============     |\n");
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
	printf("|     Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", nasc);
	getchar();
	printf("|     Celular  (apenas números): ");
	scanf("%[0-9]", celular);
  getchar();
  printf("|     Altura (Ex. 1,75): ");
  scanf("%[0-9]", altura);
	getchar();
  printf("|     Peso (Ex 59.3): ");
  scanf("%[0-9]", peso);
  getchar();
	printf("|                                                                             |\n");
	printf("|                                                                             |\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}