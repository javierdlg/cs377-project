/*
* Header file that contains Node, Edge, and other global variables
*/

// --------------
// Graph Classes
// --------------

#include <iostream>
#include <vector>
#include <pthread.h>

class Node{
public:
	vector<Edge*> input;
	int cost;
public:
	Node(c) : cost(c);
	void addEdge(Edge* e){
		input.push_back(e);
	};
};

class Edge{
public:
	Node* source;
	Node* destination;
	int weight;
public:
	Egde(Node* s, Node* d, int w) : source(s), destination(d), weight(d);
};

class threadObject{
private:
	pthread_t tid;
	vector<Node*> inputNodes;
};

// -----------------
// Global Variables
// -----------------

static vector<Node*> allNodes;
static vector<threadObject> threads;
static pthread_barrier_t barrier;