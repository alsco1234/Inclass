#include <iostream>
#define TRUE    true
#define FALSE   false
#define MAX_VERTICES    10;

short int visited[MAX_VERTICES];
void dfs(int v, label){
    node_pointer w;
    if(visited[v]) return;

    visited[v]=TRUE;
    my_label=label;
    for(w = graph[v]; w; w=w->link)
    /*graph[] : headnodes */
    if(!visited[w->vertex])
    dfs(w->vertex,label);
}

queue<int> graphQ;
void bfs (int v){
    node_pointer w;

    d[v]=0;
    visited[v] = TRUE;
    graphQ.Enqueue(v);
    while(!QueueEmpty()){
        v = graphQ.Dequeue();
        for(w = graph[v]; w; w = w->link)
        if(!visited[w->vertex]){
            d[w] = d[v]+1;
            visited[w->vertex] = TRUE;
            graphQ.Enqueue(w->vertex);
            }//if
    }//while
}//bfs

int main(void){
    cout << v;
    visited[v] = TRUE;
    cout << v;
    graphQ.Enqueue(v);
    while(!QueueEmpty()){
        v = graphQ.Dequeue();
        for(w = graph[v]; w; w=w->link){
            if(!visited[w->vertex]){
                cout << w->vertex;
                visited[w->vertex] = TRUE;
                graphQ.Enqueue(w->vertex);
                }
            } //if
    } //while
}