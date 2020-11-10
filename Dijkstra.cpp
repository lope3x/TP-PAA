#include <iostream>
#include <cstring>
#include <vector>
#include <climits> 

using namespace std;

class PriorityQueue{
    private:
        vector<int> priorityQueue;
        vector<int> valuesOfRemovedKeys;
    public:
        /*Retornar a menor chave da fila*/
        int getMinKey(){
            int min  = INT_MAX;
            for(int i = 0;i< priorityQueue.size(); i++){
                if(priorityQueue[i]<min&&priorityQueue[i]!=-1){
                    min = priorityQueue[i];
                }
            }
            return min;
        }
        /*Extrai a menor chave a fila e atualiza a fila*/
        int extractMinKey(){
            int min  = 0;
            for(int i = 0;i< priorityQueue.size(); i++){
                if(priorityQueue[min]==-1){
                    min = i;
                }
                else if(priorityQueue[i]<priorityQueue[min]&&priorityQueue[i]!=-1){
                    min = i;
                }
            }
            valuesOfRemovedKeys[min] = priorityQueue[min];
            priorityQueue[min] = -1;
            return min;
        }
        /*Altera o valor da chave passada para o valor passado por parametro*/
        void decreaseKey(int vertex, int value){
            priorityQueue[vertex] = value;
        }
        /*Verifica se a chave passada ainda está na fila*/
        bool keyIsOnQueue(int vertex){
            return priorityQueue[vertex]!=-1;
        }
        /*Insere o valor passado na fila*/
        void insertKey(int value){
            priorityQueue.push_back(value);
            valuesOfRemovedKeys.push_back(0);//inicializa o vetor de chaves removidas
        }
        /*Retorna o valor da chave passada por parametro*/
        int getKeyValue(int vertex){
            return keyIsOnQueue(vertex) ? priorityQueue[vertex] : valuesOfRemovedKeys[vertex];//se a chave já foi removida, retorna seu antigo valor
        }
        /*Verifica se a fila esta vazia*/
        bool isEmpty(){
            for(int i=0;i<priorityQueue.size() ; i++){
                if(keyIsOnQueue(i)){
                    return false;
                }
            }
            return true;
        }
};


class Graph{
    private:
        int numOfVertex;
        int ** adjMatrix;
    public:
        Graph(int numOfVertex){
            this->numOfVertex = numOfVertex+1;
            this->adjMatrix = new int*[this->numOfVertex];
            for(int i = 0 ; i < this->numOfVertex ; i++){
                this->adjMatrix[i] = new int[this->numOfVertex];
                memset(adjMatrix[i],0,sizeof(int)*this->numOfVertex);
            }
        }
        /*
           Insere uma aresta bi direcional de v1 a v2 com o valor peso
        */
        void insertBiEdge(int v1 , int v2,int weight){
            this->adjMatrix[v1][v2] = weight;
            this->adjMatrix[v2][v1] = weight;
        }
        /*
            Insere uma aresta de v1 a v2 com o valor peso
        */
        void insertEdge(int v1,int v2,int weight){
            this->adjMatrix[v1][v2] = weight;
        }
        /*
            Gera a distância do vértice start ao vértice end
        */
        int dijkstra(int start, int end){ 
            PriorityQueue priorityQueue;    
            for(int i = 0; i< numOfVertex ; i++){
                priorityQueue.insertKey(INT_MAX);
            }
            priorityQueue.decreaseKey(start,0);
            int sizePath = 0;
            while(!priorityQueue.isEmpty()&&priorityQueue.keyIsOnQueue(end)){
                int u = priorityQueue.extractMinKey();
                for(int i=0 ; i< this->numOfVertex ; i++){
                    int weightUI = adjMatrix[u][i];
                    int keyValueI = priorityQueue.getKeyValue(i);
                    int keyValueU = priorityQueue.getKeyValue(u);
                    int possiblePath = keyValueU+weightUI;
                    if(i!=u&&priorityQueue.keyIsOnQueue(i)&&keyValueI>possiblePath&&weightUI!=0){
                        priorityQueue.decreaseKey(i,possiblePath);
                    }
                }
            }
            return priorityQueue.getKeyValue(end);
        }
};


int main(){
    int vertex,edges,v,w,p,start,end;
    cin>>vertex>>edges;
    Graph * graph = new Graph(vertex);
    for(int i=0;i<edges;i++){
        cin>>v>>w>>p;
        graph->insertEdge(v,w,p);
    }
        cin>>start>>end;
        cout<<graph->dijkstra(start,end)<<endl;
}