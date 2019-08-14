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

map<long long, long long> mapR;

string checkTrue(long sYear, long long eYear) {
    string ans="true";
    
    if(mapR[eYear]==0) return "maybe";
    if(mapR[sYear]==0) ans="maybe";
    
    map<long long, long long>::iterator iter = mapR.begin();
    while(iter->first <= sYear) iter++;
    if(iter->first==eYear) return "maybe";
    
    map<long long, long long>::iterator it=mapR.end();
    it--;
    while(it->first > eYear) it--;
    long long tp = max_element(iter,it, [](const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
        return p1.second < p2.second; })->second;
    if(tp >= mapR[eYear]) return "false";
    
    /*
    while(iter->first < eYear) {
        map<long long, long long>::iterator temp = iter;
        if((++temp)->first - iter->first>1) ans="maybe";
        if(iter++->second >= mapR[eYear]) return "false";
    }
     */
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        mapR.insert({a,b});
    }
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        long long sYear, eYear;
        cin >> sYear >> eYear;
        
        cout << checkTrue(sYear, eYear) << endl;
    }
}
