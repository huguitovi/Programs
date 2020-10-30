
#include<math.h> // incluyo esta libreria de C estandar para usar la funcion ROUND!!


//Pin de entrada de la señal del potenciómetro
int potPin1 = 1;
int potPin3 = 3;
//Variable del valor del sensor
int val1 = 0;
int val3 = 0;

//--setup
void setup() {
  Serial.begin(115200);
}
int thisByte=0;
float f=0;
//--loop
void loop() {
  val1 = analogRead(potPin1); // leo la variable del pote 1
  val3 = analogRead(potPin3); // leo la variable del pote 2

  // convierto con regla de tres simple el valor de 0 a 1024 en A hasta Z 
  //(para esto hay que saber que en ACSII esto es desde 65 hasat 90)
  f=(25/1023) * val1; //auxiliar de cuenta para convertir a caracter
  thisByte=round(f) + 65; // convertir a un valor int en relacion con el caracter
  Serial.print("X:"); // de aca en mas ves que uso print sin el ln (line) y lo dejo para el ultimo, fijate lo que pasa en la consola!
  Serial.print(val1);
  Serial.print(", Letra: ");
  Serial.write(thisByte);
  Serial.print(",\tY:");
  f=(25/1023) * val3;
  thisByte=round(f) + 65;
  Serial.print(val3);
  Serial.print(", Letra: ");
  Serial.write(thisByte);
  Serial.println(",");
  delay(50);

}
