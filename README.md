# cs377-project
Programming for Performance Project


--- SUMARRY ---

This project mainly concentrates on experimenting with Bellman-Ford's Algorithm and the ways we can make it more efficient. 

We attempt to reduce the time constraint by applying the following:

	1) Iterating edges instead of Nodes

	2) Multithreaded operations

	3) Utilizing a node-dependant algorithm

	4) Utilizing a edge-dependant algorithm

This implementation is divided into 2 parts. The node dependant algorithm called "NodeRunGraph" and the edge dependant algorithm called "EdgeRunGraph".

--- How to Run --- 

- This program has been made to take in DIMACS graphs as input. Since these files are too large for github, you should download the graphs you want to test from http://www.dis.uniroma1.it/challenge9/download.shtml . This makefile can compile NY, FLA, W, and US of which NY and FLA are already included. Please download the graphs, uncompress them and place them in the graphs folder as they are. We also used RMAT16, RMAT20, and RMAT22 to test the algorithm with a social network graph. These graphs are unavailable to the public and are too big for github. 

- Compile using 
"make NodeRunGraph" or "make EdgeGraph"

- You can manually run the binary as follows:
"<Rungraph Binary> <Input File Name> <Number of Threads>"

- Otherwise you can run the individual tests as follows:
"make <Node or Edge>NYTest"
"make <Node or Edge>FLATest"
"make <Node or Edge>WTest"
"make <Node or Edge>USTest"
"make <Node or Edge>RMAT16Test"
"make <Node or Edge>RMAT20Test"
"make <Node or Edge>RMAT22Test"

- You can also run all the tests with:
"make test"
This will recompile both RunGraphs (node and edge based) and test them both with all the available graphs.

The program will run and create a "<Graph Name>.out" file with the output and log of the test.

--- Condor ---

We used Condor as one of our testing tools. Inside "condor_jobs" there is a script called "condor_script" which should upload W, NY, and FLA jobs into condor with 1, 2, 4, 8, 16 threads each 5 times. The output should be in the same location 