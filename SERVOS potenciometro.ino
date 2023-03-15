/*
    servo motor con potenciometro.
    unha montaxe na que un servo (alimentado por unha batería externa) se conecte no pin PWM D03 (3~) como entrada de control (saída para Arduíno)
    e un potenciómetro se conecte no pin analóxico A05 como entrada do Arduíno.
    A continuación realiza un programa en C++ de Arduíno, de maneira que o potenciómetro controle o ángulo de xiro do servo,
    supoñendo que este pode xirar un máximo de 180º.
    
    nombre: david andres otero elia
    data: 15/03/2023
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h> e 
 * ligado a un potenciómetro.
 */

#include <Servo.h>

//Pin de control do servo
#define CTRL 9

//Pin de lectura do potenciometro
#define POT A0

//Declaramos o objeto motor
//da clase Servo
Servo motor;
int angulo = 0;
int veloc = 100;

void setup() {
  motor.attach(CTRL);
}

void loop() {
  //Lectura do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
}
