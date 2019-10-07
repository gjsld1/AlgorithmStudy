//
//  SWExpertAcademy 7988 D4
//  internalMatch.cpp
//  SWexpert
//
//  Created by 신예지 on 18/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<string,set<string>> info;
map<string,int> check;

bool bfs(string s) {
    queue<string> q;
    queue<int> group;
    check[s]=1;
    q.push(s);
    group.push(1);
    
    while(!q.empty()) {
        string now = q.front(); q.pop();
        int nowG = group.front(); group.pop();
        
        for(auto a : info[now]) {
            if(!check[a]) {
                q.push(a);
                if(nowG==1) {
                    check[a]=2;
                    group.push(2);
                }
                else {
                    check[a]=1;
                    group.push(1);
                }
            }
            else {
                if(check[a]==nowG) return false;
            }
        }
    }
    
    return true;
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=1; i<=tc; i++) {
        int k;
        cin >> k;
        string root;
        
        for(int j=0; j<k; j++) {
            string a,b;
            cin >> a >> b;
            
            if(info.empty()) root=a;
            info[a].insert(b);
            info[b].insert(a);
        }
        
        cout << "#" << i << " ";
        if(bfs(root)) cout << "Yes" << endl;
        else cout << "No" << endl;
        
        info.clear();
        check.clear();
    }
}
