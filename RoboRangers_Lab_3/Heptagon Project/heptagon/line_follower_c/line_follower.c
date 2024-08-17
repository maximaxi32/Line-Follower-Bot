/* --- Generated the 4/5/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__max_step(int a, Line_follower__max_out* _out) {
  
  int v_2;
  int v_1;
  int v;
  v_1 = (a>50);
  if (v_1) {
    v_2 = 35;
  } else {
    v_2 = a;
  };
  v = (a<0);
  if (v) {
    _out->b = 0;
  } else {
    _out->b = v_2;
  };;
}

void Line_follower__pid_control_reset(Line_follower__pid_control_mem* self) {
  self->v_8 = true;
}

void Line_follower__pid_control_step(int sen0, int sen1, int sen3, int sen4,
                                     Line_follower__pid_control_out* _out,
                                     Line_follower__pid_control_mem* self) {
  Line_follower__max_out Line_follower__max_out_st;
  
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v;
  int error_val;
  int pid_val;
  int p;
  int d;
  v_6 = (3*sen4);
  v_5 = (2*sen3);
  v_7 = (v_5+v_6);
  v_3 = (2*sen1);
  v = (3*sen0);
  v_4 = (v+v_3);
  error_val = (v_4-v_7);
  p = (error_val/2);
  v_12 = (p/Line_follower__kp);
  v_10 = (p-self->v_9);
  if (self->v_8) {
    d = 0;
  } else {
    d = v_10;
  };
  v_11 = (d/Line_follower__kd);
  pid_val = (v_11+v_12);
  v_14 = (Line_follower__base_drive+pid_val);
  Line_follower__max_step(v_14, &Line_follower__max_out_st);
  _out->v_r = Line_follower__max_out_st.b;
  v_13 = (Line_follower__base_drive-pid_val);
  Line_follower__max_step(v_13, &Line_follower__max_out_st);
  _out->v_l = Line_follower__max_out_st.b;
  self->v_9 = p;
  self->v_8 = false;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__pid_control_reset(&self->pid_control);
}

void Line_follower__main_step(int sen4, int sen3, int sen2, int sen1,
                              int sen0, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__pid_control_out Line_follower__pid_control_out_st;
  
  int dir_Two;
  int v_r_Two;
  int v_l_Two;
  int dir_One;
  int v_r_One;
  int v_l_One;
  Line_follower__modeswitch ck;
  int v;
  int sen[5];
  Line_follower__modeswitch modnum;
  v = (sen2>Line_follower__threshold);
  if (v) {
    modnum = Line_follower__One;
  } else {
    modnum = Line_follower__Two;
  };
  ck = modnum;
  switch (ck) {
    case Line_follower__One:
      dir_One = 2;
      Line_follower__pid_control_step(sen0, sen1, sen3, sen4,
                                      &Line_follower__pid_control_out_st,
                                      &self->pid_control);
      v_l_One = Line_follower__pid_control_out_st.v_l;
      v_r_One = Line_follower__pid_control_out_st.v_r;
      _out->v_l = v_l_One;
      _out->v_r = v_r_One;
      _out->dir = dir_One;
      break;
    case Line_follower__Two:
      dir_Two = 2;
      v_r_Two = 35;
      v_l_Two = 35;
      _out->v_l = v_l_Two;
      _out->v_r = v_r_Two;
      _out->dir = dir_Two;
      break;
    default:
      break;
  };
  sen[0] = sen0;
  sen[1] = sen1;
  sen[2] = sen2;
  sen[3] = sen3;
  sen[4] = sen4;;
}

