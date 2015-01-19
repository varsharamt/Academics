#ifndef Graph_class
#define Graph_class

#include<iostream>
#include <list>
#include <stack>
#include <iterator>
#include <queue>
#include <fstream>
using namespace std;
 

class Graph{
	int V;   
    	list<int> *adj;
	int *indegree;
	int *rankArr;
	int rank;
	queue<int> Q;

	public:
    		Graph(int V);
    		void addEdge(int v, int w);
		void topoSort();
		void addEdgeUndirected(int v, int w);
		void apFinder(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
		void ap();
 		void fillOrder(int v, bool visited[], stack<int> &Stack);
    		void DFSUtil(int v, bool visited[]);
    		void printSCCs();
    		Graph getTranspose();

	private: int get(list<int> lst, int position);
	private: bool contains(list<int>lst, int value);
};

void Graph:: addEdgeUndirected(int v, int w){
	 adj[v].push_back(w);
    	 adj[w].push_back(v); 
}

bool Graph:: contains(list<int>lst, int value){
	list<int>::iterator i;
    	for (i = lst.begin(); i != lst.end(); ++i){
		if(*i == value)
			return true;
	}
	return false;
}
int Graph:: get(list<int> lst, int position){
	list<int>::iterator i = lst.begin();
	advance(i,position);
	return *i;
}

Graph::Graph(int V){
	rank = 0;
	indegree = new int [V];
	rankArr = new int [V];
	for(int i=0; i < V; i++){
		indegree[i]=0;;
		rankArr[i]=-1;
	}
    	this->V = V;
   	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    	adj[v].push_back(w);
	indegree[w]++;
}


void Graph::topoSort(){
 ofstream myfile;
	myfile<<"Topological Sort";
	 myfile.open ("output.txt", ios::app);
	for(int i=0; i<V; i++){
		if(indegree[i]==0)
			Q.push(i);
	}
	while(Q.empty()==false){
		int curVertx = Q.front();
		Q.pop();
		rankArr[rank] = curVertx;
		rank++;
		list<int>::iterator itr;
    		for (itr = adj[curVertx].begin(); itr != adj[curVertx].end(); ++itr){
			if(--indegree[*itr] == 0)
				Q.push(*itr);
		}
	}
	char c;
	for(int i=0; i< V; i++){
		c = rankArr[i] + 65;
		myfile<<c<<" ";
	}
myfile.close();
}

void Graph::apFinder(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (!visited[v]){
            children++;
            parent[v] = u;
            apFinder(v, visited, disc, low, parent, ap);
            low[u]  = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void Graph::ap()
{
 ofstream myfile;
	 myfile.open ("output.txt", ios::app);
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];
    char c;
    for (int i = 0; i < V; i++){
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            apFinder(i, visited, disc, low, parent, ap);
    for (int i = 0; i < V; i++)
        if (ap[i] == true){
	    c = i + 65;
            myfile << c << " ";
	}
myfile.close();
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
    Stack.push(v);
}

Graph Graph::getTranspose(){
    Graph g(V);
    for (int v = 0; v < V; v++){
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::DFSUtil(int v, bool visited[]){
 ofstream myfile;
	 myfile.open ("output.txt", ios::app);
    char c;
    visited[v] = true;
    c = v + 65;
    myfile << c << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
myfile.close();
}

void Graph::printSCCs(){
        ofstream myfile;
myfile<<"Strong Connected Components";
	  myfile.open ("output.txt", ios::app);
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++)
        visited[i] = false;
    while (Stack.empty() == false){
        int v = Stack.top();
        Stack.pop();
        if (visited[v] == false){
	    myfile<<"{";
            gr.DFSUtil(v, visited);
	    myfile<<"}";
 	    myfile << endl;
        }
    }
myfile.close();
}

#endif
