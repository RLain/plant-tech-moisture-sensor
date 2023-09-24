# 🌱 plant-tech-moisture-sensor

## Kit

- HKD ESP8266 NODEMCU WIFI BOARD
- 15cm Female to Female jumper leads
- Mini DC 3-6V Water pump
- TIP31C Transistor
- Moisture Sensor and relay ([FC-50](https://www.mantech.co.za/datasheets/products/FC-50_BG.pdf))

### Places to buy in Cape Town

- https://www.communica.co.za/
- https://www.fort777.co.za/ (Yebo Electronics)

## Commands

1. Create a sketch: $ `arduino-cli sketch new nameOfSketch`
2. Compile the sketch: $ `arduino-cli compile --fqbn esp8266:esp8266:nodemcuv2 nameOfSketch`
3. Add the script in the new `.ino` file.
4. Locate the port of the Arduino (make sure plugged in): $ `arduino-cli board list`
5. Update compiled code onto the Arduino: $ `arduino-cli upload -p /dev/cu.usbserial-0001 --fqbn esp8266:esp8266:nodemcuv2 nameOfSketch`

To monitor the Arduino whilst plugged in $ `arduino-cli monitor -p /dev/cu.usbserial-0001 -c baudrate=115200`. Change the baudrate depending on the baurd used by the sketch. e.g on MoistureSensor.ino `Serial.begin(115200);` is defined.

## Links

- [OfferZen Repo](https://github.com/OfferZen-Community/plant_tech_ams/tree/main)
- [Arduino CLI installation](https://arduino.github.io/arduino-cli/0.33/installation/)
- [Arduino YAML prep setup](https://github.com/OfferZen-Community/plant_tech_ams/blob/main/prep-arduino-cli.md)
- [Arduino CLI Youtube guidance](https://www.youtube.com/watch?v=8LPSjucQoso&ab_channel=datasith)
- [.INO File Extension](https://fileinfo.com/extension/ino)
- [coding-arduino-programming-language](https://emeritus.org/blog/coding-arduino-programming-language)

## Supplementary reading

1. [Soil-Moisture-Measurement-With-Arduino](https://www.instructables.com/Soil-Moisture-Measurement-With-Arduino)

There is a mapping for the level of moisture. Sensors are mainly mapped within 0 to 1023 values. So for different level of moisture, the mapping of the moisture sensor is given below-

- If the sensor value is 1000 or more than that then the sensor is not in the soil or sensor is disconnected.
- If the sensor value is more than 600 but less than 1000 then the soil is dry.
- If the sensor value is 370 to 600 then the soil is humid.
- If the sensor value is less than 370 then the sensor in the water.

2. [How Soil Moisture Sensor Works and Interface it with Arduino](https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/)
