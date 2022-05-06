
const int thermocouple_input = A1;
int calibrate; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 

   // first need to calibrate...to get it so we are able to get the most precise measurements as possible
  float value_final;
  // do 10 samples 
  for (int num=0; num<=500; num++){
    // for each of the ten samples take a temperature reading 
    float sensorValue = analogRead(thermocouple_input);
    float value = ((sensorValue) * (1.1/ 1024.0))*1000;
    value_final = value_final + value;
    //Serial.println(num);
    delay(10); //100ms
 
  }
  calibrate = (value_final/500);
  //Serial.print("Hello New Value:");
  Serial.println(calibrate);
  //Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  float volts = 0;
    for (int num = 0; num<=500; num++){
      float sensorValue = analogRead(thermocouple_input);
      // Convert the analog reading (which goes from 0 - 1023) to a voltage.
      float voltage = ((sensorValue) * (1.1/ 1024.0))*1000;
      volts = voltage + volts;
      delay(10); //10ms
    }
  float avg_volt = volts/500;
  Serial.print(avg_volt-calibrate, 8);
  Serial.println();
  delay(55000);
}
