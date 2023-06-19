void setupBuzzer() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void buzzerSound() {
  // Make a beep sound
  tone(buzzerPin, 1000); // Generate a 1kHz tone on the buzzer pin
  delay(500); // Wait for 500 milliseconds
  noTone(buzzerPin); // Stop the tone
  delay(500); // Wait for another 500 milliseconds
}

void buzzer3times() {
  for (int i = 0; i < 3; i++) {
    // Make a beep sound
    tone(buzzerPin, 1000); // Generate a 1kHz tone on the buzzer pin
    delay(500); // Wait for 500 milliseconds
    noTone(buzzerPin); // Stop the tone
    delay(500); // Wait for another 500 milliseconds
  }
}