//
//  baekjoon 1654
//  cableCut.cpp
//  BinarySearch
//
//  Created by 신예지 on 07/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    
    long long* length = new long long[k];
    long long sum = 0;
    for(int i=0; i<k; i++) {
        cin >> length[i];
        sum += length[i];
    }
    sort(length, length+k);
    
    long long min = length[0]/n;
    long long max = sum;
    
    long long ans = 0;
    
    while(min<=max) {
        long long mid = (min+max)/2;
        long long count = 0;
        
        if(mid != 0) for(int i=0; i<k; i++) count += length[i]/mid;
        
        
        if(count>=n) {
            min = mid+1;
            ans = mid;
        }
        else max = mid-1;
    }
    
    cout << ans;
}
