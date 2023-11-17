
#include <Ultrasonic.h>
 
#define pino_trigger 4
#define pino_echo 5
#define saida 7
 
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(saida, OUTPUT);
}
 
void loop()
{
  long microsec = ultrasonic.timing();
  int distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  if(distanciaCM <= 50){
    digitalWrite(saida, HIGH);
    delay(100);
  }
  else if(distanciaCM < 150) {
    digitalWrite(saida,HIGH);
    delay((distanciaCM-50)*10);
    digitalWrite(saida, LOW);
  }
  delay(100);
}