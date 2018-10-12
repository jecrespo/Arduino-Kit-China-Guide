
// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(250000);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin)*500);
  Serial.print(" ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print(" ");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n");
}
