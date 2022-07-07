STD = c++17
OPT = 3

all : virtualmachine.o keywords.o main.cpp 
	${CXX} -o cow virtualmachine.o keywords.o main.cpp -std=${STD} -O${OPT}

virtualmachine.o:
	${CXX} -c virtualmachine.cpp -std=${STD} -O${OPT}

keywords.o:
	${CXX} -c keywords.cpp -std=${STD} -g -O${OPT}

clean: 
	rm cow virtualmachine.o keywords.o
