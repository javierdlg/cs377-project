FILES :=				\
	.gitignore			\
	README.md			\
	RunGraph.cpp		\
	RunGraph.out		\
	graph.h				\
	USA-road-d.NY.gr	\
	LICENSE				\

CXX			:= g++-4.8
CXXFLAGS	:= -pedantic -std=c++11 -Wall
LDFLAGS		:= -pthread
VALGRIND 	:= valgrind

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f RunGraph.tmp
	rm -f RunGraph

config:
	git config -l

test: RunGraph.tmp

RunGraph: graph.h RunGraph.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) RunGraph.cpp -o RunGraph

RunGraph.tmp: RunGraph
	./RunGraph < USA-road-d.NY.gr > RunGraph.tmp 
	diff RunGraph.tmp RunGraph.out
