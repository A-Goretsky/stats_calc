#include <iostream>
#include <vector>
#include <string>
#include <cmath>

double information() {
    return 0;
}

double gain(double original, double avg) {
    return original - avg;
}

double entropy(std::vector<double> prob_input) {
    double total = 0;
    for (int x = 0; (int) x < prob_input.size(); x++) {
        if (prob_input[x] == 0) {
            total += 0;
        }
        else {
            total += ( (prob_input[x]) * log2(prob_input[x]) );
        }
    }
    return total * -1;
}


int main() {

    std::vector<double> amounts = {4, 4, 4, 3, 3, 3};

    std::vector<std::vector<std::string>> data = {
            {"high", "vhigh", "3", "4", "medium", "high", "Q"},
            {"high", "medium", "4", "6", "small", "high", "S"},
            {"medium", "vhigh", "3", "1", "big", "medium", "S"},
            {"medium", "high", "3", "4", "big", "high", "R"},
            {"low", "high", "1", "4", "small", "low", "S"},
            {"low", "vhigh", "3", "1", "big", "medium", "Q"},
            {"low", "vhigh", "1", "6", "small", "high", "P"},
            {"low", "high", "3", "1", "medium", "low", "S"},
            {"low", "low", "4", "6", "small", "medium", "Q"},
            {"vlow", "low", "3", "1", "big", "low", "P"},
            {"vlow", "low", "6", "4", "small", "high", "S"},
            {"vlow", "low", "4", "4", "big", "medium", "R"}
    };

    //P, Q, R, S = info(2, 3, 2, 5)

    //feature 1: high med, low, vlow
    double orig_entropy = entropy({2.0/12, 3.0/12, 2.0/12, 5.0/12});
    std::cout << "Original entropy: " << orig_entropy << "\n\n";
    double f1_entropy_1 = entropy({0.0/2, 1.0/2, 0.0/2, 1.0/2});
    double f1_entropy_2 = entropy({0.0/2, 0.0/2, 1.0/2, 1.0/2});
    double f1_entropy_3 = entropy({1.0/5, 2.0/5, 0.0/5, 2.0/5});
    double f1_entropy_4 = entropy({1.0/3, 0.0/3, 1.0/3, 1.0/3});
    //std::cout << f1_entropy_1 << '\n';
    //std::cout << f1_entropy_2 << '\n';
    //std::cout << f1_entropy_3 << '\n';
    //std::cout << f1_entropy_4 << '\n';
    double avg_f1 = ( (f1_entropy_1 * (2.0/12)) + (f1_entropy_2 * (2.0/12)) + (f1_entropy_3 * (5.0/12)) + f1_entropy_4 * (3.0/12));
    //std::cout << avg_f1 << '\n';

    //feature 2: vhigh, high, med, low
    double f2_entropy_1 = entropy({1.0/4, 2.0/4, 0.0/4, 1.0/4});
    double f2_entropy_2 = entropy({0.0/3, 0.0/3, 1.0/3, 2.0/3});
    double f2_entropy_3 = entropy({0.0/1, 0.0/1, 0.0/1, 1.0/1});
    double f2_entropy_4 = entropy({1.0/4, 1.0/4, 1.0/4, 1.0/4});
    double avg_f2 = (f2_entropy_1 * (4.0/12)) + (f2_entropy_2 * (3.0/12)) + (f2_entropy_3 * (1.0/12))+ (f2_entropy_4 * (4.0/12));
    //std::cout << avg_f2 << '\n';

    //feature 3: 1, 3, 4, 6
    double f3_entropy_1 = entropy({1.0/2, 0.0/2, 0.0/2, 1.0/2});
    double f3_entropy_2 = entropy({1.0/6, 2.0/6, 1.0/6, 2.0/6});
    double f3_entropy_3 = entropy({0.0/3, 1.0/3, 1.0/3, 1.0/3});
    double f3_entropy_4 = entropy({0.0/1, 0.0/1, 0.0/1, 1.0/1});
    double avg_f3 = (f3_entropy_1 * (2.0/12)) + (f3_entropy_2 * (6.0/12)) + (f3_entropy_3 * (3.0/12)) + (f3_entropy_4 * (1.0/12));
    //std::cout << avg_f3 << '\n';

    //feature 4: 1, 4, 6
    double f4_entropy_1 = entropy({1.0/4, 1.0/4, 0.0/4, 2.0/4});
    double f4_entropy_2 = entropy({0.0/5, 1.0/5, 2.0/5, 2.0/5});
    double f4_entropy_3 = entropy({1.0/3, 1.0/3, 0.0/3, 1.0/3});
    double avg_f4 = (f4_entropy_1 * (4.0/12)) + (f4_entropy_2 * (5.0/12)) + (f4_entropy_3 * (3.0/12));
    //std::cout << avg_f4 << '\n';

    //feature 5: big, medium, small
    double f5_entropy_1 = entropy({1.0/5, 1.0/5, 2.0/5, 1.0/5});
    double f5_entropy_2 = entropy({0.0/2, 2.0/2, 0.0/2, 1.0/2});
    double f5_entropy_3 = entropy({1.0/5, 1.0/5, 0.0/5, 3.0/5});
    double avg_f5 = (f5_entropy_1 * (5.0/12)) + (f5_entropy_2 * (2.0/12))+ (f5_entropy_3 * (5.0/12));
    //std::cout << avg_f5 << '\n';

    //feature 6: high, medium, low
    double f6_entropy_1 = entropy({1.0/5, 1.0/5, 1.0/5, 2.0/5});
    double f6_entropy_2 = entropy({0.0/4, 2.0/4, 1.0/4, 1.0/4});
    double f6_entropy_3 = entropy({1.0/3, 0.0/3, 0.0/3, 2.0/3});
    double avg_f6 = (f6_entropy_1 * (5.0/12)) + (f6_entropy_2 * (4.0/12)) + (f6_entropy_3 * (3.0/12));
    //std::cout << avg_f6 << '\n';
    
    
    std::cout << "Gain(feature1) = " << gain(orig_entropy, avg_f1) << "\n";
    std::cout << "Gain(feature2) = " << gain(orig_entropy, avg_f2) << "\n";
    std::cout << "Gain(feature3) = " << gain(orig_entropy, avg_f3) << "\n";
    std::cout << "Gain(feature4) = " << gain(orig_entropy, avg_f4) << "\n";
    std::cout << "Gain(feature5) = " << gain(orig_entropy, avg_f5) << "\n";
    std::cout << "Gain(feature6) = " << gain(orig_entropy, avg_f6) << "\n";

    std::cout << "\n";

    std::cout << "Tree would split on:\nFeature 1\n";
    //feature
    return 0;
}
