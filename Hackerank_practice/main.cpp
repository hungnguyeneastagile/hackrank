//
//  main.cpp
//  Hackerank_practice
//
//  Created by batphonghan on 9/11/18.
//  Copyright © 2018 trusting_social. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <iosfwd>
#include "Making_anagrams.h"

using namespace std;

int sockMerchant(int n, int ar_count, int *ar) {
    
    return 3;
}

long repeatedString(string s, long n) {
    
    long number_a_in_s = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'a') {
            number_a_in_s ++;
        }
    }
    
    long times_of_s_to_compare = n / s.length();
    long remain_s_to_compare = n % s.length();
    
    long number_a_in_remain = 0;
    for (int i = 0; i < remain_s_to_compare; i++) {
        if (s.at(i) == 'a') {
            number_a_in_remain ++;
        }
    }
    
    return times_of_s_to_compare * number_a_in_s + number_a_in_remain;
}

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int pairs = 0;
    for (int i = 0; i < n -1; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if ((ar[i] + ar[j]) % k == 0) {
                pairs ++;
            }
        }
    }
    return pairs;
}

int migratoryBirds(vector<int> arr) {
    unsigned long size = arr.size();
    vector<int> _arr(size, 0);
    for(int i = 0; i < size; i++) {
        _arr[arr[i]] ++;
    }
    int index_max = 0;
    for(int i = 0; i < size; i++) {
        if( _arr[i] > _arr[index_max]) {
            index_max = i;
        }
    }
    return index_max;
}

//
//string dayOfProgrammer(int year) {
//    int days = 31 + 29 + 31 + 30;
//    string result("");
//    result += "123";
//    return result;
//}

std::vector<std::string> top_color(std::vector<std::vector<std::string>> image) {
    // TODO change me!
    vector<string> result;
    unordered_map<string, int> colors;
    int max =0;
    for (auto _color : image) {
        for (auto __color : _color) {
            int times = colors[__color];
            times ++;
            colors[__color] = times;
            if (max < times) {
                max = times;
            }
        }
    }
    for (auto color : colors) {
        int times = color.second;
        if (times == max) {
            result.push_back(color.first);
        }
    }
    
    return result;
}
//std::vector<std::string> split(const std::string& s, char delimiter)
//{
//    std::vector<std::string> tokens;
//    std::string token;
//    std::istringstream tokenStream(s);
//    while (std::getline(tokenStream, token, delimiter))
//    {
//        tokens.push_back(token);
//    }
//    return tokens;
//}

class Foo {
public:
    int value() { return 5; }
    virtual int v_value() { return 5; }
};

class Bar : public Foo {
public:
    int value() { return 10; }
    virtual int v_value() { return 10; }
};


int main(int argc, const char * argv[]) {
    
//    cout << dayOfProgrammer(100) << endl;
//    std::vector<std::vector<std::string>> image =
//    { {"red","blue","red"},
//      {"red","yellow","red"},
//        {"red","green","red"} };
//
//    std::vector<std::string> top_color_result = top_color(image);
//
//    cout << "Result: " << endl;
//    for (auto color : top_color_result) {
//        cout << color;
//    }
//
    Bar *b = new Bar();
    Foo *f = (Foo *)b;
    printf("%i \n", f->value());
    printf("V %i \n", f->v_value());
    
    return 0;
}
