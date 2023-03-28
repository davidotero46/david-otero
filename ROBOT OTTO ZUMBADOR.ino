/* Programa que imita o comportamento dun robot Otto simplificado.

As conexiÃ³ns aos servos son as que se indican a seguir.
         --------------- 
        |     O   O     |
        |---------------|
LR 3==> |               | <== LL 2
         --------------- 
            ||     ||
            ||     ||
FR 5==>   -----   ------  <== FL 4
         |-----   ------|
         
O zumbador vai conectado no pin 13 e o sensor de distancia HC-SR04 
nos pins 9 (echo) e 8 (trigger).

A funciÃ³n loop() vai facendo chamadas a funciÃ³ns definidas aparte. NON inclÃºe mÃ¡is
cÃ³digo que chamdas a funciÃ³n externas.

Autor: VÃ­ctor M. Ãlvarez
Data: Marzo de 2023
*/

//#include <NewPing.h>  //PÃ³dese empregar opcionalmente, non en TinkerCad 
#include <Servo.h>

// DefiniciÃ³ns do sensor HC-SR04
#define ECHO           9
#define TRIGGER        8
#define DIST_MAX       200
#define UMBRAL_DIST    12

//NewPing sonar(TRIGGER, ECHO, DIST_MAX); //Obxecto sensor de distancia para <NewPing.h>


// Buzzer
#define BUZZER   13

// DefiniciÃ³ns dos servos
#define FR       5  // PÃ© dereito (Right Foot)
#define LR       3  // Perna dereita (Right Leg)
#define FL       4  // PÃ© esquerdo (Left Foot)
#define LL       2  // Perna esquerda (Left Leg)
float distancia;
float tiempo;
Servo peDer, pernaDer, peEsq, pernaEsp;  

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  peDer.attach(FR); 
  pernaDer.attach(LR);
  peEsq.attach(FL);
  pernaEsp.attach(LL);
}

void loop() {
  David();
}


bool David()
{
 bool objeto;
  if (distanciaObxecto() < UMBRAL_DIST) 
  { 
    zumbar();
    objeto = true;  
  }
  else
  {
    nonZumbar();
    objeto = false;
   delay(50);
   Serial.println(objeto);
   return objeto;

// FunciÃ³ns externas

// FunciÃ³n que indica se o obxecto supera o 
// umbral (true) ou non (false
 delay(50);
  }
}

// FunciÃ³n que calcula a distancia ao obxecto en cm
// IncÃºe unha espera de 50 ms
float distanciaObxecto() {
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite (TRIGGER,LOW);
  tiempo = pulseIn(ECHO, HIGH);
  distancia = tiempo/59;
  Serial.print ("Distancia ");
  Serial.print(distancia);
  Serial.println("cm ");
   return (distancia);

  
}

// FunciÃ³n que fai zumbar o zumbador durante 200 ms
void zumbar() {
    digitalWrite(BUZZER, HIGH);
	delay(20);
     
}

// FunciÃ³n que apaga o zumbador durante 200 ms
void nonZumbar() {
    digitalWrite(BUZZER, LOW);
	delay(20);
     
}
