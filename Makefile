STD = "c++17"

all : virtualmachine.o keywords.o main.cpp 
	${CXX} -o cow virtualmachine.o keywords.o main.cpp -std=${STD} -g

virtualmachine.o:
	${CXX} -c virtualmachine.cpp -std=${STD} -g

keywords.o:
	${CXX} -c keywords.cpp -std=${STD} -g

clean: 
	rm cow virtualmachine.o keywords.o