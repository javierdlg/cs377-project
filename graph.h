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
private:
	vector<Edge*> input;
	int cost;
};

class Edge{
private:
	Node* source;
	Node* destination;
	int weight;
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