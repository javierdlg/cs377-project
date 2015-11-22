#include "graph.h"
#include <iostream>
#include <vector>
#include <climits>

void loadGraph(istream& r){
	// read DIMACS file and add nodes/edges to the allNodes vector
}

void divideWork(int threadNumber){
	// initialize threadObjects, assign nodes
	for(i = 0; i < threadNumber; ++i){
		for(j = i; j<allNodes.size(); j+=threadNumber){
			threads[i].inputNodes.push_back(allNodes[j]);
		}
	}
}

void bellmanFord(threadObject* thread){
	
	for(int i = 0; i < thread->inputNodes.size(); ++i){
		Node * node = thread->inputNodes[i];
		for(int j = 0; j < node->input.size(); ++j){
			Edge *edge = node->input[j];
			if(edge->source->cost != INT_MAX && edge->source->cost < node->cost)
				node->cost = edge->source->cost;
		}		
	}
	pthread_barrier_wait(&barrier);
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
	pthread_barrier_init(&barrier, null, argv[2]);
	for(int i = 0; i < argv[2]; ++i){
		//pthread create
		pthread_create (&threads[i]->tid, NULL, threadStart, &threads[i]);
	}

	// pthread syncronize (barrier)

	// read and print graph
}