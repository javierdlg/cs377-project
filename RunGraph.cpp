/*
* CPP file that runs the parallelized Bellman-Ford algorithm
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "graph.h"

void loadGraph(const ifstream file){
	// read DIMACS file and add nodes/edges to the allNodes vector
	stringstream line;
	char id;
	int maxNodes, maxEdges;
	while (getline(file, line)){
		line >> id;
		if(id == 'c')
			continue;
		else if(id == 'p'){
			line >> id >> maxNodes >> maxEdges;
			allNodes.reserve(maxNodes);
		}
		else if(id == 'a'){

		}
	}
}

void divideWork(int threadNumber){
	// initialize threadObjects, assign nodes
}

void bellmanFord(threadObject* thread){
	for(int i = 0; i < thread->inputNodes.size(); ++i){

	}
}

void threadStart(void* args){
	args = (threadObject*)args;
	for(int i = 0; i < (allNodes.size() - 1)/argv[2]; ++i){
		bellmanFord(args);
	}
}

int main(int args char* argv[]){
	ifstream file(argv[0]);
	loadGraph(file);

	divideWork(argv[2]);
	// Start threads

	for(int i = 0; i < argv[2]; ++i){
		//pthread create
		threadStart(&threads[i]);
	}

	// pthread syncronize (barrier)

	// read and print graph
}