#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD en una posición  central.
  lcd.setCursor(0, 0);
  lcd.print("   www.aprendiendoarduino.com             ");
  lcd.setCursor(0, 1);
  lcd.print("   Tutorial LCD, Test de desplazamiento   ");
}

void loop() {
  //desplazamos una posición a la izquierda
  lcd.scrollDisplayLeft(); 
  delay(500);
}
