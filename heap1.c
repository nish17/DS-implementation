#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j){
  int* temp;
  temp = *i;
  *i = *j;
  *j = temp;
  return;
}

void heapify(int arr[], int n, int i){
  int high = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l < n && arr[l] > arr[high]) high = l;
  if(r < n && arr[r] > arr[high]) high = r;
  if(high != i){
    int *l = arr[i];
    int *r = arr[high];
    swap(l, r);
    heapify(arr,n,i);
  }
}

void heapSort(int arr, int n){
  for(int i = n-1/2; i>=0; i--) heapify(arr,n,i);
  for(int i=n-1; i>=0; i--){
    int *l = arr[0];
    int *r = arr[i];
    swap(l, r);
    heapify(arr,n,0);
  }
}

void print(int arr[], int n)
{
    for (int i=0; i<n; ++i)
      printf("%d ",arr[i]);
    printf("\n");
}


int main(){
  int arr[] = {2, 0, 31, 55, 23, 71};
  int n = sizeof(arr)/sizeof(arr[0]);
  heapSort(arr, n);
  printf("After sorting...\n");
  print(arr, n);
  return 0;
}