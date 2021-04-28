typedef struct cliente Cliente;

struct cliente {
  char matr[12];
	char nome[51];
	char email[51];
	char celular[12];
  int dia, mes, ano;
  float peso, altura;
};


void moduloCliente(void);
char menuCliente(void);
void telaAtualizarCliente(void);
void telaExcluirCliente(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);
Cliente* telaCadastrarCliente(void);
Cliente* telaPesquisarCliente(void);
void gravarCliente (Cliente*);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);