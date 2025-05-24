#include <Arduino.h>
#include <SensirionI2cSht3x.h>
#include <Wire.h>

SensirionI2cSht3x sensor;

static char errorMessage[64];
static int16_t error;

void setup() {

    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }
    Wire.begin();
    sensor.begin(Wire, SHT30_I2C_ADDR_44);

    sensor.stopMeasurement();
    delay(1);
    sensor.softReset();
    delay(100);
    uint16_t aStatusRegister = 0u;
    error = sensor.readStatusRegister(aStatusRegister);
    if (error != NO_ERROR) {
        Serial.print("Error trying to execute readStatusRegister(): ");
        errorToString(error, errorMessage, sizeof errorMessage);
        Serial.println(errorMessage);
        return;
    }
    Serial.print("aStatusRegister: ");
    Serial.print(aStatusRegister);
    Serial.println();
}

void loop() {

    float aTemperature = 0.0;
    float aHumidity = 0.0;
    error = sensor.measureSingleShot(REPEATABILITY_MEDIUM, false, aTemperature,
                                     aHumidity);
    if (error != NO_ERROR) {
        Serial.print("Error trying to execute measureSingleShot(): ");
        errorToString(error, errorMessage, sizeof errorMessage);
        Serial.println(errorMessage);
        return;
    }
    Serial.print("aTemperature: ");
    Serial.print(aTemperature);
    Serial.print("\t");
    Serial.print("aHumidity: ");
    Serial.print(aHumidity);
    Serial.println();
}