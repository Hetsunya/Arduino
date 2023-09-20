// Реализовать задание из пункта №3, но с использованием встроенного аппаратного таймера вместо нажатия на кнопку;
int ledPins[] = {0, 1, 2}; // Пины для светодиодов
int currentLed = 0; // Текущий светодиод

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Используем таймер 2 для периодического вызова функции changeLed
  Timer2.attachInterrupt(changeLed);
  Timer2.initialize(5000000); // Интервал в микросекундах (5 секунд)
  Timer2.start();
}

void loop() {
  // Здесь нет необходимости в бесконечном цикле
}

void changeLed() {
  digitalWrite(ledPins[currentLed], LOW);
  currentLed = (currentLed + 1) % 3;
  digitalWrite(ledPins[currentLed], HIGH);
}