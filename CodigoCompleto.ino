#include <DHT.h>
#include <DHT_U.h>

//Pines
int bombaAgua = 8;
int sensorTemp = 9; 
int boton = 11;

//variables    
int temp;
int hum;
float senTerm;
int estadoBoton=0;
int estadoRele=0;

//Objetos
DHT dht(sensorTemp, DHT11); 

void setup() {
 
  //setup rele
  pinMode(bombaAgua,OUTPUT);

  //setup Sensor temp
  dht.begin();

  //setup boton
  pinMode(boton, INPUT);

  //comunicacion con el puerto serial
  Serial.begin(9600);	
}

void loop() {
  //Inicializacion de Variables sensor
  temp = dht.readTemperature(); 
  hum = dht.readHumidity();
  senTerm = dht.computeHeatIndex(temp,hum,false);
  
  estadoBoton = digitalRead(boton);

  //Pantalla
 
  if(temp>=28 && hum>=50){ //Condicion para regar automaticamente
      digitalWrite(bombaAgua, LOW); //Prender bomba de agua
      Serial.print("Temperatura: ");
      Serial.print(temp);
      Serial.print(" C ");
      Serial.print("Humedad: ");
      Serial.print(hum);
      Serial.print("% ");  
      Serial.print("Sensacion Termica: ");
      Serial.print(senTerm);
      Serial.println(" C "); 
      delay(2000);
      
  } else if(estadoBoton==HIGH){ //Si se presiona el botón
      Serial.println("prendido");
      digitalWrite(bombaAgua, HIGH); //Prender bomba de agua
      delay(5000);
      
     
  } else { //Si ninguna de las condiciones anteriores...
      digitalWrite(bombaAgua, LOW); //Bomba apagada
      Serial.println("apagado");
  }

  //Si no recibe informacion del sensor
  if(temp==0 && hum==0)
  {
      Serial.println("Error en Sensor de Temperatura");
  }
}
