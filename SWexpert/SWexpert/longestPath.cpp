//
//  SWExpertAcademy 2814 D3
//  longestPath.cpp
//  SWexpert
//
//  Created by 신예지 on 24/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ans;
int* visited;
vector<set<int>> v;

void dfs(int cur) {
    if(visited[cur]) return;
    visited[cur]=1;
    ans++;
    for(set<int>::iterator it=v[cur].begin(); it!=v[cur].end(); it++) {
        dfs(*it);
    }
    return;
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=1; i<=tc; i++) {
        v.clear();
        
        int n, m;
        cin >> n >> m;
        
        v.resize(n+1);
        
        while(m--) {
            int a, b;
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
        }
        
        ans=0;
        for(int j=1; j<v.size(); j++) {
            visited = new int[n]();
            dfs(j);
        }
        
        cout << "#" << i << " " << ans << endl;
    }
}
