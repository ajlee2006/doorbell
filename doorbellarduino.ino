const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int oldButtonState = 0;
int change = 0;
int timerOn = 0;
int ctr = 0;
int minCtr = 1;
int zCtr = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  oldButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if (oldButtonState == LOW && buttonState == HIGH)
    change = 1;
  else if (oldButtonState == HIGH && buttonState == LOW)
    change = -1;
  else
    change = 0;

  if (change == 1){
    timerOn = 1;
    digitalWrite(ledPin, HIGH);
  }
  else if (change == -1) {
    timerOn = 0;
    digitalWrite(ledPin, LOW);
    if (ctr > minCtr) {
      for (int j=0; j<4; j++)
        Serial.print(ctr);
      Serial.println();
      delay(200);
    } 
  }

  if (timerOn == 1)
    ctr++;
  else {
    ctr = 0;
  }
  
  /*
  zCtr++;
  if (zCtr % 2 == 0){
    Serial.println(0);
    zCtr = 0;
  }
  */
  delay(50);
  Serial.flush(); /*required to prevent Raspberry Pi Python serial read error*/
}
