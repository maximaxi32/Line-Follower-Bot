/* --- Generated the 14/4/2024 at 16:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__max_black_out {
  long b;
} Line_follower__max_black_out;

void Line_follower__max_black_step(long a, Line_follower__max_black_out* _out);

typedef struct Line_follower__max_out {
  long b;
} Line_follower__max_out;

void Line_follower__max_step(long a, Line_follower__max_out* _out);

typedef struct Line_follower__pid_control_white_mem {
  long v_14;
  long v_13;
} Line_follower__pid_control_white_mem;

typedef struct Line_follower__pid_control_white_out {
  long v_l;
  long v_r;
} Line_follower__pid_control_white_out;

void Line_follower__pid_control_white_reset(Line_follower__pid_control_white_mem* self);

void Line_follower__pid_control_white_step(long sen0, long sen1, long sen3,
                                           long sen4, long sen2,
                                           Line_follower__pid_control_white_out* _out,
                                           Line_follower__pid_control_white_mem* self);

typedef struct Line_follower__pid_control_black_mem {
  long v_33;
  long v_30;
  long v_26;
  long v_25;
} Line_follower__pid_control_black_mem;

typedef struct Line_follower__pid_control_black_out {
  long v_l;
  long v_r;
} Line_follower__pid_control_black_out;

void Line_follower__pid_control_black_reset(Line_follower__pid_control_black_mem* self);

void Line_follower__pid_control_black_step(long sen0, long sen1, long sen3,
                                           long sen4,
                                           Line_follower__pid_control_black_out* _out,
                                           Line_follower__pid_control_black_mem* self);

typedef struct Line_follower__main_mem {
  long v_67;
  long v_65;
  long v_62;
  Line_follower__st ck;
  long pnr;
  long node_count_1;
  Line_follower__pid_control_black_mem pid_control_black;
  Line_follower__pid_control_white_mem pid_control_white;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen4, long sen3, long sen2, long sen1,
                              long sen0, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
