// C++ code
//
/*
	
    Autor: DAVID ANDRES OTERO ELIA.
    Data: febrero del 2023
*/

#include <Servo.h>

//Pin de control do servo
#define CTRL 9

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
#include <Servo.h>

//Pin de control do servo
#define CTRL 9

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
