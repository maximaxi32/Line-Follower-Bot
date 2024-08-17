/* --- Generated the 4/5/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
static const long Line_follower__threshold = 200;

static const long Line_follower__kp = 10;

static const long Line_follower__kd = 120;

static const long Line_follower__base_drive = 35;

typedef enum {
  Line_follower__One,
  Line_follower__Two
} Line_follower__modeswitch;

Line_follower__modeswitch Line_follower__modeswitch_of_string(char* s);

char* string_of_Line_follower__modeswitch(Line_follower__modeswitch x,
                                          char* buf);

#endif // LINE_FOLLOWER_TYPES_H
