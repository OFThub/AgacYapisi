hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./bin/AgacIslemleri ./lib/Agac.o ./src/Main.cpp
	
calistir:
	./bin/AgacIslemleri