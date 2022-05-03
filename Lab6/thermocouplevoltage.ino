
/* 
 *  
 *  Red Cord on Vin
 *  Blank Cord on A1
 */
const int thermocouple_input = A1; 
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  //analogReference(INTERNAL);
  Serial.begin(115200);  
  pinMode(thermocouple_input,INPUT);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float volts = 0;
  for (int num = 0; num<=500; num++){
    float sensorValue = analogRead(thermocouple_input);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage.
    float voltage = ((sensorValue) * (1.1/ 1024.0))*1000;
    volts = voltage + volts;
    delay(10); //10ms
  }
  float avg_volt = volts/500;

  // 
  
  // print out the value you read:
  Serial.print(avg_volt-987, 8);
  //Serial.print(avg_volt-988.10354004, 8);
  Serial.println();
}
