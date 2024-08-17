/* --- Generated the 4/5/2024 at 11:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__max_black_out {
  int b;
} Line_follower__max_black_out;

void Line_follower__max_black_step(int a, Line_follower__max_black_out* _out);

typedef struct Line_follower__max_out {
  int b;
} Line_follower__max_out;

void Line_follower__max_step(int a, Line_follower__max_out* _out);

typedef struct Line_follower__pid_control_white_mem {
  int v_13;
  int v_12;
} Line_follower__pid_control_white_mem;

typedef struct Line_follower__pid_control_white_out {
  int v_l;
  int v_r;
} Line_follower__pid_control_white_out;

void Line_follower__pid_control_white_reset(Line_follower__pid_control_white_mem* self);

void Line_follower__pid_control_white_step(int sen0, int sen1, int sen3,
                                           int sen4, int sen2,
                                           Line_follower__pid_control_white_out* _out,
                                           Line_follower__pid_control_white_mem* self);

typedef struct Line_follower__pid_control_black_mem {
  int v_32;
  int v_29;
  int v_25;
  int v_24;
} Line_follower__pid_control_black_mem;

typedef struct Line_follower__pid_control_black_out {
  int v_l;
  int v_r;
} Line_follower__pid_control_black_out;

void Line_follower__pid_control_black_reset(Line_follower__pid_control_black_mem* self);

void Line_follower__pid_control_black_step(int sen0, int sen1, int sen3,
                                           int sen4,
                                           Line_follower__pid_control_black_out* _out,
                                           Line_follower__pid_control_black_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st ck;
  int pnr;
  int node_count_1;
  Line_follower__pid_control_black_mem pid_control_black;
  Line_follower__pid_control_white_mem pid_control_white;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen4, int sen3, int sen2, int sen1,
                              int sen0, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
