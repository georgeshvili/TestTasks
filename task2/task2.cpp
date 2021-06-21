//
//  task2.cpp
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
#include <cmath>

float polygon_area(std::vector<std::vector<float>> polygon, int n) {
    float area = 0.0;
    
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (polygon[j][0] + polygon[i][0]) * (polygon[j][1] - polygon[i][1]);
        j = i;
    }
 
    return std::abs(area / 2.0);
}

float triangle_area(float dX0, float dY0, float dX1, float dY1, float dX2, float dY2) {
    float dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0));
    return std::abs(dArea / 2.0);
}

void check(std::vector<std::vector<float>> quadrangle, std::vector<float> point, int c){
    
    float P1 = triangle_area(quadrangle[0][0], quadrangle[0][1], quadrangle[1][0], quadrangle[1][1], point[0], point[1]);
    float P2 = triangle_area(quadrangle[1][0], quadrangle[1][1], quadrangle[2][0], quadrangle[2][1], point[0], point[1]);
    float P3 = triangle_area(quadrangle[2][0], quadrangle[2][1], quadrangle[3][0], quadrangle[3][1], point[0], point[1]);
    float P4 = triangle_area(quadrangle[3][0], quadrangle[3][1], quadrangle[0][0], quadrangle[0][1], point[0], point[1]);
    float all_area = polygon_area(quadrangle, 4);
    
    if(P1 + P2 + P3 + P4 != all_area) {
        std::cout << "Точка " << c << ": { " << point[0] << ", " << point[1] << " } снаружи" << std::endl;
    } else {
        for(int i = 0; i < 4; i++) {
            float f_line, s_line, t_line;
            if(i < 3) {
                f_line = sqrt(pow(quadrangle[i + 1][0] - quadrangle[i][0], 2) +
                                  pow(quadrangle[i + 1][1] - quadrangle[i][1], 2));
                s_line = sqrt(pow(point[0] - quadrangle[i][0], 2) +
                                  pow(point[1] - quadrangle[i][1], 2));
                t_line = sqrt(pow(quadrangle[i + 1][0] - point[0], 2) +
                                  pow(quadrangle[i + 1][1] - point[1], 2));
            } else {
                f_line = sqrt(pow(quadrangle[0][0] - quadrangle[i][0], 2) +
                                  pow(quadrangle[0][1] - quadrangle[i][1], 2));
                s_line = sqrt(pow(point[0] - quadrangle[i][0], 2) +
                                  pow(point[1] - quadrangle[i][1], 2));
                t_line = sqrt(pow(quadrangle[0][0] - point[0], 2) +
                                  pow(quadrangle[0][1] - point[1], 2));
            }
            
            if(s_line == 0 || t_line == 0) {
                std::cout << "Точка " << c << ": { " << point[0] << ", " << point[1] << " } на одной из вершин" << std::endl;
                break;
            } else {
                if(f_line == s_line + t_line) {
                    std::cout << "Точка " << c << ": { " << point[0] << ", " << point[1] << " } на одной из сторон" << std::endl;
                    break;
                } else {
                    if(i == 3) {
                    std::cout << "Точка " << c << ": { " << point[0] << ", " << point[1] << " } внутри" << std::endl;
                    }
                }
            }
        }
    }
}

int main(int argc, const char **argv) {
    
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0]
                << " test1.txt" "test2.txt" << std::endl;
        return 1;
    }
    
    std::string test_file_1_name(argv[1]);
    std::ifstream test_file_1;
    test_file_1.open(test_file_1_name);
    
    float a;
    int i = 1;
    std::vector<std::vector<float>> quadrangle;
    std::vector<float> side;
    while (test_file_1 >> a) {
        side.push_back(a);
        if(i == 2) {
            quadrangle.push_back(side);
            i = 0;
            side.clear();
        }
        i++;
    }
    test_file_1.close();
    
    for (int i = 0; i < quadrangle.size(); i++) {
        for (int j = 0; j < quadrangle[i].size(); j++) {
            std::cout << quadrangle[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
    std::string test_file_2_name(argv[2]);
    std::ifstream test_file_2;
    test_file_2.open(test_file_2_name);
    
    std::vector<float> point;
    int c = 1;
    i = 1;
    while (test_file_2 >> a) {
        if(c == 101)
            break;
        point.push_back(a);
        if(i == 2) {
            check(quadrangle, point, c);
            i = 0;
            point.clear();
            c++;
        }
        i++;
    }
    test_file_2.close();
    
    return 0;
}
