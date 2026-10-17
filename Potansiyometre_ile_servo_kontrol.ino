#include<Servo.h>
Servo sg90;
const byte potansiyometre = A5;
int pot_deger;
void setup()
{
Serial.begin(9600);
sg90.attach(13);
}
void loop()
{
pot_deger = analogRead(potansiyometre);
int servo_deger = map(pot_deger , 0, 1023, 0, 180);
sg90.write(servo_deger);
Serial.print("Servo = ");
Serial.print(servo_deger);
Serial.println(" Degrees");
delay(15);
}
