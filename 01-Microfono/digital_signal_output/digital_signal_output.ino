
int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int val; //define digital variable val
int val_analogico;
void  setup() {
  Serial.begin(250000);
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
}
void  loop() {
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  val_analogico = analogRead(A0);
  if (val == HIGH) { //when the switch sensor have signal, LED blink
    digitalWrite(Led, HIGH);
    Serial.print("600");
    Serial.print(" ");
    Serial.println(val_analogico);
  }
  else {
    digitalWrite(Led, LOW);
    Serial.print("400");
    Serial.print(" ");
    Serial.println(val_analogico);
  }
}
