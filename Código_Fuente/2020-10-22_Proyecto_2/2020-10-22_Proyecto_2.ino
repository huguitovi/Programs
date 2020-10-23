//Pin de entrada de la señal del potenciometro
int potPin1 = 1;
const int threshold = 255;

//Variable del valor del sensor
String A = "A";
String B = "B";
//--setup
void setup() {
  Serial.begin(115200);
 
 }
 
//--loop
void loop() {
  int analogValue = (analogRead(potPin1))/4;
  if(analogValue > threshold){
    analogValue = "A"; 
  } else {
    analogValue = "B";
  }
    Serial.println(analogValue);
  delay(20);

}
