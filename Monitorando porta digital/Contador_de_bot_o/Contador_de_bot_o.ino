//Monitorando uma porta digital
const int pushButton=2;
const int ledPin=13;

int buttonPushCounter=0;
int buttonState=0;
int lastButtonState=0;

void setup() {
  
  Serial.begin(9600); //começa a comunicação serial a 9600 bits/segundo
  pinMode(pushButton,INPUT);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  
buttonState = digitalRead(pushButton); //armazena o input da porta selecionada
  if (buttonState != lastButtonState){ //comparando o estado atual com o anterior
    if(buttonState == HIGH){
      buttonPushCounter++; //Incrementa de um em um essa variável
      Serial.print("número de pulsos: ");
      Serial.println(buttonPushCounter);
      }
    }

  lastButtonState = buttonState; // o atual estado do botão se tornará o anterior

//Ligando o LED a cada 4 pulsações
  if(buttonPushCounter % 4 == 0) { //se o resto da divisão por quatro for zero
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite (ledPin,LOW);  
  }


}
