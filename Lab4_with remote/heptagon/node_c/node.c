/* --- Generated the 6/3/2024 at 14:36 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 19 9:56:11 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s display -hepts node.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

void Node__line_follower_step(int sen[5], Node__line_follower_out* _out) {
  
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  v_6 = sen[3];
  v_7 = (v_6/10);
  v_4 = sen[2];
  v_5 = (v_4>=1000);
  if (v_5) {
    _out->v_r = 100;
  } else {
    _out->v_r = v_7;
  };
  v_2 = sen[1];
  v = sen[2];
  v_3 = (v_2/10);
  v_1 = (v>=1000);
  if (v_1) {
    _out->v_l = 100;
  } else {
    _out->v_l = v_3;
  };;
}

void Node__main_step(int sen0, int sen1, int sen2, int sen3, int sen4,
                     Node__main_out* _out) {
  Node__line_follower_out Node__line_follower_out_st;
  
  int sen[5];
  sen[0] = sen0;
  sen[1] = sen1;
  sen[2] = sen2;
  sen[3] = sen3;
  sen[4] = sen4;
  Node__line_follower_step(sen, &Node__line_follower_out_st);
  _out->v_l = Node__line_follower_out_st.v_l;
  _out->v_r = Node__line_follower_out_st.v_r;;
}

