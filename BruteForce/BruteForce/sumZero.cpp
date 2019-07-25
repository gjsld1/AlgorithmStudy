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
    int* sumCD = new int[n*n];
    int idx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sumAB[idx] = a[i]+b[j];
            sumCD[idx++] = c[i]+d[j];
        }
    }
    sort(sumCD, sumCD+n*n);
    
    int ans = 0;
    for(int i=0; i<n*n; i++) {
        if(binary_search(sumCD, sumCD+n*n, -sumAB[i])) ans++;
    }
    cout << ans;
}
