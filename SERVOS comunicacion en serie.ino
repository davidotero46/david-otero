/*
   Posicionamento dun servo empregando comunicación serie.
    O programa debe ser, igual que na práctica anterior, reactivo ao potenciómetro, pero ademais, se existe unha orde en forma de texto na entrada serie, 
    débese priorizar a orde lida. É dicir, compróbase a entrada serie, se hai entrada execútase, se non existe orde en forma de texto,
    posiciónase o servo onde indique o potenciómetro. A diferenza da práctica anterior, o servo só se pode accionar un máximo de 0.25 veces por segundo.
  As ordes que se poden admitir por comunicación serie son: 
(a) 'esquerda', 
(b) 'diagonal esquerda',
(c) 'centro', 
(d) 'diagonal dereita', 
(e) 'dereita', 
ou ben 
(f) un número enteiro entre 0 e 180.


Nombre: david andres otero elia
Data: 15703/2023

 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h> e 
 * ligado a un potenciómetro.
 */

#include <Servo.h>

//Pin de control del servomotor
#define CTRL 3

//Pin de lectura del potenciometro
#define POT A5	


Servo motor;					//Declaramos servomotor variables
int angulo,grados = 10;
int veloc = 3000; 			
float voltaje=0;
String orde = "";

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop(){

if(Serial.available()){
  orde = Serial.readStringUntil('\n');                    
  if(orde.equals("esquerda")){angulo = 180; }              
  else if(orde.equals("Desquerda")){angulo = 135;}  
  else if(orde.equals("centro")){angulo = 90;}             
  else if(orde.equals("Ddereita")){angulo = 45;}
  else if(orde.equals("dereita")){angulo = 0;}
  else{
  int temp = orde.toInt();
  if(temp >= 0 && temp <= 180) angulo = temp;
    else angulo = 180;  
    
  } 
}
  else{
    angulo = analogRead(POT);
    angulo = map(angulo, 0, 1023, 0, 180); 				//lee potenciometro
  }
    
  
  motor.write(angulo);
  delay(veloc);											//Actualiza el servomotor
  Serial.println(angulo);	
  

  Serial.print("  V: ");
  Serial.print(voltaje);
  Serial.print("  grados: ");
  Serial.println(grados);
  delay(100);
}



