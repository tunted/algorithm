#include <stdio.h>
#include <stdlib.h>

#define max 100

int key[max], next[max];
int head, z, t;

void stack_init(void){
  head = 0;
  z = 1;
  t = 2;

  next[head] = z;
  next[z] = z;
}

void push(int v){
  next[t] = next[head];
  next[head] = t;

  key[t] = v;
  t++;
}

int pop(void){
  t = next[head];
  next[head] = next[t];

  return key[t];
}

void main(){
  stack_init();
  push(1);
  push(2);
  push(3);

  printf(">> data : %d\n", pop());
  push(4);
  printf(">> data : %d\n", pop());
  push(5);
  push(6);
  printf(">> data : %d\n", pop());

}
