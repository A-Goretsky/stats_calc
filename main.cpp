#include <iostream>
#include <vector>
#include "basic_calc.hpp"

int main() {

    //THIS IS VERY POOR TESTING AT THE MOMENT
    //WILL EXPAND TO USE DOCTEST AND MANY MORE CONDITIONS

    //testing mean
    std::vector<double> test = {1, 5, 6, 3, 5.3};
    iter_mean(test);
    ord_mean(test);

    //testing freq_list
    std::vector<double> freq_test = {1, 1, 3, 3, 3, 4, 7, 8, 10, 10};
    iter_freq_list(freq_test);
    //testing order_freq_list
    
}
