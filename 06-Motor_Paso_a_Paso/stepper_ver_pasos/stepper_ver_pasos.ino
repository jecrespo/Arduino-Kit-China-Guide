#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

int Paso [ 8 ][ 4 ] =
{ {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int Steps = 0;                       // Define el paso actual de la secuencia
float angulo = 0.0;
float angulo_paso = 360.0/(64*64);

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  stepper() ;     // Avanza un paso
  Serial.println("Paso: " + String(Steps));
  Serial.print("Grados desplazado: ");
  Serial.println(angulo);
  Serial.println("Bobinas activas:\n1  -> " + String(Paso[Steps % 8][0]) + "\n2  -> " + String(Paso[Steps % 8][1]) + "\n3  -> " + String(Paso[Steps % 8][2]) + "\n4  -> " + String(Paso[Steps % 8][3]));
  Serial.println();
  delay (100) ; //Un paso cada 250 ms para ver los leds
}

void stepper()            //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps % 8][ 0] );
  digitalWrite( IN2, Paso[Steps % 8][ 1] );
  digitalWrite( IN3, Paso[Steps % 8][ 2] );
  digitalWrite( IN4, Paso[Steps % 8][ 3] );
  Steps++;
  angulo += angulo_paso;
}
