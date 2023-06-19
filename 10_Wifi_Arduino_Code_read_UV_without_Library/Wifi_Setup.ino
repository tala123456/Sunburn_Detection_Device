void setupWiFi() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Startup pause...");
  delay(2000);

  Serial.println("My MAC address:");
  Serial.println(WiFi.macAddress());

  WiFi.begin(NETWOWORK_NAME, NETWORK_PASSWORD);
  while (WiFi.status()!= WL_CONNECTED) {
    Serial.println("Connecting...");
    //Serial.print(WiFi.status());
    delay(1000);
  }

  Serial.println("Success! Connected to network");

  Serial.print("My IP:");
  Serial.print(WiFi.localIP());

}