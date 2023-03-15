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

//Pin de control do servo
#define CTRL 3

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int veloc = 20;

String orde ="";
int posicion = 0;

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop() {
  //Comprobamos se hai orde no teclado
  if(Serial.available()) {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase();
    if(orde.equals("esquerda")) posicion = 180;
    else if(orde.equals("dereita")) posicion = 0;
    else if(orde.equals("centro")) posicion = 90;
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) posicion = tmp;
      else posicion = 0;      
    }
  }
  motor.write(posicion);
  delay(veloc);
}
