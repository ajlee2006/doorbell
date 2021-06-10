const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int oldButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  oldButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } Serial.println(buttonState); delay(100);
}
  
