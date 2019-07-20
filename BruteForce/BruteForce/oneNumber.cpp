//
//  baekjoon 1065
//  oneNumber.cpp
//  BruteForce
//
//  Created by 신예지 on 17/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int countNum(int n) {
    if(n<=99) return n;
    if(n==1000) n--;
    
    int ans = 99;
    
    int digit100 = n/100;
    
    for(int i=1; i<=digit100; i++) {
        for(int j=0; j<=(9-i)/2; j++) {
            if(100*i+10*(i+j)+(i+j+j) > n) continue;
            ans++;
        }
        for(int j=1; i-(2*j)>=0; j++) {
            if(100*i+10*(i-j)+(i-j-j) > n) continue;
            ans++;
        }
    }
    
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << countNum(n);
}
