//
//  new_year_chaos.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/12/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int> q, int i) {
    int temp = q[i];
    q[i] = q[i - 1];
    q[i - 1] = temp;
}

void minimumBribes(vector<int> q) {
    vector<int> track_move (q.size(), 0);
    
    int times_swap = 0;
    
    int current_index = 1;
    
    while(current_index < q.size() && current_index > 0) {
        int current = q[current_index];
        int pre = q[current_index - 1];
        
        if (q[current_index] < q[current_index - 1]) {
            int temp = q[current_index];
            q[current_index] = q[current_index - 1];
            q[current_index - 1] = temp;
            
            current_index--;
            track_move[current_index - 1] ++;
        }
        
        current_index ++;
    }
    
    bool isTooChaotic = false;
    for (int i = 1; i < q.size(); i ++) {
        if (q[i] < q[i -1]) {
            isTooChaotic = true;
            break;
        }
    }
    
    if (isTooChaotic) {
        cout << "Too chaotic" << endl;
    } else {
        cout << times_swap << endl;
    }
}


int main() {
    cout << "HIIII" << endl;
    
//    vector<int> people = {2 ,1 ,5 ,3 ,4};
    vector<int> people = {1 ,2 ,5 ,3 ,7 ,8 ,6 ,4};
    
    minimumBribes(people);
}
