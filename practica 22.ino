/*PROGRAMA PARA SIMULAR LA FUNCION DE UNA VENTANA DE AUTOMOVIL 
  DE MANERA SIMPLIFICADA. EL PULSADOR ACCIONA EL MOTOR DE SUBIDA AL SER PRESIONADO
  UNA SEGUNDA PULSACION PROVOCA QUE EL MOTOR DE BAJADA SE ACCIONE. 
  MIENTRAS LOS MOTORES ESTAN ACCIONADOS DEBEN RESPONDER AL ACCIONAMIENTO DEL PULSADOR (RESPONSIVE)
  
  En la segunda parte del problema (practica 21) tenemos que forzar que el pulsador tenga 3 estados (arriba, parado y abajo)
  y que despues de cada accionamiento, pase por 0 o parada que es lo msmo.
  
  En la tercera parte del problema(practica 22) tuvimos que añadir dos nuevos sensores digitales, finales de carrera, que simulamos con pulsadores, 
  ya que en tinkercad no tenemos finales de carrera. estos sensores sustituyen el control por tiempo, y hacen que al estar activados, 
  la ventanilla pare en la parte superior o inferior y permanezca en esa posicion hasta que se vuelva a presionar el pulsador de accionamiento.
  el pulsador de accionamiento tiene la misma funcion.
  
  
  
  ENTRADA: PULSADOR (SEÑAL DIGITAL)
    
  SAlIDAS: 2 RELÉ  (SEÑAL DIGITAL)
     
  AUTOR: DAVID ANDRES OTERO ELIA
  DATA: 02/02/2023 */
   
    



#define motorArriba 11
#define motorAbajo 12   
#define pulsador  7
#define fcArriba  8
#define fcAbaixo  9





	int estado = 1;					 
	int contador = 0; 				

	void setup() {
 		 pinMode(motorArriba,OUTPUT);
 		 pinMode(motorAbajo,OUTPUT);
 		 pinMode(pulsador,INPUT);
  		 pinMode(fcArriba,INPUT);
 		 pinMode(fcAbaixo,INPUT);
      
         Serial.begin(9600);
}
  
  

	void loop() {
 									                            
  		if(digitalRead(pulsador)) {                              	
    			estado = (estado + 1) % 4;   						
   	   	   	    contador = 100;	
    	while(digitalRead(pulsador)) {								 
            delay(20);
   		 }	 
   	 }

  
if(digitalRead(fcArriba)) {    						 
if(estado |= 2 )  {
    estado = 1;    								 
    delay(20);   
 	  }
	}



if(digitalRead(fcAbaixo)) {   					    
if(estado |= 0 ) {									
     estado = 3;
     delay(20);
 	 }
	}

     //fin lectura del pulsador

  Serial.print("valor del contador: ");
  Serial.print(contador);
  Serial.print(" | estado:  ");
  Serial.println(estado);
  
  
  //accionamiento de los motores
  
   		 //if (contador > 0) {
   		 if(estado == 0) {   		 
    		  digitalWrite(motorArriba, HIGH); 		
    		  digitalWrite(motorAbajo, LOW);  		
     		  delay (70);
      // contador--;   						/
    }
   
         else if(estado == 2){
      		digitalWrite(motorAbajo, HIGH);
      		digitalWrite(motorArriba, LOW);
     	    delay(70); 
     // contador--;
      
    }
   
         else {			
    			digitalWrite(motorAbajo, LOW);
    			digitalWrite(motorArriba, LOW);  
    			delay(70);
  

      
        
        
      //FIN DE ACCIONAMIENTO DE MOTORES
     //delay(80);
      
      }
    }
   
    

 
