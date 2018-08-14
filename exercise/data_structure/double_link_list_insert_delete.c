#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
  struct node *prev;
};

struct node *head, *z;

void initialize(void){
  head = (struct node *) malloc(sizeof *head);
  z    = (struct node *) malloc(sizeof *z);

  head->next = z;
  head->prev = z;
  head->key = 0;

  z->next = z;
  z->prev = head;
  z->key = 100;
}

struct node *insert_after(int v, struct node *t){
  struct node *new_node;
  new_node = (struct node *) malloc(sizeof *new_node);

  new_node->key = v;

  new_node->next = t->next;
  t->next->prev = new_node;

  new_node->prev = t;
  t->next = new_node;

  return new_node;
}

void delete(struct node *t){
  t->prev->next = t->next;
  t->next->prev = t->prev;

  free(t);
}

void main(){
  initialize();

  struct node *a, *b, *c, *d, *e;

  a = insert_after(1, head); 
  b = insert_after(2, a);
  c = insert_after(3, b);
  d = insert_after(4, c);
  e = insert_after(5, d);

  struct node *x;
  x = a;

  printf(">>> bug at delete a\n");
  delete(b);

  printf(">>> bug at delete c\n");
  delete(d);

  while (x->next != x){
    printf("%5d", x->key);
    x = x->next;
  }

  printf("\n");
}
