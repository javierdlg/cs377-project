#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include "time.h"
#include "graph.h"
#define BILLION 1E9
using namespace std;

void loadGraph(const char* fileName){
	// read DIMACS file and add nodes/edges to the allNodes vector
	ifstream in(fileName);
	string line;
	stringstream ss;
	int maxNodes, nodeSource, nodeDestination, weight;
	while (getline(in, line)){
		if(line.front() == 'c')
			continue;
		else if(line.front() == 'p'){
			istringstream iss(line);
			string s;
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			maxNodes = atoi(s.c_str());
			getline(iss, s, ' ');
			allNodes.reserve(maxNodes);
			for(int i = 0; i < maxNodes; ++i)
			{
				Node *node = new Node(INT_MAX);

				allNodes.push_back(node);
			}
			ss.str(string());
		}
		else if(line.front() == 'a'){
			istringstream iss(line);
			string s;
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			nodeSource = atoi(s.c_str()) - 1;
			getline(iss, s, ' ');
			nodeDestination = atoi(s.c_str()) - 1;
			getline(iss, s, ' ');
			weight = atoi(s.c_str());
			Edge *e = new Edge(allNodes[nodeSource], allNodes[nodeDestination], weight);
			allNodes[nodeDestination]->addEdge(e);
			ss.str(string());
		}
	}
	in.close();
}


void bellmanFord(){
	for(unsigned int i = 0; i < allNodes.size(); ++i){
		Node * node = allNodes[i];
		for(unsigned int j = 0; j < node->input.size(); ++j){
			Edge *edge = node->input[j];
			if(edge->source->cost != INT_MAX && (edge->source->cost + edge->weight) < node->cost)
				node->cost = edge->source->cost + edge->weight;
			
		}		
	}
}

void Start(){
	for(unsigned int i = 0; i < (allNodes.size() - 1); ++i){
		bellmanFord();
	}
}

void graphPrint(){
	for(unsigned int i = 0; i < allNodes.size(); ++i){
		cout << allNodes[i]->cost <<endl;
	}
}

/*
* Program runs as the following:
* graphTest "Filename" ThreadCount
*/
int main(int args, char* argv[]){



	loadGraph(argv[1]);
	allNodes[0]->cost = 0;


	timespec time1, time2;
	clock_gettime(CLOCK_MONOTONIC, &time1);
	Start();

	clock_gettime(CLOCK_MONOTONIC, &time2);
	timespec temp;
	if((time2.tv_nsec - time1.tv_nsec)<0)
	  {
	    temp.tv_sec = time2.tv_sec - time1.tv_sec-1;
	    temp.tv_nsec = 1000000000+time2.tv_nsec-time1.tv_nsec;
	  }
	else
	  {
	    temp.tv_sec = time2.tv_sec - time1.tv_sec;
	    temp.tv_nsec = time2.tv_nsec - time1.tv_nsec;
	  }
	cout << "Time (from gettime): " << temp.tv_sec << ":" << temp.tv_nsec << endl;
/*
* Clock end
*/
	// read and print graph
	graphPrint();
}
