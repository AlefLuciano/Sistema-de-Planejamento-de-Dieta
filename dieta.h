typedef struct dieta Dieta;
struct dieta {
  char codDieta[4];
  char objetivo[12];
  char cafeDaManhã[7];
  char lanche1[7];
  char almoco[7];
  char lanche2[7];
  char jantar[7];
  char ceia[7];
  int status;
};

void moduloDieta(void);
char menuDieta(void);

void cadastrarDieta(void);
void pesquisarDieta(void);
void atualizarDieta(void);
void excluirDieta(void);

Dieta* telaCadastrarDieta(void);
void telaPesquisarDieta(void);
void telaAtualizarDieta(void);
void telaExcluirDieta(void);

void gravarDieta(Dieta*);

