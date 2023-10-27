bin/rana: src/rana.cpp include/*
	c++ src/rana.cpp -o bin/rana -lcurses -I include 

run : bin/rana
	./bin/rana
	