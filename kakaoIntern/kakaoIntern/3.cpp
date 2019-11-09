//
//  3.cpp
//  kakaoIntern
//
//  Created by 신예지 on 09/11/2019.
//  Copyright © 2019 신예지. All rights reserved.
//
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(string user, string ban) {
    if(user.length()!=ban.length()) return false;
    
    for(int i=0; i<ban.length(); i++) {
        if(ban[i]=='*') continue;
        else {
            if(ban[i]!=user[i]) return false;
        }
    }
    return true;
}

set<set<int>> s;

void dfs(vector<vector<int>> possible, int cur, int* selected, set<int> temp) {
    if(temp.size()==possible.size()) s.insert(temp);
    if(cur==possible.size()) return;
    
    for(int j=0; j<possible[cur].size(); j++) {
        if(selected[possible[cur][j]]) continue;
        temp.insert(possible[cur][j]);
        selected[possible[cur][j]]=1;
        dfs(possible, cur+1, selected, temp);
        selected[possible[cur][j]]=0;
        temp.erase(possible[cur][j]);
    }
    
}
int solution(vector<string> user_id, vector<string> banned_id) {
    
    vector<vector<int>> possible(banned_id.size());
    for(int i=0; i<banned_id.size(); i++) {
        for(int j=0; j<user_id.size(); j++) {
            if(check(user_id[j], banned_id[i])) possible[i].push_back(j);
        }
    }
    
    int* selected = new int[user_id.size()]();
    set<int> temp;
    dfs(possible, 0, selected, temp);
    
    return s.size();
}

int main() {
    vector<string> user_id;
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");
    
    vector<string> banned_id;
    banned_id.push_back("fr*d*");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    banned_id.push_back("******");
    
    cout << solution(user_id, banned_id) << endl;
}
