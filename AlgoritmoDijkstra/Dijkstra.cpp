#include<iostream>
#include<queue>
#include<stack>
#include<limits>

using namespace std;

class Graph {
private:
      int **adjMatrix;
      int vertexCount;
	  // below attributes are for Prims

	  int *key;
	  int *distance;
	  int *parent;

public:
    Graph(int vertexCount);
    ~Graph();
	void addEdgeDirectedWeight(int i, int j, int cost);
	void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
	void initializeState();

	void showBasicInfo();
	void Dijkstra(int startNode);
	int isAllKeyTrue();  //0 means not MST, 1 means MST
	int findMinDistanceNode();

};
Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;

	this->key = new int[vertexCount];
	this->distance = new int[vertexCount];
	this->parent = new int[vertexCount];

    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = 0;
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}
void Graph::initializeState(){
	for(int i=0; i<this->vertexCount; i++){
		this->key[i] = 0; // 0=not in MST, 1=yes in MST
		this->distance[i]= INT_MAX; //initially distance is Max int
		this->parent[i] = -1;  // -1=no parent, else parent info
		                       //
	}
}
void Graph::addEdgeDirectedWeight(int i, int j, int cost) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = cost;
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
    }
}
int Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else{
		cout<<"Invalid vertex number.\n";
		return 0;
	}
}
void Graph::display(){
    int  u,v; //vertex
	cout<<"\t     ";
	for(u=0; u<vertexCount; u++){
		cout<<u<<" ";
	}
    for(u=0; u<vertexCount; u++) {
    	if(u<9)
    		cout << "\nNodo[0" << u+1 << "] -> ";
		else
        	cout << "\nNodo[" << u+1 << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << " " << adjMatrix[u][v];
        }
    }
    cout << "\n\n";
}
void Graph::showBasicInfo(){
	for(int i=0; i<vertexCount; i++){
		cout<<"node: "<<i<<" Key: "<<key[i]
			<<" distance: "<<distance[i]<<" parent: "<<parent[i]<<"\n";
	}
}
int Graph::isAllKeyTrue(){
	for(int i=0; i<this->vertexCount; i++){
		if(this->key[i]==0)
			return 0; // not MST yet
	}
	return 1; // MST done

}
int Graph::findMinDistanceNode(){
	int minDistant=INT_MAX;
	int minDistantNode;

	for(int i=0; i<vertexCount; i++) {
		if(minDistant > this->distance[i] && this->key[i]==0)
		{ //0 means that node is not in MST
			minDistantNode = i;
			minDistant = this->distance[i];
			//cout<<"min: "<<minDistantNode<<"\n";
		}
	}
	//cout<<"Min Distant Node: "<<minDistantNode<<" Cost: "<<minDistant<<"\n";
	return minDistantNode;
}

void Graph::Dijkstra(int startNode){
	cout<<"\nComienza el camino más corto de Dijkstra. . . \n";

	// initialization is done before call this method
	this->distance[startNode]=0; //start node's distance is 0
	int minDistanceNode, i;

	// 0 means Shortest path calculation is not done yet.
	while(!this->isAllKeyTrue()){
		//cout<<"-------------------------------\n";
		minDistanceNode = findMinDistanceNode();
		this->key[minDistanceNode] = 1;  // this node's shortes path is done

		cout<<"Trayectoria mas corta: "<<this->parent[minDistanceNode]<<" -> "
			<<minDistanceNode<<"\t,\tEl costo del nodo de destino es:"<<distance[minDistanceNode]<<"\n";


		for(i=0; i<vertexCount; i++){
			if(this->isEdge(minDistanceNode, i) && this->key[i]==0 ){
                //Below is the code for relaxation
				if(this->distance[i] > this->distance[minDistanceNode]
					                   + adjMatrix[minDistanceNode][i]){
					this->distance[i] = this->distance[minDistanceNode]
						                + adjMatrix[minDistanceNode][i];
					this->parent[i] = minDistanceNode;
				}
			}
		}
		//this->showBasicInfo(); // To visualize more clearly
		// you can comment this to only show the edges of MST
	}

}

int main(){
	Graph g(18);
	g.addEdgeDirectedWeight(0, 1, 230);
	g.addEdgeDirectedWeight(1, 2, 110);
	g.addEdgeDirectedWeight(2, 3, 600);
	g.addEdgeDirectedWeight(3, 10, 200);
	g.addEdgeDirectedWeight(3, 4, 600);
	g.addEdgeDirectedWeight(4, 5, 300);
	g.addEdgeDirectedWeight(5, 6, 400);
	g.addEdgeDirectedWeight(6, 7, 450);
	g.addEdgeDirectedWeight(7, 8, 400);
	g.addEdgeDirectedWeight(8, 9, 200);
	g.addEdgeDirectedWeight(1, 10, 600);
	g.addEdgeDirectedWeight(10, 4, 600);
	g.addEdgeDirectedWeight(4, 11, 450);
	g.addEdgeDirectedWeight(11, 12, 400);
	g.addEdgeDirectedWeight(12, 13, 150);
	g.addEdgeDirectedWeight(13, 8, 150);
	g.addEdgeDirectedWeight(0, 14, 600);
	g.addEdgeDirectedWeight(14, 15, 550);
	g.addEdgeDirectedWeight(15, 16, 500);
	g.addEdgeDirectedWeight(16, 17, 400);
	g.addEdgeDirectedWeight(17, 12, 200);
	g.addEdgeDirectedWeight(12, 18, 350);
	g.display();

	g.initializeState();
	int startNode = 0;
	//g.showBasicInfo();
	g.Dijkstra(startNode);
	//g.showBasicInfo();
	return 0;

}
