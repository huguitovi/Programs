// Emulador disponible en:

// https://www.tinkercad.com/things/3AbcvOwmZ8W 
 
// Cantidad de adquiciciones para Filtro de promedio pesado
#define rep 1000.

//Pin de entrada de la señal del potenciómetro y botones
const int xPin = 1;
const int yPin = 0;
const int zPin = 3;
const int wPin = 2;
//Variable del sensor
unsigned long int w = 0;
unsigned long int z = 0;
unsigned long int x = 0;
unsigned long int y = 0;
unsigned long int k = 0; // contador de filtro
unsigned int w1 = 0;
unsigned int w2 = 0;
unsigned int w3 = 0;
unsigned int y1 = 0;
unsigned int y2 = 0;
unsigned int y3 = 0;
unsigned int x1 = 0;
unsigned int x2 = 0;
unsigned int x3 = 0;
unsigned int z1 = 0;
unsigned int z2 = 0;
unsigned int z3 = 0;
//--setup
void setup() {
  // A la salida lo que veremos sera el pulsador pulsador en estado 1
  Serial.begin(115200);
}



//--loop
void loop() {
  while (k < rep) {
    x += analogRead(xPin);
    y += analogRead(yPin);
    z += analogRead(zPin);
    w += analogRead(wPin);

    k++;
  }

  x = x / rep;
  y = y / rep;
  z = z / rep;
  w = w / rep;
  x = 999 / 1023. * (float)x;
  x1 = x / 100;
  x2 = x / 10 - x1 * 10 ;
  x3 = x  - x2 * 10 - x1 * 100;
  Serial.print(x1);  Serial.print(x2);  Serial.print(x3);


  y = 999 / 1023. * (float)y;
  y1 = y / 100;
  y2 = y / 10 - y1 * 10 ;
  y3 = y  - y2 * 10 - y1 * 100;
  Serial.print(y1);  Serial.print(y2);  Serial.print(y3);

  z = 999 / 1023. * (float)z;
  z1 = z / 100;
  z2 = z / 10 - z1 * 10 ;
  z3 = z  - z2 * 10 - z1 * 100;
  Serial.print(z1);  Serial.print(z2);  Serial.print(z3);


  w = 999 / 1023. * (float)w;
  w1 = w / 100;
  w2 = w / 10 - w1 * 10 ;
  w3 = w  - w2 * 10 - w1 * 100;
  Serial.print(w1);  Serial.print(w2);  Serial.println(w3);
  k = 0;
}
