const int buttonPin = 2;  
const int ledPin1 = 3;    
const int ledPin2 = 4;    
const int ledPin3 = 5;    
int ledState = 0;         
int buttonState = 0;      
int lastButtonState = 0;  

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) { 
      ledState++;
      if (ledState > 3) {
        ledState = 0;
      }
      updateLEDs();
    }
    delay(50);  
  }

  lastButtonState = buttonState;
}

void updateLEDs() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  if (ledState == 1) {
    digitalWrite(ledPin1, HIGH);
  } else if (ledState == 2) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, HIGH);
  } else if (ledState == 3) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
}
