//
//  baekjoon 7453
//  sumZero.cpp
//  BruteForce
//
//  Created by 신예지 on 21/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];
    int* d = new int[n];
    
    for(int i=0; i<n; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    
    int* sumAB = new int[n*n];
    map<int,int> m;
    
    int idx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sumAB[idx++] = a[i]+b[j];
            int temp = c[i]+d[j];
            
            if(m.find(temp)!=m.end()) m[temp]=m.find(temp)->second+1;//m.insert({temp,m.find(temp)->second+1});
            else m.insert({temp,1});
        }
    }
    
    int ans = 0;
    for(int i=0; i<n*n; i++) {
        if(m.find(-sumAB[i])!=m.end()) ans+=m.find(-sumAB[i])->second;
    }
    
    cout << ans;
}
