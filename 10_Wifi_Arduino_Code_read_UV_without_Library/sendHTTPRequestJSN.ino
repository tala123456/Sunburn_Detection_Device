String sendHTTPRequestJSN(String request) {
  HTTPClient client;

  String protocol = "https";
  String host = "studenthome.hku.nl/~tanja.landolt";
  String url = protocol + "://" + host + request;

  client.begin(url);

  Serial.println("Send request...");
  Serial.println(url);
  String response;

  int httpResultCode = client.GET();
  if (httpResultCode == HTTP_CODE_OK) {
    response = client.getString();
    Serial.println(response);
  } else {
    Serial.print("Error in request: code= ");
    Serial.println(httpResultCode);
    delay(3000);
  }
  client.end();
  return response;
}