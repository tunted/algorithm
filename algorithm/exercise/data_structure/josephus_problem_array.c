#include <stdio.h>
#include <stdlib.h>

#define max 100

int key[max+2], next[max+2];

void main(){
    int N = 9, M = 5;       
    int index = N - 1;
    for (int i = 0; i < N; i++){
        key[i] = i+1;
        next[i] = i + 1;
    }
    next[N-1] = 0;

    while (next[index] != index){
        for (int i = 1; i < M; i++){
            index = next[index];
        }
        
        printf("%5d", key[next[index]]);
        next[index] = next[next[index]];
    }
    
    printf("%5d\n", key[index]);


}

