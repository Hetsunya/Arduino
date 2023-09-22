// Реализовать задание из пункта №3, но с использованием встроенного аппаратного таймера вместо нажатия на кнопку;
const int ledPins[] = {D0, D1, D2};
int currentLED = 0;
unsigned long previousMillis = 0;
const long interval = 200;  // Интервал между сменой светодиода (200 миллисекунд)

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    digitalWrite(ledPins[currentLED], LOW);
    currentLED = (currentLED + 1) % 3;
    digitalWrite(ledPins[currentLED], HIGH);
    previousMillis = currentMillis;
  }
}
