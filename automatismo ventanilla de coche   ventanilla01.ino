/*PROGRAMA PARA SIMULAR LA FUNCION DE UNA VENTANA DE AUTOMOVIL 
DE MANERA SIMPLIFICADA. EL PULSADOR ACCIONA EL MOTOR DE SUBIDA AL SER PRESIONADO
  UNA SEGUNDA PULSACION PROVOCA QUE EL MOTOR DE BAJADA SE ACCIONE. 
  MIENTRAS LOS MOTORES ESTAN ACCIONADOS DEBEN RESPONDER AL ACCIONAMIENTO DEL PULSADOR (RESPONSIVE)
  
  ENTRADA: PULSADOR (SEÑAL DIGITAL)
    
  SAlIDAS: 2 RELÉ  (SEÑAL DIGITAL)
     
  AUTOR: DAVID ANDRES OTERO ELIA
  DATA: 02/02/2023 */
   
    
#define motorArriba 11
#define motorAbajo 12   
#define pulsador  7
    
//int motor arriba = 11;    
//int motor abajo = 12;
 
	int estado = 0; // Bool (estado booliano 0 y 1)
	int contador = 100; // contador para el nº de impulsos del pulsador para conectar el motor.




	void setup() {
 		 pinMode(motorArriba,OUTPUT);
 		 pinMode(motorAbajo,OUTPUT);
 		 pinMode(pulsador,INPUT);
  
 		 Serial.begin(9600);
  	   	 int estado;
  		 Serial.println(estado);
 
  
}

void loop() {
  //lectura del pulsador
  	if(digitalRead(pulsador)) {  //si esta pulsado......
    	estado = !estado;   //ASIGNACION //cambiame el estado, activa/ desactiva.
   	    contador = 100;
    while(digitalRead(pulsador)) { //lee que esta el pulsador pulsado
        delay(20); // espera 20milisegundos mientras esta pulsado y vuelve a empezar el bucle(autolectura) 
    };
  }
  //fin lectura del pulsador
  
  Serial.print("valor del contador: ");
  Serial.println(contador);
  
  
  //accionamiento de los motores
  
  if (contador > 0) {
    if(estado == 0) {    // == COMPARACION
      digitalWrite(motorArriba, HIGH); // ABRIMOS RELE QUE ACTIVA MOTOR DE SUBIDA
      digitalWrite(motorAbajo, LOW);  // CERRAMOS RELE QUE ACTIVA MOTOR DE BAJADA
      delay (70);
      contador--;   //restamos 1 a la variable ///contador///////
    }
  else {
      digitalWrite(motorAbajo, HIGH);
      digitalWrite(motorArriba, LOW);
      delay(70);
      contador--;
      
    }
  } 
  else{			// SI NO ESTA EL MOTOR ACCIONADORA . LEE EL BOTON 10 VECES
    	digitalWrite(motorAbajo, LOW);
    	digitalWrite(motorArriba, LOW);  
    	delay(100);
  }
      //FIN DE ACCIONAMIENTO DE MOTORES
 
delay(80);
}
 
  
  
