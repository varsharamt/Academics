#include "graph.h"
#include "dijkstra.h"
#include "kruskal.h"

#include <fstream>
#include <sstream>

using namespace std;
int main(){

	Graph g(7);
	Graph gc1(7);
	Graph gc2(7);
	Graph sc(7);

	Dijkstra obj(7);
	KruskalClass krus(7);
	krus.initializeKrusk(7,24);
	ifstream file("input.txt");
	string str;
	bool gotFirst,toIncrRowCount=true;
	int firstInt, colIter=0,rowCount=-1,colCount=0,n,graphIndicator=-1,w,dij_v, edg_counter=0;

	while(getline(file, str)){
		istringstream iss(str);
		gotFirst=true;
		toIncrRowCount=true;
		while(iss >> n){
			if(toIncrRowCount){
				rowCount++;
				toIncrRowCount=false;
			}
			if(true==gotFirst){
				firstInt = n;
				colIter = 0;
				if(0==rowCount){
					graphIndicator++;
				}
				gotFirst=false;
				if(0 == firstInt){
					obj.addEdge(rowCount,rowCount,0);
					gotFirst=true;
				}
			}
			else{
				 if(0==graphIndicator){
					colIter++;
					if(0 != (colIter%2)){
						g.addEdge(rowCount,n-1);
					}
					if(6==rowCount){
						rowCount=-1;
					}
				}
				else if(1==graphIndicator){
					colIter++;
					if(rowCount!=-1){
						dij_v = rowCount;
					}
					if(0 != (colIter%2)){
						w=n-1;
					}
					if(0==(colIter%2)){
						obj.addEdge(dij_v,w,n);
					}
					if(6==rowCount){
						rowCount=-1;
					}
				}
				else if(2==graphIndicator){
					colIter++;
					if(rowCount!=-1){
						dij_v = rowCount;
					}
					if(0 != (colIter%2)){
						w=n-1;
					}
					if(0==(colIter%2)){
						krus.addEdgeKrusk(edg_counter,dij_v,w,n);
						edg_counter++;
					}
					if(6==rowCount){
						rowCount=-1;
					}
				}
				else if(3==graphIndicator || 4==graphIndicator){
					colIter++;
					if(0 != (colIter%2)){
						if(3==graphIndicator)						
							gc1.addEdge(rowCount,n-1);
						else
							gc2.addEdge(rowCount,n-1);
					}
					if(6==rowCount){
						rowCount=-2;
					}
				}
				else if(5==graphIndicator){
					colIter++;
					if(0 != (colIter%2)){
						sc.addEdge(rowCount,n-1);
					}
					if(6==rowCount){
						rowCount=-1;
					}
				}
			}			
		}
	}

	//myfile<<endl<<endl;
	//myfile <<"Topological Sort of the 1st graph"<<endl;
	g.topoSort();
	//myfile<<endl<<endl;

	//myfile << "Dijsktra's algorithm for single source shortest path"<<endl;
	obj.findShortestPath();
	//myfile<<endl<<endl;

	//myfile << "Kruskal's algorithm"<<endl;
	krus.KruskalMST();
	//myfile<<endl<<endl;

	//myfile <<"Articluation points the 4th graph"<<endl;
	gc1.ap();
	//myfile<<endl<<endl;

	//myfile << "Following is a Articluation points the 5th graph"<<endl;
	gc2.ap();
	//myfile<<endl<<endl;

	//myfile << "Following is a Strongly Connected points the 6th graph"<<endl;
	sc.printSCCs();
	//myfile<<endl<<endl;
//myfile.close();
	return 0;
}
