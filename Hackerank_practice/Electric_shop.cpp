//
//  Electric_shop.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 10/2/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//


#include <vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    sort(keyboards.begin(), keyboards.end());
    sort(drives.begin(), drives.end());
    
    int k = int(keyboards.size() - 1);
    int d = int(drives.size() - 1);
    
    int max = -1;
    
    while (k >= 0 && d >= 0) {
        max = keyboards[k] + drives[d];
        if (max <= b) {
            return max;
        }
        
        max = -1;
        if (k >= 1 && d >= 1) {
            if (keyboards[k - 1] < drives[d - 1]) {
                k --;
            } else {
                d --;
            }
            
            continue;
        } else if (k > 1) {
            k --;
            continue;
        } else if (d > 1) {
            d --;
            continue;
        } else {
            k --;
            d --;
        }
    }
    
    return max;
}

int main () {
    vector<int> kb1 = {3, 1,};
    vector<int> drives1 = {5, 2, 8};
    int money = 10;
    assert(getMoneySpent(kb1, drives1, money) == 9);
    
    vector<int> kb2 = {5};
    vector<int> drives2 = {4};
    int money2 = 5;
    assert(getMoneySpent(kb2, drives2, money2) == -1);
    
    
    vector<int> kb3 = {4};
    vector<int> drives3 = {5};
    int money3 = 5;
    assert(getMoneySpent(kb2, drives2, money3) == -1);
    
    
    vector<int> kb4 = {6};
    vector<int> drives4 = {1, 2, 3 ,5};
    int money4 = 11;
    assert(getMoneySpent(kb4, drives4, money4) == 11);
    
}
