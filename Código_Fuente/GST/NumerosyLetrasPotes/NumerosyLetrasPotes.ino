
#include<math.h> // incluyo esta libreria de C estandar para usar la funcion ROUND!!


//aca cambias al calor maximo que muestre en pantalla agregar el ".0" es necesario por el tipo de variable Float
#define MaximoX 1023.0
//aca lo mismo
#define MaximoY 1023.0

// en este Filtro podes aumentar el valor de filtro para que no oscilen los valores,
// cuando mayor es el valor, mayor es lo que disminuye la frecuencia de las muestras que vez en pantalla
#define Filtro 100


//Pin de entrada de la señal del potenciómetro
int potPin1 = 1;
int potPin3 = 3;
//Variable del valor del sensor inicializadas en 0
int val1 = 0;
int val3 = 0;
//estas las uso para convertir el valor en un caracter
int thisByte = 0;
float f = 0;

//--setup de la comunicacion importante para el monitor serie
void setup() {
  Serial.begin(115200);
}

//--loop
void loop() {
  for (int i = 0; i < 100; i++)
  {
    val1 += analogRead(potPin1);
    val3 += analogRead(potPin3);
  }    // leo las variables 100 veces y las acumulo con el "+="
  val1 = val1 / 100; //saco el promedio pesado dividiendo el valor por 100 asi funciona este filtro que reduce las variaciones
  val3 = val3 / 100;

  // convierto con regla de tres simple el valor de 0 a 1023 en A hasta Z
  //(para esto hay que saber que en ACSII esto es desde los enteros 65 hasta 90)
  f = (25 / MaximoX) * val1; //auxiliar de cuenta para convertir a caracter
  thisByte = round(f) + 65; // convertir a un valor int en relacion con el caracter
  Serial.print("X:"); // de aca en mas ves que uso print sin el ln (line) y lo dejo para el ultimo, fijate lo que pasa en la consola!
  Serial.print(val1);
  Serial.print(", Letra: ");
  Serial.write(thisByte);  // nota que aca use el Serial.write porque quiero que un valor int imprima en el monitor pero como un char!!!
  Serial.print(", Y:");
  f = (25 / MaximoY) * val3;
  thisByte = round(f) + 65;
  Serial.print(val3);
  Serial.print(", Letra: ");
  Serial.write(thisByte);
  Serial.println(",");
  int val1 = 0;  // importante reiniciar los valores para el nuevo filtrado
  int val3 = 0;

}
