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

int main() {
    int n, c;
    cin >> n >> c;
    
    int* house = new int[n];
    for(int i=0; i<n; i++) cin >> house[i];
    
    sort(house, house+n);
    
    int left = 1;
    int right = house[n-1];
    int mid, answer=0;
    
    while(left <= right) {
        mid = (left+right)/2;
        int install = 1;
        int start = house[0];
        
        for(int i=1; i<n; i++) {
            int dist = house[i]-start;
            
            if(mid <= dist) {
                install++;
                start = house[i];
            }
        }
        
        if(install >= c) {
            left = mid+1;
            answer = mid;
        }
        else right = mid-1;
    }
    
    cout << answer;
}
