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
    int digit10 = (n-(100*digit100))/10;
    int digit1 = n%10;
    
    for(int i=1; i<digit100; i++) {
        for(int j=0; j<=(9-i)/2; j++) ans++;
        for(int j=1; i-(2*j)>=0; j++) ans++;
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << countNum(n);
}
