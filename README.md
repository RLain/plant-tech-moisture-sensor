# plant-tech-moisture-sensor

## Commands

1. Create a sketch: $ `arduino-cli sketch new nameOfSketch`
2. Compile the sketch: $ `arduino-cli compile --fqbn esp8266:esp8266:nodemcuv2 nameOfSketch`
3. Locate the port of the Arduino (make sure plugged in): $ `arduino-cli board list`
4. Update compiled code onto the Arduino: $ `arduino-cli upload -p /dev/cu.usbserial-0001 --fqbn esp8266:esp8266:nodemcuv2 nameOfSketch`

To monitor the Arduino whilst plugged in $ `arduino-cli monitor -p /dev/cu.usbserial-0001 -c baudrate=115200`. Change the baudrate depending on the baurd used by the sketch. e.g on MoistureSensor.ino `Serial.begin(115200);` is defined.

## Links

- [OfferZen Repo](https://github.com/OfferZen-Community/plant_tech_ams/tree/main)
- [Arduino CLI installation](https://arduino.github.io/arduino-cli/0.33/installation/)
- [Arduino YAML prep setup](https://github.com/OfferZen-Community/plant_tech_ams/blob/main/prep-arduino-cli.md)
- [Arduino CLI Youtube guidance](https://www.youtube.com/watch?v=8LPSjucQoso&ab_channel=datasith)
