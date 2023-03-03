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

#define LDR A0
#define Rele 12


int umbral = 960;
int entrada = 0;
int releON = false;
int contador = 100;


void setup() {
	pinMode(LDR, INPUT); 				//no es necesario declarar las entradas analogicas.
    pinMode(Rele,OUTPUT);
  	Serial.begin(9600); 
}

void loop() {
  // lectura de entradas 
     entrada = analogRead(LDR);        //la lectura tiene que estar entre 54 y 974
  	 Serial.print(entrada);
  	 Serial.print("Entrada LDR: ");
     Serial.print(contador);
  	 Serial.println("  contador");
 
  delay(70);
  	if (entrada > umbral) {
  	  releON = true;
   	 // contador = 100;
    //  digitalWrite(Rele, releON);
      contador--;
      //delay(70);
  }
 	 else {
    releON = false;
  }
  	if (contador > 0) {
   //Serial.print("contador: "); 
  // Serial.println(contador);
  // contador--;
   delay(70);
  }
  
 	 else  {
    releON = false;
    contador = 0;
    
  }
   
    
    digitalWrite(Rele, releON);
   // delay(70);
    
}
