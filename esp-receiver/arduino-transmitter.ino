#define SOIL_PIN A0
#define LDR_PIN 2

#define RELAY_PIN 7
#define LED_PIN 8

void setup()
{
  Serial.begin(9600);

  pinMode(LDR_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  int soilValue = analogRead(SOIL_PIN);

  int soilPercent = map(soilValue, 1023, 300, 0, 100);
  soilPercent = constrain(soilPercent, 0, 100);

  int ldrValue = digitalRead(LDR_PIN);

  String statusPompa;
  String statusLampu;
  String statusCahaya;

  // Relay
  if (soilPercent < 40)
  {
    digitalWrite(RELAY_PIN, LOW);
    statusPompa = "ON";
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);
    statusPompa = "OFF";
  }

  // LED U V

  if (ldrValue == HIGH)
  {
    digitalWrite(LED_PIN, HIGH);

    statusLampu = "ON";
    statusCahaya = "GELAP";
  }
  else
  {
    digitalWrite(LED_PIN, LOW);

    statusLampu = "OFF";
    statusCahaya = "TERANG";
  }

  // Kirim ke ESP8266

  Serial.print(soilPercent);
  Serial.print(",");

  Serial.print(soilValue);
  Serial.print(",");

  Serial.print(statusPompa);
  Serial.print(",");

  Serial.print(statusCahaya);
  Serial.print(",");

  Serial.println(statusLampu);

  delay(2000);
}
