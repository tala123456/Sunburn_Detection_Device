  void setupButtons(){
    pinMode(buttonPinadd, INPUT_PULLDOWN); //pulldown works as a resistor 
    pinMode(buttonPinfewer, INPUT_PULLDOWN);  // Set the button pin as input
    Serial.begin(115200);
  }

void checkButtons() {
  int buttonState = digitalRead(buttonPinadd);  // Read the button state

 if (buttonState == HIGH) {
   Serial.println(buttonState == HIGH);
    multiplyValues = true;
  }
  // Multiply UV_Max by 5 if buttonPinadd is pressed
  if (digitalRead(buttonPinadd) == HIGH) {
    UV_Max *= 5;
    Serial.print("UV_Max multiplied by 5: ");
    Serial.println(UV_Max);
  }


  buttonState = digitalRead(buttonPinfewer);  // Read the button state
  if (buttonState == HIGH) {
   Serial.println(buttonState == HIGH);
    multiplyValues = true;
  }

// Divide UV_Max by 5 if buttonPinadd is pressed
  if (digitalRead(buttonPinfewer) == HIGH) {
    UV_Max /= 5;
    Serial.print("UV_Max divide by 5: ");
    Serial.println(UV_Max);
  }


  delay(100);  // Add a small delay to avoid rapid button state changes
}
