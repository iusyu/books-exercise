#include <stdio.h>
#include <stdlib.h>

void cond(long a, long *p) {
  if( p && *p )
    *p = a;
}


void cond_goto(long a, long *p) {
  if( p )
    goto nextjudge;
nextjudge:
  if( *p )
    goto execut;
execut:
  *p = a;
}



int main(int argc, char* argv[]) {
  long dd = 20;
  cond(50, &dd);
}
