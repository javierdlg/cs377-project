# cs377-project
Programming for Performance Project


--- SUMARRY ---

This project mainly concentrates on experimenting with Bellman-Ford's Algorithm and the ways we can make it more efficient. 

We attempt to reduce the time constraint by applying the following:

	1) Iterating edges instead of Nodes

	2) Multithreaded operations

	3) Bucketing and nearfar

--- Performance Increase Explainations --- 

1) Iterating edges instead of nodes:
Instead of iterating all the nodes and then the edges pointing into the node to calculate the total cost to that node, we iterate through all the edges and modify the cost of the destination node. This forces us to use mutex and atomic operations to prevent race conditions.

2) Multithreaded operations:
We divide the edges in equal parts and split these among the available threads (decided from input). 

3) Bucketing and nearfar:


--- How to Run --- 

This program has been made to take in DIMACS graphs as input. Simply compile using 

"Make RunGraph" 

and then run the program as 

"RunGraph <Input File Name> <Number of Threads>"


The program will run and create a Rungraph.tmp file with the output and log of the test.