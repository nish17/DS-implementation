#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COUNT 10
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};
typedef struct Node* node;
node root;
node createNewNode(int data){
  node child = (node)malloc(sizeof(node));
  child->data = data;
  child->left = child->right = NULL;
  return child;
}

node insert(node root, int data){
  if(root == NULL){
    root = createNewNode(data);
  }
  else if(data <= root->data){
    root->left = insert(root->left, data);
  }
  else {
    root->right = insert(root->right,data);
  }
  return root;
}

bool search(node root, int data){
  if(root == NULL){
    printf("%d not found\n",data);
    return 0;
  }
  else if(root->data == data){
    printf("%d found\n",data);
    return 1;
  }
  else if(data <= root->data) return search(root->left, data);
  else return search(root->right, data);
}

void print2D(node root, int space){
  int i;
  if(root == NULL) return;

  space += COUNT;

  print2D(root->right, space);
  printf("\n");
  for(i=COUNT; i<space; i++) printf(" ");
  printf("%d\n",root->data);
  print2D(root->left, space);
}
void print2(node root){
  print2D(root, 0);
}
int main(){
  root = NULL;
  int t,n,c,k;
  printf("Number of inputs: ");
  scanf("%d",&t);
  printf("Enter the value ");
  while(t--){
    scanf("%d",&n);
    root = insert(root,n);
  }
  printf("sadf\n");
  scanf("%d",&c);
  if(c==1) print2(root);

  // printf("You wanna search for any element? if yes press 1\n");
  // scanf("%d",&c);
  // if(c==1){
  //   printf("Enter the value u wanna search\n");
  //   scanf("%d",&k);
  //   search(root,k);
  // }
  // else exit(-1); 
}