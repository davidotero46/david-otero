// C++ code
//
/*
	Este script es para medir voltajes en una entrada analogica y pasar por monitor serie el valor en mV.
    Este script activa un motor que despliega un toldo cuando aumenta la luz solar.
no es un caso real, porque no se recoge el toldo.
	El sensor tampoco es el mas indicado o preciso para esta funcion.
    Al superarse un determinado umbral luminoso, se activa el relé que alimenta el motor, 
    El motor esta activo durante todo el recorrido del toldo, que se estima que se despliega en 7 segundos.
    
    Autor: DAVID ANDRES OTERO ELIA.
    Data: febrero del 2023
*/


#define LDR A0		// Pin alanalogico para la fotorresistencia.
#define relé 12

float tension = -999;

void setup() {
	pinMode(LDR, INPUT); 				//no es necesario declarar las entradas analogicas.
    Serial.begin(9600);
  
}


void loop() {
    tension = analogRead(LDR);
  // tension = 5. * tension / (1023 - 0);
  	tension = map(tension, 0, 1023, 0, 5);
  
  	Serial.print("valor de entrada-tension: ");
    Serial.print(tension);
    Serial.println("entrada-mV");
    delay(500); 
  
  
  
  
  

}


float map(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

}
