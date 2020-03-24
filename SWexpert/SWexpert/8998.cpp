//
//  8998.cpp
//  SWexpert
//
//  Created by 신예지 on 23/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // 시간초과 방지
    
    int tc;
    cin >> tc;
    for(int t=1; t<=tc; t++) {
        int n;
        cin >> n;
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            int t, d;
            cin >> t >> d;
            v.push_back({d,t});
        }
        sort(v.begin(),v.end());
        
        int startDay = v.back().first-v.back().second+1;
        v.pop_back();
        
        while(!v.empty()) {
            
            int end = v.back().first;
            int start = end-v.back().second+1;
            v.pop_back();
            
            if(end>= startDay) startDay = start-(end-startDay+1);
            else startDay = start;
        
        }
        
        cout << "#" << t << " " << startDay-1 << endl;
    }
}
