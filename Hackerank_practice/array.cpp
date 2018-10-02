//
//  array.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/11/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int max_sum = INT_MIN;
    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 4; j++) {
            
            int value1 = arr.at(i + 0).at(j);
            int value2 = arr.at(i + 0).at(j + 1);
            int value3 = arr.at(i + 0).at(j + 2);
            
            int value4 = arr.at(i + 1).at(j + 1);
            
            int value5 = arr.at(i + 2).at(j + 0);
            int value6 = arr.at(i + 2).at(j + 1);
            int value7 = arr.at(i + 2).at(j + 2);
            int sum = value1 + value2 + value3 + value4 + value5 + value6 + value7;
            
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    
    return max_sum;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> arr
    =  {{ 1, 1, 1, 0, 0, 0},
        { 0, 1, 0, 0, 0, 0},
        { 1, 1, 1, 0, 0, 0},
        { 0, 0, 2, 4, 4, 0},
        { 0, 0, 0, 2, 0, 0},
        { 0, 0, 1, 2, 4, 0} };
    
    
    
   vector<vector<int>> arr2 =
    { {0, -4, -6, 0, -7, -6},
    {-1, -2, -6, -8, -3, -1},
    {-8, -4, -2, -8, -8, -6},
    {-3, -1, -2, -5, -7, -4},
    {-3, -5, -3, -6, -6, -6},
    {-3, -6, 0, -8, -6, -7} };
    
    
    
    cout << hourglassSum(arr) << endl;
    cout << hourglassSum(arr2) << endl;
    
    
    cout << "HI" << endl;
}
