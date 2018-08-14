#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};

struct node *head, *z, *t;

void stack_init(void){
  head = (struct node *) malloc(sizeof *head);
  z = (struct node *) malloc(sizeof *z);

  head->next = z;
  head->key = 0;

  z->next = z;
}

void push(int v){
  t = (struct node *) malloc(sizeof *t);
  t->key = v;
  t->next = head->next;
  head->next = t;
}

int pop(void){
  int x;
  t = head->next;
  head->next = t->next;

  x = t->key;
  free(t);
  return x;
}

int stack_empty(void){
  return head->next == z;
}

void main(){
  stack_init();
  push(1);
  push(2);
  push(3);

  printf(">> data : %d\n", pop());
  printf(">> data : %d\n", pop());
  printf(">> data : %d\n", pop());

}
