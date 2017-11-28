#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct Node{
  int data,height;
  struct Node* left;
  struct Node* right;
};
typedef struct Node* node;
int getMax(int a, int b){
  return (a > b) ? a:b;
}

int getHeight(node root){
  if(root == NULL) return 0;
  return root->height;
}

node createNode(int data){
  node current = (node)malloc(sizeof(node));
  current->data = data;
  current->left = current->right = NULL;
  current->height = 1;
  return current;
}

node getBalance(node root){
  if(root == NULL) return 0;
  return getHeight(root->left) - getHeight(root->right);
}
node rightRotate(node root){
  node newRoot = root->left;
  node temp = newRoot->right;
  newRoot->right = root;
  root->left = temp;

  root->height = getMax(getHeight(root->left),getHeight(root->right)) + 1;
  newRoot->height = getMax(getHeight(newRoot->left),getHeight(newRoot->right)) + 1;
  return newRoot;
}

node leftRotate(node root){
  node newRoot = root->right;
  node temp = newRoot->left;
  newRoot->left = root;
  root->right = temp;

  root->height = getMax(getHeight(root->left), getHeight(root->right))+1; 
  newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right))+1;

  return newRoot;
}
node insert(node root, int data){
    
    if (root == NULL)
        return(createNode(data));
 
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else 
        return root;
 
    root->height = 1 + getMax(getHeight(root->left),
                           getHeight(root->right));
 
    int balance = getBalance(root);
 
 
    
    if (balance > 1){// && data < root->left->data)
        return rightRotate(root);
    }
    
    if (balance < -1){// && data > root->right->data)
        return leftRotate(root);
    }
    
    if (balance > 1){ //&& data > root->left->data){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    
    if (balance < -1){// && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
void preOrder(node root)
{
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
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
  node root = NULL;
    
  int t,n;
  printf("Enter the number elements\n");
  scanf("%d",&t);
  printf("Enter the elements:\n");
  while(t--){
    scanf("%d",&n);
    root = insert(root, n);
  }  
  
//   root = insert(root, 20);
//   root = insert(root, 30);
//   root = insert(root, 40);
//   root = insert(root, 50);
//   root = insert(root, 25);
 
  printf("after rotation Traversal:\ntree is \n");
  preOrder(root);
  print2(root);
  return 0;
}