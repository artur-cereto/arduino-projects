void setup() {
  // Porta 11  será saída
  pinMode(11,OUTPUT);

}

void loop() {
  // Piscando o LED
  //Acendendo o LED
  digitalWrite(11,HIGH); // digitalWrite (porta, tensão entregue)
  //Setando o intervalo (milissegundo)
  delay(500);
 //apagando o LED
  digitalWrite(11,LOW);
 //INTERVALO
 delay(500);

}
