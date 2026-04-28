# 🛡️ CellarSentry-MS390
**Ultra-Głośny, Energooszczędny System Alarmowy DIY do Piwnicy**

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📖 O projekcie
**CellarSentry-MS390** to zaawansowany system alarmowy zaprojektowany z myślą o ochronie piwnic, garaży i magazynów. W przeciwieństwie do gotowych rozwiązań, projekt ten stawia na ekstremalną siłę rażenia akustycznego przy zachowaniu minimalnego poboru prądu.

Głównym elementem wykonawczym jest **syrena mechaniczna MS-390**, która generuje dźwięk o natężeniu **125dB** – wystarczający, by zmusić intruza do natychmiastowej ucieczki.

## 🚀 Kluczowe Funkcje
* **Deep Sleep Logic:** Dzięki optymalizacji kodu i sprzętu (usunięcie zbędnych diod LED), układ pobiera w spoczynku poniżej **1mA**.
* **Mechanical Power:** Wykorzystanie przekaźnika 40A pozwala bezpiecznie sterować silnikiem syreny MS-390.
* **Entry Delay (30s):** Czas na spokojne opuszczenie pomieszczenia po uzbrojeniu alarmu.
* **Siren Latch:** Po wyzwoleniu syrena wyje przez zaprogramowany czas (np. 120s), ignorując ponowne zamknięcie drzwi.
* **Star Grounding:** Profesjonalny układ masy oparty na złączkach WAGO 221, eliminujący zakłócenia od silnika.

## 🛠️ Lista Komponentów (BOM)
| Komponent | Model/Parametry | Ilość |
| :--- | :--- | :--- |
| Mikrokontroler | Arduino Pro Mini (3.3V / 8MHz) | 1 szt. |
| Syrena | Mechaniczna MS-390 (12V, 125dB) | 1 szt. |
| Przekaźnik | DaierTek 40A (z diodą gaszącą) | 1 szt. |
| Czujnik | Kontaktron magnetyczny | 1 szt. |
| Zasilanie | Akumulator 12V + Przetwornica Step-Down | 1 kpl. |
| Sterowanie | Tranzystor NPN (np. BC547) + rezystor 1kΩ | 1 kpl. |
| Obudowa | Puszka hermetyczna (min. 120x80mm) | 1 szt. |

## 🔌 Schemat Połączeń
W projekcie zastosowano separację obwodu logicznego od obwodu mocy:
1.  **Pin D2:** Wejście czujnika (z wewnętrznym podciąganiem PULLUP).
2.  **Pin D10:** Wyjście na tranzystor sterujący cewką przekaźnika.
3.  **Zasilanie:** Przetwornica obniża napięcie z 12V do stabilnego 3.3V dla Arduino.
4.  **Masa:** Wszystkie minusy schodzą się w jednym punkcie (złączka WAGO).

---
### 📸 Galeria
*(Tutaj wrzuć zdjęcia swojego gotowego układu)*
![Widok ogólny](https://via.placeholder.com/600x300?text=Zdjecie+Twojego+Alarmu)

---

## ⚠️ Bezpieczeństwo i Testy
* **HAŁAS:** MS-390 jest ekstremalnie głośna. Podczas testów w zamkniętych pomieszczeniach używaj ochronników słuchu!
* **PRĄD:** Syrena przy starcie może pobierać ponad 15A. Wymagany bezpiecznik **20A** oraz kable o przekroju min. **1.5mm²**.
* **ZAKŁÓCENIA:** Pamiętaj o kondensatorze (470uF) na zasilaniu Arduino, aby zapobiec resetom podczas startu silnika syreny.

## 👨‍💻 Autor
Projekt i kod: [Twoje Imię / Nick]
Kontakt: [Twój email lub link do profilu]
