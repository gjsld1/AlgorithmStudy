//
//  immigration.cpp
//  BinarySearch
//
//  Created by 신예지 on 06/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    long long* time = new long long[n];
    for(int i=0; i<n; i++) cin >> time[i];
    sort(time, time+n);
    
    long long min = time[0];
    long long max = time[n-1]*m;
    
    long long ans = max;
    
    while(min<=max) {
        long long mid = (min+max)/2;
        long long pass = 0;
        
        for(int i=0; i<n; i++) {
            pass += mid/time[i];
        }
        
        if(pass>=m) {
            max = mid-1;
            ans = mid;
        }
        else min = mid+1;
    }
    
    cout << ans;
}
