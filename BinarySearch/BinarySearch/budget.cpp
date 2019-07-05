//
//  budget.cpp
//  BinarySearch
//
//  Created by 신예지 on 01/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, budget;
    cin >> n;
    
    int* request = new int[n];
    
    for(int i=0; i<n; i++) cin >> request[i];
    cin >> budget;
    
    int min = request[0];
    int max = request[n-1];
    
    int ans = 0;
    
    while(min<=max) {
        int mid = (min+max)/2;
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            if(request[i] >= mid) sum+=mid;
            else sum+=request[i];
        }
        
        if(sum > budget) {
            max=mid-1;
            ans = mid;
        }
        else if(sum < budget) min=mid+1;
    }
    cout << ans;
}
