// V3 included the addition of the pump logic which started working! But then had timing issues meaning the pump stayed on.

/* Change these values based on your calibration values */
#define soilWet 400   // Define max value we consider soil 'wet'
#define soilDry 600   // Define min value we consider soil 'dry'

// Sensor pins
#define sensorPower D7
#define sensorPin A0
#define pump D6

void setup() {
        pinMode(sensorPower, OUTPUT);
        pinMode(sensorPin, OUTPUT);
        pinMode(pump, OUTPUT);
        Serial.begin(115200);
        Serial.println("Begin program");
}

void loop() {
        //get the reading from the function below and print it
        int moisture = readSensor();
        Serial.print("Analog Output: ");
        Serial.println(moisture);

        // Determine status of our soil
        if (moisture < soilWet) {
                Serial.println("Status: Soil is too wet");
        } else if (moisture >= soilWet && moisture < soilDry) {
                Serial.println("Status: Soil moisture is perfect");
        } else {
                Serial.println("Status: Soil is too dry - time to water!");
          digitalWrite(pump, LOW);
          delay(2000);
          digitalWrite(pump, HIGH);
        }

        delay(5000);    // Take a reading every second for testing
                        // Normally you should take reading perhaps once or twice a day
        Serial.println();
}

//  This function returns the analog soil moisture measurement
int readSensor() {
        digitalWrite(sensorPower, HIGH);        // Turn the sensor ON
        delay(5000);                             // Allow power to settle
        int val = analogRead(sensorPin);        // Read the analog value form sensor
        digitalWrite(sensorPower, LOW);         // Turn the sensor OFF
        return val;                             // Return analog value
}