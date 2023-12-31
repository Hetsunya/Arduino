// Светодиоды подключены к пинам D0, D1, D2 и загораются по очереди при нажатии на кнопку подключенную к пину D3 (модель светофора):
const int ledPins[] = {D0, D1, D2};
const int buttonPin = D3;
int currentLED = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPins[currentLED], LOW);
    currentLED = (currentLED + 1) % 3;
    digitalWrite(ledPins[currentLED], HIGH);
    delay(200);
  }
}