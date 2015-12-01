#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <fstream>
#include <string>

#include "graph.h"

using namespace std;

static int threadCount;

void loadGraph(const char* fileName){
	// read DIMACS file and add nodes/edges to the allNodes vector
	ifstream in(fileName);
	string line;
	stringstream ss;
	int maxNodes, maxEdges, nodeSource, nodeDestination, edge, weight;
	while (getline(in, line)){
		if(line.front() == 'c')
			continue;
		else if(line.front() == 'p'){
			ss << line << line << line;
			ss >> maxNodes >> maxEdges;
			allNodes.reserve(maxNodes);
			ss.str(string());
		}
		else if(line.front() == 'a'){
			ss << line << line << line;
			ss >>  weight >> nodeDestination >> nodeSource;
			Edge e(allNodes[nodeSource], allNodes[nodeDestination], weight);
			allNodes[nodeDestination]->addEdge(&e);
			ss.str(string());
		}
	}
	in.close();
}

void divideWork(int threadNumber){
	// initialize threadObjects, assign nodes
	threads.reserve(threadNumber);
	for(int i = 0; i < threadNumber; ++i){
		threadObject thread;
		threads.push_back(thread);
	}
	for(int i = 0; i < threadNumber; ++i){
		for(int j = i; j < allNodes.size(); j += threadNumber){
			threads[i].inputNodes.push_back(allNodes[j]);
		}
	}
	for (int i = allNodes.size() - (allNodes.size()%threadNumber); i < allNodes.size(); ++i){
		threads[threadNumber-1].inputNodes.push_back(allNodes[i]);
	}
}

void bellmanFord(threadObject* thread){
	
	for(int i = 0; i < thread->inputNodes.size(); ++i){
		Node * node = thread->inputNodes[i];
		for(int j = 0; j < node->input.size(); ++j){
			Edge *edge = node->input[j];
			if(edge->source->cost != INT_MAX && (edge->source->cost + edge->weight) < node->cost)
				node->cost = edge->source->cost + edge->weight;
		}		
	}
	pthread_barrier_wait(&barrier);
}

void* threadStart(threadObject* args){
	threadObject* args1 = (threadObject*)args;
	for(int i = 0; i < (allNodes.size() - 1)/threadCount; ++i){
		bellmanFord(args1);
	}
}

void graphPrint(){
	for(int i = 0; i < allNodes.size(); ++i){
		cout << allNodes[i]->cost;
	}
}

/*
* Program runs as the following:
* graphTest "Filename" ThreadCount
*/
int main(int args, char* argv[]){
	threadCount = atoi(argv[2]);
	loadGraph(argv[1]);
	divideWork(threadCount);

	// Start threads
	pthread_barrier_init(&barrier, NULL, threadCount);
	for(int i = 0; i < threadCount; ++i){
		//pthread create
		pthread_create (&(threads[i].tid), NULL, threadStart, &threads[i]);
	}

	// pthread syncronize (barrier)
	for(int i = 0; i < threadCount; ++i){
		pthread_join(threads[i].tid, NULL);
	}

	// read and print graph
	graphPrint();
}