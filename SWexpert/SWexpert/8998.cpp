//
//  8998.cpp
//  SWexpert
//
//  Created by 신예지 on 23/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tc, c=1;
    cin >> tc;
    
    while(tc--) {
        int n;
        cin >> n;
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            int t,d;
            cin >> t >> d;
            v.push_back({d,t});
        }
        sort(v.begin(), v.end());
        
        int* schedule = new int[v[n-1].first+1]();
        
        for(int i=0; i<n; i++) {
            int check=0;
            int lastDay=v[i].first;
            
            while(check != v[i].second) {
                if(!schedule[lastDay]) {
                    schedule[lastDay]=1;
                    check++;
                }
                lastDay--;
            }
        }
        
        int startDay=1;
        while(!schedule[startDay]) startDay++;
        
        cout << "#" << c << " " << startDay-1 << endl;
    }
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // 시간초과 방지
    
    int tc, c=1;
    cin >> tc;
    
    while(tc--) {
        int n;
        cin >> n;
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            int t, d;
            cin >> t >> d;
            v.push_back({d,t});
        }
        sort(v.begin(),v.end());
        
        int endDay= v[n-1].first;
        int startDay = endDay-v[n-1].second+1;
        
        for(int i=n-2; i>=0; i--) {
            if(v[i].first>=startDay) {
                int originStart = startDay;
                startDay = v[i].first-v[i].second+1;
                startDay -= v[i].first-originStart+1;
            }
            else startDay = v[i].first-v[i].second+1;
        }
        
        cout << "#" << c << " " << startDay-1 << endl;
    }
}
