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

string checkTure(long sYear, long long eYear) {
    string ans="true";
    
    map<long long, long long>::iterator iter = mapR.begin();
    if(mapR.find(eYear)==mapR.end()) return "maybe";
    if(mapR.find(sYear)==mapR.end()) ans="maybe";
    while(iter->first <= sYear) iter++;
    
    while(iter->first < eYear) {
        map<long long, long long>::iterator temp = iter;
        temp++;
        if(temp->first - iter->first>1) {
            ans = "maybe";
        }
        if(iter->second > mapR[eYear]) return "false";
        iter++;
    }
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
        
        cout << checkTure(sYear, eYear) << endl;
    }
}
