//============================================================================
// Name        : rodgersA10.cpp
// Author      : Tyler ROdgers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;



struct Vertex{  //vertecies
    int vertexValue;
    bool visited;
    vector<int>neighbor;
};


void buildGraph(vector<Vertex>&graph){  //builds graph
    fstream file;
    file.open("data.txt");
    if(!file){
        cout<<"File couldn't be opened!!";
        exit(0);
    }
    int count=0;
    string line;
    while(getline(file,line))
       count++;
    file.close();
    file.open("data.txt");
    for(int i=0;i<count;i++){   //for each vertex

        int vertexValue;    //reads value
        file>>vertexValue;
        vector<int>neighbor;
        int x;
        while(file>>x && x!=-1) //reads all neighbor till -1
            neighbor.push_back(x);
        graph.push_back({vertexValue,false,neighbor}); //i don't know why this isn't working, it worked earlier in my testing


        cout<<"Vertex number "<<i<<" value "<<vertexValue<<" neighbors->";
        for(int i:neighbor){  //????????????
        	cout<<i<<" ";
        }

        cout<<endl;
    }
}



void dftInternal(vector<Vertex>&graph,int vertex){
    if(graph[vertex].visited)
        return;
    graph[vertex].visited=true; //marks visited
    cout<<graph[vertex].vertexValue<<" ";
    for(int i:graph[vertex].neighbor){ //i don't know why this isn't working
    	dftInternal(graph,i);
    }

}


void dft(vector<Vertex>&graph){
    cout<<"Depth-first Traversal:\n";
    for(int i=0;i<graph.size();i++){}

}


void bft(vector<Vertex>&graph){
    cout<<"\nBreadth-first Traversal:\n";
    for(int i=0;i<graph.size();i++)
        graph[i].visited=false;
    queue<int>q;
    q.push(0);
    graph[0].visited=true;
    label:
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i:graph[cur].neighbor){ //why doesn't this work???? c'mon tyler. do better.
        	if(!graph[i].visited){
        		graph[i].visited = true;
        		q.push(i);
        	}
        }
    }
    for(int i=0;i<graph.size();i++){
        if(!graph[i].visited){
            graph[i].visited=true;
            q.push(i);
            goto label;
        }
    }
}


int main(){
    //function calling
    vector<Vertex>graph;
    buildGraph(graph);
    dft(graph);
    bft(graph);

}

    // prints BFS traversal
    /*void BFS(T src){
    	queue <T> q;
    	map <T, bool> visited; //using a hash map to check if the nodes have been visited

    	q.push(src);
    	visited[src] = true;

    	while(!q.empty()){
    		T node = q.front();
    		cout << node << "";
    		q.pop();

    		for (T neighbour: adjList[node]){
    			if (!visited[neighbour]){
    				q.push(neighbour);
    				visited[neighbour] = true;
    			}
    		}
    	}
    }*/

/*
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
*/
