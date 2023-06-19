
 void setupUVSensor() {
  pinMode(LED_BUILTIN, OUTPUT);
 
  Serial.begin(115200);
  pinMode(34, INPUT);
  Serial.println(__FILE__);

  //Serial.print("ANALOG_UVSENSOR_LIB_VERSION: ");
  //Serial.println(ANALOG_UVSENSOR_LIB_VERSION);

 // AUV.begin(analogValue, 3.3, 4096);
  //AUV.begin(analogValue, 5.0, 1023);
 }

void UVSensorRead() {
  int avg = 0;
  for (int i = 0; i < 5; ++i) {
    int value = analogRead(34);
    avg += value;
  }
  avg /= 5;
  uvMeasurement = map(avg, UV_MIN, UV_MAX, 0.0, 7.0);

  Serial.print(uvMeasurement);
  Serial.print(',');
  Serial.println(avg);
}
