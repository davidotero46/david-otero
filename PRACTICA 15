/*PUERTAS LOGICAS 07 PROBLEMA REAL
AÑADIMOS 3 PULSADORES (ENTRADAS) Y CUANDO SE CUMPLE NUESTRA FUNCION LOGICA DE LA PRACTICA 7. LAS ENTRADAS VAN A LOS PINS 10, 9, 8..... CUANDO SE DEN LAS CONDICIONES EL LED SE ACTIVA. CUANDO NO SE DEN LAS CONDICIONES NO SE DEBE ENCENDER EL LED. 
DAVID ANDRES OTERO ELIA
16/12/2022 */


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
}

void loop()
{
  A += digitalRead(10);
  B += digitalRead(9);
  C += digitalRead(8);

  if (((!(A == 0)) && B == 1) && (!(C == 0)) || ((A == 1 && B == 1) && (!(C == 0)) || (A == 1 && B == 1) && C == 1)) {
    digitalWrite(12, HIGH);
    delay(4000); // Wait for 4000 millisecond(s)
  } else {
    digitalWrite(12, LOW);
    delay(4000); // Wait for 4000 millisecond(s)
  }
}
