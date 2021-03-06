#include <iostream>
#include <vector>
#include <cmath>

/////////MEAN/////////
double iter_mean(std::vector<double> const& data);
double ord_mean(std::vector<double> const& data);

/////////FREQ LIST/////////
std::vector<double> iter_freq_list(std::vector<double> const& data);
std::vector<double> ord_freq_list(std::vector<double> data);
std::vector<double> set_freq_list(std::vector<double> data);

/////////MEDIAN/////////
double median(std::vector<double> const& data);

/////////MODE/////////
double mode(std::vector<double> data);

/////////MIN MAX RANGE/////////
void min_max_range(std::vector<double> data);

/////////VARIANCE/////////
double basic_variance(std::vector<double> const& data);

/////////STANDARD DEV/////////
double basic_standard_dev(std::vector<double> const& data);

/////////PRINT VECTOR/////////
template<class T>
void print_vector(std::vector<T> const& input);
