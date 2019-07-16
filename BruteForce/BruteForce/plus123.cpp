//
//  baekjoon 9095
//  plus123.cpp
//  BruteForce
//
//  Created by 신예지 on 15/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {
    if(n<=1) return 1;
    return n * factorial(n-1);
}

int combination(vector<int> v) {
    int c;
    
    int one = 0;
    int two = 0;
    int three = 0;
    
    for(int i=0; i<v.size(); i++) {
        if(v[i]==1) one++;
        else if(v[i]==2) two++;
        else if(v[i]==3) three++;
    }
    
    c = factorial(one+two+three);
    c /= factorial(one)*factorial(two)*factorial(three);
    
    return c;
}
int main() {
    int n;
    cin >> n;
    
    int max2 = n/2;
    
    vector<int> one;
    for(int i=0; i<n; i++) one.push_back(1);
    
    vector<vector<int>> line;
    line.push_back(one);
    
    for(int i=0; i<max2; i++) {
        one.erase(one.begin());
        one.erase(one.begin());
        one.push_back(2);
        
        line.push_back(one);
    }
    
    for(int i=0; i<line.size(); i++) {
        vector<int> temp = line[i];
        while(temp.size()>=3 && temp[2]==1) {
            temp.erase(temp.begin());
            temp.erase(temp.begin());
            temp.erase(temp.begin());
            temp.push_back(3);
            
            line.push_back(temp);
        }
    }
    
    int ans = 0;
    for(int i=0; i<line.size(); i++) ans += combination(line[i]);
    
    cout << ans;
}
