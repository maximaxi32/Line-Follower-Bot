/* --- Generated the 14/4/2024 at 16:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__max_black_step(int a, Line_follower__max_black_out* _out) {
  
  int v_2;
  int v_1;
  int v;
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

void Line_follower__max_step(int a, Line_follower__max_out* _out) {
  
  int v_4;
  int v_3;
  int v;
  v_3 = (a>35);
  if (v_3) {
    v_4 = 30;
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
  self->v_13 = true;
}

void Line_follower__pid_control_white_step(int sen0, int sen1, int sen3,
                                           int sen4, int sen2,
                                           Line_follower__pid_control_white_out* _out,
                                           Line_follower__pid_control_white_mem* self) {
  Line_follower__max_out Line_follower__max_out_st;
  
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v;
  int error_val;
  int pid_val;
  int p;
  int d;
  v_11 = (sen2<750);
  if (v_11) {
    v_12 = sen2;
  } else {
    v_12 = 0;
  };
  v_8 = (4*sen4);
  v_7 = (2*sen3);
  v_9 = (v_7+v_8);
  v_5 = (2*sen1);
  v = (4*sen0);
  v_6 = (v+v_5);
  v_10 = (v_6-v_9);
  error_val = (v_10-v_12);
  p = (error_val/2);
  v_17 = (p/Line_follower__kp);
  v_15 = (p-self->v_14);
  if (self->v_13) {
    d = 0;
  } else {
    d = v_15;
  };
  v_16 = (d/Line_follower__kd);
  pid_val = (v_16+v_17);
  v_19 = (Line_follower__base_drive+pid_val);
  Line_follower__max_step(v_19, &Line_follower__max_out_st);
  _out->v_r = Line_follower__max_out_st.b;
  v_18 = (Line_follower__base_drive-pid_val);
  Line_follower__max_step(v_18, &Line_follower__max_out_st);
  _out->v_l = Line_follower__max_out_st.b;
  self->v_14 = p;
  self->v_13 = false;;
}

void Line_follower__pid_control_black_reset(Line_follower__pid_control_black_mem* self) {
  self->v_33 = true;
  self->v_30 = true;
  self->v_25 = true;
}

void Line_follower__pid_control_black_step(int sen0, int sen1, int sen3,
                                           int sen4,
                                           Line_follower__pid_control_black_out* _out,
                                           Line_follower__pid_control_black_mem* self) {
  Line_follower__max_black_out Line_follower__max_black_out_st;
  
  int v_35;
  int v_34;
  int v_32;
  int v_31;
  int v_29;
  int v_28;
  int v_27;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v;
  int error_val;
  int pid_val;
  int p;
  int d;
  v_23 = (3*sen4);
  v_22 = (2*sen3);
  v_24 = (v_22+v_23);
  v_20 = (2*sen1);
  v = (3*sen0);
  v_21 = (v+v_20);
  error_val = (v_21-v_24);
  p = (error_val/2);
  v_29 = (p/Line_follower__kp);
  v_27 = (p-self->v_26);
  if (self->v_25) {
    d = 0;
  } else {
    d = v_27;
  };
  v_28 = (d/Line_follower__kd);
  pid_val = (v_28+v_29);
  v_34 = (Line_follower__base_drive_black-pid_val);
  Line_follower__max_black_step(v_34, &Line_follower__max_black_out_st);
  v_35 = Line_follower__max_black_out_st.b;
  if (self->v_33) {
    _out->v_r = 15;
  } else {
    _out->v_r = v_35;
  };
  v_31 = (Line_follower__base_drive_black+pid_val);
  Line_follower__max_black_step(v_31, &Line_follower__max_black_out_st);
  v_32 = Line_follower__max_black_out_st.b;
  if (self->v_30) {
    _out->v_l = 15;
  } else {
    _out->v_l = v_32;
  };
  self->v_33 = false;
  self->v_30 = false;
  self->v_26 = p;
  self->v_25 = false;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__pid_control_white_reset(&self->pid_control_white);
  Line_follower__pid_control_black_reset(&self->pid_control_black);
  self->node_count_1 = 0;
  self->pnr = false;
  self->v_62 = true;
  self->ck = Line_follower__St_White_Line_Follower;
}

void Line_follower__main_step(int sen4, int sen3, int sen2, int sen1,
                              int sen0, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__pid_control_black_out Line_follower__pid_control_black_out_st;
  Line_follower__pid_control_white_out Line_follower__pid_control_white_out_st;
  
  int v_57;
  Line_follower__st v_56;
  int v_55;
  Line_follower__st v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v;
  int r_1;
  int v_68;
  int v_66;
  int v_64;
  int v_63;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int r_2;
  int temp;
  int cnt;
  int nr_St_Parking;
  Line_follower__st ns_St_Parking;
  int node_count_St_Parking;
  int dir_St_Parking;
  int v_r_St_Parking;
  int v_l_St_Parking;
  int nr_St_Black_Node_Turner;
  Line_follower__st ns_St_Black_Node_Turner;
  int node_count_St_Black_Node_Turner;
  int dir_St_Black_Node_Turner;
  int v_r_St_Black_Node_Turner;
  int v_l_St_Black_Node_Turner;
  int nr_St_Black_Line_Follower;
  Line_follower__st ns_St_Black_Line_Follower;
  int node_count_St_Black_Line_Follower;
  int dir_St_Black_Line_Follower;
  int v_r_St_Black_Line_Follower;
  int v_l_St_Black_Line_Follower;
  int nr_St_White_Line_Follower;
  Line_follower__st ns_St_White_Line_Follower;
  int node_count_St_White_Line_Follower;
  int dir_St_White_Line_Follower;
  int v_r_St_White_Line_Follower;
  int v_l_St_White_Line_Follower;
  Line_follower__st ns;
  int r;
  int nr;
  int sen[5];
  int node_count;
  r = self->pnr;
  switch (self->ck) {
    case Line_follower__St_White_Line_Follower:
      node_count_St_White_Line_Follower = self->node_count_1;
      v_66 = (self->v_65+1);
      if (self->v_62) {
        v_63 = true;
      } else {
        v_63 = r;
      };
      v_59 = (sen0+sen1);
      v_60 = (v_59+sen3);
      v_61 = (v_60+sen4);
      temp = (v_61+sen2);
      v_64 = (temp>3500);
      if (v_64) {
        v_68 = v_66;
      } else {
        v_68 = self->v_67;
      };
      if (v_63) {
        cnt = 0;
      } else {
        cnt = v_68;
      };
      dir_St_White_Line_Follower = 2;
      v_58 = (cnt>50);
      if (v_58) {
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
      _out->v_l = v_l_St_White_Line_Follower;
      _out->v_r = v_r_St_White_Line_Follower;
      node_count = node_count_St_White_Line_Follower;
      _out->dir = dir_St_White_Line_Follower;
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
      v = (sen2>200);
      v_37 = (v&&v_36);
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
      _out->v_l = v_l_St_Black_Line_Follower;
      _out->v_r = v_r_St_Black_Line_Follower;
      node_count = node_count_St_Black_Line_Follower;
      _out->dir = dir_St_Black_Line_Follower;
      ns = ns_St_Black_Line_Follower;
      nr = nr_St_Black_Line_Follower;
      break;
    case Line_follower__St_Black_Node_Turner:
      v_r_St_Black_Node_Turner = -2;
      v_l_St_Black_Node_Turner = -2;
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
      _out->v_l = v_l_St_Black_Node_Turner;
      _out->v_r = v_r_St_Black_Node_Turner;
      node_count = node_count_St_Black_Node_Turner;
      dir_St_Black_Node_Turner = node_count;
      _out->dir = dir_St_Black_Node_Turner;
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
      _out->v_l = v_l_St_Parking;
      _out->v_r = v_r_St_Parking;
      node_count = node_count_St_Parking;
      _out->dir = dir_St_Parking;
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
  switch (self->ck) {
    case Line_follower__St_White_Line_Follower:
      self->v_67 = cnt;
      self->v_65 = cnt;
      self->v_62 = false;
      break;
    default:
      break;
  };
  self->ck = ns;;
}

