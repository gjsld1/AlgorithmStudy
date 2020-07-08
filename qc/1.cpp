//
//  main.cpp
//  qshell
//
//  Created by 신예지 on 2020/07/04.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> v) {
    vector<pair<int,int>> temp;
    for(int i=0; i<v.size(); i++) {
        temp.push_back({v[i],i});
    }
    sort(temp.begin(), temp.end());
    
    int ans=temp[0].first-temp[v.size()-1].first;
    for(int i=v.size()-1; i>=0; i--) {
        for(int j=0; j<v.size(); j++) {
            if(i==j) continue;
            if(temp[i].second<temp[j].second) {
                ans= (ans>temp[i].first-temp[j].first)? ans : temp[i].first-temp[j].first;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n=10;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    cout << solution(n,v);
}
