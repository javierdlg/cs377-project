#include "graph.h"
#include <iostream>
#include <vector>

void loadGraph(istream& r){
	// read DIMACS file and add nodes/edges to the allNodes vector
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
	loadGraph(argv[1]);
	divideWork(argv[2]);
	// Start threads

	for(int i = 0; i < argv[2]; ++i){
		//pthread create
		threadStart(&threads[i]);
	}

	// pthread syncronize (barrier)

	// read and print graph
}