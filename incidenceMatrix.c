#include<stdio.h>

struct node{
  int from, to;
};
struct node a[5], t;

void addEdge(int am[][5], int i, int j, int in){
  int p, q;
  a[in].from = i;
  a[in].to = j;
  for ( p = 0; p <= in; p++){
    for (q = p + 1; q <= in; q++){
      if (a[p].from > a[q].from){
        t = a[p];
        a[p] = a[q];
        a[q] = t;
      }
      else if (a[p].from == a[q].from){
        if (a[p].to > a[q].to){
          t = a[p];
          a[p] = a[q];
          a[q] = t;
        }
      }
      else  continue;
    }
  }
}

int main(){
  int n, c = 0, x, y, ch, i, j;
  int t = 5;
  int am[t][t];
  printf("Enter the no of vertices\n");
  scanf("%d", &n);
  for (i = 0; i < 5; i++){
    for (j = 0; j < 5; j++) am[i][j] = 0;
  }
  while (ch < t){
    printf("Enter the 2 nodes for edges\n");
    scanf("%d%d", &x, &y);
    addEdge(am, x, y, c);
    c++;
    printf("Input value greater than %d to exit\n",t);
    scanf("%d", &ch);
  }    
  for (j = 0; j < c; j++){
    am[a[j].from][j] = 1;
    am[a[j].to][j] = 1;
  }
  for (i = 0; i < n; i++){
    for (j = 0; j < c; j++){
      printf("%d\t" ,am[i][j]);
    }
    printf("\n");
  } 
  return 0;
}