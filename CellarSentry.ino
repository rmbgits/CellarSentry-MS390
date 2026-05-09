// KONFIGURACJA PINÓW
const int kontaktronPin = 2; 
const int syrenaPin = 10;    
const int ledPin = 13;       

void setup() {
  pinMode(kontaktronPin, INPUT_PULLUP);
  pinMode(syrenaPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(syrenaPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // 1. BŁYSK KONTROLNY (Oszczędne "czuwanie")
  digitalWrite(ledPin, HIGH); 
  delay(15);
  digitalWrite(ledPin, LOW);

  // 2. SPRAWDZANIE DRZWI (przez 3 sekundy)
  for (int i = 0; i < 30; i++) {
    if (digitalRead(kontaktronPin) == HIGH) { 
      uruchomPelnyAlarm(); 
    }
    delay(100); 
  }
}

void uruchomPelnyAlarm() {
  for (int cykl = 0; cykl < 5; cykl++) {
    // TWOJA MODULOWANA MELODIA Z SZYBKIM MIGANIEM DIODY:
    wyjZMiganiem(15000);  cisza(2000); 
    wyjZMiganiem(10000);  cisza(500);  
    wyjZMiganiem(10000);  cisza(1000); 
    wyjZMiganiem(20000);  cisza(2000); 
  }

  // BLOKADA PO 5 CYKLACH
  while(digitalRead(kontaktronPin) == HIGH) {
    digitalWrite(syrenaPin, LOW); 
    // Dioda mruga powoli w trybie blokady (ostrzeżenie)
    digitalWrite(ledPin, HIGH); delay(50); digitalWrite(ledPin, LOW);
    delay(1000); 
  }
}

// NOWA FUNKCJA: Wycie syreny + bardzo szybkie miganie diody (stroboskop)
void wyjZMiganiem(int ms) {
  unsigned long startT = millis();
  digitalWrite(syrenaPin, HIGH); // Włącz syrenę
  
  while (millis() - startT < ms) {
    digitalWrite(ledPin, HIGH);
    delay(50);  // Szybki błysk
    digitalWrite(ledPin, LOW);
    delay(50);  // Szybka przerwa
  }
}

void cisza(int ms) {
  digitalWrite(syrenaPin, LOW);
  digitalWrite(ledPin, LOW); // Dioda też milczy w przerwie
  delay(ms);
}
