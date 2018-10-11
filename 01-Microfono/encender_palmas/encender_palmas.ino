
int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int val; //define digital variable val
int ant_val;
int val_analogico;
int palmas = 0;
boolean estado_led = LOW;
unsigned long tiempo_palmas;

void  setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
  ant_val = digitalRead(buttonpin);
}

void  loop() {
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  val_analogico = analogRead(A0);

  if (val != ant_val) {
    if (val == HIGH) { //Flanco Ascendente
      unsigned long tiempo_rebote = millis();
      while (true) {  //Para evitar rebotes espero que no vengan nuevos pulsos, es un filtro
        if (digitalRead(buttonpin) == HIGH) {
          tiempo_rebote = millis();
          Serial.println("rebote");
        }
        if ((millis() - tiempo_rebote) > 100) {
          break;
        }
      }
      Serial.println(val_analogico);
      palmas++;
      
      if (palmas == 1) {
        tiempo_palmas = millis(); //primera detección palmas
        Serial.println("primera palmada");
      }

      if (palmas == 2) {
        estado_led = !estado_led;
        Serial.print("Tiempo entre palmas: ");
        Serial.print(millis() - tiempo_palmas);
        Serial.println(" ms. Cambio estado led");
        digitalWrite(Led, estado_led);
        palmas = 0;
      }
    }
  }
  if ((palmas == 1) && ((millis() - tiempo_palmas) > 2000 )) {  //Si han pasado 2 segundo sin que venga una segunda palma reinicio
    Serial.println("palmada demasiado larga");
    palmas = 0;
  }
  ant_val = val;
}
