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