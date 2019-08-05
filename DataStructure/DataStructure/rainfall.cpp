//
//  baekjoon 2094
//  rainfall.cpp
//  DataStructure
//
//  Created by 신예지 on 05/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    int* info = new int[n];
    int sYear;
    cin >> sYear >> info[0];
    
    for(int i=1; i<n; i++) {
        int temp;
        cin >> temp >> info[i];
    }
    
    cin >> m;
    for(int i=0; i<m; i++) {
        int start, end;
        cin >> start >> end;
        
        string ans = "true";
        start -= sYear;
        end -= sYear;
        
        for(int j=start+1; j<end; j++) {
            if(info[j]>info[end]) {
                ans="false";
                break;
            }
        }
        cout << ans << endl;
    }
    /*
    vector<pair<long long,long long>> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    cin >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        
        vector<pair<long long>>::iterator iter = find(v.begin(), v.end());
    }
     */
}
