const int SensorEC = A5; // Cria constante para assinalar a porta A5
const int SensorTemp = A4;// Cria constante para assinalar a porta A4
const int SensorUR = A3;// Cria constante para assinalar a porta A3
const int Verde = 2; // Cria constante para assinalar o pino do LED Verde
const int Vermelho = 3;// Cria constante para assinalar o pino do LED Vermelho
const int Verde2 = 4; // Cria constante para assinalar o pino do LED Verde 2
const int Amarelo = 5;// Cria constante para assinalar o pino do LED Amarelo
const int Vermelho2 = 6;// Cria constante para assinalar o pino do LED Vermelho 2
const int ReleB = 12; // Cria constante para assinalar o pino do Relé da Bomba
const int ReleV = 13; // Cria constante para assinalar o pino do Relé do Ventilador

//Constantes de thresholds (Limites superiores e inferiores)

const int TempMax = 24;
const int TempMin = 7;
const int URMax = 70;
const int URMin = 60;
const float ECMax = 2.70;
const float ECMin = 2.22;



float LeituraSensorEC; // cria varável para registrar valor de leitura do Sensor de EletroCondutividade
float LeituraSensorTemp;// cria varável para registrar valor de leitura do Sensor de Temperatura
float LeituraSensorUR;// cria varável para registrar valor de leitura do Sensor de Umidade Relativa
float EC;// cria variável para armazenar valor da EletroCondutividade
float Temperatura;// cria variável para armazenar valor da Temperatura 
float UR;// cria variável para armazenar valor da Umidade Relativa
float voltec=0;// Cria variável para armazenar valor da tensão já transformada entregue pelo sensor de EletroConduvitividade
float volttemp=0;// Cria variável para armazenar valor da tensão já transformada entregue pelo sensor de temperatura
float voltur=0;// Cria variável para armazenar valor da tensão já transformada entregue pelo sensor de Umidade Relativa

void setup()
{
  pinMode(Verde, OUTPUT);// Determina que a porta definida para o LED Verde será uma saída
  pinMode(Vermelho, OUTPUT);// Determina que a porta definida para o LED Vermelho será uma saída
  pinMode(Verde2, OUTPUT); // Determina que a porta definida para o LED Verde 2 será uma saída
  pinMode(Amarelo, OUTPUT);// Determina que a porta definida para o LED amarelo será uma saída
  pinMode(Vermelho2, OUTPUT);// Determina que a porta definida para o LED Vermelho 2 será uma saída
  pinMode(ReleB, OUTPUT);// Determina que a porta definida para o Relé da Bomba será uma saída
  pinMode(ReleV, OUTPUT);// Determina que a porta definida para o Relé do Ventilador será uma saída
  pinMode(SensorEC, INPUT); // Determina que a porta definida para o sensor de Eletro Condutividade será uma Entrada
  pinMode(SensorTemp, INPUT); // Determina que a porta definida para o sensor de temperatura será uma Entrada
  pinMode(SensorUR, INPUT); // Determina que a porta definida para o sensor de Umidade relativa será uma Entrada
  Serial.begin(9600);//Configura a taxa de transferência em bits por segundo para a transmissão serial
}

void loop()
{
  LeituraSensorEC = analogRead(SensorEC);//Leitura da porta Analógica A5
  voltec=LeituraSensorEC * 4.887;//ajustando valor da leitura para mV
  EC = ((voltec*4)+0.0052)/1000;// Conversão da tensão lida para o valor de EC. Transformação oriunda da curva de comportamento do sensor 
  
  LeituraSensorTemp = analogRead(SensorTemp);//Leitura da porta Analógica A4
  volttemp= LeituraSensorTemp*4.887;//ajustando valor da leitura para mV
  Temperatura= (volttemp/0.1)/1000;// Conversão da tensão lida para o valor de Temperatura. Transformação oriunda da curva de comportamento do sensor 
  
  LeituraSensorUR =analogRead (SensorUR);//Leitura da porta Analógica A3
  voltur = LeituraSensorUR*4.887;//ajustando valor da leitura para mV
  UR = ((voltur/0.0714)/1000)+20;// Conversão da tensão lida para o valor de UR. Transformação oriunda da curva de comportamento do sensor 

  //Criação de variáveis para tornar o código mais legível:
  bool TemperaturaIdeal = (Temperatura >= TempMin) && (Temperatura <= TempMax); //Variável booleana (TRUE ou FALSE) resumindo se a temperatura está no intervalo ideal
  bool URIdeal = (UR>=60)&&(UR<=70);//Idem, só que em relacao a UR
  
  
  if ((Temperatura > TempMax)||(UR > URMax)) //Se a Temperatura ou a UR estiverem acima dos limites:
  {
    digitalWrite (ReleV,HIGH);//Acionar Relé do Ventilador
    digitalWrite (Amarelo, HIGH);//Acender LED Amarelo
  }
  else //Caso contrário:
  {
    digitalWrite (ReleV,LOW);//Desativar Relé do Ventilador
    digitalWrite (Amarelo, LOW);//Acender LED Amarelo
  }
  
    if((TemperaturaIdeal) && (URIdeal))//Verificar se Temperatura e UR estão dentro dos intervalos ideais, caso sim:
  {
    digitalWrite (Verde2, HIGH);//Acender LED Verde 2
  }
    else //Caso contrário:
    {
      digitalWrite (Verde2, LOW); //Apagar LED Verde2
    }
  
  if ((Temperatura < TempMin)||(UR < URMin)) // Verificar se a Temperatura ou a UR estão abaixo do valor mínimo, caso afirmativo:
  {
    digitalWrite (Vermelho2, HIGH);//Acender LED Vermelho
  }
  else //Caso contrário:
  {
    digitalWrite (Vermelho2, LOW); // Apagar LED vermelho
  }
  
 
  if ((EC >= ECMin) && (EC<=ECMax))//Verifica se a EC está no intervalo ideal, caso esteja:
  {
    digitalWrite (ReleB,LOW);//Desativa Relé da Bomba
    digitalWrite (Verde, HIGH);//Acende LED Verde
    digitalWrite (Vermelho, LOW);//apaga LED Vermelho  
  }
 
 else if (EC<ECMin)//Verifica se o Valor de EC é menor que o limite inferior, caso seja:
  {
    digitalWrite (ReleB,HIGH);//Acionar Relé da Bomba
    digitalWrite (Verde, LOW);//Apagar LED Verde
    digitalWrite (Vermelho, HIGH);//Acender LED Vermelho
  } 
  
 else if(EC> ECMax) //Verifica se o valor de EC é maior que o limite superior, caso seja?
  {
    digitalWrite (ReleB,LOW); //Desativa Relé da Bomba
    digitalWrite (Verde, LOW);//Apaga LED Verde
    digitalWrite (Vermelho, HIGH); //Acende LED Vermelho
  }
    
                
  
  //Para fins de testes e diagnósticos, exibindo as leituras dos sensores no Monitor Serial
  
  Serial.print("Temperatura:"); 
  Serial.print(Temperatura,1);
  Serial.println("C");
  Serial.print("UR: ");
  Serial.println(UR,1);
  Serial.print("EC: ");
  Serial.println(EC,2);
  delay(500);
    
}