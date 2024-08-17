#include "alphabot_drivers.h"
#include "line_follower.h"
#include <time.h>
#include <SoftwareSerial.h>

SoftwareSerial Xbee(8, 9);

#define NUM_SENSORS 5
#define BLACK_NODE -2     // Signal to turn left on node
#define PARKING -3        // Signal to activate parking mode
#define TURN_CYCLES 40000 // Number of cycles to turn at a node
#define TURN_SPEED 50     // Speed of turning at a node
#define FREE_LEFT -1      // If left block is free for parking
#define FREE_RIGHT 1      // If right block is free for parking
#define OCCUPIED 0        // If both slots occupied for parking
#define BLOCK_TIME 3000   // Time to travel from block to block on the parking line

int sensorValues[NUM_SENSORS];
int base_drive_black = 50;
// PID constants
int kp = 15;
int kd = 150;
int arena_number = 0; // either 0 or 1
int mode = 0;         // Remote, Heptagon
int parking_mode = 0;
int parked = 0;
Line_follower__main_out _res;
Line_follower__main_mem _mem;
void setup()
{
  init_devices();
  Serial.begin(9600);
  Xbee.begin(9600);
}

// For beep mechanism
void beep()
{
  stop();
  beep_on();
  delay(100);
  beep_off();
  forward();
}

void beep_no_stop()
{
  beep_on();
  delay(100);
  beep_off();
}

// function for parking left
void park_left()
{
  backward();
  delay(900);
  back_right();
  delay(1800);
  backward();
  delay(550);
}

// function for parking right
void park_right()
{
  backward();
  delay(900);
  back_left();
  delay(1800);
  backward();
  delay(550);
}

void turn_right()
{
  stop();
  SetSpeed(TURN_SPEED, TURN_SPEED);
  for (unsigned long i = 0; i < TURN_CYCLES; i++)
  {
    forward_right();
  }
  SetSpeed(TURN_SPEED, TURN_SPEED);
  forward();
}

void turn_left()
{
  stop();
  SetSpeed(TURN_SPEED, TURN_SPEED);
  for (unsigned long i = 0; i < TURN_CYCLES; i++)
  {
    forward_left();
  }
  SetSpeed(TURN_SPEED, TURN_SPEED);
  forward();
}

int get_next_node_action(int node_count, int arena_number)
{
  beep();
  if (node_count == 1)
  {
    if (arena_number == 0 || arena_number == 2)
    {
      return 1;
    }
    else
      return -1;
  }
  else if (node_count == 2)
  {
    if (arena_number == 0 || arena_number == 1)
    {
      return 1;
    }
    else
      return -1;
  }
  else if (node_count == 3 || node_count == 4)
  {
    if (arena_number == 0 || arena_number == 1)
    {
      return -1;
    }
    else
      return 1;
  }
}

void loop()
{
  char c = '_';

  if (Xbee.available())
  {
    c = Xbee.read();
    Xbee.flush();

    if (c == 'F')
    {
      forward();
    }
    else if (c == 'M')
    {
      beep_no_stop();
      arena_number = (arena_number + 1) % 4;
    }
    else if (c == 'C')
    {
      mode = (mode + 1) % 2;
      stop();
    }
    else if (c == 'L')
    {
      SetSpeed(TURN_SPEED, TURN_SPEED);
      forward_left();
    }
    else if (c == 'R')
    {
      SetSpeed(TURN_SPEED, TURN_SPEED);
      forward_right();

    }
    else if (c == 'U')
    {
      SetSpeed(TURN_SPEED, TURN_SPEED);
      forward();

    }
    else if (c == 'D')
    {
      SetSpeed(TURN_SPEED, TURN_SPEED);
      backward();
    }
    else if(c=='S')
    {
      if(mode==0)
        stop();
    }
  }

  // condition dekh lena mode switch ke baad bhi return ho rha h
  if(mode==0)
    return ;

  Serial.print(c);
  Serial.print(' ');
  if (parked) // exit if parked already
    return;

  Serial.print(arena_number);
  Serial.print(' ');
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print(' ');
  }
  Serial.println();

  AnalogRead(sensorValues);

  // Parking mode not yet activated
  if (parking_mode == 0)
    Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], &_res, &_mem);
  // If Parking mode activated
  else
  {
    // beep();
    int sc = scanner();
    if (sc == FREE_RIGHT)
    {
      park_right();
      stop();
      parked = 1;
    }
    else if (sc == FREE_LEFT)
    {
      park_left();
      stop();
      parked = 1;
    }
    else
    {
      parking_mode = 1;
    }
    return;
  }

  if (_res.v_l == BLACK_NODE && _res.v_l == BLACK_NODE) // Signal from heptagon to turn right on node
  {
    int node_count = _res.dir;
    int turn_dir = get_next_node_action(node_count, arena_number);

    if (turn_dir == -1)
    {
      turn_left();
    }
    else if (turn_dir == 1)
    {
      turn_right();
    }
  }
  else if (_res.v_l == PARKING) // Activate Parking Mode
  {
    parking_mode = 1;
  }
  else // Line following
  {
    SetSpeed(_res.v_l, _res.v_r);
  }
}

/* function that follows black line and checks from block to block for presence of any obstacle and if not then
 invokes corresponding parking function else continues to follow the black line
 */

int scanner()
{
  unsigned long previousMillis = millis();
  unsigned long currentMillis = millis();
  const long interval = 100;
  AnalogRead(sensorValues);
  int sen4 = sensorValues[0];
  int sen3 = sensorValues[1];
  int sen1 = sensorValues[3];
  int sen0 = sensorValues[4];
  int prevp = 0;
  bool fl = true;
  bool fr = true;
  // keep checking for obstacle in a block between two grey lines
  while (currentMillis - previousMillis <= BLOCK_TIME)
  {
    currentMillis = millis();

    AnalogRead(sensorValues);
    fl = fl and (ir_read_customl() ? true : false); // detecting obstacle on left
    fr = fr and (ir_read_customr() ? true : false); // detecting obstacle on right

    sen4 = sensorValues[0];
    sen3 = sensorValues[1];
    sen1 = sensorValues[3];
    sen0 = sensorValues[4];

    // black line following
    int error_val = ((3 * sen0 + 2 * sen1) - (2 * sen3 + 3 * sen4));
    int p = error_val / 2;
    int d = 0;
    d = p - prevp;
    prevp = p;
    int pid = (d / kd) + (p / kp);
    int vl = max_black(base_drive_black + pid);
    int vr = max_black(base_drive_black - pid);
    SetSpeed(vl, vr);
  }
  // invoking parking functions according to condition
  if (fl)
    return FREE_LEFT;
  else if (fr)
    return FREE_RIGHT;
  return OCCUPIED;
}
