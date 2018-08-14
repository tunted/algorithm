#include <stdio.h>

#define max 10

int key[max+2], next[max+2];
int x, head, z;

void list_initialize(){
    head = 0; 
    z = 1; 
    x = 2;

    next[head] = z; 
    next[z] = z;
}

void delete_next(int t){
    next[t] = next[next[t]];
}

int insert_after(int v, int t){
    key[x] = v;
    next[x] = next[t];
    next[t] = x;
    return x++;
}
