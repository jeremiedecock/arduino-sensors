const int DELAY_MS = 60 * 1000;

const int TMP36_PIN = A0;

const bool ENABLE_TMP36 = true;

unsigned long millisec_cycle = 0;   // TODO: add sth to avoid 50 days overflow issue of the millis() function
unsigned long millisec = 0;

void setup() {
    Serial.begin(9600);

    // Print CSV header
    Serial.print("millisec");
    if(ENABLE_TMP36) {Serial.print(",temperature_degree_celsius");}
    Serial.println("");
}

void loop() {
    delay(DELAY_MS);

    millisec = millis();
    Serial.print(millisec);

    if(ENABLE_TMP36) {
        int raw_tmp36_temperature = analogRead(TMP36_PIN);
        float tmp36_volts = (raw_tmp36_temperature/1024.0) * 5.0;
        float temperature_degrees = (tmp36_volts - 0.5) * 100;
        Serial.print(",");
        Serial.print(temperature_degrees);
    }

    Serial.println("");
}
