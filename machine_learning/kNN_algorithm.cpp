//Anton Goretsky
//Machine Learning
//Assignment 1
//kNN Implementation

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Data {
    double f1;
    double f2;
    double f3;
    double f4;
    char label;

    friend std::ostream& operator<<(std::ostream& out, Data input) {
        out << "{" << input.f1 << ", " << input.f2 << ", " << input.f3 << ", " << input.f4 << "}\n";
        return out;
    }
};

struct Distance_Label {
    double eucl_distance;
    double manh_distance;
    char label;
    friend std::ostream& operator<<(std::ostream& out, Distance_Label input) {
        out << "{" << input.eucl_distance << ", " << input.manh_distance << ", " << input.label << "}\n";
        return out;
    }
};

double findMax(std::vector<Data> &data, int f);
double findMin(std::vector<Data> &data, int f);
Data normalize_single(std::vector<Data> &data, Data newdata, int x);

double eucl_dis(double input1, double input2) {
    return pow((input2 - input1), 2);
}

double eucl_dis_composite(std::vector<Data> my_data, int x) {
    double total;
    //data[14] represents the new example
    total += eucl_dis(my_data[14].f1, my_data[x].f1);
    total += eucl_dis(my_data[14].f2, my_data[x].f2);
    total += eucl_dis(my_data[14].f3, my_data[x].f3);
    total += eucl_dis(my_data[14].f4, my_data[x].f4);
    return total;
}

double manhattan_dis(double input1, double input2) {
    return abs(input1 - input2);
}

double manh_dis_composite(std::vector<Data> my2_data, int x) {
    double total;
    //data[14] represents the new example
    total += manhattan_dis(my2_data[14].f1, my2_data[x].f1);
    total += manhattan_dis(my2_data[14].f2, my2_data[x].f2);
    total += manhattan_dis(my2_data[14].f3, my2_data[x].f3);
    total += manhattan_dis(my2_data[14].f4, my2_data[x].f4);
    return total;
}

double compare_euclid_label(const Distance_Label &a, const Distance_Label &b) {
    return a.eucl_distance < b.eucl_distance;
}

double compare_manh_label(const Distance_Label &a, const Distance_Label &b) {
    return a.manh_distance < b.manh_distance;
}

char largest_of_3(int num1, int num2, int num3) {
    if ((num1 >= num2) && (num1 >= num3))
        return 'A';
    else if ((num2 >= num1) && (num2 >= num3))
        return 'B';
    else
        return 'C';
}


Data normalize(std::vector<Data> &data, int x) {
    double maxf1 = findMax(data, 1);
    double minf1 = findMin(data, 1);
    double normalf1 = ( (data[x].f1 - minf1) / (maxf1 - minf1) );

    double maxf2 = findMax(data, 2);
    double minf2 = findMin(data, 2);
    double normalf2 = ( (data[x].f2 - minf2) / (maxf2 - minf2) );

    double maxf3 = findMax(data, 3);
    double minf3 = findMin(data, 3);
    double normalf3 = ( (data[x].f3 - minf3) / (maxf3 - minf3) );

    double maxf4 = findMax(data, 4);
    double minf4 = findMin(data, 4);
    double normalf4 = ( (data[x].f4 - minf4) / (maxf4 - minf4) );

    Data normal_data = {normalf1, normalf2, normalf3, normalf4, data[x].label};
    return normal_data;
}


int main() {
    //Original data vector
    std::vector<Data> all_data = {
        {5.1, 3.5, 1.3, 0.2, 'A'},
        {5.7, 3.4, 1.3, 0.2, 'C'},
        {4.7, 3.1, 1.6, 0.2, 'A'},
        {5.0, 4.6, 1.4, 0.1, 'B'},
        {5.9, 3.3, 4.0, 1.3, 'C'},
        {6.5, 2.7, 4.6, 1.5, 'A'},
        {5.7, 2.8, 4.4, 1.3, 'B'},
        {6.3, 3.3, 4.7, 1.4, 'C'},
        {4.7, 2.4, 3.2, 1.0, 'A'},
        {7.7, 3.6, 6.7, 2.2, 'B'},
        {7.7, 2.6, 6.5, 2.3, 'C'},
        {6.0, 2.2, 5.0, 1.4, 'A'},
        {6.9, 3.2, 5.7, 9.3, 'B'},
        {5.6, 2.2, 4.6, 2.0, 'C'},
        {5.0, 2.8, 4.6, 0.7, 'Z'} //new example line
    };

    //Normalized data vector
    std::vector<Data> all_data_normal;

    //Data new_example = {5.0, 2.8, 4.6, 0.7, 'Z'};
    std::vector<Distance_Label> distances;
    std::vector<Distance_Label> normal_distances;

    //normalization (edited)
    for (int x = 0; x < 15; x++) {
        all_data_normal.push_back(normalize(all_data, x));
    }
    /*
    for (int x = 0; x < all_data_normal.size(); x++) {
        std::cout << all_data_normal[x];
    }
    */

    double total_eucl_distance = 0;
    double total_manh_distance = 0;
    double normal_total_eucl_distance = 0;
    double normal_total_manhattan_distance = 0;

    for (int x = 0; x < 14; x++) {
        /////////////////////EUCLIDIAN DISTANCE//////////////////
        total_eucl_distance += eucl_dis_composite(all_data, x);
        normal_total_eucl_distance += eucl_dis_composite(all_data_normal, x);

        //Square root
        total_eucl_distance = sqrt(total_eucl_distance);
        normal_total_eucl_distance = sqrt(normal_total_eucl_distance);

        /////////////////////MANHATTAN DISTANCE//////////////////
        total_manh_distance += manh_dis_composite(all_data, x);
        normal_total_manhattan_distance += manh_dis_composite(all_data_normal, x);

        Distance_Label new_dis = {total_eucl_distance, total_manh_distance, all_data[x].label};
        Distance_Label normal_new_dis = {normal_total_eucl_distance, normal_total_manhattan_distance, all_data_normal[x].label};
        //std::cout << new_dis;
        //std::cout << normal_new_dis;
        distances.push_back(new_dis);
        normal_distances.push_back(normal_new_dis);

        total_eucl_distance = 0;
        total_manh_distance = 0;
        normal_total_eucl_distance = 0;
        normal_total_manhattan_distance = 0;
    }

    //std::cout << total_eucl_distance <<"\n";

    /////////////////////EUCLIDIAN DISTANCE//////////////////
    std::cout << "Euclid Distance\n";
    std::sort(distances.begin(), distances.end(), compare_euclid_label);
    std::sort(normal_distances.begin(), normal_distances.end(), compare_euclid_label);
    std::vector<int> k_vals = {1, 4, 6};

/*
    for (int x = 0; x < distances.size(); x++) {
        std::cout << distances[x].eucl_distance << " " << distances[x].label << "\n";
    }
    std::cout << "Normal\n";
    for (int x = 0; x < normal_distances.size(); x++) {
        std::cout << normal_distances[x].eucl_distance << " " << normal_distances[x].label << "\n";
    }
    */

    int a_count = 0;
    int b_count = 0;
    int c_count = 0;

    for (int x = 0; x < k_vals.size(); x++) {
        for (int y = 0; y < k_vals[x]; y++) {
            if (distances[y].label == 'A')
                a_count++;
            if (distances[y].label == 'B')
                b_count++;
            if (distances[y].label == 'C')
                c_count++;
        }
        std::cout << "k = " << k_vals[x] << "\n";
        std::cout << "label: " << largest_of_3(a_count, b_count, c_count) << "\n";
        a_count = 0;
        b_count = 0;
        c_count = 0;
    }

    std::cout << "NORMALIZED VALUES\n";

    for (int x = 0; x < k_vals.size(); x++) {
        for (int y = 0; y < k_vals[x]; y++) {
            if (normal_distances[y].label == 'A')
                a_count++;
            if (normal_distances[y].label == 'B')
                b_count++;
            if (normal_distances[y].label == 'C')
                c_count++;
        }
        std::cout << "k = " << k_vals[x] << "\n";
        std::cout << "label: " << largest_of_3(a_count, b_count, c_count) << "\n";
        a_count = 0;
        b_count = 0;
        c_count = 0;
    }

    std::cout << "\nManhattan Distance\n";
    std::sort(distances.begin(), distances.end(), compare_manh_label);
    std::sort(normal_distances.begin(), normal_distances.end(), compare_manh_label);

    /*
    for (int x = 0; x < distances.size(); x++) {
        std::cout << distances[x].manh_distance << " " << distances[x].label << "\n";
    }
    std::cout << "Normal\n";
    for (int x = 0; x < normal_distances.size(); x++) {
        std::cout << normal_distances[x].manh_distance << " " << normal_distances[x].label << "\n";
    }
    */

    for (int x = 0; x < k_vals.size(); x++) {
        for (int y = 0; y < k_vals[x]; y++) {
            if (distances[y].label == 'A')
                a_count++;
            if (distances[y].label == 'B')
                b_count++;
            if (distances[y].label == 'C')
                c_count++;
        }
        std::cout << "k = " << k_vals[x] << "\n";
        std::cout << "label: " << largest_of_3(a_count, b_count, c_count) << "\n";
        a_count = 0;
        b_count = 0;
        c_count = 0;
    }

    std::cout << "NORMALIZED VALUES\n";

    for (int x = 0; x < k_vals.size(); x++) {
        for (int y = 0; y < k_vals[x]; y++) {
            if (normal_distances[y].label == 'A')
                a_count++;
            if (normal_distances[y].label == 'B')
                b_count++;
            if (normal_distances[y].label == 'C')
                c_count++;
        }
        std::cout << "k = " << k_vals[x] << "\n";
        std::cout << "label: " << largest_of_3(a_count, b_count, c_count) << "\n";
        a_count = 0;
        b_count = 0;
        c_count = 0;
    }

    return 0;
}

//////////////STUPID FUNCTIONS THAT CAN BE CUT DOWN TO GENERALIZED ONES///////////////
//(And will be later)


double findMax(std::vector<Data> &data, int f) {
    double final_max = -1;
    if (f == 1) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f1 > final_max)
                final_max = data[x].f1;
        }
    }
    if (f == 2) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f2 > final_max)
                final_max = data[x].f2;
        }
    }
    if (f == 3) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f3 > final_max)
                final_max = data[x].f3;
        }
    }
    if (f == 4) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f4 > final_max)
                final_max = data[x].f4;
        }
    }
    return final_max;
}


double findMin(std::vector<Data> &data, int f) {
    double final_min = -1;
    if (f == 1) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f1 < final_min)
                final_min = data[x].f1;
        }
    }
    if (f == 2) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f2 < final_min)
                final_min = data[x].f2;
        }
    }
    if (f == 3) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f3 < final_min)
                final_min = data[x].f3;
        }
    }
    if (f == 4) {
        for (int x = 0; x < 15; x++) {
            if (data[x].f4 < final_min)
                final_min = data[x].f4;
        }
    }
    return final_min;
}
