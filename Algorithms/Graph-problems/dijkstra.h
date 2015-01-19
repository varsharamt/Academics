#ifndef Dijkstra_class
#define Dijkstra_class

#include <iostream>
#include <vector>
#include <string>
#include <list>
 
#include <limits> // for numeric_limits
 
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
#include <fstream>
 
typedef int vertex_t;
typedef double weight_t;

using namespace std;

const weight_t max_weight = numeric_limits<double>::infinity();
	struct neighbor {
	    vertex_t target;
	    weight_t weight;
	    neighbor(vertex_t arg_target, weight_t arg_weight)
		: target(arg_target), weight(arg_weight) { }
	};
	 
	typedef vector<vector<neighbor> > adjacency_list_t;
	adjacency_list_t adjacency_list(7);
class Dijkstra{
	public:
	void DijkstraComputePaths(vertex_t source, const adjacency_list_t &adjacency_list, vector<weight_t> &min_distance, vector<vertex_t> &previous);
	list<vertex_t> DijkstraGetShortestPathTo(vertex_t vertex, const vector<vertex_t> &previous);
	Dijkstra(int V);
	void addEdge(int v, int w, int weight);
	void findShortestPath();
};

void Dijkstra:: findShortestPath(){
	ofstream myfile;
	 myfile.open ("output.txt", ios::app);
myfile<<endl;
myfile<<endl;
	vector<weight_t> min_distance;
	vector<vertex_t> previous;
	DijkstraComputePaths(0, adjacency_list, min_distance, previous);
	char c;
	for (int i=0; i < adjacency_list.size(); i++) {
		c = i + 65;
		myfile << "Distance from A to " << c <<": " << min_distance[i] << endl;
		list<vertex_t> path = DijkstraGetShortestPathTo(i, previous);
		//cout << "Path : ";
		myfile<< "Path : ";
	    	//copy(path.begin(), path.end(), ostream_iterator<vertex_t>(cout, " "));
		list<vertex_t>::iterator itr;
    		for (itr = path.begin(); itr != path.end(); ++itr){
			c = *itr + 65;
			myfile<<c<< " ";
		}
	    	myfile<< endl;
		myfile<< endl;
	}
myfile.close();
}

void Dijkstra:: addEdge(int v, int w, int weight){
	adjacency_list[v].push_back(neighbor(w, weight));
}

Dijkstra::Dijkstra(int V){
	
}

list<vertex_t> Dijkstra:: DijkstraGetShortestPathTo(vertex_t vertex, const vector<vertex_t> &previous){
	    list<vertex_t> path;
	    for ( ; vertex != -1; vertex = previous[vertex])
		path.push_front(vertex);
	    return path;
}

void Dijkstra:: DijkstraComputePaths(vertex_t source, const adjacency_list_t &adjacency_list, vector<weight_t> &min_distance, vector<vertex_t> &previous){
	int n = adjacency_list.size();
	min_distance.clear();
	min_distance.resize(n, max_weight);
	min_distance[source] = 0;
	previous.clear();
	previous.resize(n, -1);
	set<pair<weight_t, vertex_t> > vertex_queue;
	vertex_queue.insert(make_pair(min_distance[source], source));
	while (!vertex_queue.empty()){
		weight_t dist = vertex_queue.begin()->first;
		vertex_t u = vertex_queue.begin()->second;
		vertex_queue.erase(vertex_queue.begin());
	 
		// Visit each edge exiting u
		const vector<neighbor> &neighbors = adjacency_list[u];
		for (vector<neighbor>::const_iterator neighbor_iter = neighbors.begin(); neighbor_iter != neighbors.end(); neighbor_iter++){
			vertex_t v = neighbor_iter->target;
		    	weight_t weight = neighbor_iter->weight;
		    	weight_t distance_through_u = dist + weight;
		    	if (distance_through_u < min_distance[v]) {
				vertex_queue.erase(make_pair(min_distance[v], v));
				min_distance[v] = distance_through_u;
				previous[v] = u;
				vertex_queue.insert(make_pair(min_distance[v], v));
		    	}
	 
		}
	}
}

#endif
