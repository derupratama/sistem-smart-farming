# Smart Greenhouse Monitoring System

## Deskripsi Sistem

Smart Greenhouse Monitoring System merupakan sistem monitoring dan kontrol greenhouse berbasis Internet of Things (IoT) yang menggunakan kombinasi **Arduino Uno** sebagai pengendali utama dan **ESP8266 NodeMCU** sebagai modul komunikasi WiFi.

Sistem ini memanfaatkan **Soil Moisture Sensor** untuk mengukur kelembapan tanah dan **LDR Module (Light Dependent Resistor)** untuk mendeteksi kondisi cahaya lingkungan. Berdasarkan data yang diperoleh, sistem akan mengendalikan **Pompa Air** melalui modul Relay dan **Lampu UV (LED)** secara otomatis.

Data sensor serta status aktuator dikirim dari Arduino Uno ke ESP8266 menggunakan komunikasi **UART Serial**, kemudian diteruskan ke platform **Blynk IoT** sehingga pengguna dapat memantau kondisi greenhouse secara real-time melalui smartphone maupun dashboard web.

---

# Fitur Utama

### Monitoring Kelembapan Tanah

* Membaca nilai kelembapan tanah menggunakan Soil Moisture Sensor.
* Mengonversi nilai sensor menjadi persentase kelembapan (%).
* Menampilkan nilai ADC sensor secara real-time.

### Pompa Air Otomatis

* Pompa menyala otomatis ketika kelembapan tanah kurang dari 40%.
* Pompa mati otomatis ketika kelembapan tanah kembali normal.

### Monitoring Intensitas Cahaya

* Menggunakan sensor LDR untuk mendeteksi kondisi terang dan gelap.
* Menampilkan status cahaya lingkungan.

### Lampu UV Otomatis

* Menyala otomatis saat kondisi lingkungan gelap.
* Mati otomatis saat kondisi lingkungan terang.

### Monitoring IoT

* Data sensor dikirim dari Arduino Uno ke ESP8266 menggunakan UART.
* ESP8266 mengirim data ke platform Blynk IoT melalui WiFi.


---

# Komponen yang Digunakan

| No | Komponen               |
| -- | ---------------------- |
| 1  | Arduino Uno            |
| 2  | ESP8266 NodeMCU        |
| 3  | Soil Moisture Sensor   |
| 4  | LDR Module             |
| 5  | Relay Module 1 Channel |
| 6  | Pompa Air DC           |
| 7  | LED UV                 |
| 8  | Resistor 220Ω          |
| 9  | Powerbank 5V           |
| 10 | Breadboard             |
| 11 | Kabel Jumper           |

---



# Konfigurasi Rangkaian

<img width="989" height="647" alt="rangkaian drawio" src="https://github.com/user-attachments/assets/578338da-f030-497b-a962-2a6cce760cdb" />

---


# Library yang Digunakan

## Arduino Uno (Transmitter)

Arduino Uno tidak memerlukan library tambahan karena hanya menggunakan fungsi bawaan Arduino IDE:

```cpp
Serial.begin()
analogRead()
digitalRead()
digitalWrite()
```

---

## ESP8266 (Receiver)

Library yang harus diinstal:

### Blynk

```text
Blynk by Volodymyr Shymanskyy
```

### ESP8266 Board Package

Tambahkan URL berikut pada Arduino IDE:

```text
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

Kemudian install:

```text
ESP8266 by ESP8266 Community
```

---

# Konfigurasi Blynk IoT

## 1. Membuat Akun

Daftar melalui:

```text
https://blynk.io
```

atau aplikasi:

```text
Blynk IoT
```

---

## 2. Membuat Template

Masuk ke:

```text
Templates
↓
New Template
```

Isi:

```text
Template Name : Smart Greenhouse
Hardware      : ESP8266
Connection    : WiFi
```

---

## 3. Membuat Datastream

### V0 - Kelembapan Tanah

```text
Nama        : Kelembapan Tanah
Virtual Pin : V0
Data Type   : Integer
Min         : 0
Max         : 100
Unit        : %
```

### V1 - Soil Raw

```text
Nama        : Soil Raw
Virtual Pin : V1
Data Type   : Integer
Min         : 0
Max         : 1023
Unit        : ADC
```

### V2 - Status Pompa

```text
Nama        : Status Pompa
Virtual Pin : V2
Data Type   : String
```

### V3 - Kondisi Cahaya

```text
Nama        : Kondisi Cahaya
Virtual Pin : V3
Data Type   : String
```

### V4 - Status LED UV

```text
Nama        : Status LED UV
Virtual Pin : V4
Data Type   : String
```

---

# Dashboard Blynk

Tambahkan widget berikut:

| Widget        | Virtual Pin |
| ------------- | ----------- |
| Gauge         | V0          |
| Value Display | V1          |
| Label         | V2          |
| Label         | V3          |
| Label         | V4          |

---

## Layout Dashboard

```text
┌──────────────────────────┐
│ SMART GREENHOUSE         │
└──────────────────────────┘

Kelembapan Tanah
      65 %

Soil Raw
550

Status Pompa
OFF

Kondisi Cahaya
TERANG

Status LED UV
OFF
```

---

# Format Data UART

Arduino mengirim data ke ESP8266 dalam format:

```text
65,550,OFF,TERANG,OFF
```

Keterangan:

```text
65      = Kelembapan Tanah (%)
550     = Nilai ADC Soil Moisture
OFF     = Status Pompa
TERANG  = Kondisi Cahaya
OFF     = Status LED UV
```

---

# Contoh Output Serial Monitor ESP8266

```text
===== DATA DARI ARDUINO =====

Kelembapan : 65
Soil Raw   : 550
Pompa      : OFF
Cahaya     : TERANG
LED UV     : OFF
```

---

# Cara Menjalankan Sistem

1. Upload program Arduino Uno.
2. Upload program ESP8266 (Selesaikan Upload Program ESP8266 dulu baru sambungin TX dan RX).
3. Hubungkan Arduino TX ke ESP RX menggunakan voltage divider.
4. Hubungkan GND Arduino dengan GND ESP8266.
5. Sambungkan ESP8266 ke jaringan WiFi.
6. Jalankan aplikasi Blynk.
7. Lakukan pengujian sensor dan amati perubahan data secara real-time.

---

