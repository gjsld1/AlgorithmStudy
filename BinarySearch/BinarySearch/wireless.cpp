//
//  wireless.cpp
//  BinarySearch
//
//  Created by 신예지 on 25/06/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int minDist(int* house, int n, int c) {
    int min = 1;
    int max = house[n-1]-house[0];
    int mid, ans=0;
    
    while(min <= max) {
        mid = (min+max)/2;
        int start = house[0];
        int install = 1;
        
        for(int i=1; i<n; i++) {
            if(mid<=house[i]-start) {
                install++;
                start = house[i];
            }
        }
        
        if(install >= c) {
            min = mid+1;
            ans = install;
        }
        else max = mid-1;
    }
    
    return ans;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    int* house = new int[n];
    for(int i=0; i<n; i++) cin >> house[i];
    sort(house, house+n);
    
    cout << minDist(house, n, c);
}
