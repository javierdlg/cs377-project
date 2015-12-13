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

test: NodeRunGraph.out EdgeRunGraph.out

NodeRunGraph: NodeGraph.h NodeRunGraph.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) NodeRunGraph.cpp -o NodeRunGraph

NodeNYTest:
	./NodeRunGraph graphs/USA-road-d.NY.gr 1 > NodeUSA-road-d.NY1.out
	./NodeRunGraph graphs/USA-road-d.NY.gr 2 > NodeUSA-road-d.NY2.out
	./NodeRunGraph graphs/USA-road-d.NY.gr 4 > NodeUSA-road-d.NY4.out
	./NodeRunGraph graphs/USA-road-d.NY.gr 8 > NodeUSA-road-d.NY8.out
	./NodeRunGraph graphs/USA-road-d.NY.gr 16 > NodeUSA-road-d.NY16.out

NodeFLATest:
	./NodeRunGraph graphs/USA-road-d.FLA.gr 1 > NodeUSA-road-d.FLA1.out
	./NodeRunGraph graphs/USA-road-d.FLA.gr 2 > NodeUSA-road-d.FLA2.out
	./NodeRunGraph graphs/USA-road-d.FLA.gr 4 > NodeUSA-road-d.FLA4.out
	./NodeRunGraph graphs/USA-road-d.FLA.gr 8 > NodeUSA-road-d.FLA8.out
	./NodeRunGraph graphs/USA-road-d.FLA.gr 16 > NodeUSA-road-d.FLA16.out

NodeWTest:
	./NodeRunGraph graphs/USA-road-d.W.gr 1 > NodeUSA-road-d.W1.out
	./NodeRunGraph graphs/USA-road-d.W.gr 2 > NodeUSA-road-d.W2.out
	./NodeRunGraph graphs/USA-road-d.W.gr 4 > NodeUSA-road-d.W4.out
	./NodeRunGraph graphs/USA-road-d.W.gr 8 > NodeUSA-road-d.W8.out
	./NodeRunGraph graphs/USA-road-d.W.gr 16 > NodeUSA-road-d.W16.out

NodeUSTest:
	./NodeRunGraph graphs/USA-road-d.US.gr 1 > NodeUSA-road-d.US1.out
	./NodeRunGraph graphs/USA-road-d.US.gr 2 > NodeUSA-road-d.US2.out
	./NodeRunGraph graphs/USA-road-d.US.gr 4 > NodeUSA-road-d.US4.out
	./NodeRunGraph graphs/USA-road-d.US.gr 8 > NodeUSA-road-d.US8.out
	./NodeRunGraph graphs/USA-road-d.US.gr 16 > NodeUSA-road-d.US16.out

NodeRMAT16Test:
	./NodeRunGraph graphs/rmat16.dimacs 1 > Nodermat16.dimacs1.out
	./NodeRunGraph graphs/rmat16.dimacs 2 > Nodermat16.dimacs2.out
	./NodeRunGraph graphs/rmat16.dimacs 4 > Nodermat16.dimacs4.out
	./NodeRunGraph graphs/rmat16.dimacs 8 > Nodermat16.dimacs8.out
	./NodeRunGraph graphs/rmat16.dimacs 12 > Nodermat16.dimacs12.out
	./NodeRunGraph graphs/rmat16.dimacs 16 > Nodermat16.dimacs16.out

NodeRMAT20Test:
	./NodeRunGraph graphs/rmat20.dimacs 1 > Nodermat20.dimacs1.out
	./NodeRunGraph graphs/rmat20.dimacs 2 > Nodermat20.dimacs2.out
	./NodeRunGraph graphs/rmat20.dimacs 4 > Nodermat20.dimacs4.out
	./NodeRunGraph graphs/rmat20.dimacs 8 > Nodermat20.dimacs8.out
	./NodeRunGraph graphs/rmat20.dimacs 12 > Nodermat20.dimacs12.out
	./NodeRunGraph graphs/rmat20.dimacs 16 > Nodermat20.dimacs16.out

NodeRMAT22Test:
	./NodeRunGraph graphs/rmat22.dimacs 1 > Nodermat22.dimacs1.out
	./NodeRunGraph graphs/rmat22.dimacs 2 > Nodermat22.dimacs2.out
	./NodeRunGraph graphs/rmat22.dimacs 4 > Nodermat22.dimacs4.out
	./NodeRunGraph graphs/rmat22.dimacs 8 > Nodermat22.dimacs8.out
	./NodeRunGraph graphs/rmat22.dimacs 12 > Nodermat22.dimacs12.out
	./NodeRunGraph graphs/rmat22.dimacs 16 > Nodermat22.dimacs16.out

NodeRunGraph.out: NodeRunGraph NodeNYTest NodeFLATest NodeWTest NodeUSTest NodeRMAT16Test NodeRMAT20Test NodeRMAT22Test

EdgeRunGraph: EdgeGraph.h EdgeRunGraph.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) EdgeRunGraph.cpp -o EdgeRunGraph

EdgeNYTest:
	./EdgeRunGraph graphs/USA-road-d.NY.gr 1 > EdgeUSA-road-d.NY1.out
	./EdgeRunGraph graphs/USA-road-d.NY.gr 2 > EdgeUSA-road-d.NY2.out
	./EdgeRunGraph graphs/USA-road-d.NY.gr 4 > EdgeUSA-road-d.NY4.out
	./EdgeRunGraph graphs/USA-road-d.NY.gr 8 > EdgeUSA-road-d.NY8.out
	./EdgeRunGraph graphs/USA-road-d.NY.gr 16 > EdgeUSA-road-d.NY16.out

EdgeFLATest:
	./EdgeRunGraph graphs/USA-road-d.FLA.gr 1 > EdgeUSA-road-d.FLA1.out
	./EdgeRunGraph graphs/USA-road-d.FLA.gr 2 > EdgeUSA-road-d.FLA2.out
	./EdgeRunGraph graphs/USA-road-d.FLA.gr 4 > EdgeUSA-road-d.FLA4.out
	./EdgeRunGraph graphs/USA-road-d.FLA.gr 8 > EdgeUSA-road-d.FLA8.out
	./EdgeRunGraph graphs/USA-road-d.FLA.gr 16 > EdgeUSA-road-d.FLA16.out

EdgeWTest:
	./EdgeRunGraph graphs/USA-road-d.W.gr 1 > EdgeUSA-road-d.W1.out
	./EdgeRunGraph graphs/USA-road-d.W.gr 2 > EdgeUSA-road-d.W2.out
	./EdgeRunGraph graphs/USA-road-d.W.gr 4 > EdgeUSA-road-d.W4.out
	./EdgeRunGraph graphs/USA-road-d.W.gr 8 > EdgeUSA-road-d.W8.out
	./EdgeRunGraph graphs/USA-road-d.W.gr 16 > EdgeUSA-road-d.W16.out

EdgeUSTest:
	./EdgeRunGraph graphs/USA-road-d.US.gr 1 > EdgeUSA-road-d.US1.out
	./EdgeRunGraph graphs/USA-road-d.US.gr 2 > EdgeUSA-road-d.US2.out
	./EdgeRunGraph graphs/USA-road-d.US.gr 4 > EdgeUSA-road-d.US4.out
	./EdgeRunGraph graphs/USA-road-d.US.gr 8 > EdgeUSA-road-d.US8.out
	./EdgeRunGraph graphs/USA-road-d.US.gr 16 > EdgeUSA-road-d.US16.out

EdgeRMAT16Test:
	./EdgeRunGraph graphs/rmat16.dimacs 1 > Edgermat16.dimacs1.out
	./EdgeRunGraph graphs/rmat16.dimacs 2 > Edgermat16.dimacs2.out
	./EdgeRunGraph graphs/rmat16.dimacs 4 > Edgermat16.dimacs4.out
	./EdgeRunGraph graphs/rmat16.dimacs 8 > Edgermat16.dimacs8.out
	./EdgeRunGraph graphs/rmat16.dimacs 12 > Edgermat16.dimacs12.out
	./EdgeRunGraph graphs/rmat16.dimacs 16 > Edgermat16.dimacs16.out

EdgeRMAT20Test:
	./EdgeRunGraph graphs/rmat20.dimacs 1 > Edgermat20.dimacs1.out
	./EdgeRunGraph graphs/rmat20.dimacs 2 > Edgermat20.dimacs2.out
	./EdgeRunGraph graphs/rmat20.dimacs 4 > Edgermat20.dimacs4.out
	./EdgeRunGraph graphs/rmat20.dimacs 8 > Edgermat20.dimacs8.out
	./EdgeRunGraph graphs/rmat20.dimacs 12 > Edgermat20.dimacs12.out
	./EdgeRunGraph graphs/rmat20.dimacs 16 > Edgermat20.dimacs16.out

EdgeRMAT22Test:
	./EdgeRunGraph graphs/rmat22.dimacs 1 > Edgermat22.dimacs1.out
	./EdgeRunGraph graphs/rmat22.dimacs 2 > Edgermat22.dimacs2.out
	./EdgeRunGraph graphs/rmat22.dimacs 4 > Edgermat22.dimacs4.out
	./EdgeRunGraph graphs/rmat22.dimacs 8 > Edgermat22.dimacs8.out
	./EdgeRunGraph graphs/rmat22.dimacs 12 > Edgermat22.dimacs12.out
	./EdgeRunGraph graphs/rmat22.dimacs 16 > Edgermat22.dimacs16.out

EdgeRunGraph.out: EdgeRunGraph EdgeNYTest EdgeFLATest EdgeWTest EdgeUSTest EdgeRMAT16Test EdgeRMAT20Test EdgeRMAT22Test
