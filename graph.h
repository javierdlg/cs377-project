/*
* Header file that contains Node, Edge, and other global variables
*/

// --------------
// Graph Classes
// --------------

#include <iostream>
#include <vector>


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


// ----------------- 
// Global Variables
// -----------------

static vector<Node*> allNodes;
static vector<Edge*> allEdges;
