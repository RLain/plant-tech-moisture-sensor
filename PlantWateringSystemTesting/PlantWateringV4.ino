// V4 included the addition of the interval logic but the timing issues persisted meaning the pump stayed on.

/* Change these values based on your calibration values */
#define soilWet 500   // Define max value we consider soil 'wet'
#define soilDry 600   // Define min value we consider soil 'dry'

// Sensor pins
#define sensorPower D7
#define sensorPin A0
#define pump D6

// Define timing variables
unsigned long previousMillis = 0;
const unsigned long interval = 5000;  // Interval for taking readings (5 seconds)

void setup() {
    pinMode(sensorPower, OUTPUT);
    pinMode(sensorPin, OUTPUT);
    pinMode(pump, OUTPUT);
    Serial.begin(115200);
    Serial.println("Begin program");
}

void loop() {
    unsigned long currentMillis = millis();

    // Check if it's time to take a reading
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        // Get the reading from the function below and print it
        int moisture = readSensor();
        Serial.print("Analog Output: ");
        Serial.println(moisture);

        // Determine the status of our soil
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
    }

    // You can perform other non-blocking tasks here

}

// This function returns the analog soil moisture measurement
int readSensor() {
    digitalWrite(sensorPower, HIGH);        // Turn the sensor ON
    delay(100);                             // Allow power to settle
    int val = analogRead(sensorPin);        // Read the analog value from the sensor
    digitalWrite(sensorPower, LOW);         // Turn the sensor OFF
    return val;                             // Return analog value
}
