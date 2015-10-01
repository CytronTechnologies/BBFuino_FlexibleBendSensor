#include <LiquidCrystal.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
const int analogPin = A0;
unsigned char voltage;
void setup()
{
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  pinMode(analogPin, INPUT);
}

void loop()
{
  voltage = obtain_volt();
  lcd.setCursor(0,1);
  lcd.print(voltage/10,DEC);         // Print the value in decimal 
  lcd.print('.');
  lcd.print(voltage%10,DEC);
  delay(100);
}

int obtain_volt()
{
  float adc = 0;
  float total = 0;
  int average = 0;
  for (int i = 0; i<100; i++);
  {
    adc = analogRead(analogPin);    // Read the value from analog pin for 1000 time
    total += adc * (5.0/1024)*1000; 
  }
  average = int(total/100);         // Get the average value
  return average;
}
