//
//  task4.cpp
//  TestTasks
//
//  Created by Георгий Джаниашвили on 21/06/2021.
//  Copyright © 2021 Георгий Джаниашвили. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

std::vector<int> find_intersection( std::vector<std::vector<int>> vec, int f, int s){
    
    std::vector<int> intersection;
    int l = 0, r = 0;
    if ((vec[f][1] <= vec[s][0]) ||  (vec[s][1] <= vec[f][0])){
        //std::cout << "no inter" << std::endl;
    }
    else {
        l = std::max(vec[f][0], vec[s][0]);
        r = std::min(vec[f][1], vec[s][1]);
    }
    intersection.push_back(l);
    intersection.push_back(r);
    
    return intersection;
    
}

int main(int argc, const char **argv) {
    
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0]
                << " test4.txt" << std::endl;
        return 1;
    }
    
    std::string test_file_name(argv[1]);
    std::ifstream test_file;
    test_file.open(test_file_name);
    
    std::vector<std::vector<int>> vec;
    std::string line;
    std::vector<int> array;
    while (std::getline(test_file, line)) {
        int i = line.find(':');
        array.push_back(std::stoi(line.substr(0,i))*60 + std::stoi(line.substr(i+1,2)));
        line = line.erase(0,i+3);
        i = line.find(':');
        array.push_back(std::stoi(line.substr(0,i))*60 + std::stoi(line.substr(i+1,2)));
        vec.push_back(array);
        array.clear();
    }
    test_file.close();
    
    std::sort(vec.begin(), vec.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
      return a[0] < b[0];
    });

    int j = 1;
    int max_count = 0;
    std::vector<std::vector<int>> tmp_result;
    for(int i = 0; i < vec.size() - 1; i++){
        int tmp_count = 1;
        if(j != 1) {
            j = i + 1;
        }
        while(vec[i][1] > vec[j][0]) {
            std::vector<int> intersection;
            intersection = find_intersection(vec, i, j);
            if(intersection[0] > 0 && intersection[1] > 0){
                tmp_count++;
                tmp_result.push_back(intersection);
                intersection.clear();
            }
            if(j < vec.size()-1){
                j++;
            }
            else {
                break;
            }
        }
        if(max_count <= tmp_count) {
            max_count = tmp_count;
        } else {
            while(tmp_count != 1){
                tmp_result.pop_back();
                tmp_count--;
            }
        }
    }
    
    std::vector<std::vector<int>> result;
    int c = 0;
    for(int i = 0; i < tmp_result.size(); i++) {
        if(tmp_result[c][1] == tmp_result[c+1][0]) {
            while(tmp_result[c][1] == tmp_result[c+1][0]){
                c++;
            }
            result.push_back(std::vector<int> {tmp_result[i][0], tmp_result[c][1] });
            i = c;
        } else {
            result.push_back(std::vector<int> {tmp_result[i][0], tmp_result[i][1] });
            c = i;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] / 60 << ":";
            std::cout << std::setfill('0') << std::setw(2) << (result[i][j] % 60) << ' ';
        }
        std::cout << std::endl;
    }
}
