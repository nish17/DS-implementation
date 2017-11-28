#include <stdio.h>
#include <stdlib.h>
 
struct node{
  int vertex;
  struct node* next;
};

struct Graph{
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
	newNode->next = NULL;
  return newNode;
}
 
struct Graph* createGraph(int vertices){
  int i;
	struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
 	graph->adjLists = malloc(vertices * sizeof(struct node*));
 	for (i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
 	return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest){
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
 	newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
 
void printGraph(struct Graph* graph){
  int v;
  for (v = 0; v < graph->numVertices; v++){
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp){
      printf("%d -> ", temp->vertex);
      temp = temp->next;
      if(temp == NULL) printf("NULL ");
    }
    printf("\n");
  }
}
int main(){
  int t=0,n,src,dest;
  printf("Input number of vertices\n");
  scanf("%d",&n);
  struct Graph* graph = createGraph(n);
  printf("Input source and destination edges\n");
  
  while(t<10){
    scanf("%d %d",&src,&dest);
    addEdge(graph, src, dest);
    t++;
  }
  printGraph(graph);
  return 0;
}
