#ifndef Kruskal_class
#define Kruskal_class

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
struct Edge
{
    int src, dest, weight;
};

struct GraphKrusk{
    int V, E;
    struct Edge* edge;
};

struct GraphKrusk* createGraph(int V, int E){
    struct GraphKrusk* graph = (struct GraphKrusk*) malloc( sizeof(struct GraphKrusk) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

class KruskalClass{
	public:
		KruskalClass(int V);
		void addEdgeKrusk(int e,int s,int d, int w);
		void initializeKrusk(int V,int E);
		void Union(struct subset subsets[], int x, int y);
		int find(struct subset subsets[], int i);
		void KruskalMST();
};

struct GraphKrusk* graph;

KruskalClass::KruskalClass(int V){
	
}

int KruskalClass:: find(struct subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void KruskalClass:: Union(struct subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void KruskalClass::addEdgeKrusk(int e,int s,int d, int w){
	graph->edge[e].src=s;
	graph->edge[e].dest=d;
	graph->edge[e].weight=w;
}

void KruskalClass::initializeKrusk(int V,int E){
	graph = createGraph(V, E);
}

void KruskalClass::KruskalMST()
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    int totalCost = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1){
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    ofstream myfile;
    myfile.open ("output.txt", ios::app);
myfile<<endl;
myfile<<endl;myfile<<endl;
myfile<<endl;
   // printf("");
   
  
    char c1,c2;
    for (i = 0; i < e; ++i){
	c1 = result[i].src + 65;
	c2 = result[i].dest + 65;
	myfile<<"("<<c1<<","<<c2<<") ";
//	cout<<"("<<c1<<","<<c2<<") ";
	totalCost += result[i].weight;
        //printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    //cout<<endl<<"Total cost is : " <<totalCost<<endl;
	myfile<<endl<<"Total cost is : " <<totalCost<<endl;
    myfile.close();
    return;
}

/*int main(){
	KruskalClass krus(7);
	krus.addEdgeKrusk(1,0,2,6);
	krus.addEdgeKrusk(2,0,3,5);
	krus.addEdgeKrusk(3,1,3,15);
	krus.addEdgeKrusk(4,2,3,4);
}*/
#endif
