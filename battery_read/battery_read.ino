// Battery is connected to ADC pin A13 (or 35)
const int ADC_Pin = A13;

// variables for storing the battery value
int ADC_Value = 0;
float voltage = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading battery value
  ADC_Value = analogRead(ADC_Pin);
  Serial.print("ADC Value = ");
  Serial.println(ADC_Value);
  // When you read the ADC you’ll get a 12-bit number from 0 to 4095.
  // To convert this value to a real voltage you’ll need to divide it
  // by the maximum value of 4095, then double it (note that Adafruit
  // halves the voltage), then multiply that by the reference voltage
  // of the ESP32 which is 3.3V and then finally, multiply that again
  // by the ADC Reference Voltage of 1.1V.
  voltage = ADC_Value / 4095.0 * 2.0 * 3.3 * 1.1;
  Serial.print("Voltage   = ");
  Serial.print(voltage);
  Serial.println("V");
  delay(500);
}
