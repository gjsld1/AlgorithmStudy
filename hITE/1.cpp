//
//  1.cpp
//  hITE
//
//  Created by 신예지 on 2020/05/10.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include<vector>
#include <queue>
using namespace std;

#define SEA 0
#define LAND 1

int r, c, ans=0;

bool isInRange(int x, int y){
    return (x>=0&&x<r && y>=0&&y<c);
}
void dfs(vector<vector<int>> maps, int** visited, int x, int y) {
    if(visited[x][y]==1 || maps[x][y]==SEA) return;
    visited[x][y]=1;
    
    if(!isInRange(x, y-1) || (isInRange(x, y-1) && maps[x][y-1]==SEA)) ans++;
    if(!isInRange(x, y+1) || (isInRange(x, y+1) && maps[x][y+1]==SEA)) ans++;
    if(!isInRange(x-1, y) || (isInRange(x-1, y) && maps[x-1][y]==SEA)) ans++;
    if(!isInRange(x+1, y) || (isInRange(x+1, y) && maps[x+1][y]==SEA)) ans++;
    
    if(isInRange(x,y-1) && visited[x][y-1]==0) dfs(maps, visited, x, y-1);
    if(isInRange(x,y+1) && visited[x][y+1]==0) dfs(maps, visited, x, y+1);
    if(isInRange(x-1,y) && visited[x-1][y]==0) dfs(maps, visited, x-1, y);
    if(isInRange(x+1,y) && visited[x+1][y]==0) dfs(maps, visited, x+1, y);
}

int solution(vector<vector<int> > maps){
    r=maps.size();
    c=maps[0].size();
    
    int** visited = new int*[r];
    queue<pair<int,int>> q;
    
    for(int i=0; i<r; i++) {
        visited[i] = new int[c]();
        for(int j=0; j<c; j++) {
            if(maps[i][j]==LAND) q.push({i,j});
        }
    }
    
    int answer=0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(visited[x][y]==1) continue;
        dfs(maps, visited, x, y);
        answer+=ans;
        ans=0;
    }
    
    return answer;
}

int main() {
    vector<vector<int>> maps;
    maps.push_back({0,0,1,0,0});
    maps.push_back({0,1,1,0,1});
    maps.push_back({0,0,1,0,1});
    maps.push_back({1,1,1,0,1});
    
    cout << solution(maps) << endl;
}
