/* * CONTROL AUTOMÁTICO DE TEMPERATURA Y HUMEDAD PARA INCUBADORA
 * Mantiene la temperatura estable encendiendo o apagando el foco (relé) 
 * según las lecturas del sensor DHT22 y muestra los datos en la pantalla LCD.
 */

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define PIN_CALENTADOR 3 

const float TEMP_IDEAL = 37.5;
const float HISTERESIS = 0.5; 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(PIN_CALENTADOR, OUTPUT);
  digitalWrite(PIN_CALENTADOR, LOW); 
  
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Incubadora V1.0");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Sensor   ");
    digitalWrite(PIN_CALENTADOR, LOW); 
    return;
  }

  if (t < (TEMP_IDEAL - HISTERESIS)) {
    digitalWrite(PIN_CALENTADOR, HIGH); 
  } 
  else if (t > (TEMP_IDEAL + HISTERESIS)) {
    digitalWrite(PIN_CALENTADOR, LOW);  
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: "); lcd.print(t, 1); lcd.print(" C   ");
  
  lcd.setCursor(0, 1);
  lcd.print("Humedad: "); lcd.print(h, 0); lcd.print("%  ");
  
  delay(1500); 
}