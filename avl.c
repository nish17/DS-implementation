#include <stdio.h>
#include <stdlib.h>

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
  return height(root->left) - height(root->right);
}
node rightRotate(node root){
  node newRoot = root->left;
  node temp = newRoot->right;
  newRoot->right = root;
  root->left = temp;

  root->height = max(height(root->left),height(root->right)) + 1;
  newRoot->height = max(height(newRoot->left),height(newRoot->right)) + 1;
  return newRoot;
}

node leftRotate(node root){
  node newRoot = root->right;
  node temp = newRoot->left;
  newRoot->left = root;
  root->right = temp;

  root->height = max(height(root->left), height(root->right))+1; 
  newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;

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
 
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    int balance = getBalance(root);
 
 
    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && data > root->left->data){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && data < root->right->data){
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
 
int main(){
  node root = NULL;
 
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}