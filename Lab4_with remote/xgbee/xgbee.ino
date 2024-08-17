#include <time.h>
#include <SoftwareSerial.h>

#define LEFT_LEVER_SWITCH 6
#define RIGHT_LEVER_SWITCH 7
#define JOYSTICK_MID_SWITCH A2
#define JOYSTICK_Y_SWITCH A3
#define JOYSTICK_X_SWITCH A4

SoftwareSerial Xbee(2, 3); // RX,TX
void setup()
{
  Serial.begin(9600);
  Xbee.begin(9600);
  pinMode(JOYSTICK_MID_SWITCH, INPUT); // switch
  pinMode(JOYSTICK_Y_SWITCH, INPUT);   // y-axis  up:0  down:1023
  pinMode(JOYSTICK_X_SWITCH, INPUT);   // x-axis  left:0 right:1023
  pinMode(LEFT_LEVER_SWITCH, INPUT_PULLUP);
  pinMode(RIGHT_LEVER_SWITCH, INPUT_PULLUP);
}

void loop()
{

  int joystick_mid = analogRead(JOYSTICK_MID_SWITCH);
  int joystick_x = analogRead(JOYSTICK_X_SWITCH);
  int joystick_y = analogRead(JOYSTICK_Y_SWITCH);
  int left_lever = digitalRead(LEFT_LEVER_SWITCH);
  int right_lever = digitalRead(RIGHT_LEVER_SWITCH);

  // Serial.print(joystick_mid);
  // Serial.print(" ");
  // Serial.print(joystick_x);
  // Serial.print(" ");
  // Serial.println(joystick_y);

  if(joystick_mid>=300 && joystick_mid<=500 && joystick_x>=500 and joystick_y>=500)
  {
    Xbee.write('S');
    Xbee.flush();
    Serial.println("S");

  }
  if (joystick_x == 0)
  {
    Xbee.write('L');
    Xbee.flush();
    Serial.println("L");
  }
  else if (joystick_x == 1023)
  {
    Xbee.write('R');
    Xbee.flush();
    Serial.println("R");
  }
  else if (joystick_y <= 50)
  {
    Xbee.write('U');
    Xbee.flush();
    Serial.println("U");
  }
  else if (joystick_y == 1023)
  {
    Xbee.write('D');
    Xbee.flush();
    Serial.println("D");
  }
  else if (joystick_mid == 0)
  {
    Xbee.write('C');
    Xbee.flush();
    Serial.println("C");
  }
  else if (left_lever == 0)
  {
    Xbee.write('M');
    Xbee.flush();
    Serial.println("M");
    delay(500);
  }
  else if (right_lever == 0)
  {
    Xbee.write('F');
    Xbee.flush();
    Serial.println("F");
    delay(500);
  }
  delay(40);
  Xbee.flush();
}
