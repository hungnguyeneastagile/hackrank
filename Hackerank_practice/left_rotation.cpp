//
//  left_rotation.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/11/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> b;
    
    for (int i = 0; i < a.size(); i++) {
        int index = i + d;
        if (index > a.size() - 1 ) {
            index = index - a.size();
        }
        int current = a[index];
        b.push_back(current);
    }
    return b;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {1 ,2 ,3 ,4 ,5};
    
    vector<int> b = rotLeft(a, 4);
    for (int i : b) {
        cout << i;
    }
    
    return 0;
}
