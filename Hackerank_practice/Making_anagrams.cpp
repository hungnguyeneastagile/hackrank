//
//  Making_anagramss.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/12/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int makeAnagram(string a, string b) {
    
    return 0;
}

void revert_str(string &str) {
    for (int i = 0; i < str.length() / 2; i ++) {
        swap(str[i], str[str.length() - i -1]);
    }
}

int diagonalDifference(vector<vector<int>> arr) {
    int size = (int)arr.size();
    int sum_from_left = 0;
    int sum_from_right = 0;
    
    for (int i = 0; i < size; i ++ ) {
        vector<int> vec = arr[i];
        sum_from_left += vec[i];
        sum_from_right += vec[size - i -1];
    }
    return abs(sum_from_left - sum_from_right);
}

void plusMinus(vector<int> arr) {
    int positive = 0;
    int negative = 0;
    int zeos = 0;
    for (auto v : arr) {
        if (v == 0) {
            zeos ++;
        } else if (v > 0) {
            positive ++;
        } else if (v < 0) {
            negative ++;
        }
    }
    unsigned long size = arr.size();
    cout << (float)positive / size << endl;
    cout << (float)negative / size << endl;
    cout << (float)zeos / size << endl;
}

void staircase(int n) {
    for (int i = n; i > 0; i--) {
        // space
        for (int j = 0; j < i - 1; j ++) {
            cout << " ";
        }
        
        // stair
        for (int j = 0; j < (n- i + 1); j ++) {
            cout << "#";
        }
        
        cout << endl;
    }
    
}

void miniMaxSum(vector<int> arr) {
    if (arr.size() == 0) {
        return;
    }
    
    int min = arr[0];
    int max = arr[0];
    long long sum = 0;
    
    for (int v : arr) {
        if (v < min) {
            min = v;
        }
        if (v > max) {
            max = v;
        }
        sum += v;
    }
    
    cout << (sum - max) << " " << (sum - min) << endl;
    
}

int birthdayCakeCandles(vector<int> ar) {
    
    int max = INT_MIN;
    int times_set_max = 0;
    for (auto v : ar) {
        if (max < v) {
            max = v;
            times_set_max = 1;
        } else if (max == v) {
            times_set_max ++;
        }
    }
    return times_set_max;
}

//string timeConversion(string s) {
//    /*
//     * Write your code here.
//     */
//
//}

int max_of_four(int a, int b, int c, int d) {
    int max = a;
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    return max;
}

void update(int *a,int *b) {
    int _a = (*a + *b);
    *a = _a;
    
    
    int _b = *a - 2 * *b;
    if (_b < 0) {
        _b = -_b;
    }
    
    *b = _b;
}

vector<int> gradingStudents(vector<int> grades) {
    vector<int> gradedStudents;
    for (int i = 0; i < grades.size(); i ++) {
        int new_grade;
        if (grades[i] >= 38) {
            new_grade = (ceil((float)grades[i] / 5)) * 5;
            if ((new_grade - grades[i])  >= 3){
                new_grade = grades[i];
            }
        } else {
            new_grade = grades[i];
        }
        gradedStudents.push_back(new_grade);
    }
    
    return gradedStudents;
}

void countApplesAndOranges(int s, int t, int a, int b,
                           vector<int> apples, vector<int> oranges) {
    unsigned int apple_count = 0;
    for (auto apple : apples) {
        if ((apple + a) >= s && (apple + a) <= t) {
            apple_count ++;
        }
    }
    
    unsigned int orange_count = 0;
    for (auto orange : oranges) {
        if ((orange + b )>= s && (orange + b ) <= t) {
            orange_count ++;
        }
    }
    
    cout << apple_count << "\n" << orange_count << endl;
    
}

bool same_sign(int x, int y) {
    return (x >= 0) ^ (y < 0);
}
//
string kangaroo(int x1, int v1, int x2, int v2) {
    int distance = x2 - x1;
    int diff_vel = v1 - v2;
    if (!same_sign(distance, diff_vel)) {
        return "NO";
    }
    if (diff_vel == 0) {
        return distance == 0 ? "YES" : "NO";
    }
    
    return distance % diff_vel == 0 ? "YES" : "NO";

}



vector<int> breakingRecords(vector<int> scores) {
    vector<int> record(2, 0);

    int min = scores[0];
    int max = scores[0];
    for(int i = 1; i < scores.size(); i ++) {
        if (scores[i] < min) {
            record[0] ++;
        }
        if (scores[i] > max) {
            record[1] ++;
        }
    }
    return record;
}
int birthday(vector<int> s, int d, int m) {
    int ways = 0;
    int sum_to_m = 0;
    
    int size = (int)s.size();
    for (int i = 0; i < m && i < size; i ++) {
        sum_to_m += s[i];
    }
    if (sum_to_m == d) {
        ways ++;
    }
    
    int i = 1;
    
    // While has enough m index to go
    while ( (size - m - i + 1) > 0) {
        sum_to_m = sum_to_m - s[i - 1] + s[i - 1 + m];
        if (sum_to_m == d) {
            ways ++;
        }
        i ++;
    }
    
    return ways;
    
}


namespace Making_anagram {
    void run() {
        
        vector<int> s = {1 ,1 ,1 ,1 ,1 ,1};
        cout << birthday(s, 3, 2) << endl;
//
//        vector<int> s1 = {4};
//        cout << birthday(s1, 4, 1) << endl;
        
        vector<int> s2 = {1 ,2 ,1 ,3 ,2};
        cout << birthday(s2, 3, 2) << endl;
        
        vector<int> s3 = {};
        cout << birthday(s3, 3, 2) << endl;
        
        
        vector<int> s4 = {
            2, 3, 4, 4, 2, 1, 2, 5, 3, 4, 4, 3,
            4, 1, 3, 5, 4, 5, 3, 1, 1, 5, 4, 3,
            5, 3, 5, 3, 4, 4, 2, 4, 5, 2, 3, 2,
            5, 3, 4, 2, 4, 3, 3, 4, 3, 5, 2, 5,
            1, 3, 1, 4, 2, 2, 4, 3, 3, 3, 3, 4,
            1, 1, 4, 3, 1, 5, 2, 5, 1, 3, 5, 4,
            3, 3, 1, 5, 3, 3, 3, 4, 5, 2};
        
        cout << birthday(s4, 26, 8) << endl;
        
    }
}

