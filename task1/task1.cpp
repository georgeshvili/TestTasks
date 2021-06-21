//
//  task1.cpp
//  TestTasks
//
//  Created by Георгий Джаниашвили on 21/06/2021.
//  Copyright © 2021 Георгий Джаниашвили. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>

double percentile(std::vector<int> array, double percentile){
    //std::sort(array.begin(), array.end());
    double realIndex = percentile*(array.size() - 1);
    int index = (int) realIndex;
    double frac = realIndex - index;
    if(index + 1 < array.size())
        return array[index] *(1-frac) + array[index+1]*frac;
    else
        return array[index];
}

//std::vector<int> max_and_min(std::vector<int> array){
//
//    int smallest_element = array[0];
//    int largest_element = array[0];
//    for(int i = 1; i < array.size(); i++)
//    {
//        if(array[i] < smallest_element)
//        {
//           smallest_element = array[i];
//        }
//        if(array[i] > largest_element)
//        {
//           largest_element = array[i];
//        }
//    }
//    std::vector<int> array_max_min = { largest_element, smallest_element };
//    return array_max_min;
//
//}

double average(std::vector<int> array){
    double sum = 0;
    for(int i = 0; i < array.size(); i++){
        sum += array[i];
    }
    return sum / array.size();
}

int main(int argc, const char **argv) {
    
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0]
                << " test1.txt" << std::endl;
        return 1;
    }
    
    std::string test_file_name(argv[1]);
    std::ifstream test_file;
    test_file.open(test_file_name);
    std::vector<int> array;
    std::string line;
    while (std::getline(test_file, line)) {
        array.push_back(std::stoi(line));
    }
    test_file.close();
    
    std::sort(array.begin(), array.end());
    std::cout << std::setprecision(2) << std::fixed << percentile(array, 0.9) << std::endl;
    std::cout << std::setprecision(2) << std::fixed << percentile(array, 0.5) << std::endl;
    std::cout << std::setprecision(2) << std::fixed << (double) array[array.size() - 1] << std::endl;
    std::cout << std::setprecision(2) << std::fixed << (double) array[0] << std::endl;
    std::cout << std::setprecision(2) << std::fixed << average(array) << std::endl;
    
    return 0;
}
