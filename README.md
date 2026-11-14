# 🐻🍬 Bäromat3000

![Release](https://img.shields.io/badge/Hardware-LaserCut%20%26%203D%20Print-orange)
![Arduino](https://img.shields.io/badge/Microcontroller-Arduino%20Uno%20R4%20WiFi-00979D?logo=arduino)
![Interface](https://img.shields.io/badge/GUI-WiFi%20Access%20Point%20&%20Webserver-yellow?logo=html5)
![Status](https://img.shields.io/badge/Status-Operational-brightgreen)

Ein automatisierter, lasergeschnittener Mini-Süßigkeiten-Vending-Automat aus Holz für die perfekte Gummibärchen-Ausgabe! 

Gesteuert wird das System über einen **Arduino Uno R4 WiFi** im eigenständigen Access-Point-Modus. Jedes Smartphone oder Tablet verbindet sich direkt mit dem Automaten und bedient ihn über eine integrierte Web-Oberfläche – inklusive Multi-Fach-Auswahl, Not-Aus und einem interaktiven Audio-Synthesizer für die offizielle Bäromat-Hymne!

---

## 📸 Vorschau & Komponenten

| Komponente | Details |
| :--- | :--- |
| **Gehäuse** | Laser-Cut Holzrahmen (Multi-Tier Vending-System) |
| **Förderkanal** | 3D-gedruckte rotierende Spiralschächte auf Basis von: https://makerworld.com/de/models/2380835-full-size-modular-vending-machine#profileId-2607127  |
| **Ansteuerung** | NEMA 17 Schrittmotoren via CNC Shield V3 |
| **Steuerung** | Kabelloses Web-Interface (WLAN / WiFi AP) |

---

## 🛠️ Hardware-Architektur

### 1. Mechanik & Gehäuse
- **Holz-Chassis:** Präzise gelaserte Holzbauteile für einen stabilen Stand.
- **3D-Druck-Komponenten:** Passgenaue Förderspiralen für 4 unabhängige Ausgabeschächte.

### 2. Elektronik
- **Arduino Uno R4 WiFi:** Haupt-Mikrocontroller mit integriertem WLAN-Modul und Webserver.
- **CNC Shield V3.0:** Motor-Shield zur sauberen Ansteuerung von bis zu 4 Achsen.
- **Treibereinheit:** A4988 / DRV8825 Schrittmotortreiber.
- **Netzteil:** Externe Spannungsversorgung für ruckelfreies Drehmoment.

> [!TIP]
> **Aktives Energiemanagement:** Die Firmware nutzt eine *Active-Low*-Steuerung des Enable-Pins (Pin 8). Die Motoren stehen nur während des Ausgabevorgangs unter Strom. Im Leerlauf sind sie komplett spannungsfrei – das verhindert Überhitzung und lästiges Standby-Fiepen.

---

## 💻 Software & Steuerung

Das Projekt setzt auf eine saubere, modulare 2-Dateien-Struktur in der Arduino IDE:

- [x] **Hauptsketch (`WifiBaer_4Motor.ino`):** C++ Firmware für den WLAN-Access-Point, den internen Webserver und die präzise Ansteuerung der 4 Stepper-Motoren.
- [x] **Frontend (`index.h`):** Vollständige HTML5/CSS3-Oberfläche (Dark-Mode, Grid-Buttons) direkt im Flash-Speicher des Arduinos hinterlegt.
- [x] **Audio-Synthesizer:** Native Web Audio API im Browser für eine synchrone, fröhliche Melodie während der Ausgabe.

---

## 🔌 Pin-Belegung (CNC Shield V3)

| Bauteil / Achse | Arduino Pin | Funktion |
| :--- | :---: | :--- |
| **Motor A (Fach 1)** | `Pin 2` (Step) / `Pin 5` (Dir) | X-Achse (Spirale 1) |
| **Motor B (Fach 2)** | `Pin 3` (Step) / `Pin 6` (Dir) | Y-Achse (Spirale 2) |
| **Motor C (Fach 3)** | `Pin 4` (Step) / `Pin 7` (Dir) | Z-Achse (Spirale 3) |
| **Motor D (Fach 4)** | `Pin 12` (Step) / `Pin 13` (Dir) | A-Achse (Spirale 4) |
| **ENABLE (ENA)** | `Pin 8` | Gemeinsamer Freigabe-Pin (`LOW` = Aktiv, `HIGH` = Stromlos) |

---

## 🚀 Schnellstart & Anleitung

### 1. Projekt vorbereiten
1. Installiere die Arduino IDE und füge das Board-Paket für den **Arduino Uno R4** hinzu.
2. Stelle sicher, dass die **`WiFiS3`**-Bibliothek installiert ist.
3. Erstelle einen Ordner namens `WifiBaer_4Motor` und lege dort hinein:
   * Den Hauptsketch (`WifiBaer_4Motor.ino`)
   * Die HTML-Headerdatei (`index.h`)
4. Lade den Sketch auf deinen Arduino Uno R4 WiFi hoch.

### 2. Mit dem Bäromaten-WLAN verbinden
1. Schalte den Arduino ein. Er spannt ein eigenes WLAN auf:
   * **SSID (Netzwerkname):** `Baeromat3000`
   * **Passwort:** `gummibaerchen` !!!!!Unbedingt ändern
2. Verbinde dein Smartphone, Tablet oder deinen Laptop mit diesem WLAN.

### 3. Web-Interface aufrufen & Naschen
1. Öffne den Browser auf deinem Endgerät.
2. Gib in die Adresszeile folgende IP ein:
   👉 **`http://192.168.4.1`**
3. Die Steuerungsoberfläche lädt direkt vom Arduino:
   * Wähle **Fach 1 bis 4** aus.
   * Klicke auf den Ausgabebutton – die Spirale rotiert, während im Browser die Bärchen-Hymne erklingt!
   * Über den roten **Not-Aus**-Button wird das System sofort stromlos geschaltet. (Naja sollte es zumindest)

---

## 📂 Repository-Struktur

```text
📂 WifiBaer_4Motor/
 ┣ 📜 WifiBaer_4Motor.ino   # Arduino Firmware (AP, Webserver & Stepper-Logik)
 ┗ 📜 index.h               # HTML/JS Frontend (UI, Vektor-Logo & Web Audio API)
