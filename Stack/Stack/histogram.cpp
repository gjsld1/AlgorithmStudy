//
//  baekjoon 1725 & leetcode largest rectangle in histogram
//  histogram.cpp
//  Stack
//
//  Created by 신예지 on 27/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int* heights = new int[n];
    for(int i=0; i<n; i++) cin>>heights[i];
    
    stack<int> s;
    int height;
    int ans = 0;
    
    for(int i=0; i<=n; i++) {
        if(i==n) height=0;
        else height=heights[i];
        
        if(s.empty() || height>=heights[s.top()]) s.push(i);
        else {
            int t = s.top(); s.pop();
            int width;
            if(s.empty()) width = i;
            else width = i-1-s.top();
            ans = max(ans, heights[t]*width);
            i--;
        }
    }
    cout << ans;
}
