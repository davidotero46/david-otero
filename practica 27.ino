/*


Práctica 27

Aplicación móbil para comunicación MQTT

Obxectivos:

Familiarizarse cos parámetros básicos da comunicación MQTT

Crear un canal de comunicación MQTT entre dous computadores

Crear un canal de comunicación entre un móbil e un computador

Crear unha aplicación MQTT básica nun Dashboard descargado da Play Store de Android ou iPhone

Comunicar o móbil co servidor MQTT e outros dispositivos


  */
#include <ESP8266WiFi.h>

*//Wifi móbil
#define MAX_INTENTOS 50
#define WIFI_SSID "ssd"
#define WIFI_PASS "pass"

// Pins datos
// GPIO14: D5
#define LED 14

int tempo = 500;
bool conectado = false;

void setup() {
  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  conectarWiFi();
}

// Función que se encarga de xestionar a conexión á rede
void conectarWiFi() {
  
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect(); 
  WiFi.begin(WIFI_SSID, WIFI_PASS); // Inicia a conexion
  Serial.print("\n\nAgardando pola WiFi ");
  int contador = 0; 
  while(WiFi.status() != WL_CONNECTED and contador < MAX_INTENTOS) {
    contador++;
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  // Informa do estado da conexion e IP en caso de exito
  if(contador < MAX_INTENTOS) {
    Serial.print("Conectado á WiFi coa IP: ");
    Serial.println(WiFi.localIP());
  }
  else{
    Serial.println("Non se puido conectar á WiFi");
  }
}
