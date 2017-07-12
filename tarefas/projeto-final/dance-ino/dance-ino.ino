void setup() {
  // Iniciando a porta serial
  Serial.begin(9600);
}

int controle = 0;

void loop() {
  // lendo a entrada analógica, que retorna valores entre 0 e 1023
  int valueTeclado = analogRead(A0);

  // mapeando o valor analógico para a tecla apertada
  int tecla[] = {5,3,5,1,5,4,5,2,5,5,5,5}; //11=*, 12=#
  int corrente_tecla[] = {242, 143, 18, 441, 387, 325, 558, 524, 487, 637, 615, 590};

  if (valueTeclado < 800) {
    if (controle == 0) {
        int i, x;
        for (i = 0; i <= 12; i++) {
          if (abs(valueTeclado - corrente_tecla[i]) < 5) {
              //Serial.println(tecla[i]);
              Serial.write(tecla[i]);
              controle = 1;
              break;
          }  
        }
    }
  }
  else {
    controle = 0;
  }
}
