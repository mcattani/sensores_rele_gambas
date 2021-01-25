/*
 * Este sketch utiliza un sensor DHT11 (Pin D4) y un LDR (Pin A7) para leer la temperatura/humedad y cantidad
 * de luz y los envía a la PC (programa hecho en GAMBAS) también recibe comando de la pc
 * para activar/desactivar el relee (Pin D9).
 * También hay conectado un módulo Bluetooth HC-06, si no se quiere usar este móduloel sketch funciona igualmente conectado 
 * con el cable USB a la PC.
 * Por favor visitar https://thenerdyapprentice.blogspot.com/ para más información y descar el programa para la PC.
 */

#include <DHT.h> //Librería DHT11


// Declaramos los pines
const byte dht = 4;
const byte Rele = 9;
const byte LDR = A7;

// Declaramos variables que vamos a necesitar
byte vLDR;
byte vHumedad;
byte vTemperatura;

DHT sDHT(dht, DHT11);  // Creamos el objeto sDHT

void setup() {

// Declaramos los pines como salida
pinMode(Rele, OUTPUT);
pinMode(LDR, INPUT);

Serial.begin(9600); //Inicializamos puerto Serie

digitalWrite(Rele, LOW); // Inicializmos el Rele en low
sDHT.begin(); // Iniciamos el sensor DHT

Serial.println("- Hola desde el Arduino!"); // Enviamos el saludo a la PC

}

void loop() {
// Guardmos en la variable los datos mapeados del LDR para enviar a la PC
vLDR = map(analogRead(LDR), 0, 1023, 0,100);
  
  if (vLDR<10) { // Esto es necesario porque el programa de la PC se vuelve inestable si el valor es < 10
    vLDR = 10; 
  }
  
vHumedad = sDHT.readHumidity();
vTemperatura = sDHT.readTemperature();

Serial.print("l");Serial.print(vLDR);Serial.print("\n"); // Enviamos valor del LDR
delay(500);
Serial.print("t");Serial.print(vTemperatura);Serial.print("\n"); // Enviamos valor de temperatura
delay(500);
Serial.print("h");Serial.print(vHumedad);Serial.print("\n"); // Enviamos valor de humedad
delay(500);

// Si recibimos datos por el puerto Serie
if (Serial.available()){
  String Comando = Serial.readStringUntil("\n"); // Leemos lo que llega por el puerto serie hasta \n
  delay(100);
  Comando.trim(); // Los comandos llegan con espacios en blanco, los recortamos
     if (Comando=="RE") {
      digitalWrite(Rele, HIGH);
      Serial.println("Arduino: Rele encendido"); //Enviamos mensaje de estado a la PC
      } else
        if (Comando=="RA") {
        digitalWrite(Rele, LOW);
        Serial.println("Arduino: Rele apagado"); //Enviamos mensaje de estado a la PC
        }
  }

}
