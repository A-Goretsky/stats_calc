//Anton Goretsky
//General items of machine learning, instance objects.

#include <iostream>
#include <string>
#include <vector>

class Numeric_Instance {
    public:
        Numeric_Instance() = default;
        Numeric_Instance(std::vector<double> input) {
            features = input;
            feature_count = input.size();
        }
    private:
        std::vector<double> features;
        size_t feature_count;
        std::string label; //class
};

class Data {
    public:
        Data() = default;
        Data(std::vector<std::vector<double>> input) {
            instance_count = input.size();
            size_t features = input[0].size();
            for (size_t x = 0; x < instance_count; x++) {
                for (size_t y = 0; y < features; y++) {
                    instances.
                }
            }
        }
        Data(std::string filename) {

        }
    private:
        std::vector<Numeric_Instance> instances;
        size_t instance_count;
};

int main() {
    return 0;
}


