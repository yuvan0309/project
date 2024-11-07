#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if needed
int tempPin = A0;         // Temperature sensor connected to analog pin A0
int moisturePin = A1;     // Moisture sensor connected to analog pin A1
int buzzerPin = 9;        // Define the pin connected to the buzzer

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Temp & Moisture");
  delay(2000);
  lcd.clear();
  Serial.begin(9600); // Start Serial Monitor at 9600 baud
  pinMode(buzzerPin, OUTPUT); // Set buzzerPin as output
}

void loop() {
  // Read temperature in Celsius for LM35
  int tempReading = analogRead(tempPin);
  float temperatureC = (tempReading * 5.0 * 100.0) / 1024.0; // Conversion for LM35 sensor

  // Display temperature in Serial Monitor for debugging
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Read moisture level and map to percentage
  int moistureReading = analogRead(moisturePin);
  int moisturePercent = map(moistureReading, 1023, 0, 0, 100); // Adjust based on sensor calibration

  // Display temperature in Celsius
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C  ");

  // Display moisture percentage
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print(" %  ");

  // Handle buzzer based on temperature
  if (temperatureC >= 25 && temperatureC <= 39) {
    beep(1, 500); // Single beep
  } else if (temperatureC >= 40 && temperatureC <= 50) {
    beep(2, 500); // Double beep
  } else if (temperatureC >= 55 && temperatureC <= 80) {
    beep(3, 500); // Triple beep
  } else if (temperatureC > 80) {
    digitalWrite(buzzerPin, HIGH); // Constant beep for high temperature
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off buzzer if temperature is below 25
  }

  delay(1000); // Update every 1 second
}

void beep(int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(duration);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
