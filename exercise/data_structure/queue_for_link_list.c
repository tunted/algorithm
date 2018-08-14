#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
struct node{
  int key;
  struct node *next;
};

struct node *head, *tail;

struct node *insert_after(int v, struct node *t){
  struct node *new_node;
  new_node = (struct node *) malloc(sizeof new_node);
  new_node->next = t->next;
  t->next = new_node;

  new_node->key = v;
}

void delete_next(struct node *t){
  struct node *x;
  x = t->next;
  t->next = t->next->next;

  free(x);
}

void initialize(void){
  struct node *start, *x;
  start = (struct node *)malloc(sizeof *start);
  x = start;

  for (int i = 0; i <= SIZE; i++){
    x->next = (struct node *) malloc(sizeof *x);
    x = x->next;
  }
  x->next = start;
  
  head = start;
  tail = start;
}

void put(int v){
  if (tail->next == head){
    return;
  }

  tail->key = v;
  tail = tail->next;
}

int get(void){
  if (tail->next == head){
    return -1;
  }

  int data = head->key;
  head = head->next;
  return data;
}

void main(){
  initialize();

  put(1);
  put(2);
  put(3);

  printf(">> data : %d\n", get());
  printf(">> data : %d\n", get()); 
  printf(">> data : %d\n", get());
}
