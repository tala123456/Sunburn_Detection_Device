#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
//#include "AnalogUVSensor.h"

//AnalogUVSensor AUV;
//int analogValue = analogRead(34);

//for UV Sensor
const int UV_MAX = 500;
const int UV_MIN = 10;
float uvMeasurement = 0.0;

float UV_Max;
float UV_measured_Total;
float time_elapsed;

//for buttons
const int buttonPinadd = 27; // + more values > can stay longer in the sun
const int buttonPinfewer = 33; // - less values > can stay less in the sun

// for adding suncream (aka more UV ratio)
bool multiplyValues = false;

//for buzzer
const int buzzerPin = 12;

// connection through hotspot phone
#define NETWOWORK_NAME "AndroidAP2138" 
#define NETWORK_PASSWORD "9876543210"


void setup() {
  setupWiFi();
  setupUVSensor();
  setupButtons();
  setupBuzzer();
  }

void loop() {

  //run UV Sensor 
  UVSensorRead();


  String request = "/UV_Insertfile.php?";
  String objectid = "id=3";  //defines skintype!! >> needs to be changed based on user
  String changedvalue = "&UVmes=" + String(uvMeasurement, 1);

  String response = sendHTTPRequest(request + objectid + changedvalue);


  String request2 = "/Sum_UV_Light_3.php?";
  String objectid2 = "device_id=3";  //defines skintype!! >> needs to be changed based on user

  String response2 = sendHTTPRequestJSN(request2 + objectid2);

  // Parse the JSON response
  DynamicJsonDocument jsonDoc(1024); // Adjust the size as per your requirements
  DeserializationError error = deserializeJson(jsonDoc, response2);

  // Check for parsing errors
  if (error) {
    Serial.print("JSON parsing error: ");
    Serial.println(error.c_str());
    return;
  }

  // Extract the UV_Max and UV_measured_Total values
  UV_Max = jsonDoc["UV_Max"];
  UV_measured_Total = jsonDoc["UV_measured_Total"];
  //time_elapsed = jsonDoc["time_elapsed"];

  Serial.println(time_elapsed);

  float hours = (time_elapsed / 3600);
//  Serial.print("hours");
 // Serial.println(hours/14);
  //Serial.println(UV_measured_Total/UV_Max);

 // if ((hours/14) < (UV_measured_Total/UV_Max)) {
 //    buzzer3times();
 // }
  

  //Serial.println (UV_Max);
  //Serial.println (UV_measured_Total);
     

for (int wait = 0; wait < 500; wait++) {
  delay(10);

  checkButtons();


  if (UV_measured_Total >= UV_Max) {
  //   UV_measured_Total is bigger than UV_Max, trigger the buzzer
   buzzerSound();
  }
}
}



