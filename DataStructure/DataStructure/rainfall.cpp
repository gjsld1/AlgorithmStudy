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

map<long long, long long> mapRain;

string checkTure(long sYear, long long eYear) {
    string ans="true";
    
    long long year = eYear-sYear;
    
    if(mapRain.find(eYear)==mapRain.end()) return "maybe";
    for(int i=0; i<year-1; i++) {
        long long tmp = sYear;
        if(mapRain.find(++tmp)!=mapRain.end()) {
            if(mapRain[eYear]-mapRain[tmp]>=0) continue;
            else return "false";
        }
        else ans="maybe";
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        mapRain.insert({a,b});
    }
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        long long sYear, eYear;
        cin >> sYear >> eYear;
        
        cout << checkTure(sYear, eYear) << endl;
    }
}
