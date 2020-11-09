const int i = 3; // pin digital conecta al pulsador
const int x = A0; // pin analogico conecta al eje x
const int y = A1; // pin analogico conecta al eje y
const int j = 4; // pin digital conecta al pulsador
const int z = A2; // pin analogico conecta al eje x
const int w = A3; // pin analogico conecta al eje y

void setup() {
  pinMode(i, INPUT); 
  digitalWrite(i, HIGH); // A la salida lo que veremos sera el pulsador pulsador en estado 1
  
  pinMode(j, INPUT); 
  digitalWrite(j, HIGH); // A la salida lo que veremos sera el pulsador pulsador en estado 1
  
  Serial.begin(115200);
}

void loop() {
  Serial.print("Boton i: "); // con esto podremos ver en el serial puerto las palabras "Boton i:"
  Serial.print(digitalRead(i));
  Serial.print("\n"); // Espacio a otro renglon
  Serial.print("Eje x: "); // con esto podremos ver en el serial puerto las palabras "Eje x:"
  Serial.print(analogRead(x));
  Serial.print("\n");
  Serial.print("Eje y: "); // con esto podremos ver en el serial puerto las palabras "Eje y:"
  Serial.print(analogRead(y));
  Serial.print("\n\n");
  Serial.print("Boton j: "); // con esto podremos ver en el serial puerto las palabras "Boton j:"
  Serial.print(digitalRead(j));
  Serial.print("\n"); // Espacio a otro renglon
  Serial.print("Eje z: "); // con esto podremos ver en el serial puerto las palabras "Eje z:"
  Serial.print(analogRead(z));
  Serial.print("\n");
  Serial.print("Eje w: "); // con esto podremos ver en el serial puerto las palabras "Eje w:"
  Serial.print(analogRead(w));
  Serial.print("\n\n");
  delay(500);
}
