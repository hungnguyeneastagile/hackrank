//
//  timeConversion.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/24/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string timeConversion(string s) {
    /*
     * Write your code here.
     */
//    cout << s.length();
    unsigned long length = s.length();
    char c = s[length - 2];
    
    string removed_format = s.erase(length - 2, length - 1);
    
    string hoursStr = s.substr(0,2);
    int hours = stoi(hoursStr);
    if (c == 'P') {
        if (hours != 12) {
            hours += 12;
        }
        
    } else {
        if (hours == 12) {
            hours = 0;
        }
    }
    hoursStr = to_string(hours);
    if (hoursStr.size() == 1) {
        hoursStr = "0" + hoursStr;
    }
    removed_format = s.replace(0, 2, hoursStr);
    return removed_format;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd((b % a), a);
}

int gcd(vector<int> a) {
    int result = a[0];
    for (int i = 1; i < a.size(); i++) {
        result = gcd(result, a[i]);
    }
    
    return result;
}

int getTotalX(vector<int> a, vector<int> b) {
    /*
     * Write your code here.
     */
    int gcd_b = gcd(b);
    int gcd_a = gcd(a);
    long long mul = 1;
    for (int v : a) {
        mul *= v;
    }
    long long lcm_a = mul / gcd_a;
    
    int times = 0;
    while (lcm_a < gcd_b) {
        times ++;
        lcm_a *= times;
    }
    
    return times;
}
string dayOfProgrammer(int year) {
    
    
    int days_without_feb = (31 +  31 + 30 + 31 + 30 + 31 + 31);
    
    int feb;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        feb = 29;
    } else {
        feb = 28;
    }
    
    int remain_day = 256 - days_without_feb - feb;
    
    if (year == 1918) {
        remain_day += 14;
    }
    string result = to_string(remain_day) + ".09." + to_string(year);
    
    return result;
}

void bonAppetit(vector<int> bill, int k, int b) {
    unsigned long size = bill.size();
    
    int sum = 0;
    for (int i = 0; i < size; i ++) {
        if (i != k) {
            sum += bill[i];
        }
    }
    int shared = sum / 2;
    if (shared == b) {
        cout << "Bon Appetit" << endl;
    } else {
        cout << (b - shared) << endl;
    }
    
    
}

int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    if (n % 2 == 0) {
        n += 1;
    }
    int times_from_head = p / 2;
    int times_from_tail = (n - p) / 2;
    
    if (times_from_head < times_from_tail) {
        return  times_from_head;
    }
    return times_from_tail;
}


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


