int xPin = A0;
int yPin = A1;
int swPin = 3;

int xPos, yPos, xMap, yMap, xPrev, yPrev = 0;
boolean swState, swPrev = 0;

void setup() {
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
}

void loop() {
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  swState = digitalRead(swPin);

  xMap = map(xPos, 0, 1023, 512, -512);
  yMap = map(yPos, 0, 1023, -512, 512);

  if(swPrev!= swState){
    swPrev = swState;
    print();
  }
  if(xPrev!= xMap && xPrev != (xMap-1) && xPrev!= (xMap+1)){
    xPrev = xMap;
    print();
  }
  if(yPrev!= yMap && yPrev != (yMap-1) && yPrev!= (yMap+1)){
    yPrev = yMap;
    print();
  }
  
  delay(100);

}

void print(){
  Serial.println("X: " + String(xMap) + " | Y: " + String(yMap) + " | Button: " + String(swState));
}
