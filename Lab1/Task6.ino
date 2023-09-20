// Светодиод подключенный к пину D0 меняет яркость при повороте потенциометра подключенного к пину D1 с частотой 60Гц (ШИМ-сигнал).
int ledPin = 0;
int potPin = 1;
int potValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin); // Считываем значение потенциометра (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // Преобразуем значение в диапазон яркости (0-255)
  analogWrite(ledPin, brightness); // Устанавливаем яркость светодиода
  delay(16); // Задержка для частоты 60 Гц (1 секунда / 60 Гц ≈ 16 миллисекунд)
}