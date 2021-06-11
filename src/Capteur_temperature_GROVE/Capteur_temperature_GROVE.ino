/*
    ** Mesure Température module Grove **
       PIN A0 Module shield GROVE
       Baud rate 9600 -> Moniteur série
*/

#include <math.h>

const int B = 4275;
const int R0 = 100000;
const int pinTempSensor = A0;

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

void setup() {
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(pinTempSensor);

  float R = 1023.0 / a - 1.0;
  R = R0 * R;

  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15;

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.println();
  delay(500);
}
