/* --- Generated the 6/3/2024 at 14:36 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 19 9:56:11 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s display -hepts node.ept --- */

#ifndef NODE_H
#define NODE_H

#include "node_types.h"
typedef struct Node__line_follower_out {
  int v_l;
  int v_r;
} Node__line_follower_out;

void Node__line_follower_step(int sen[5], Node__line_follower_out* _out);

typedef struct Node__main_out {
  int v_l;
  int v_r;
} Node__main_out;

void Node__main_step(int sen0, int sen1, int sen2, int sen3, int sen4,
                     Node__main_out* _out);

#endif // NODE_H
