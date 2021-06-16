# 33115-Capteur de température GROVE

Capteur de température GROVE [33115](https://www.pierron.fr/interface-arduino-uno-5952.html)

<div style="text-align: justify">Le capteur de température V1.1 utilise une thermistance pour détecter la température ambiante. La résistance d’une thermistance augmentera lorsque la température ambiante diminuera. C’est cette caractéristique que nous utilisons pour calculer la température ambiante. La portée détectable de ce capteur est de -40 à +125 °C avec une précision de ±1,5 °C.</div>

Caractéristiques techniques :
- Alimentation : 3,3 à 5 V
- Plage de mesure : -40 à +125 °C
- Précision : 1,5 °C

![L-33115](/img/L-33115.jpg)

# Usage :
Pour l’utilisation de ce module, référez-vous aux indications présentes sur le circuit imprimé GROVE.

# Schémas :

![SCH-33115](/img/SCH-33115.jpg)
![BRD-33115](/img/BRD-33115.jpg)

# Complément sur la programmation :

Si vous souhaitez affiner l’algorithme de température, référez-vous à l’image ci-dessous:

![C-33115](/img/C-33115.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [NCP18WF104F03RC](https://github.com/pierron-asco-celda/33169-Telemetre_ir_GROVE/blob/main/src/Datasheet_GP2Y0A21YK.pdf)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure Température module Grove **
       PIN A0 Module shield GROVE
       Baud rate 9600 -> Moniteur série*
*/

#include <math.h>

const int B = 4275; // cf. datasheet
const int R0 = 100000; // cf. datasheet SCH GROVE
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

  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15; // cf. datasheet conversion en degré Celsius 

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.println();
  delay(500);
}
```
## À propos :
<div style="text-align: justify">*Le débit en bauds est un taux de transfert de données en unités de bits par seconde (bps). Si le débit en bauds est de 9600, cela signifie que la possibilité d’envoyer des données est de 9600 bits en une seconde. 1 caractère est identique à 1 octet.</div>
<br>

PIERRON ASCO-CELDA (https://www.pierron.fr).
