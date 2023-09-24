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
- [Arduino Language Reference](https://www.arduino.cc/reference/en/language)
- [.INO File Extension](https://fileinfo.com/extension/ino)
- [coding-arduino-programming-language](https://emeritus.org/blog/coding-arduino-programming-language)

## Learnings

1. `Turning the Sensor on allows the Arduino to get a reading`. This is controlled by `digitalWrite(SENSOR, HIGH);`. We can
   then get a reading by using a read command e.g. Analog reading = `analogValue = analogRead(ANA);` with ANA being the Arduino port defined.
   Once we have the reading, then we can turn the sensor off using `digitalWrite(SENSOR, LOW);` [Source](https://emeritus.org/blog/coding-arduino-programming-language)

2. `VCC vs GND`: VCC (Voltage Common Collector) is the power supply of a device . Ground is the the reference point against which the VCC is compared.

- `VCC`. (electronics, also VCC) Common Collector Voltage; the positive supply voltage for an integrated circuit containing bipolar junction transistors.
- What Does Ground (`GND`) Mean? Ground, in the context of electronics, is the reference point for all signals or a common path in an electrical circuit where all of the voltages can be measured from. This is also called the common drain since the voltage measurement along it is zero.

3. `Why the analogRead() was printing a value despite no A port being used` = "If the analog input pin is not connected to anything, the value returned by analogRead() will fluctuate based on a number of factors (e.g. the values of the other analog inputs, how close your hand is to the board, etc.)." [Source](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)

4. `NO/NC/C`: https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/. See the `fc-50_circuit_diagram.png` in this repo for positions of the connections. The `fc-50_CMU-circuit_diagram.png` is the relay module I purchased [JQF-3ff-S-Z](https://www.communica.co.za/products/cmu-moisture-sensor-with-relay?variant=40204733055049) however if you compare the images they are the same.

💡 When holding the relay module so the writing is legible, the left hand connections are top-to-bottom order: NO -> COMM -> NC.

## Supplementary reading

1. [Soil-Moisture-Measurement-With-Arduino](https://www.instructables.com/Soil-Moisture-Measurement-With-Arduino)

There is a mapping for the level of moisture. Sensors are mainly mapped within 0 to 1023 values. So for different level of moisture, the mapping of the moisture sensor is given below-

- If the sensor value is 1000 or more than that then the sensor is not in the soil or sensor is disconnected.
- If the sensor value is more than 600 but less than 1000 then the soil is dry.
- If the sensor value is 370 to 600 then the soil is humid.
- If the sensor value is less than 370 then the sensor in the water.

2. [How Soil Moisture Sensor Works and Interface it with Arduino](https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/)
