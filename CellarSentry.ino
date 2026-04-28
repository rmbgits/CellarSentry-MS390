/*
 * CellarSentry-MS390
 * Autor: Twój Nick / GitHub
 * Opis: System alarmowy z obsługą syreny mechanicznej.
 */

#include "LowPower.h" // Wymaga zainstalowania biblioteki LowPower

const int PIN_SENSOR = 2;   // Kontaktron
const int PIN_SIREN  = 10;  // Przekaźnik syreny
const int ARMING_DELAY = 30; // Czas na wyjście (sekundy)
const int ALARM_DURATION = 120; // Czas wycia (sekundy)

void setup() {
  pinMode(PIN_SENSOR, INPUT_PULLUP);
  pinMode(PIN_SIREN, OUTPUT);
  digitalWrite(PIN_SIREN, LOW);

  // Czas na bezpieczne opuszczenie piwnicy
  for (int i = 0; i < ARMING_DELAY; i++) {
    delay(1000);
  }
}

void loop() {
  // Sprawdzenie stanu czujnika
  if (digitalRead(PIN_SENSOR) == HIGH) {
    triggerAlarm();
  }

  // Uśpienie procesora na 1 sekundę w celu oszczędzania energii
  // Po przebudzeniu pętla loop rusza od nowa
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); 
}

void triggerAlarm() {
  digitalWrite(PIN_SIREN, HIGH); // Start bestii MS-390
  
  // Syrena wyje przez określony czas
  for (int i = 0; i < ALARM_DURATION; i++) {
    delay(1000);
  }

  digitalWrite(PIN_SIREN, LOW); // Wyłączenie (syrena będzie jeszcze chwilę zwalniać)
  
  // Krótka zwłoka po alarmie przed ponownym uzbrojeniem
  delay(5000); 
}
