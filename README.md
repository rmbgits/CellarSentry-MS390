# 🛡️ CellarSentry-MS390
**Ultra-Głośny, Energooszczędny System Alarmowy DIY do Piwnicy**

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
<img width="1242" height="1656" alt="1-1" src="https://github.com/user-attachments/assets/b122fc91-198a-473b-83aa-408e44794205" />

## 📖 O projekcie
**CellarSentry-MS390** to zaawansowany system alarmowy zaprojektowany z myślą o ochronie piwnic, garaży i magazynów. W przeciwieństwie do gotowych rozwiązań, projekt ten stawia na ekstremalną siłę rażenia akustycznego przy zachowaniu minimalnego poboru prądu, co pozwala na wielomiesięczną pracę z akumulatora 12V.

Głównym elementem wykonawczym jest **syrena mechaniczna MS-390**, która generuje dźwięk o natężeniu **125dB**. System wykorzystuje unikalną, modulowaną sekwencję dźwiękową, która zwiększa skuteczność odstraszania i zapobiega ignorowaniu sygnału przez otoczenie.
<img width="622" height="844" alt="1" src="https://github.com/user-attachments/assets/9635f545-9b95-4375-a756-0cb693ac2de5" />


## 🚀 Kluczowe Funkcje
* **Ultra-Low Power:** Pobór prądu w spoczynku to zaledwie **1.1mA** (z przetwornicą i Arduino).
* **Modulated Siren Sequence:** Inteligentny algorytm sterujący syreną (sekwencja 5-minutowa z różnymi interwałami wycia i krótkimi przerwami).
* **Smart Status LED:** Wielofunkcyjna dioda informująca o stanie systemu:
    * *Błysk co 3s:* System uzbrojony (czuwanie).
    * *Szybki stroboskop:* Procedura alarmowa w toku.
    * *Błysk co 1s:* Pamięć naruszenia (drzwi były otwarte, alarm zakończył cykl).
* **Auto-Lockout:** Po wykonaniu pełnej sekwencji 5 cykli syrena milknie, aby chronić akumulator, ale system nadal sygnalizuje naruszenie diodą LED.
* **Battery Monitor:** Zintegrowany woltomierz cyfrowy aktywowany przyciskiem do szybkiej kontroli stanu naładowania.

## 🛠️ Lista Komponentów (BOM)
| Komponent | Model/Parametry | Ilość |
| :--- | :--- | :--- |
| Mikrokontroler | Arduino Pro Mini / Nano (3.3V) | 1 szt. |
| Syrena | Mechaniczna MS-390 (12V, 4.5A, 125dB) | 1 szt. |
| Przekaźnik | Samochodowy 30A/40A 12V | 1 szt. |
| Czujnik | Kontaktron magnetyczny | 1 szt. |
| Zasilanie | Akumulator żelowy 12V 7Ah + Przetwornica Step-Down | 1 kpl. |
| Sterowanie | Tranzystor NPN BC337 + rezystor 1kΩ | 1 kpl. |
| Monitorowanie | Woltomierz DC + przycisk chwilowy | 1 kpl. |
| Montaż | Kostki WAGO 221 + Puszka hermetyczna | 1 kpl. |

## 🔌 Schemat Połączeń
System wykorzystuje separację obwodu sterującego od obwodu mocy:
1. **Pin D2:** Wejście kontaktronu (tryb `INPUT_PULLUP`).
2. **Pin D10:** Wyjście na bazę tranzystora BC337 (sterowanie przekaźnikiem).
3. **Pin D13:** Wyjście na diodę sygnalizacyjną LED (3-6V).
4. **Masa:** Wszystkie punkty GND połączone wspólnie w złączce WAGO (Star Grounding).
5. **Zasilanie:** 12V z akumulatora obniżone do 3.3V dla zasilania Arduino (Pin VCC).

⚠️ Bezpieczeństwo
Ochrona słuchu: Podczas testów w piwnicy używaj stoperów/nauszników. 125dB w małym pomieszczeniu jest niebezpieczne.

Zasilanie: Akumulator żelowy należy ładować, gdy napięcie spadnie do 12.1V - 12.2V.

Okablowanie: Ze względu na prąd startowy syreny (ok. 15A), stosuj przewody o przekroju minimum 1.5mm² w obwodzie mocy.

👨‍💻 Autor
Projekt i kod: [Twoje Imię / Nick]
Kontakt: [Link do Twojego profilu]
