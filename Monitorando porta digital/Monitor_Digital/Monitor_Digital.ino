//Monitorando uma porta digital
int pushButton=2;
int ledPin=13;

void setup() {
  Serial.begin(9600); //começa a comunicação serial a 9600 bits/segundo
  pinMode(pushButton,INPUT);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  int buttonState = digitalRead(pushButton); //cria uma variável para armazenar o input da porta selecionada
  if (buttonState==1){
    digitalWrite(ledPin,HIGH);
  }  else {
    digitalWrite(ledPin,LOW);
  }
//imprimindo o estado do botao no monitor
  Serial.println(buttonState);
  delay(500);
}
