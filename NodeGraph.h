/*
* Header file that contains Node, Edge, and other global variables
*/

// --------------
// Graph Classes
// --------------

#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

class Node;

class Edge{
public:
	Node* source;
	Node* destination;
	int weight;
public:
	Edge(Node* s, Node* d, int w) : source(s), destination(d), weight(w) {};
};

class Node{
public:
	vector<Edge*> input;
	int cost;
public:
	Node(int c) : cost(c) {};
	void addEdge(Edge* e){
		input.push_back(e);
	};
};

class threadObject{
public:
	pthread_t tid;
	vector<Node*> inputNodes;
	bool threadComplete = true;
	int threadID;
};

// -----------------
// Global Variables
// -----------------
bool threadCheck();
static vector<Node*> allNodes;
static vector<threadObject> threads;
static pthread_barrier_t barrier;
static pthread_barrier_t barrierCheck;
static pthread_barrier_t barrierCheck2;
static pthread_mutex_t mutex;