# 🐻🍬 Bäromat3000

![Release](https://img.shields.io/badge/Hardware-LaserCut%20%26%203D%20Print-orange)
![Arduino](https://img.shields.io/badge/Microcontroller-Arduino%20Uno%20R3-00979D?logo=arduino)
![Interface](https://img.shields.io/badge/GUI-Web%20Serial%20API-yellow?logo=html5)
![Status](https://img.shields.io/badge/Status-Operational-brightgreen)

Ein individueller, lasergeschnittener Mini-Süßigkeiten-Vending-Automat aus Holz für die automatische Ausgabe kleiner Haribo Goldbären-Packs! 

Gesteuert wird das System über einen **Arduino Uno R3**, ein **CNC Shield V3** und ein browserbasiertes Web-Interface via **Web Serial API** über USB – inklusive interaktivem Handbetrieb und Audio-Synthesizer.

---

## 📸 Vorschau & Komponenten

| Komponente | Details |
| :--- | :--- |
| **Gehäuse** | Laser-Cut Holzrahmen (3-Tier Vending-System) |
| **Förderkanal** | 3D-gedruckte horizontale Förderspiralen |
| **Ansteuerung** | NEMA 17 Schrittmotoren via DRV8825 Treiber |
| **Steuerung** | USB Serial Interface (Chrome/Edge Web Serial) |

---

## 🛠️ Hardware-Architektur

### 1. Mechanik & Gehäuse
* **Holz-Chassis:** Präzise gelaserte Holzbauteile für einen stabilen Stand und ein edles Finish.
* **3D-Druck-Komponenten:** Passgenaue Förderspiralen zur Führung und Ausgabe der Haribo-Tüten.

### 2. Elektronik
* **Arduino Uno R3:** Haupt-Mikrocontroller für die Schrittketten-Steuerung.
* **CNC Shield V3.0:** Motor-Shield zur Ansteuerung der einzelnen Achsen.
* **DRV8825 Motortreiber:** Integrierte Microstepping-Konfiguration für ruhigen Lauf.
* **24V-Netzteil:** Externe Spannungsversorgung am Shield für hohes Drehmoment.

> [!TIP]
> **Hitze- & Geräuschschutz:** Die Firmware nutzt eine *Active-Low*-Steuerung des Enable-Pins (Pin 8). Die Motoren werden nur während der Drehbewegung unter Strom gesetzt. Im Leerlauf sind sie komplett spannungsfrei – das verhindert Überhitzung und lästiges Standby-Fiepen.

---

## 💻 Software & Steuerung

Das System basiert auf zwei Hauptkomponenten:

- [x] **Firmware (`Main_J1_J2.ino`):** C++ Arduino-Sketch zur präzisen Schrittsteuerung (1800 Schritte / Portion) sowie Live-Befehlsauswertung via USB-Serial (`115200 Baud`).
- [x] **Web-Interface (`index.html`):** Lokales Control-Panel für den PC oder ein angeschlossenes Tablet. Nutzt die native Web Serial API (keine Server- oder Driver-Installation nötig).
- [x] **Audio-Synthesizer:** Integrierte Web Audio API für eine automatische, synchrone Bäromat-Hymne während des Ausgabevorgangs.

---

## 🔌 Pin-Belegung (CNC Shield V3)

| Komponente | Arduino Pin | Funktion |
| :--- | :---: | :--- |
| **X-STEP** | `Pin 2` | Schritt-Signal Motor A (X-Achse) |
| **X-DIR** | `Pin 5` | Richtungs-Signal Motor A |
| **Y-STEP** | `Pin 3` | Schritt-Signal Motor B (Y-Achse) |
| **Y-DIR** | `Pin 6` | Richtungs-Signal Motor B |
| **ENABLE** | `Pin 8` | Gemeinsamer Enable-Pin (LOW = Aktiv, HIGH = Frei) |

---

## 🚀 Schnellstart

1. **Repository klonen:**
   ```bash
   git clone [https://github.com/DEIN-USERNAME/Baeromat3000.git](https://github.com/DEIN-USERNAME/Baeromat3000.git)
