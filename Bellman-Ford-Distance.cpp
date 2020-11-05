#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <climits>

#define infinity INT_MAX


typedef struct Edge{
    int src;
    int dest;
    int weight;
} Edge;


using namespace std;

class Graph{
    private:
        int ** adjMatrix;
        vector<Edge> edges;
        int numOfVertex;
        int * dist;
    public:
        Graph(int numOfVertex);
        void addEdge(int v1, int v2,int weight);
        void printGraph();
        void initilizeDist(int src);
        void relax(int u, int v);
        int bellmanFord(int src,int dest);
        void printDistances();

};
Graph::Graph(int numOfVertex){
    this->numOfVertex = numOfVertex;
    this->adjMatrix = new int*[this->numOfVertex];
    dist = new int[this->numOfVertex];
    for(int i = 0 ; i < this->numOfVertex ; i++){  
        this->adjMatrix[i] = new int[this->numOfVertex];
        memset(adjMatrix[i],0,sizeof(int)*this->numOfVertex);
    }
}

void Graph::addEdge(int v1, int v2,int weight){
    adjMatrix[v1][v2] = weight;
    Edge edge;
    edge.src = v1;
    edge.dest = v2;
    edge.weight =  weight;
    edges.push_back(edge);
}

void Graph::printGraph(){
    for(int i = 0;i<this->numOfVertex;i++){
        for(int j = 0;j<this->numOfVertex;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::initilizeDist(int src){
    for(int i = 0;i<this->numOfVertex;i++){
        dist[i] = infinity; 
    }
    dist[src] = 0;
}

void Graph::relax(int u, int v){
    int weightUV = adjMatrix[u][v];
    if(dist[v]>dist[u] + weightUV){
        dist[v] = dist[u] + weightUV;
    }
}

int Graph::bellmanFord(int src, int dest){
    initilizeDist(src);
    for(int i = 0;i<this->numOfVertex-1;i++){
        for(Edge &edge : edges){
            relax(edge.src,edge.dest);
        }
    }
    return dist[dest];
}

void Graph::printDistances(){
    for(int i= 0;i<this->numOfVertex;i++){
        cout<<dist[i]<<endl;
    }
}

int main(){
    int numOfVertex, numOfEdges, u, v, weight;
    cin>>numOfVertex>>numOfEdges;
    Graph g(numOfVertex);
    for(int i = 0;i<numOfEdges;i++){
        cin>>u>>v>>weight;
        g.addEdge(u,v,weight);
    }
    cin>>u>>v;
    cout<<g.bellmanFord(u,v)<<endl;
}