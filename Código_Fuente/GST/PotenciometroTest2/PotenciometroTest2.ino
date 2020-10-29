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

//--loop
void loop(){
  val1 = analogRead(potPin1);
  val3 = analogRead(potPin3);

  Serial.println(val1);
  Serial.println(val3);
  delay(20);

}
