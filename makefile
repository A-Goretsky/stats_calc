CXXFLAGS=-std=c++11

main: main.cpp basic_calc.cpp
	g++ $(CXXFLAGS) -o main main.cpp basic_calc.cpp
	
interface: interface_main.cpp basic_calc.cpp
	g++ $(CXXFLAGS) -o interface interface_main.cpp basic_calc.cpp

run:
	./main

run_interface:
	./interface

debug:
	g++ $(CXXFLAGS) -o main main.cpp basic_calc.cpp -g

clean:
	rm main
