const int z = 3; // pin digital conecta al pulsador
const int x = 0; // pin analogico conecta al eje x
const int y = 1; // pin analogico conecta al eje y
void setup() {
  pinMode(z, INPUT); 
  digitalWrite(z, HIGH); // A la salida lo que veremos sera el pulsador pulsador en estado 1
  Serial.begin(115200);
}

void loop() {
  Serial.print("Boton z: "); // con esto podremos ver en el serial puerto las palabras "Boton z:"
  Serial.print(digitalRead(z));
  Serial.print("\n"); // Espacio a otro renglon
  Serial.print("Eje x: "); // con esto podremos ver en el serial puerto las palabras "Eje x:"
  Serial.print(analogRead(x));
  Serial.print("\n");
  Serial.print("Eje y: "); // con esto podremos ver en el serial puerto las palabras "Eje y:"
  Serial.print(analogRead(y));
  Serial.print("\n\n");
  delay(500);
}
