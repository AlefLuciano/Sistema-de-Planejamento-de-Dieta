typedef struct dieta Dieta;
struct dieta {
  char codDieta[7];
  char objetivo[13];
  char cafeDaManha[30];
  char lanche1[30];
  char almoco[30];
  char lanche2[30];
  char jantar[30];
  char ceia[30];
  int status;
};

void moduloDieta(void);
char menuDieta(void);

char objDieta(char);

void cadastrarDieta(void);
void pesquisarDieta(void);
void atualizarDieta(void);
void excluirDieta(void);

Dieta* telaCadastrarDieta(void);
char* telaPesquisarDieta(void);
char* telaAtualizarDieta(void);
char* telaExcluirDieta(void);

void gravarDieta(Dieta*);
Dieta* buscarDieta(char*);
void exibirDieta(Dieta*);
void regravarDieta(Dieta*);

