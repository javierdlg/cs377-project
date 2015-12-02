#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <fstream>
#include <string>
#include <pthread.h>
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
			istringstream iss(line);
			string s;
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			maxNodes = atoi(s.c_str());
			getline(iss, s, ' ');
			maxEdges = atoi(s.c_str());
			printf("test %d\n", maxNodes);
			allNodes.reserve(maxNodes);
			for(int i = 0; i < maxNodes; ++i)
			{
				Node *node = new Node(INT_MAX);

				allNodes.push_back(node);
			}
			ss.str(string());
		}
		else if(line.front() == 'a'){
			//cout << line;
			//ss << line << line << line;
			istringstream iss(line);
			string s;
			getline(iss, s, ' ');
			getline(iss, s, ' ');
			weight = atoi(s.c_str());
			getline(iss, s, ' ');
			nodeSource = atoi(s.c_str());
			getline(iss, s, ' ');
			nodeDestination = atoi(s.c_str());
			//ss >> weight >> nodeDestination >> nodeSource;
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
		for(unsigned int j = i; j < allNodes.size(); j += threadNumber){
			threads[i].inputNodes.push_back(allNodes[j]);
		}
	}
	for (unsigned int i = allNodes.size() - (allNodes.size()%threadNumber); i < allNodes.size(); ++i){
		threads[threadNumber-1].inputNodes.push_back(allNodes[i]);
	}
}

void bellmanFord(threadObject* thread){
	
	for(unsigned int i = 0; i < thread->inputNodes.size(); ++i){
		Node * node = thread->inputNodes[i];
		for(unsigned int j = 0; j < node->input.size(); ++j){
			Edge *edge = node->input[j];
			if(edge->source->cost != INT_MAX && (edge->source->cost + edge->weight) < node->cost)
				node->cost = edge->source->cost + edge->weight;
		}		
	}
	pthread_barrier_wait(&barrier);
}

void* threadStart(void* args){
	threadObject* args1 = (threadObject*)args;
	for(unsigned int i = 0; i < (allNodes.size() - 1)/threadCount; ++i){
		bellmanFord(args1);
	}
	return args;
}

void graphPrint(){
	for(unsigned int i = 0; i < allNodes.size(); ++i){
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
		pthread_create (&(threads[i].tid), NULL, threadStart, (void *)(&threads[i]));
	}
	printf(" Super test %d\n",2);
	// pthread syncronize (barrier)
	for(int i = 0; i < threadCount; ++i){
		pthread_join(threads[i].tid, NULL);
	}

	// read and print graph
	graphPrint();
}
