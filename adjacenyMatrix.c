#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,e,row,column;
  printf("How many vertices are there?\n");
  scanf("%d",&n);

  int _array[n][n],i,j;
  for(i=0;i<n;i++){
    for(j=0; j<n; j++){
      _array[i][j] = 0;
    }
  }

  printf("Before putting the edges the graph looks something like this\n");
  // printIt(_array,n);

  for(i=0;i<n;i++){
    for(j=0; j<n; j++){
      printf("%d ",_array[i][j]);
    }
    printf("\n");
  }  
  printf("How many edges you wanna put in this graph?\n");
  scanf("%d",&e);

  while(e--){
    printf("Input row_column of that edge\n");
    scanf("%d %d",&row,&column);
    _array[row][column] = 1;
  }

  for(i=0;i<n;i++){
    for(j=0; j<n; j++){
      printf("%d ",_array[i][j]);
    }
    printf("\n");
  }
  // printIt(_array,n);
  return 0;
}