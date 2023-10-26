CXX = x86_64-w64-mingw32-g++ #windows
CXX = c++ #linux
br: clean compilar ejecutar 

compilar : src/main.cpp
	$(CXX) src/main.cpp -o bin/mascotas -I include

ejecutar : bin/mascotas
	./bin/mascotas

clean : bin/mascotas
	rm bin/mascotas 