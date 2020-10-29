
//Pin de entrada de la señal del potenciómetro
int potPin3 = 3;
//Variable del valor del sensor
int val3 = 0;

//--setup
void setup() {
  Serial.begin(115200);
}

//--loop
void loop(){
  val3 = analogRead(potPin3);

  Serial.println(val3);
  delay(20);

}
