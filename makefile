CXXFLAGS=-std=c++11

main: main.cpp basic_calc.cpp
	g++ $(CXXFLAGS) -o main main.cpp basic_calc.cpp

debug:
	g++ $(CXXFLAGS) -o main main.cpp basic_calc.cpp -g

clean:
	rm main
