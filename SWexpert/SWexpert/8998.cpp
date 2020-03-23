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
        
        int idx=1;
        while(!schedule[idx]) idx++;
        
        cout << "#" << c << " " << idx-1 << endl;
    }
}
