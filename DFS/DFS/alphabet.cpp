//
//  baekjoon 1987
//  alphabet.cpp
//  DFS
//
//  Created by 신예지 on 18/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int r, c;
char** map;

bool isInRange(int x, int y) {
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

int bfs(int* visited, stack<pair<int,int>> s, int ans) {
    int* temp = visited;
    
    while(!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        if(visited[map[x][y]-'A']==1) break;
        
        temp[map[x][y]-'A']=1;
        s.pop();
        ans++;
        
        if(isInRange(x+1,y) && visited[map[x+1][y]-'A']==0) {
            s.push({x+1,y});
            int tmp = bfs(temp,s,ans);
            ans = (ans<=tmp)? tmp:ans;
            temp = visited;
        }
        if(isInRange(x-1,y) && visited[map[x-1][y]-'A']==0) {
            s.push({x-1,y});
            int tmp = bfs(temp,s,ans);
            ans = (ans<=tmp)? tmp:ans;
            temp = visited;
        }
        if(isInRange(x,y+1) && visited[map[x][y+1]-'A']==0) {
            s.push({x,y+1});
            int tmp = bfs(temp,s,ans);
            ans = (ans<=tmp)? tmp:ans;
            temp = visited;
        }
        if(isInRange(x,y-1) && visited[map[x][y-1]-'A']==0) {
            s.push({x,y-1});
            int tmp = bfs(temp,s,ans);
            ans = (ans<=tmp)? tmp:ans;
            temp = visited;
        }
    }
    return ans;
}

int main() {
    cin >> r >> c;
    
    map = new char* [r];
    for(int i=0; i<r; i++) {
        map[i] = new char[c];
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
    
    int visited[26] = {0};
    stack<pair<int,int>> s;
    
    s.push({0,0});
    int ans = 0;
    cout << bfs(visited, s, ans);
}
