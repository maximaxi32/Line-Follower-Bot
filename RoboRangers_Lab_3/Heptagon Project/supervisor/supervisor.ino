#include "alphabot_drivers.h"
#include "line_follower.h"

#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem _mem;
void setup()
{

  //roborangers

  init_devices();
  Serial.begin(115200);


  forward();   // For starting the motors
}

void loop()
{


 for (int i = 0; i < NUM_SENSORS; i++)
 {
   Serial.print(sensorValues[i]);
   Serial.print(' ');
 }
 Serial.println();

  AnalogRead(sensorValues);
  Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], &_res,&_mem);
  SetSpeed(_res.v_l, _res.v_r);

}
