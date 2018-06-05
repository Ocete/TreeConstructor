all:
	g++ TreeConstructor.cpp -o tree_constructor
	./tree_constructor < input
	rm tree_constructor
