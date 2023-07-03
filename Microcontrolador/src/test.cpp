#include <test.h>

double Vpot = 0,Vmot = 0;
double Vsaida = 5; //Tensao de saida, muda do arduino para o esp
int i = 0;

void setup()
{
    pinMode(PIN_MOTOR, OUTPUT);
    
    Serial.begin(115200);

}

void loop()
{
    Serial.println("Vmotor;Vpotenciometro");
    for(i=0;i<100;i++){
        for(i=0;i<10;i++){
            analogWrite(PIN_MOTOR, i); //Resolução de 0-255
            Vmot = Vsaida*i/255;

            delay(200);

            Vpot = analogRead(PIN_POTENCIOMETRO)*Vsaida/4095; //Lemos pino com resolução de 12 bits (0-4095)

            Serial.print(Vmot);
            Serial.print(";");
            Serial.println(Vpot);
        }
    }
}
