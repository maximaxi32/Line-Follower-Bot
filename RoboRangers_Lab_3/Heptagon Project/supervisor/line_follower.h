/* --- Generated the 4/5/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__max_out {
  long b;
} Line_follower__max_out;

void Line_follower__max_step(long a, Line_follower__max_out* _out);

typedef struct Line_follower__pid_control_mem {
  long v_9;
  long v_8;
} Line_follower__pid_control_mem;

typedef struct Line_follower__pid_control_out {
  long v_l;
  long v_r;
} Line_follower__pid_control_out;

void Line_follower__pid_control_reset(Line_follower__pid_control_mem* self);

void Line_follower__pid_control_step(long sen0, long sen1, long sen3, long sen4,
                                     Line_follower__pid_control_out* _out,
                                     Line_follower__pid_control_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__pid_control_mem pid_control;
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
