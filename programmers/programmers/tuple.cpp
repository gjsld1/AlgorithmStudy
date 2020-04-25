//
//  tuple.cpp
//  mock
//
//  Created by 신예지 on 28/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findPower(string s, int idx) {
    int sq=idx;
    
    while(sq++) {
        if(sq>=s.size()) break;
        if(s[sq]=='}' || s[sq]==',') break;
    };
    sq-=idx+1;
    
    return sq;
}

vector<int> solution(string s) {
    vector<pair<int,vector<int>>> tuple;
    
    int size=0, sq=0, t=0;
    vector<int> temp;
    for(int i=1; i<s.size()-1; i++) {
        if(s[i]=='{') {
            i++;
            sq=findPower(s,i);
            
            while(s[i]!='}') {
                if(s[i]==',') {
                    sq=findPower(s, i+1);
                    temp.push_back(t); size++; i++; t=0;
                    continue;
                }
                t+=(s[i]-'0')*pow(10,sq--);
                i++;
            }
            size++;
            temp.push_back(t); t=0; sq=findPower(s, i+1);
            tuple.push_back({size,temp});
            size=0; temp.clear();
        }

    }
    sort(tuple.begin(),tuple.end());
    
    vector<int> answer;
    answer.push_back(tuple[0].second[0]);
    for(int i=1; i<tuple.size(); i++) {
        for(int j=0; j<tuple[i].second.size(); j++) {
            if(find(answer.begin(), answer.end(), tuple[i].second[j])==answer.end()) {
                answer.push_back(tuple[i].second[j]);
            }
        }
    }
    
    return answer;
}

int main() {
    string str = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    for(int i=0; i<solution(str).size(); i++) {
        cout << solution(str)[i] << " ";
    }
    cout << endl;
}
