#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
};

struct node *head, *z;

void initialize(void){
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);

    head->next = z;
    z->next = z;

    head->key = 0;
    z->key = 100;
}

struct node *add_to_next(int value, struct node *t){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof *new_node);

    new_node->next = t->next; 

    t->next = new_node;

    new_node->key = value;

    return new_node;
}

void remove_next_node(struct node *t){
    struct node *x;
    x = t->next;

    t->next = t->next->next;
    free(x);
}

void move_next_to_front(struct node *t){
    struct node *x;
    x = t->next;

    t->next = t->next->next;

    x->next = head->next;
    head->next = x;
}

void main(void){
    struct node *a, *b, *c;
    
    initialize();

    a = add_to_next(1, head);

    b = add_to_next(2, a);

    c = add_to_next(3, b);

    struct node *temp = head;

    int index = 0;

    move_next_to_front(b);
    move_next_to_front(a);
    while (temp->next != temp){
        printf(">> value at index %d is : %d\n", index++, temp->key);
        temp = temp->next;
    }

}

