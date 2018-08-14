#include <stdio.h>
#include <stdlib.h>

#define M 20
#define N 20

int gcd(int a, int b){
  while (0 != a){
    if (a < b){
      int t = a;
      a = b;
      b = t;
    }
    a = a - b;
  }

  return b;
}

int main(){
  int a[M+1][N+1];
  for (int i = 1; i <= M; i++){
      for (int j = 1; j <= N; j++){
          if (gcd(i,j) == 1){
              a[i][j] = 1;
          }
          else{
              a[i][j] = 0;
          }

          printf("%5d", a[i][j]);
      }
      printf("\n");
  }

}
