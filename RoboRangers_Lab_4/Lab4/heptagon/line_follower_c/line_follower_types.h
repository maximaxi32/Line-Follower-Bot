/* --- Generated the 4/5/2024 at 11:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_White_Line_Follower,
  Line_follower__St_Parking,
  Line_follower__St_Black_Node_Turner,
  Line_follower__St_Black_Line_Follower
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const int Line_follower__black_threshold = 480;

static const int Line_follower__white_threshold = 550;

static const int Line_follower__kp = 10;

static const int Line_follower__kd = 120;

static const int Line_follower__base_drive = 35;

static const int Line_follower__base_drive_black = 50;

#endif // LINE_FOLLOWER_TYPES_H
