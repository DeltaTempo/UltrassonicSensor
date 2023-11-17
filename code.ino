
#include <Ultrasonic.h>
 
#define pin_trigger 4 
#define pin_echo 5
#define pin_output 7
 
Ultrasonic ultrasonic(pin_trigger, pin_echo);
 
void setup()
{
  pinMode(pin_output, OUTPUT);
}
 
void loop()
{
  long microsec = ultrasonic.timing();
  int distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  if(distanciaCM <= 50){
    digitalWrite(pin_output, HIGH);
    delay(100);
  }
  else if(distanciaCM < 150) {
    digitalWrite(pin_output,HIGH);
    delay((distanciaCM-50)*10);
    digitalWrite(pin_output, LOW);
  }
  delay(100);
}
