/* --- Generated the 4/5/2024 at 11:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 18 21:28:53 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_White_Line_Follower")==0)) {
    return Line_follower__St_White_Line_Follower;
  };
  if ((strcmp(s, "St_Parking")==0)) {
    return Line_follower__St_Parking;
  };
  if ((strcmp(s, "St_Black_Node_Turner")==0)) {
    return Line_follower__St_Black_Node_Turner;
  };
  if ((strcmp(s, "St_Black_Line_Follower")==0)) {
    return Line_follower__St_Black_Line_Follower;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_White_Line_Follower:
      strcpy(buf, "St_White_Line_Follower");
      break;
    case Line_follower__St_Parking:
      strcpy(buf, "St_Parking");
      break;
    case Line_follower__St_Black_Node_Turner:
      strcpy(buf, "St_Black_Node_Turner");
      break;
    case Line_follower__St_Black_Line_Follower:
      strcpy(buf, "St_Black_Line_Follower");
      break;
    default:
      break;
  };
  return buf;
}

