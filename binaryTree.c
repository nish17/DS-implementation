#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *left, *right;
};

typedef struct Node* node;
node root;

node createNewNode(int data){
  node current = (node)malloc(sizeof(node));
  current->data = data;
  current->left = current->right = NULL;
  return current;
}

void inOrder(node root){
  if( root != NULL){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}

int main(){
  root = NULL;

  root = createNewNode(10);
  root->left = createNewNode(99);
  root->right = createNewNode(2);
  root->left->left = createNewNode(17);
  root->right->right = createNewNode(171);

  printf("    %d    \n",root->data);
  printf("   /   \\  \n");
  node temp1 = root->left;
  node temp2 = root->right;
  printf("  %d    %d  \n",temp1->data,temp2->data);
  printf(" /        \\  \n");
  printf("%d         %d  \n",temp1->left->data,temp2->right->data);

  return 0;
}