//V5 took inspiration from the OfferZen interval logic and combined V1 and V4. The pump control is finally working....and timing is working.

/* Change these values based on your calibration values */
#define soilWet 500   // Define max value we consider soil 'wet'
#define soilDry 650   // Define min value we consider soil 'dry'

// Sensor pins
#define sensorPower D7
#define sensorPin A0
#define pump D6

// Define timing variables
unsigned long checkInterval=10000;
unsigned long nextCheckAt = 0; //Starts at 0.

void setup() {
    pinMode(sensorPower, OUTPUT);
    pinMode(sensorPin, OUTPUT);
    pinMode(pump, OUTPUT);
    Serial.begin(115200);
    Serial.println("Begin program");
}

void loop() {
    // https://www.arduino.cc/reference/en/language/functions/time/millis/
    unsigned long currentMillis = millis();

    // Check if it's time to take a reading
   if(currentMillis > nextCheckAt) {
        // Get the reading from the function below and print it
        int moisture = readSensor();
        Serial.print("Analog Output: ");
        Serial.println(moisture);

        // Determine the status of our soil
        if (moisture < soilWet) {
            Serial.println("Status: Soil is too wet");
            digitalWrite(pump, LOW);
        } else if (moisture >= soilWet && moisture < soilDry) {
            Serial.println("Status: Soil moisture is perfect");
            digitalWrite(pump, LOW);
        } else {
            Serial.println("Status: Soil is too dry - time to water!");
            digitalWrite(pump, HIGH);
            delay(3000);
            digitalWrite(pump, LOW);
        }
    //Set the next check time. This works in relation to the currentMillis counter.
    nextCheckAt = currentMillis+checkInterval;
    }
}

// This function returns the analog soil moisture measurement
int readSensor() {
    digitalWrite(sensorPower, HIGH);        // Turn the sensor ON
    delay(100);                             // Allow power to settle
    int val = analogRead(sensorPin);        // Read the analog value from the sensor
    digitalWrite(sensorPower, LOW);         // Turn the sensor OFF
    return val;                             // Return analog value
}
