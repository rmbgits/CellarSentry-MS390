
# CellarSentry-MS390 🛡️📟
Profesjonalny, energooszczędny system alarmowy do piwnicy oparty na Arduino Pro Mini i potężnej syrenie mechanicznej MS-390.

## 📋 Główne funkcjonalności
- **Ultra-low power:** Pobór prądu w trybie czuwania poniżej 1mA (po modyfikacji sprzętowej).
- **Potężny sygnał:** Obsługa syreny silnikowej MS-390 (125dB) przez przekaźnik 40A.
- **Inteligentna logika:** 30-sekundowa zwłoka na uzbrojenie i automatyczne wygaszanie alarmu.
- **Monitor napięcia:** Zintegrowany woltomierz do kontroli stanu akumulatora.

## 🛠️ Lista komponentów (BOM)
- **Mózg:** Arduino Pro Mini 3.3V / 8MHz
- **Wykonanie:** Syrena mechaniczna MS-390 (12V)
- **Sterowanie mocą:** Przekaźnik samochodowy DaierTek 40A (z diodą gaszącą)
- **Zasilanie:** Akumulator 12V + Przetwornica Step-Down (na 3.3V dla Arduino)
- **Czujnik:** Kontaktron magnetyczny (NC/NO)
- **Akcesoria:** Tranzystor NPN (BC547), rezystor 1kΩ, kondensator 470uF, złączki WAGO 221.

## ⚡ Schemat połączeń (Logika)
1. **Pin D2:** Wejście czujnika (Kontaktron) -> Masa (GND)
2. **Pin D10:** Wyjście sterujące -> Rezystor 1k -> Baza tranzystora
3. **Kolektor tranzystora:** -> Pin 85 przekaźnika (Cewka -)
4. **Pin 86 przekaźnika:** -> +12V (Cewka +)
5. **Pętla mocy:** Akumulator +12V -> Pin 30 -> Pin 87 -> Syrena MS-390 (+) -> Masa
