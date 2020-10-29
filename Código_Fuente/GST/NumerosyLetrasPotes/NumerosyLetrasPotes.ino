
#include<math.h> // incluyo esta libreria de C estandar para usar la funcion ROUND!!


//Pin de entrada de la señal del potenciómetro
int potPin1 = 1;
int potPin3 = 3;
//Variable del valor del sensor
int val1 = 0;
int val3 = 0;
int thisByte=0;
//--setup
void setup() {
  Serial.begin(115200);
}

//--loop
void loop() {
  val1 = analogRead(potPin1); // leo la variable del pote 1
  val3 = analogRead(potPin3); // leo la variable del pote 2

  // convierto con regla de tres simple el valor de 0 a 1024 en A hasta Z 
  //(para esto hay que saber que en ACSII esto es desde 65 hasat 90)
  thisByte=round(25/1023*val1)+65;
  Serial.print("X:"); // de aca en mas ves que uso print sin el ln (line) y lo dejo para el ultimo, fijate lo que pasa en la consola!
  Serial.print(val1);
  Serial.print(", Letra: ");
  Serial.print(thisByte);
  Serial.print(",\tY:");
  thisByte=round(25/1023*val3)+65;
  Serial.print(val3);
  Serial.print(", Letra: ");
  Serial.print(thisByte);
  Serial.println(",");
  delay(50);

}
