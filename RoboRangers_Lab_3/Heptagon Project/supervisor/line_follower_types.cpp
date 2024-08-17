/* --- Generated the 4/5/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__modeswitch Line_follower__modeswitch_of_string(char* s) {
  if ((strcmp(s, "One")==0)) {
    return Line_follower__One;
  };
  if ((strcmp(s, "Two")==0)) {
    return Line_follower__Two;
  };
}

char* string_of_Line_follower__modeswitch(Line_follower__modeswitch x,
                                          char* buf) {
  switch (x) {
    case Line_follower__One:
      strcpy(buf, "One");
      break;
    case Line_follower__Two:
      strcpy(buf, "Two");
      break;
    default:
      break;
  };
  return buf;
}

