#include <Wire.h>

#define DAC_ADDR 0x58
const int ADC_PIN = A2;
#define LED_PIN 25 
void writeDAC(uint8_t ch, uint16_t val)
{
    if (val > 4095) val = 4095;
    Wire.beginTransmission(DAC_ADDR);
    Wire.write(ch == 0 ? 0x02 : 0x04);
    Wire.write(val >> 8);
    Wire.write(val & 0xFF);
    Wire.endTransmission();
}
float analogMul(float x, float y)
{
    writeDAC(0, (int)x);
    writeDAC(1, (int)y);
    delay(5); // settle time
    return analogRead(ADC_PIN);
}
void setup()
{
    Serial.begin(115200);
    while (!Serial);

    Wire.begin();
    analogReadResolution(12);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Serial.println("Demo active");
    Serial.println("Enter 8 values: a b c d e f g h");
}
void loop()
{
    if (!Serial.available()) return;

    float a = Serial.parseFloat();
    float b = Serial.parseFloat();
    float c = Serial.parseFloat();
    float d = Serial.parseFloat();
    float e = Serial.parseFloat();
    float f = Serial.parseFloat();
    float g = Serial.parseFloat();
    float h = Serial.parseFloat();
    while (Serial.available()) Serial.read();
    float C00 = analogMul(a, e) + analogMul(b, g);
    float C01 = analogMul(a, f) + analogMul(b, h);
    float C10 = analogMul(c, e) + analogMul(d, g);
    float C11 = analogMul(c, f) + analogMul(d, h);

    Serial.println("\nRESULT (analog-assisted):");

    Serial.print(C00); Serial.print("  ");
    Serial.println(C01);

    Serial.print(C10); Serial.print("  ");
    Serial.println(C11);

    Serial.println("\nEnter next 8 numbers:");

    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
}
