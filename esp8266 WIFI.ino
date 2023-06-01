/*26. Conectar esp8266 a unha WiFi móbil propia

Práctica 26

Conectar esp8266 a unha WiFi móbil propia.

Obxectivos:

    Programar esp8266 con C++ de Arduíno

    Identificar os parámetro necesarios para acceder a unha WiFi móbil desde dispositivos IoT

    Comprender a necesidade de comprobar a conexión e reconexionar en caso necesario

    Instalar e usar as librerías necesarias

    Empregar comunicacións serie para obter informacións da placa esp8266

Descrición:

Revisa o video explicativo e segue os pasos indicados para: (a) crear unha rede WiFi no teu móbil, (b) identificar os parámetros de conexión, (c) crear un script que se conecte á rede móbil, (d) proporcionar indicacións do estado da conexión empregando o monitor serie e (e) conectar e programar un LED que indica o estado da conexión (conectado ou non conectado) do esp8266 á WiFi.

Nesta práctica non é preciso preocuparse da reactividade do script. Pódese pór esperas (delay) con tempos amplos (máximo 3 s).


DAVID OTERO ELIA


*/



#include <ESP8266WiFi.h>

//Wifi móbil
#define MAX_INTENTOS 50
#define WIFI_SSID "ssd"
#define WIFI_PASS "pass"

// Pins datos
// GPIO14: D5
#define LED 14
int tempo = 500;
bool conectado = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);
  conectado = conectarWiFi();
}

void loop() {
  if(conectado) escintila(tempo);
  else escintila(tempo/10);
}

void escintila(int espera) {
  digitalWrite(LED, HIGH);
  delay(espera);
  digitalWrite(LED, LOW);
  delay(espera);
}

// Función que se encarga de xestionar a conexión á rede
bool conectarWiFi() { 
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); 
  WiFi.begin(WIFI_SSID, WIFI_PASS); 
  Serial.print("\n\nAgardando pola WiFi "); 
  int contador = 0;
  while(WiFi.status() != WL_CONNECTED and contador < MAX_INTENTOS) {
    contador++;
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  // Informa do estado da conexion e IP en caso de éxito
  if(contador < MAX_INTENTOS) {
    conectado = true;
    Serial.print("Conectado á WiFi coa IP: "); Serial.println(WiFi.localIP());
  }
  else{
    Serial.println("Non se puido conectar á WiFi");
    conectado = false;
  }
  return(conectado); 
}
