// KONFIGURACJA PINÓW
const int kontaktronPin = 2; 
const int syrenaPin = 10;    
const int ledPin = 9; // PRZEPIĘTE Z 13 NA 9 (PWM)

// USTAWIENIA JASNOŚCI I CZASU
const int jasnoscDiodny = 6; // Wartość od 1 do 255

void setup() {
  pinMode(kontaktronPin, INPUT_PULLUP);
  pinMode(syrenaPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(syrenaPin, LOW);
  analogWrite(ledPin, 0);
}

void loop() {
  // 1. BŁYSK KONTROLNY (Czuwanie)
  analogWrite(ledPin, jasnoscDiodny); 
  delay(30);
  analogWrite(ledPin, 0);

  // 2. SPRAWDZANIE DRZWI
  for (int i = 0; i < 30; i++) {
    if (digitalRead(kontaktronPin) == HIGH) { 
      proceduraOstrzegawcza(); 
      uruchomPelnyAlarm(); 
    }
    delay(100); 
  }
}

void proceduraOstrzegawcza() {
  // CZAS NA REAKCJĘ (ok. 3.7 sekundy)
  for (int i = 0; i < 17; i++) {
    analogWrite(ledPin, 3); 
    delay(110);
    analogWrite(ledPin, 0);
    delay(110);
  }
}

void uruchomPelnyAlarm() {
  // 2 CYKLE PO 40 SEKUND WYCIA = ŁĄCZNIE 1m 20s
  for (int cykl = 0; cykl < 2; cykl++) {
    
    // ZMODYFIKOWANA MELODIA (Suma wycia w cyklu = 40s):
    wyjZMiganiem(10000);  cisza(2000); // 10s wycia
    wyjZMiganiem(10000);  cisza(500);  // 10s wycia
    wyjZMiganiem(5000);   cisza(1000); // 5s wycia
    wyjZMiganiem(15000);  cisza(2000); // 15s wycia
  }

  // BLOKADA POALARMOWA
  while(digitalRead(kontaktronPin) == HIGH) {
    digitalWrite(syrenaPin, LOW); 
    analogWrite(ledPin, 30); delay(50); analogWrite(ledPin, 0);
    delay(1000); 
  }
}

void wyjZMiganiem(int ms) {
  unsigned long startT = millis();
  digitalWrite(syrenaPin, HIGH); 
  
  while (millis() - startT < ms) {
    analogWrite(ledPin, 4); 
    delay(50);
    analogWrite(ledPin, 0);
    delay(50);
  }
}

void cisza(int ms) {
  digitalWrite(syrenaPin, LOW);
  analogWrite(ledPin, 0);
  delay(ms);
}
