#include <iostream>
#include <vector>

/////////MEAN/////////
void iter_mean(std::vector<double> const& data);
void ord_mean(std::vector<double> const& data);

/////////FREQ LIST/////////
void iter_freq_list(std::vector<double> data);
std::vector<double> ord_freq_list(std::vector<double> data);
std::vector<double> set_freq_list(std::vector<double> data);

/////////MEDIAN/////////
double median(std::vector<double> const& data);

/////////MODE/////////
double mode(std::vector<double> data);

/////////MIN MAX RANGE/////////
void min_max_range(std::vector<double> data);

/////////VARIANCE/////////
/////////STANDARD DEV/////////


/////////PRINT VECTOR/////////
template<class T>
void print_vector(std::vector<T> const& input);
