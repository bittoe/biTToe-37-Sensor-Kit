/*
 * inventr.io 37 in 1 Sensor Kit (https://inventr.io/product/37-in-1-sensor-kit/)
 * Sensor Course (https://inventr.io/course/sensor-training/)
 *
 * Code contributions:
 *    David Schmidt (davids@inventr.io)
 *    biTToe        (bittoe@yahoo.com)
 * Lesson - [KY-024] Linear Hall
 *
 *
 * The KY-024 linear hall effect sensor is a type of magnetic sensor
 * that measures the strength and direction of a magnetic field. It works
 * based on the Hall effect, which states that when a magnetic field is applied
 * perpendicular to a current-carrying conductor, a voltage is generated
 * proportional to the magnetic field strength.
 *
 * The KY-024 sensor is used in various applications, including linear positioning,
 * linear speed sensing, and linear current sensing. It's a compact, low-cost,
 * and easy-to-use device that can interface with microcontrollers like Arduino and Raspberry Pi.
 * Many laptops & tablets use a hall effect switch to determine the position of the lid (open or closed)
 *
 * The KY-024 sensor outputs an analog voltage signal proportional to the strength of the
 * magnetic field it's exposed to, making it easy to read and process the data.
 * Additionally, it has a linear response to the magnetic field, meaning that the
 * output voltage changes linearly with the magnetic field strength, making it ideal for
 * applications that require accurate and reliable measurements.
 *
 * | – You MUST set the pinMode of BOTH    |\
 * | – the analog and digital pins,        | > Aparently this is NOT true
 * | – Otherwise ky024_Dval is ALWAYS == 0 |/

 * Comments by biTToe:
 * It is more reliable than a mechanical switch.
 * The cool thing about this switch is that it has two sensors:
 * The analog sensor returns both field strength and polarity
 * The digital sensor returns only polarity.
 *
 * With no magnet nearby:
 * the analog value is ~512 | range 0 – 1023 ideally
 * The digital value is 0 (LOW) by defaut
 * For the FRONT side of the sensor:
 * As the NORTH pole of a magnet approaches the FRONT side of the sensor
 * the ANALOG output value INCREASES (>512) and the DIGITAL output is 0 (LOW).
 * As the SOUTH pole of a magnet approaches the FRONT side of the sensor
 * the ANALOG output value DECREASES (<512) and the DIGITAL output is 1 (HIGH).
 * For the BACK side of the sensor it is just the opposite.
 * Get a magnet and play around.
 *
 * This project uses: 
 * One Digital pin to INPUT (Polarity)
 * One Analog pin to OUTPUT (Magnetic field strength & polarity)
 * The onboard LED
 * On the Hero (Arduino Uno compatible) we *could* use: D0-D13, A0-A5.
 * Skip: A0-A5 (can use for any ANALOG pin),
 *       D0/D1 (used by USB),
 *       D2/D3 (save for interrupts),
 *       D13 (used by LED_BUILTIN and SPI Clock),
 *       D5, D6, D9, D10 and D11 (save for PWM)
 *       D11 (SPI MOSI)
 *       D12 (SPI MISO)
 * Recommended for fewest conflicts:
 *    Digital pin: D4, D7 or D8
 *    Analog pin:  A0-A5
 */

const uint8_t KY_024_DIGITAL_OUT = 8; // digital sensor
const uint8_t KY_024_ANALOG_OUT = A0; // analog sensor
int ky024_Dval;
int ky024_Aval;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // define LED_BUILTIN as output interface
}
void loop() {
  ky024_Dval = digitalRead(KY_024_DIGITAL_OUT); // Reads digital value & sets pin as input
  ky024_Aval = analogRead(KY_024_ANALOG_OUT);   // Reads analog value & sets pin as input
  if (ky024_Dval == HIGH)                       // (S) on FRONT or (N) on BACK of sensor
  {
    digitalWrite(LED_BUILTIN, HIGH);
  } else                                        // (N) on the FRONT or (S) on the BACK of sensor
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
   /*
   *To see what the sensor is writing to the Hero board
   * Uncomment the five Serial.print lines below
   * This information is also useful during calibration
  */
  // Serial.print("Digital Value: ");
  // Serial.println(ky024_Dval);
  // Serial.print("Analog value: ");
  // Serial.println(ky024_Aval);
  // Serial.print("\n\n");
  delay(1000);
}