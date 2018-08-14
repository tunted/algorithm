#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
};

struct node *head, *z, *t;

void list_initialize(){
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);
    head->next = z;
    z->next = z;
 } 

void deletenext(struct node *t){
//    free(t->next);
    t->next = t->next->next;
}

struct node *insert_after(int v, struct node *t){
    struct node *x;
    x = (struct node *) malloc(sizeof *x);
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

void main(){
  list_initialize();
  struct node *new1 = (struct node *)insert_after(20, head);
  struct node *new2 = (struct node *)insert_after(30, new1);
  printf(">>> data of new 1 : %d\n", new1->key);
  printf(">>> data of new 2 : %d\n", new2->key);

  deletenext(new1);
  printf(">>> data of new 1 : %d\n", new1->key);
  printf(">>> data of new 2 : %d\n", new2->key);

}
