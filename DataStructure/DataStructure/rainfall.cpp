//
//  baekjoon 2094
//  rainfall.cpp
//  DataStructure
//
//  Created by 신예지 on 05/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<long long, long long> map;
    for(int i=0; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        map.insert({a,b});
    }
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        long long sYear, eYear;
        cin >> sYear >> eYear;
        
        string ans = "false";
        
        long long year = eYear-sYear;
        long long* check = new long long[year]();
        
        long long temp = eYear;
        while(map.find(temp)==map.end()) temp--;
        long long endRain = map[temp];
        if(temp!=eYear) check[year-1] = 0;
        else check[year-1] = 1;
        
        int idx=0;
        for(int i=0; i<year-1; i++) {
            long long tmp = sYear;
            if(map.find(++tmp)!=map.end()) {
                if(endRain-map[tmp]>=0) check[idx++]=1;
                else check[idx++]=-1;
            }
            else check[idx++]=0;
        }
        
        if(find(check, check+year, -1)!=check+year) ans="false";
        else {
            if(find(check, check+year, 0)!=check+year) ans="maybe";
            else ans="true";
        }
        cout << ans << endl;
    }
}
