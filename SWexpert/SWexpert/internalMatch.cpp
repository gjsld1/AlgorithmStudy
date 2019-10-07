//
//  SWExpertAcademy 7988 D4
//  internalMatch.cpp
//  SWexpert
//
//  Created by 신예지 on 18/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<string, set<string> > v;
map<string, int> chk;

bool bfs(string node)
{
    queue<string> q;
    queue<int> dir;
    q.push(node);
    dir.push(1);
    chk[node] = 1;
    while(!q.empty()){
        string now = q.front(); q.pop();
        int d = dir.front(); dir.pop();
        for(auto a: v[now]){
            if(!chk[a]){
                if(d == 1){
                    q.push(a);
                    dir.push(2);
                    chk[a] = 2;
                }
                else{
                    q.push(a);
                    dir.push(1);
                    chk[a] = 1;
                }
            }
            else{
                if(chk[a] == d) return false;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i=1; i<=t;i++){
        int n;
        cin >> n;
        string root;
        
        for(int p=0; p<n; p++){
            string a,b;
            cin >> a >> b;
            
            v[a].insert(b);
            v[b].insert(a);
            if(p == 0) root=a;
        }
        
        cout << "#" << i << " ";
        if(!bfs(root)) cout << "No" << endl;
        else cout << "Yes" << endl;
        
        v.clear();
        chk.clear();
    }
}
