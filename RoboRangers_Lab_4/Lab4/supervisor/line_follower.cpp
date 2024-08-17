/* --- Generated the 4/5/2024 at 11:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__max_black_step(long a, Line_follower__max_black_out* _out) {
  
  long v_2;
  long v_1;
  long v;
  v_1 = (a>80);
  if (v_1) {
    v_2 = 68;
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

void Line_follower__max_step(long a, Line_follower__max_out* _out) {
  
  long v_4;
  long v_3;
  long v;
  v_3 = (a>50);
  if (v_3) {
    v_4 = 35;
  } else {
    v_4 = a;
  };
  v = (a<0);
  if (v) {
    _out->b = 0;
  } else {
    _out->b = v_4;
  };;
}

void Line_follower__pid_control_white_reset(Line_follower__pid_control_white_mem* self) {
  self->v_12 = true;
}

void Line_follower__pid_control_white_step(long sen0, long sen1, long sen3,
                                           long sen4, long sen2,
                                           Line_follower__pid_control_white_out* _out,
                                           Line_follower__pid_control_white_mem* self) {
  Line_follower__max_out Line_follower__max_out_st;
  
  long v_18;
  long v_17;
  long v_16;
  long v_15;
  long v_14;
  long v_11;
  long v_10;
  long v_9;
  long v_8;
  long v_7;
  long v_6;
  long v_5;
  long v;
  long error_val;
  long pid_val;
  long p;
  long d;
  v_11 = (sen2/2);
  v_8 = (4*sen4);
  v_7 = (2*sen3);
  v_9 = (v_7+v_8);
  v_5 = (2*sen1);
  v = (4*sen0);
  v_6 = (v+v_5);
  error_val = (v_6-v_9);
  v_10 = (error_val/2);
  p = (v_10+v_11);
  v_16 = (p/Line_follower__kp);
  v_14 = (p-self->v_13);
  if (self->v_12) {
    d = 0;
  } else {
    d = v_14;
  };
  v_15 = (d/Line_follower__kd);
  pid_val = (v_15+v_16);
  v_18 = (Line_follower__base_drive+pid_val);
  Line_follower__max_step(v_18, &Line_follower__max_out_st);
  _out->v_r = Line_follower__max_out_st.b;
  v_17 = (Line_follower__base_drive-pid_val);
  Line_follower__max_step(v_17, &Line_follower__max_out_st);
  _out->v_l = Line_follower__max_out_st.b;
  self->v_13 = p;
  self->v_12 = false;;
}

void Line_follower__pid_control_black_reset(Line_follower__pid_control_black_mem* self) {
  self->v_32 = true;
  self->v_29 = true;
  self->v_24 = true;
}

void Line_follower__pid_control_black_step(long sen0, long sen1, long sen3,
                                           long sen4,
                                           Line_follower__pid_control_black_out* _out,
                                           Line_follower__pid_control_black_mem* self) {
  Line_follower__max_black_out Line_follower__max_black_out_st;
  
  long v_34;
  long v_33;
  long v_31;
  long v_30;
  long v_28;
  long v_27;
  long v_26;
  long v_23;
  long v_22;
  long v_21;
  long v_20;
  long v_19;
  long v;
  long error_val;
  long pid_val;
  long p;
  long d;
  v_22 = (3*sen4);
  v_21 = (2*sen3);
  v_23 = (v_21+v_22);
  v_19 = (2*sen1);
  v = (3*sen0);
  v_20 = (v+v_19);
  error_val = (v_20-v_23);
  p = (error_val/2);
  v_28 = (p/Line_follower__kp);
  v_26 = (p-self->v_25);
  if (self->v_24) {
    d = 0;
  } else {
    d = v_26;
  };
  v_27 = (d/Line_follower__kd);
  pid_val = (v_27+v_28);
  v_33 = (Line_follower__base_drive_black-pid_val);
  Line_follower__max_black_step(v_33, &Line_follower__max_black_out_st);
  v_34 = Line_follower__max_black_out_st.b;
  if (self->v_32) {
    _out->v_r = 15;
  } else {
    _out->v_r = v_34;
  };
  v_30 = (Line_follower__base_drive_black+pid_val);
  Line_follower__max_black_step(v_30, &Line_follower__max_black_out_st);
  v_31 = Line_follower__max_black_out_st.b;
  if (self->v_29) {
    _out->v_l = 15;
  } else {
    _out->v_l = v_31;
  };
  self->v_32 = false;
  self->v_29 = false;
  self->v_25 = p;
  self->v_24 = false;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__pid_control_white_reset(&self->pid_control_white);
  Line_follower__pid_control_black_reset(&self->pid_control_black);
  self->node_count_1 = 0;
  self->pnr = false;
  self->ck = Line_follower__St_White_Line_Follower;
}

void Line_follower__main_step(long sen4, long sen3, long sen2, long sen1,
                              long sen0, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__pid_control_black_out Line_follower__pid_control_black_out_st;
  Line_follower__pid_control_white_out Line_follower__pid_control_white_out_st;
  
  long v;
  long v_57;
  Line_follower__st v_56;
  long v_55;
  Line_follower__st v_54;
  long v_53;
  long v_52;
  long v_51;
  long v_50;
  long v_49;
  long v_48;
  long v_47;
  long v_46;
  long v_45;
  long v_44;
  long v_43;
  long v_42;
  long v_41;
  long v_40;
  long v_39;
  long v_38;
  long v_37;
  long v_36;
  long v_35;
  long r_1;
  long v_64;
  long v_63;
  long v_62;
  long v_61;
  long v_60;
  long v_59;
  long v_58;
  long r_2;
  long nr_St_Parking;
  Line_follower__st ns_St_Parking;
  long node_count_St_Parking;
  long dir_St_Parking;
  long v_r_St_Parking;
  long v_l_St_Parking;
  long nr_St_Black_Node_Turner;
  Line_follower__st ns_St_Black_Node_Turner;
  long node_count_St_Black_Node_Turner;
  long dir_St_Black_Node_Turner;
  long v_r_St_Black_Node_Turner;
  long v_l_St_Black_Node_Turner;
  long nr_St_Black_Line_Follower;
  Line_follower__st ns_St_Black_Line_Follower;
  long node_count_St_Black_Line_Follower;
  long dir_St_Black_Line_Follower;
  long v_r_St_Black_Line_Follower;
  long v_l_St_Black_Line_Follower;
  long nr_St_White_Line_Follower;
  Line_follower__st ns_St_White_Line_Follower;
  long node_count_St_White_Line_Follower;
  long dir_St_White_Line_Follower;
  long v_r_St_White_Line_Follower;
  long v_l_St_White_Line_Follower;
  Line_follower__st ns;
  long r;
  long nr;
  long sen[5];
  long node_count;
  r = self->pnr;
  switch (self->ck) {
    case Line_follower__St_White_Line_Follower:
      node_count_St_White_Line_Follower = self->node_count_1;
      dir_St_White_Line_Follower = 2;
      v_63 = (sen3>Line_follower__white_threshold);
      v_61 = (sen1>Line_follower__white_threshold);
      v_59 = (sen0>Line_follower__white_threshold);
      v_58 = (sen2<Line_follower__black_threshold);
      v_60 = (v_58&&v_59);
      v_62 = (v_60&&v_61);
      v_64 = (v_62&&v_63);
      if (v_64) {
        nr_St_White_Line_Follower = true;
        ns_St_White_Line_Follower = Line_follower__St_Black_Line_Follower;
      } else {
        nr_St_White_Line_Follower = false;
        ns_St_White_Line_Follower = Line_follower__St_White_Line_Follower;
      };
      r_2 = r;
      if (r_2) {
        Line_follower__pid_control_white_reset(&self->pid_control_white);
      };
      Line_follower__pid_control_white_step(sen0, sen1, sen3, sen4, sen2,
                                            &Line_follower__pid_control_white_out_st,
                                            &self->pid_control_white);
      v_l_St_White_Line_Follower = Line_follower__pid_control_white_out_st.v_l;
      v_r_St_White_Line_Follower = Line_follower__pid_control_white_out_st.v_r;
      _out->dir = dir_St_White_Line_Follower;
      node_count = node_count_St_White_Line_Follower;
      _out->v_l = v_l_St_White_Line_Follower;
      _out->v_r = v_r_St_White_Line_Follower;
      ns = ns_St_White_Line_Follower;
      nr = nr_St_White_Line_Follower;
      break;
    case Line_follower__St_Black_Line_Follower:
      node_count_St_Black_Line_Follower = self->node_count_1;
      dir_St_Black_Line_Follower = 2;
      v_53 = (self->node_count_1==5);
      if (v_53) {
        v_55 = true;
        v_54 = Line_follower__St_Parking;
      } else {
        v_55 = false;
        v_54 = Line_follower__St_Black_Line_Follower;
      };
      v_51 = (sen3<Line_follower__black_threshold);
      v_49 = (sen1<Line_follower__black_threshold);
      v_47 = (sen2<Line_follower__black_threshold);
      v_46 = (self->node_count_1==4);
      v_48 = (v_46&&v_47);
      v_50 = (v_48&&v_49);
      v_52 = (v_50&&v_51);
      if (v_52) {
        v_57 = true;
        v_56 = Line_follower__St_Parking;
      } else {
        v_57 = v_55;
        v_56 = v_54;
      };
      v_44 = (sen4<Line_follower__black_threshold);
      v_42 = (sen3<Line_follower__black_threshold);
      v_40 = (sen0<Line_follower__black_threshold);
      v_38 = (sen1<Line_follower__black_threshold);
      v_36 = (sen2<Line_follower__black_threshold);
      v_35 = (sen2>200);
      v_37 = (v_35&&v_36);
      v_39 = (v_37&&v_38);
      v_41 = (v_39&&v_40);
      v_43 = (v_41&&v_42);
      v_45 = (v_43&&v_44);
      if (v_45) {
        nr_St_Black_Line_Follower = true;
        ns_St_Black_Line_Follower = Line_follower__St_Black_Node_Turner;
      } else {
        nr_St_Black_Line_Follower = v_57;
        ns_St_Black_Line_Follower = v_56;
      };
      r_1 = r;
      if (r_1) {
        Line_follower__pid_control_black_reset(&self->pid_control_black);
      };
      Line_follower__pid_control_black_step(sen0, sen1, sen3, sen4,
                                            &Line_follower__pid_control_black_out_st,
                                            &self->pid_control_black);
      v_l_St_Black_Line_Follower = Line_follower__pid_control_black_out_st.v_l;
      v_r_St_Black_Line_Follower = Line_follower__pid_control_black_out_st.v_r;
      _out->dir = dir_St_Black_Line_Follower;
      node_count = node_count_St_Black_Line_Follower;
      _out->v_l = v_l_St_Black_Line_Follower;
      _out->v_r = v_r_St_Black_Line_Follower;
      ns = ns_St_Black_Line_Follower;
      nr = nr_St_Black_Line_Follower;
      break;
    case Line_follower__St_Black_Node_Turner:
      dir_St_Black_Node_Turner = 2;
      node_count_St_Black_Node_Turner = (self->node_count_1+1);
      if (true) {
        nr_St_Black_Node_Turner = true;
      } else {
        nr_St_Black_Node_Turner = false;
      };
      if (true) {
        ns_St_Black_Node_Turner = Line_follower__St_Black_Line_Follower;
      } else {
        ns_St_Black_Node_Turner = Line_follower__St_Black_Node_Turner;
      };
      _out->dir = dir_St_Black_Node_Turner;
      node_count = node_count_St_Black_Node_Turner;
      v = (node_count<=2);
      if (v) {
        v_r_St_Black_Node_Turner = -1;
        v_l_St_Black_Node_Turner = -1;
      } else {
        v_r_St_Black_Node_Turner = -2;
        v_l_St_Black_Node_Turner = -2;
      };
      _out->v_l = v_l_St_Black_Node_Turner;
      _out->v_r = v_r_St_Black_Node_Turner;
      ns = ns_St_Black_Node_Turner;
      nr = nr_St_Black_Node_Turner;
      break;
    case Line_follower__St_Parking:
      dir_St_Parking = 2;
      v_r_St_Parking = -3;
      v_l_St_Parking = -3;
      node_count_St_Parking = (self->node_count_1+1);
      if (true) {
        nr_St_Parking = true;
      } else {
        nr_St_Parking = false;
      };
      if (true) {
        ns_St_Parking = Line_follower__St_Black_Line_Follower;
      } else {
        ns_St_Parking = Line_follower__St_Parking;
      };
      _out->dir = dir_St_Parking;
      node_count = node_count_St_Parking;
      _out->v_l = v_l_St_Parking;
      _out->v_r = v_r_St_Parking;
      ns = ns_St_Parking;
      nr = nr_St_Parking;
      break;
    default:
      break;
  };
  sen[0] = sen0;
  sen[1] = sen1;
  sen[2] = sen2;
  sen[3] = sen3;
  sen[4] = sen4;
  self->node_count_1 = node_count;
  self->pnr = nr;
  self->ck = ns;;
}

