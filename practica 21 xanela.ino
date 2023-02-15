/*PROGRAMA PARA SIMULAR LA FUNCION DE UNA VENTANA DE AUTOMOVIL 
DE MANERA SIMPLIFICADA. EL PULSADOR ACCIONA EL MOTOR DE SUBIDA AL SER PRESIONADO
  UNA SEGUNDA PULSACION PROVOCA QUE EL MOTOR DE BAJADA SE ACCIONE. 
  MIENTRAS LOS MOTORES ESTAN ACCIONADOS DEBEN RESPONDER AL ACCIONAMIENTO DEL PULSADOR (RESPONSIVE)
  EN LA SEGUNDA PARTE DEL PROBLEMA HAY QUE FORZAR QUE EL PULSADOR TENGA 3 ESTADOS (ARRIBA 0. PARADA 1 Y ABAJO 2 , PARADA 3)
  Y QUE DESPUES DE CADA ACCIONAMIENTO DEL PULSADOR PASE POR "0" O PARADA .
  
  
  ENTRADA: PULSADOR (SEÑAL DIGITAL)
    
  SAlIDAS: 2 RELÉ  (SEÑAL DIGITAL)
     
  AUTOR: DAVID ANDRES OTERO ELIA
  DATA: 02/02/2023 */
   
    
#define motorArriba 11
#define motorAbajo 12   
#define pulsador  7
    
//int motor arriba = 11;    
//int motor abajo = 12;
 
	int estado = 1; // Bool (estado booliano 0 y 1)practica anterior ----------INT en este caso puede tomar valores 0, 1, 2.
	int contador = 0; // contador para el nº de impulsos del pulsador para conectar el motor.




void setup() {
 		 pinMode(motorArriba,OUTPUT);
 		 pinMode(motorAbajo,OUTPUT);
 		 pinMode(pulsador,INPUT);
  
 		 Serial.begin(9600);
}

void loop() {
  //lectura del pulsador
  	if(digitalRead(pulsador)) { 
     //si esta pulsado......
     estado = (estado + 1) % 4; 			//ASIGNACION //cambiame el estado, activa/ desactiva. / ACTUALIZACION DEL ESTADO PARA ESTAR ENTRE 0 Y 3
   	 contador = 100;
      while(digitalRead(pulsador)) { //lee que esta el pulsador pulsado
        delay(20);      // espera 20milisegundos mientras esta pulsado y vuelve a empezar el bucle(autolectura) 
      }
    }

  //fin lectura del pulsador
  
  Serial.print(" valor del contador: ");
  Serial.print(contador);
  Serial.print(" | estado: ");
  Serial.println(estado);
  
  //accionamiento de los motores
  
  if (contador > 0) {
    if(estado == 0) {    // == COMPARACION
      digitalWrite(motorArriba, HIGH); // ABRIMOS RELE QUE ACTIVA MOTOR DE SUBIDA
      digitalWrite(motorAbajo, LOW);  // CERRAMOS RELE QUE ACTIVA MOTOR DE BAJADA
      delay (70);
      contador--;   //restamos 1 a la variable ///contador///////
    }
  else if(estado == 2)  {
     	 digitalWrite(motorAbajo, HIGH);
     	 digitalWrite(motorArriba, LOW);
     	 delay(70);
    	 contador--;
    }
    else {
     	  digitalWrite(motorAbajo, LOW);
    	  digitalWrite(motorArriba, LOW);
    	  delay(70);
		  contador--;
    }
  }
  else{			// SI NO ESTA EL MOTOR ACCIONADORA . LEE EL BOTON 10 VECES
    	digitalWrite(motorAbajo, LOW);
    	digitalWrite(motorArriba, LOW);  
    	delay(10); 
  }
  }
      //FIN DE ACCIONAMIENTO DE MOTORES
     //delay(80);

  
