//
//  bacUser.cpp
//  mock
//
//  Created by 신예지 on 28/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <set>
using namespace std;

bool isPossible(string banned, string s) {
    if(banned.size() != s.size()) return false;
    
    for(int i=0; i<banned.size(); i++) {
        if(banned[i]=='*') continue;
        if(banned[i]!=s[i]) return false;
    }
    return true;
}

set<set<string>> answer;
void possibleSet(vector<vector<string>> candidate, int idx, set<string> s) {
    if(idx!=s.size()) return;
    if(idx==candidate.size()) {
        if(s.size()==candidate.size()) answer.insert(s);
        return;
    }
    for(int i=0; i<candidate[idx].size(); i++) {
        set<string> temp=s;
        temp.insert(candidate[idx][i]);
        possibleSet(candidate, idx+1, temp);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> candidate(banned_id.size());
    
    for(int i=0; i<banned_id.size(); i++) {
        for(int j=0; j<user_id.size(); j++) {
            if(isPossible(banned_id[i], user_id[j])) candidate[i].push_back(user_id[j]);
        }
    }
    
    set<string> s;
    possibleSet(candidate,0,s);
    return answer.size();
}

int main() {
    vector<string> user_id;
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");
    vector<string> banned_id;
    banned_id.push_back("*rodo");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    
    cout << solution(user_id, banned_id) << endl;
}
