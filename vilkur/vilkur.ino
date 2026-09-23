// MATIK Git-harjutus: LED-i vilgutamine
// Plaadi sisseehitatud LED on pinnil 13 (LED_BUILTIN).

const int LED_PIN = LED_BUILTIN;
const int VILKUMISE_AEG = 1000;   // millisekundites

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(VILKUMISE_AEG);
  digitalWrite(LED_PIN, LOW);
  delay(VILKUMISE_AEG);
}
