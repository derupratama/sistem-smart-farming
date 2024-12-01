#define BLYNK_TEMPLATE_ID "TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "Greenhouse"
#define BLYNK_AUTH_TOKEN "ISI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "WIFI";
char pass[] = "PASSWORD";

String dataMasuk = "";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  if (Serial.available())
  {
    dataMasuk = Serial.readStringUntil('\n');

    int p1 = dataMasuk.indexOf(',');
    int p2 = dataMasuk.indexOf(',', p1 + 1);
    int p3 = dataMasuk.indexOf(',', p2 + 1);
    int p4 = dataMasuk.indexOf(',', p3 + 1);

    int soilPercent =
      dataMasuk.substring(0, p1).toInt();

    int soilRaw =
      dataMasuk.substring(p1 + 1, p2).toInt();

    String pompa =
      dataMasuk.substring(p2 + 1, p3);

    String cahaya =
      dataMasuk.substring(p3 + 1, p4);

    String ledUV =
      dataMasuk.substring(p4 + 1);

    Serial.println("===== DATA DARI ARDUINO =====");

    Serial.print("Kelembapan : ");
    Serial.println(soilPercent);

    Serial.print("Soil Raw : ");
    Serial.println(soilRaw);

    Serial.print("Pompa : ");
    Serial.println(pompa);

    Serial.print("Cahaya : ");
    Serial.println(cahaya);

    Serial.print("LED UV : ");
    Serial.println(ledUV);

    // Kirim ke Blynk

    Blynk.virtualWrite(V0, soilPercent);
    Blynk.virtualWrite(V1, soilRaw);
    Blynk.virtualWrite(V2, pompa);
    Blynk.virtualWrite(V3, cahaya);
    Blynk.virtualWrite(V4, ledUV);
  }
}
