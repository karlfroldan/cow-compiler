STD = "c++17"

all : virtualmachine.o keywords.o main.cpp 
	${CXX} -o moo virtualmachine.o keywords.o main.cpp -std=${STD}

virtualmachine.o:
	${CXX} -c virtualmachine.cpp -std=${STD}

keywords.o:
	${CXX} -c keywords.cpp -std=${STD}

clean: 
	rm moo virtualmachine.o keywords.o