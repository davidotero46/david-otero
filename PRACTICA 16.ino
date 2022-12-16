/* PRACTICA 16. 
EN ESTA PRACTICA VAMOS CONDICION A CONDICION VIENDO LO QUE REALIZA EN VEZ DE USAR TODA LA FUNCION A LA VEZ. TIENE LOS MISMOS PINS 10, 9, 8 PARA CADA PULSADOR.
DAVID ANDRES OTERO ELIA 
16/12/2022*/


// C++ code
//
int A = 0;

int B = 0;

int C = 0;

void setup()
{
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(12, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop()
{
  A += digitalRead(10);
  B += digitalRead(9);
  C += digitalRead(8);

  if (((!(A == 0)) && B == 1) && (!(C == 0))) {
    digitalWrite(12, HIGH);
    delay(4000); // Wait for 4000 millisecond(s)
  } else {
    digitalWrite(0, LOW);
    delay(4000); // Wait for 4000 millisecond(s)
    if ((A == 1 && B == 1) && C == 0) {
      digitalWrite(12, HIGH);
      delay(4000); // Wait for 4000 millisecond(s)
    } else {
      digitalWrite(12, LOW);
      delay(4000); // Wait for 4000 millisecond(s)
      if ((A == 1 && B == 1) && C == 1) {
        digitalWrite(12, HIGH);
        delay(4000); // Wait for 4000 millisecond(s)
      } else {
        digitalWrite(12, LOW);
        delay(4000); // Wait for 4000 millisecond(s)
      }
    }
  }
}
