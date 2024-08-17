#ifndef ALPHABOT_DRIVER_H
#define ALPHABOT_DRIVER_H


#include "Arduino.h"
#include <Wire.h>

#define Clock     13
#define Address   12
#define DataOut   11
#define CS        10
#define IRL        4
#define IRR        7

#define NUM_SENSORS 5

#define DefaultSpeed 255
#define ENL 5
#define ENR 6

#define INLF A0
#define INLB A1
#define INRF A3
#define INRB A2

#define Addr  0x20

#define ECHO   2
#define TRIG   3


void sensor_init(void);
void AnalogRead(int *);

void motion_init(void);
void forward(void);
void backward();
void right();
void left();
void forward_right();
void forward_left();
void back_right();
void back_left();
void stop();
void SetSpeed(char ,char );

void beep_on();
void beep_off();

char joystick_read();
char ir_read();
int ir_read_customl();
int ir_read_customr();

void ultrasonic_init();
int Distance_test();
int max_black(int);

void init_devices();


#endif 
