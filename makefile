FILES :=				\
	.gitignore			\
	README.md			\
	RunGraph.cpp		\
	RunGraph.out		\
	graph.h				\
	USA-road-d.NY.gr	\
	LICENSE				\

CXX			:= g++-4.8
CXXFLAGS	:= -pedantic -std=c++11 -Wall -o3
LDFLAGS		:= -pthread

clean:
	rm -f *.out
	rm -f RunGraph


test: RunGraph.out

RunGraph: graph.h RunGraph.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) RunGraph.cpp -o RunGraph
SimpleTest:
	./RunGraph graphs/simple.gr 1 > simple1.out
	./RunGraph graphs/simple.gr 2 > simple2.out
	./RunGraph graphs/simple.gr 4 > simple4.out
	./RunGraph graphs/simple.gr 8 > simple8.out
	./RunGraph graphs/simple.gr 12 > simple12.out
	./RunGraph graphs/simple.gr 16 > simple16.out

RomeTest:
	./RunGraph graphs/rometest.gr 1 > rometest1.out
	./RunGraph graphs/rometest.gr 2 > rometest2.out
	./RunGraph graphs/rometest.gr 4 > rometest4.out
	./RunGraph graphs/rometest.gr 8 > rometest8.out
	./RunGraph graphs/rometest.gr 12 > rometest12.out
	./RunGraph graphs/rometest.gr 16 > rometest16.out

NYTest:
	./RunGraph graphs/USA-road-d.NY.gr 1 > USA-road-d.NY1.out
	./RunGraph graphs/USA-road-d.NY.gr 2 > USA-road-d.NY2.out
	./RunGraph graphs/USA-road-d.NY.gr 4 > USA-road-d.NY4.out
	./RunGraph graphs/USA-road-d.NY.gr 8 > USA-road-d.NY8.out
	./RunGraph graphs/USA-road-d.NY.gr 12 > USA-road-d.NY12.out
	./RunGraph graphs/USA-road-d.NY.gr 16 > USA-road-d.NY16.out

RunGraph.out: RunGraph SimpleTest RomeTest NYTest
