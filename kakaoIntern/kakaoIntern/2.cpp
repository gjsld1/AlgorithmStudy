//
//  2.cpp
//  kakaoIntern
//
//  Created by 신예지 on 09/11/2019.
//  Copyright © 2019 신예지. All rights reserved.
//
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a.length()<b.length();
}

vector<vector<int>> parsing(string s) {
    vector<string> parsed;
    
    for(int i=1; i<s.length()-1; i++) {
        if(s[i]=='{') {
            int j=i+1;
            while(s[j]!='}') j++;
            
            parsed.push_back(s.substr(i+1, j-i-1));
            i=j+1;
        }
    }
    
    sort(parsed.begin(),parsed.end(),comp);
    
    vector<vector<int>> sets;
    for(int i=0; i<parsed.size(); i++) {
        vector<int> temp;
        for(int j=0; j<parsed[i].length(); j++) {
            int k=j+1;
            while(k!=parsed[i].length() && parsed[i][k]!=',') k++;
            
            temp.push_back(atoi(parsed[i].substr(j,k-j).c_str()));
            j+=k-j;
        }
        sets.push_back(temp);
    }
    return sets;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> sets = parsing(s);
    set<int> check;
    
    for(int i=0; i<sets.size(); i++) {
        for(int j=0; j<sets[i].size(); j++) {
            if(check.find(sets[i][j])==check.end()) {
                check.insert(sets[i][j]);
                answer.push_back(sets[i][j]);
            }
        }
    }
    
    return answer;
}

int main() {
    vector<int> ans = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

