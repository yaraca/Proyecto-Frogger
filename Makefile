br: compilar ejecutar //primero se compila y luego se ejecuta directamente 

compilar: src/main.cpp
	g++ src/main.cpp -o bin/mascotas -I include

ejecutar: bin/mascotas
	./bin/mascotas

clean: bin/mascotas
	rm bin/mascotas //se borra el archivo de mascotas 