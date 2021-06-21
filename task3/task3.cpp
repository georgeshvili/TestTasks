//
//  task3.cpp
//  TestTasks
//
//  Created by Георгий Джаниашвили on 21/06/2021.
//  Copyright © 2021 Георгий Джаниашвили. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>

//float get_random() {
//    static std::default_random_engine e;
//    static std::uniform_real_distribution<> dis(1, 5); // rage 0 - 1
//    return dis(e);
//}

int main(int argc, const char **argv) {
    
//    std::vector<float> nums;
//    for (int i{}; i != 80; ++i)
//        nums.emplace_back(get_random());
//
//    for (int i = 0; i < 80; i++){
//        if(i % 16 == 0)
//            std::cout << std::endl;
//        std::cout << std::setprecision(2) << std::fixed << nums[i] << std::endl;
//    }
    
    if(argc != 6) {
        std::cerr << "Usage: " << argv[0]
                << " Cash1.txt" "Cash2.txt Cash3.txt Cash4.txt Cash5.txt" << std::endl;
        return 1;
    }
    
    std::string test_file_1_name(argv[1]);
    std::string test_file_2_name(argv[2]);
    std::string test_file_3_name(argv[3]);
    std::string test_file_4_name(argv[4]);
    std::string test_file_5_name(argv[5]);
    std::ifstream test_file;
    
    test_file.open(test_file_1_name);
    std::vector<float> cash1;
    float a;
    while (test_file >> a) {
        cash1.push_back(a);
    }
    test_file.close();
    
    test_file.open(test_file_2_name);
    std::vector<float> cash2;
    while (test_file >> a) {
        cash2.push_back(a);
    }
    test_file.close();
    
    test_file.open(test_file_3_name);
    std::vector<float> cash3;
    while (test_file >> a) {
        cash3.push_back(a);
    }
    test_file.close();
    
    test_file.open(test_file_4_name);
    std::vector<float> cash4;
    while (test_file >> a) {
        cash4.push_back(a);
    }
    test_file.close();
    
    test_file.open(test_file_5_name);
    std::vector<float> cash5;
    while (test_file >> a) {
        cash5.push_back(a);
    }
    test_file.close();
    
    std::vector<float> sum_cashes;
    for(int i = 0; i < 16; i++) {
        sum_cashes.push_back(cash1[i] + cash2[i] + cash3[i] + cash4[i] + cash5[i]);
    }
//    for (const auto& i : sum_cashes) std::cout << i << " ";
//    std::cout << std::endl;
    
    std::vector<float>::iterator result;
    result = std::max_element(sum_cashes.begin(), sum_cashes.end());
    std::cout <</* "max element at: " <<*/ std::distance(sum_cashes.begin(), result) + 1 << std::endl;
    
    return 0;
}
