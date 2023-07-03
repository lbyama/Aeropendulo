#include <control.h>

double Setpoint, Input, Output; //Setpoint e Input são ângulos em graus e o output é a força em Newtons
double Vpot,Vmot;

double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  pinMode(PIN_MOTOR, OUTPUT);
  pinMode(PIN_POTENCIOMETRO, INPUT);
  
  Setpoint = 20; //Angulo desejado em graus

  Serial.begin(115200);

  myPID.SetMode(AUTOMATIC); //Ligar o controlador PID 
}

void loop()
{
  Vpot = analogRead(PIN_POTENCIOMETRO); //Lemos pino com resolução de 12 bits (0-4095)
  Vpot = Vpot*3.3/4095; //convertemos o valor lido para tensão
  Input = Vpot;

  myPID.Compute(); //Calcular o output

  Vmot = Output;
  Vmot = Vmot*3.3/256;
  analogWrite(PIN_MOTOR, Output); //Resolução de 0-255
}
