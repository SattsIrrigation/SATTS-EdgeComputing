#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("SATTS SYSTEM");

  delay(2000);
}

void loop() {
  int umidade = analogRead(A0);
  int solo = analogRead(A1);

  lcd.clear();

  if (umidade > 700) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

    noTone(7);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: IDEAL");
  }

  else if (umidade > 300) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);

    noTone(7);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: ALERTA");
  }

  else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);

    tone(7, 200);
    delay(100);
    noTone(7);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: IRRIGAR");
  }

  lcd.setCursor(0, 1);

  if (solo >= 650) {
    lcd.print("SOLO: OTIMO");
  }

  else if (solo >= 300) {
    lcd.print("SOLO: MEDIO");
  }

  else {
    lcd.print("SOLO: RUIM");
  }

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" | Solo: ");
  Serial.println(solo);

  delay(500);
}
