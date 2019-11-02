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
            feature_count = input.size() - 1; //exclude label
            label = input[feature_count]; //label = last element
            input.pop_back(); //Remove class label from feature vector
        }
        //Copy Constructor
        Numeric_Instance(const Numeric_Instance& other) {

        }
        //Move Constructor
        Numeric_Instance(Numeric_Instance&& other) {
            
        }
        friend std::ostream& operator<<(std::ostream& out, Numeric_Instance input) {
            return out;
        }
        //Copy assignment
        Numeric_Instance& operator=(const Numeric_Instance& other) {
            
        }
        //Move assignment
        Numeric_Instance& operator=(Numeric_Instance&& other) {

        }
    private:
        std::vector<double> features;
        size_t feature_count;
        std::string label = ""; //class
};

class Data {
    public:
        //Default constructor
        Data() = default;
        //Constructor using vectored numeric input.
        //Mostly for the purpose of testing
        Data(std::vector<std::vector<double>> input) {
            instance_count = input.size();
            size_t features = input[0].size();
            for (size_t x = 0; x < instance_count; x++) {
                for (size_t y = 0; y < features; y++) {
                    Numeric_Instance* to_add = new Numeric_Instance;
                    instances.push_back(to_add);
                }
            }
        }
        //Constructor for .csv and .arff files
        Data(std::string filename, std::string type) {
            
        }
    private:
        std::vector<Numeric_Instance *> instances;
        size_t instance_count;
};

int main() {
    return 0;
}


