#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

typedef struct Node* node;
node root;
node createNewNode(int x){
  node current = (node) malloc(sizeof(node));
  current->data =x;
  current->left = current->right = NULL;
  return current;
}

node plant(node root, int x){
  if(root == NULL) root = createNewNode(x);
  else if(x <= root->data) root->left = plant(root->left, x);
  else if(x > root->data) root->right = plant(root->right, x);

  return root;
}

node minOf(node root){
  while(root->left != NULL) root = root->left;
  return root;
}

node deleteIt(node root, int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = deleteIt(root->left,data);
  else if(data > root->data) root->right = deleteIt(root->right,data);
  else{
    if(root->right == NULL && root->left == NULL){
      free(root);
      root = NULL;
    }
    else if(root->left == NULL){
      node temp = root;
      root = root->right;
      free(temp);
    }
    else if(root->right == NULL){
      node temp = root;
      root = root->left;
      free(temp);
    }
    else{
      node temp = minOf(root->right);
      root->data = temp->data;
      root->right = deleteIt(root->right,temp->data);
    }
  }
  return root;
}

int search(node root, int x){
  if(root == NULL) return 0;
  else if(x == root->data) return 1;
  else if(x <= root->data) return search(root->left, x);
  else if(x > root->data) return search(root->right, x);
  else return 0;
}

void postOrderTraversal(node root){
  if (root == NULL) return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  printf("%d ", root->data);
}

void inOrderTraversal(node root){
  if (root == NULL) return;
  inOrderTraversal(root->left);
  printf("%d ", root->data);  
  inOrderTraversal(root->right);
}
 
void preOrderTraversal(node root){
  if (root == NULL) return;
  printf("%d ", root->data);  
  preOrderTraversal(root->left);  
  preOrderTraversal(root->right);
}    


int main(){
  root = NULL;
  
  int k,t,n,ch;
  printf("Enter the number of inputs\n");
  scanf("%d",&n);
  printf("Enter the values\n");
  while(n--){
    scanf("%d",&t);
    root = plant(root, t);
}
  
  printf("you wanna search for any element?\n");
  scanf("%d",&k);
  scanf("%d",&ch);
  if(k==1){
    if(search(root,ch)) printf("found\n");
    else printf("not found");
  }
  preOrderTraversal(root);
  return 0;
}