//fazer com que luzes diferentes se acendam de acordo com o acionamento de botões
//declarando as variáveis 
  int botao1 = 12;
  int botao2 = 0;
  int ledred = 5;
  int ledgreen = 6;
  int i=0;
  int ledpower = 13;
  int buttonstate1=0;
  int buttonstate2=0;
void setup() {

//designando as portas e seus tipos
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(ledred,OUTPUT);
  pinMode(ledgreen,OUTPUT);
  pinMode(ledpower,OUTPUT);
}

void loop() {
//verificando o estado dos botões
buttonstate1=digitalRead(botao1);
buttonstate2=digitalRead(botao2);

//LED vermelho é ligado por default
  digitalWrite(ledpower,HIGH);
  
//vendo os casos:

delay(1500);

  if (buttonstate1== HIGH && buttonstate2==HIGH){ //se os dois forem acionados
    digitalWrite (ledred, LOW);
    digitalWrite (ledgreen, HIGH);
    delay(4000);
    digitalWrite (ledgreen, LOW);
  }  

  if ( buttonstate1==HIGH ^ buttonstate2 == HIGH){ // se apenas um dos dois for acionado, piscar vermelho)
    i=0;
    while (i<5){
      digitalWrite(ledred,HIGH);
      delay (750);
      digitalWrite(ledred,LOW);
      delay(750);
      i=i+1;
    }  
  }


 }
