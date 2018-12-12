//Anton Goretsky
//Statstical Calculator
//C++ Exploration Project, useful tool.
//Basic statistically relevant calculation methods.

#include "basic_calc.hpp"

/////////MEAN METHODS/////////
void iter_mean(std::vector<double> const& data) {
	double sum;
	std::vector<double>::const_iterator x;
	for (x = data.begin(); x != data.end(); ++x) {
		sum += *x;
	}
	double res = sum / (int) data.size();
	std::cout << "Iter Mean: " << res << "\n";
}


void ord_mean(std::vector<double> const& data) {
	double ret = 0;
	for (int x = 0; x < data.size(); x++) {
		ret += data[x];
	}
	std::cout << "Ord Mean: " << ret / (data.size()) << "\n";
}


/////////FREQUENCY LIST METHODS//////////
void iter_freq_list(std::vector<double> data) {
	std::vector<double> elements;
	std::vector<double> freq;
	int ctr = 0;
	for (int x = 0; x < data.size(); x++) {
		if (find(elements.begin(), elements.end(), data[x]) == elements.end()) {
			elements.push_back(data[x]);
		}
	}
	//auto will be std::vector<double>::iterator
	auto e = elements.begin();
	while (e != elements.end()) {
		auto x = data.begin();
		for (; x != data.end(); ++x) {
			if (*x == *e)
				ctr++;
		}
		freq.push_back(ctr);
		++e;
		ctr = 0;
	}

	std::cout << "Elements  |  Frequency\n";
	print_vector(elements);
	print_vector(freq);
}

std::vector<double> ord_freq_list(std::vector<double> data) {
	std::vector<double> freq;
	return freq;
}

std::vector<double> set_freq_list(std::vector<double> data) {
	std::vector<double> elements;
	return elements;
}

void freq_list_ordered(std::vector<double> data) {
	std::cout << "Not Implemented Yet.\n"; 
}

/////////MIN MAX RANGE METHODS/////////
void min_max_range(std::vector<double> data) {
	double max = data[0];
	double min = data[0];
	for (int x = 0; x < data.size(); x++) {
		if (data[x] > max)
			max = data[x];
		if (data[x] < min)
			min = data[x];
	}
	std::cout << "Min: " << min << "\n";
	std::cout << "Max: " << max << "\n";
	std::cout << "Range: " << max - min << "\n";
}

/////////MEDIAN METHODS/////////
double median(std::vector<double> const& data) {
	size_t size = data.size();
	if (size % 2 == 0) {
		return ( ( data[size/2] + data[size/2 + 1] ) / 2);
	}
	else {
		return data[size/2 + 1];
	}
}

/////////MODE METHODS/////////
double mode(std::vector<double> data) {
	return 0.0;
}

/////////PRINT VECTOR TEMPLATE/////////

//ASSUMING ONLY SIMPLE TYPES, EX: INT, DOUBLE, STRING
template <class T>
void print_vector(std::vector<T> const& input) {
	for (int x = 0; x < input.size(); x++) {
		std::cout << input[x] << " ";
	}
	std::cout << "\n";
}

/*
void freq_chart(double list[]) {
	std::cout << "Not Written Yet\n";
}
*/
