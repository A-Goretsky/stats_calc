//Anton Goretsky
//Statistical Calculator
//C++ Exploration Project, useful tool.
//Basic statistically relevant calculation methods.

#include "basic_calc.hpp"

/////////MEAN METHODS/////////
double iter_mean(std::vector<double> const& data) {
	double sum;
	std::vector<double>::const_iterator x;
	for (x = data.begin(); x != data.end(); ++x) {
		sum += *x;
	}
	return sum / (int) data.size();
	//std::cout << "Iter Mean: " << res << "\n";
}

double ord_mean(std::vector<double> const& data) {
	double ret = 0;
	for (int x = 0; x < data.size(); x++) {
		ret += data[x];
	}
	return (ret / (data.size()));
}


/////////FREQUENCY LIST METHODS//////////
std::vector<double> iter_freq_list(std::vector<double> const& data) {
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

	std::cout << "Elements\n---------\nFrequency\n";
	print_vector(elements);
	print_vector(freq);
	return freq;
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
double min(std::vector<double> const& data) {
	double min = data[0];
	for (int x = 0; x < data.size(); x++) {
		if (data[x] < min)
			min = data[x];
	}
	return min;
}

double max(std::vector<double> const& data) {
	double max = data[0];
	for (int x = 0; x < data.size(); x++) {
		if (data[x] > max)
			max = data[x];
	}
	return max;
}

double range(std::vector<double> const& data) {
	double max = data[0];
	double min = data[0];
	for (int x = 0; x < data.size(); x++) {
		if (data[x] > max)
			max = data[x];
		if (data[x] < min)
			min = data[x];
	}
	return max - min;
}

/////////MEDIAN / QUARTILE METHODS/////////
double median(std::vector<double> const& data) {
	size_t size = data.size();
	if (size % 2 == 0) {
		return ( ( data[size/2] + data[size/2 + 1] ) / 2);
	}
	else {
		return data[size/2 + 1];
	}
}

double low_quartile(std::vector<double> const& data) {
	size_t size = data.size();
	if (size % 2 == 0) {
		
	}
	else {
		
	}
}

double upp_quartile(std::vector<double> const& data) {
	return 0.0;
}

double iqr(std::vector<double> const& data) {
	return 0.0;
}

/////////MODE METHODS/////////
double mode(std::vector<double> data) {
	std::vector<double> freq = iter_freq_list(data);
	return max(freq);
}

/////////VARIANCE METHODS/////////
double basic_variance(std::vector<double> const& data) {
	//Variance -  s^2 = Summation((x - x̅)^2) / (n - 1)
	double mean = ord_mean(data);
	double summation;
	for (int x = 0; x < data.size(); x++) {
		summation += ((x - mean)*(x - mean));
	}
	return summation / (data.size() - 1);
}

/////////STANDARD DEV METHODS/////////
double basic_standard_dev(std::vector<double> const& data) {
	return sqrt(basic_variance(data));
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

/////////CHART METHODS/////////
/*
void freq_chart(std::vector<double> data) {
	std::cout << "Not Written Yet\n";
}

void box_whisker(std::vector<double> data) {

}
*/
