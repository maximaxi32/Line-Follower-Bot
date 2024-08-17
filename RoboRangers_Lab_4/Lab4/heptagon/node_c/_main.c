/* --- Generated the 6/3/2024 at 14:36 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 19 9:56:11 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s display -hepts node.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

int main(int argc, char** argv) {
  int step_c;
  int step_max;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
  };
  return 0;
}

