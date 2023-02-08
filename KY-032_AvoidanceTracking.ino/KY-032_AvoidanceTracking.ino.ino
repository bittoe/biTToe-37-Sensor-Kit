/*
 * inventr.io 37 in 1 Sensor Kit (https://inventr.io/product/37-in-1-sensor-kit/)
 * Sensor Course (https://inventr.io/course/sensor-training/)
 *
 * Code contributions by David Schmidt and Frank Visco.
 *
 * Lesson - [KY-032] Avoidance Tracking
 *
 * *
 * KY-032 is an infrared (IR) obstacle avoidance sensor
 * The module consists of an IR transmitter and receiver that can detect
 * the presence of an object in front of the sensor by measuring the reflection
 * of the IR light. 
 *
 * The sensor outputs a digital signal that can be read by a microcontroller
 * to determine the presence or absence of an obstacle.
 * *
 *
 * Library requirements:
 * None
 *
 * Code contributions:
 *    David Schmidt (davids@inventr.io)
 *    biTToe (bittoe@yahoo.com)
 */

/*
.-------------------------------------.
| Avoidance tracker Calibration        |
|                                     |
| LED pot all the way clockwise       |
| Sensor pot all the way counterclockwise
| Hand over sensor and adjust sensor  |
| pot until there is detection        |
:-------------------------------------:
*/

void setup() {
Serial.begin(9600);
pinMode(3, INPUT);// set pin as input

}

void loop() {
  //Written for Robojax on Dec 28, 2017
  int detect = digitalRead(3);// read obstacle status and store it into "detect"
  if(detect == LOW){
   
   Serial.println("Obastacle in the way");
  }else{
   
   Serial.println("clear");  
  }
  Serial.println(detect);
  delay(500);
}