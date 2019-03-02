int rled = 11; // Pin PWN 11 para led rojo
int bled = 10; // Pin PWM 10 para led azul
int gled = 9;  // Pin PWM 9  para led verde

void setup() {
  Serial.begin(9600);
  //Se inicializan pines PWM como salida
  pinMode(rled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
  analogWrite(rled, 0);
  analogWrite(bled, 0);
  analogWrite(gled, 0);

  //Test de color
  analogWrite(rled, 255); // Se enciende color rojo
  delay(1000);            // Se esperan 1 s
  analogWrite(rled, 50); // Se enciende color rojo
  delay(1000);            // Se esperan 1 s
  analogWrite(rled, 0);  // Se apaga color rojo
  analogWrite(bled, 255); // Se enciende color azul
  delay(1000);            // Se esperan 1 s
  analogWrite(bled, 50); // Se enciende color azul
  delay(1000);            // Se esperan 1 s
  analogWrite(bled, 0);  // Se apaga color azul
  analogWrite(gled, 255); // Se enciende color verde
  delay(1000);            // Se esperan 1 s
  analogWrite(gled, 50); // Se enciende color verde
  delay(1000);            // Se esperan 1 s
  analogWrite(gled, 0);  // Se apaga colo verde
  
}

void loop() {
  //Colores Aleatorios
  int r = random(0, 255);
  int g = random(0, 255);
  int b = random(0, 255);
  analogWrite(rled, r);
  analogWrite(gled, g);
  analogWrite(bled, b);
  Serial.println(String(r) + "," + String(g) + "," + String(b));
  delay(500);
}
