/*
          .————————————.
The KY-024 linear hall effect sensor is a type of magnetic sensor that measures the strength and direction 
of a magnetic field. It works based on the Hall effect, which states that when a magnetic field is applied 
perpendicular to a current-carrying conductor, a voltage is generated proportional to the magnetic field strength.

The KY-024 sensor is used in various applications, including linear positioning, linear speed sensing, and linear current sensing. 
It's a compact, low-cost, and easy-to-use device that can interface with microcontrollers like Arduino and Raspberry Pi.

The KY-024 sensor outputs an analog voltage signal proportional to the strength of the magnetic field it's exposed to, 
making it easy to read and process the data. Additionally, it has a linear response to the magnetic field, 
meaning that the output voltage changes linearly with the magnetic field strength, making it ideal for applications 
that require accurate and reliable measurements.

| – You MUST set the pinMode of BOTH |
| – the analog and digital pins,     |
| – Otherwise dig_val is ALWAYS == 0 |
           :————————————:
Comments by biTToe:
Many laptops use the hall effect switch to determine the position of the lid (open or closed) It is more reliable than a mechanical switch.
The cool thing about this switch is that it has two sensors.
The analog sensor returns both field strength and polarity
The digital sensor returns only polarity.
With no magnet nearby:
the analog value is ~512 | range 0 – 1023 ideally
The digital value is 0 (LOW)
For the FRONT side of the sensor:
As the north pole of a magnet approaches the FRONT side of the sensor, the analog output value INCREASES (>512) and the digital output is LOW.
As the south pole of a magnet approaches the FRONT side of the sensor, the analog output value DECREASES (<512) and the digital output is HIGH.
For the BACK side of the sensor it is just the opposite.
Get a magnet and play around.
Here is my code with better variable names and better comments IMHO
*/

const uint8_t onboardLED = 13;        // onboard onboardLED
const uint8_t KY_024_DIGITAL_OUT = 3; // digital sensor
const uint8_t KY_024_ANALOG_OUT = A0; // analog sensor
int dig_val;
int ana_val;

void setup() {
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT);        // define onboardLED as output interface
  pinMode(KY_024_DIGITAL_OUT, INPUT); // define digital pin as input
  pinMode(KY_024_ANALOG_OUT, INPUT);  // define analog pin as input
}
void loop() {
  dig_val = digitalRead(KY_024_DIGITAL_OUT);  // Get digital value
  ana_val = analogRead(KY_024_ANALOG_OUT);    // Get analog value
  if (dig_val == HIGH)                // (S) on FRONT or (N) on BACK of sensor
  {
    digitalWrite(onboardLED, HIGH);
  } else  // (N) on the BACK or (S) on the FRONT of sensor
  {
    digitalWrite(onboardLED, LOW);
  }
  Serial.print("Digital Value: ");
  Serial.println(dig_val);
  Serial.print("Analog value: ");
  Serial.println(ana_val);
  Serial.print("\n\n");
  delay(1000);
}