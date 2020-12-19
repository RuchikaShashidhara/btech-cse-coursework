#include<stdio.h>
#include<stdlib.h>

int n;
int bfsVisited[100];
int dfsVisited[100];
int graph[100][100];
int queue[100];
int front, rear;

void createGraph();
void queueInsert(int v);
int queueDelete();
int queueIsEmpty();
void bfs(int v);
void dfs(int v);
int components();

int main(){
    int i, v;
    front = rear = -1;
    printf("\nEnter the no. of vertices: ");
    scanf("%d", &n);
    createGraph();
    printf("\nEnter the source vertex: ");
    scanf("%d", &v);
    printf("\nVertices traversed from vertex %d using bfs: ", v);
    bfs(v);
    printf("\nVertices traversed from vertex %d using dfs: ", v);
    dfs(v);
    int result;
    result = components();
    printf("\nThe number of components in the graph: %d", result);
    return 0;
}

void createGraph(){
    int i,j;
    while(1){
        printf("\nEnter source and destination: ");
        scanf("%d %d", &i, &j);
        if((i==0) && (j==0))
            return; 
        graph[i][j] = graph[j][i] = 1;
    }
}

void queueInsert(int v){
    rear++;
    queue[rear] = v;
    if(front == -1)
        front = 0;
}

int queueDelete(){
    int w;
    w = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return w;
}

int queueIsEmpty(){
    if(front == -1)
        return 1;
    return 0;
}

void bfs(int v){
    int w;
    bfsVisited[v] = 1;
    printf("%d ", v);
    while(!queueIsEmpty()){
        v = queueDelete();
        for(w=1; w<=n; w++){
            if ((graph[v][w] == 1) && (bfsVisited[w] == 0)){
                bfsVisited[w] = 1;
                printf("%d ", w);
                queueInsert(w);
            }
        }
    }
}

void dfs(int v){
    int w;
    dfsVisited[v] = 1;
    printf("%d ", v);
    for(w=1; w<=n; w++){
        if((graph[v][w] == 1) && (dfsVisited[w] == 0))
            dfs(w);
    }
}

int components(){
    int i;
    int label = 0;
    int visit[100];
    for(i=1; i<=n; i++)
        visit[i] = 0;
    for(i=1; i<=n; i++){
        if(visit[i] == 0){
            label++;
            dfs(i);
        }
    }
    return label;
}






