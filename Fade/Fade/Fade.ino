int led = 5;
int brightness = 0;
int fadeAmount = 5;

void setup() {
pinMode(led, OUTPUT);
}
void loop() {
 analogWrite(led,brightness);
//muda o brilho no próximo loop
 brightness=brightness + fadeAmount;
 //mudando a direção quando chegar nos extremos

 if(brightness == 0 || brightness == 255){
  fadeAmount=-fadeAmount; //Se brightness for igual a zero OU (||)a 255, o fade amount inverterá de sinal 
 }
delay(50);
}
