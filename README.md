# cs377-project
Programming for Performance Project


--- SUMARRY ---

This is the baseline program we created to get baseline results with Bellman-Ford. We run this with the simple, Rome, and New York road map graph. We ran each graph with 1, 2, 4, 8, 12, 16 threads.

--- How to Run --- 

This program has been made to take in DIMACS graphs as input. Compile using:

"make RunGraph" 

You can manually run tests with: 

"RunGraph <Input File Name> <Number of Threads>"

Or alternatively run each graph's tests (1 to 16 threads each) with either of these:

"make SimpleTest"
"make RomeTest"
"make NYTest"

To run all the tests:

"make test"

The program will run and create a Rungraph.out file with the output and log of the test.