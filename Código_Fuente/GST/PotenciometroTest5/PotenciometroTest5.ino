#include <string.h>
#define rep 1000
unsigned long int valorx=0, valory=0, valorz=0, valorw=0, k=0;
const int i = 3; // pin digital conecta al pulsador
const int x = A1; // pin analogico conecta al eje x
const int y = A0; // pin analogico conecta al eje y
const int j = 4; // pin digital conecta al pulsador
const int z = A3; // pin analogico conecta al eje x
const int w = A2; // pin analogico conecta al eje y
  unsigned char trama[13];
  
void setup() {
  pinMode(i, INPUT); 
  digitalWrite(i, HIGH); // A la salida lo que veremos sera el pulsador pulsador en estado 1
  
  pinMode(j, INPUT); 
  digitalWrite(j, HIGH); // A la salida lo que veremos sera el pulsador pulsador en estado 1
  
  Serial.begin(115200);
}

void loop() {
  while(k<rep){
    
  valorx += analogRead(A1);
    
  valory += analogRead(A0);
    
  valorz += analogRead(A3);
    
  valorw += analogRead(A2);
    
  k++;
  }
  valorx=valorx/rep;
  valory=valory/rep;
  valorz=valorz/rep;
  valorw=valorw/rep;
  k=0;
  if(valorx > 999) 
    valorx = 999;
  if(valory > 999) 
    valory = 999;
  if(valorz > 999) 
    valorz = 999;
  if(valorw > 999) 
    valorw = 999;
  sprintf(trama,"%03d%03d%03d%03d",valorx,valory,valorz,valorw);
  
  for(int t=0;t<13;t++)
  Serial.write(trama[t]);
  Serial.print("\n");
  valorx=0;
  valory=0;
  valorz=0;
  valorw=0;
//  Serial.print("Boton i: "); // con esto podremos ver en el serial puerto las palabras "Boton i:"
//  Serial.print(digitalRead(i));
//  Serial.print("\n"); // Espacio a otro renglon
//  Serial.print("Eje x: "); // con esto podremos ver en el serial puerto las palabras "Eje x:"
//  Serial.print(analogRead(x));
//  Serial.print("\n");
//  Serial.print("Eje y: "); // con esto podremos ver en el serial puerto las palabras "Eje y:"
//  Serial.print(analogRead(y));
//  Serial.print("\n\n");
//  Serial.print("Boton j: "); // con esto podremos ver en el serial puerto las palabras "Boton j:"
//  Serial.print(digitalRead(j));
//  Serial.print("\n"); // Espacio a otro renglon
//  Serial.print("Eje z: "); // con esto podremos ver en el serial puerto las palabras "Eje z:"
//  Serial.print(analogRead(z));
//  Serial.print("\n");
//  Serial.print("Eje w: "); // con esto podremos ver en el serial puerto las palabras "Eje w:"
//  Serial.print(analogRead(w));
//  Serial.print("\n\n");
//  delay(500);
}
