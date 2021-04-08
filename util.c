int validaAltura (float altura) {
  if (altura < 0.00 || altura > 3.00) {
    return 0; }
  else 
    return 1;
}

int validaPeso (float peso) {
    if (peso < 2.00 || peso > 200.00) {
    return 0; }
  else 
    return 1; 
}

float calcularIMC(float peso, float altura) {
  float a2, imc;
  a2 = altura * altura;
  imc = peso / a2;
  return imc;
}

//// Essa função é um adaptação do "valida datas" apresentada em aula 
int bissexto(int);

int validadeDataDeNascimento(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || aa > 2021 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11) {
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
}

int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}