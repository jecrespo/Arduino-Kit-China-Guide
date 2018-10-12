//salida digital y calibración

/*
 * El código de digital_signal_output funciona cuando la voz llega a un cierto valor,
 * activará una señal digital y se enciende el indicador L al mismo tiempo.
 * Este valor desencadenante puede cambiarse según el método de ajuste de sensibilidad con el potenciometro.
 * Este código también nos ayuda a calibrar la sensibilidad de la salida digital,
 * cuando las pulsaciones de un sonido están entre 2 y 15 y la distancia entre pulsos consecutivos no es mayor de 100 ms.
 */

int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int val; //define digital variable val
int val_anterior;
int val_analogico;
int pulsos = 0;
unsigned long tiempo_pulsos;

void  setup() {
  Serial.begin(250000);
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
  val_anterior = digitalRead(buttonpin);
}
void  loop() {
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  val_analogico = analogRead(A0);
  if (val == HIGH) { //when the switch sensor have signal, LED blink
    digitalWrite(Led, HIGH);
    Serial.print("600");
    Serial.print(" ");
    Serial.print(val_analogico);
  }
  else {
    digitalWrite(Led, LOW);
    Serial.print("400");
    Serial.print(" ");
    Serial.print(val_analogico);
  }
  //cuenta los pulsos
  if (val_anterior != val) {
    if (val == HIGH) {  //pulso alto
      pulsos ++;
      tiempo_pulsos = millis();
    }
    val_anterior = val;
  }

  if (((millis() - tiempo_pulsos) > 100) && (pulsos > 0)) {
    Serial.println(" pulsos: " + (String)pulsos);
    if ((pulsos > 1) && (pulsos < 16)) { //en cada palmada entre 2 y 15 pulsos de sensibilidad
      Serial.println("CALIBRADO!!");
      delay(1000);
    }
    pulsos = 0;
  }
  Serial.print(" ");
  Serial.println(pulsos);
}
