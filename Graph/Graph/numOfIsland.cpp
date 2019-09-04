//
//  baekjoon 4963
//  numOfIsland.cpp
//  Graph
//
//  Created by 신예지 on 01/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define SEA 0
#define LAND 1

int w, h;

bool isInRange(int x, int y, int w, int h){
    if(x>=0&&x<h && y>=0&&y<w) return true;
    return false;
}

void dfs(int** visited, int x, int y, int group) {
    if(visited[x][y]==1) return;
    visited[x][y]=1;
    
    if(isInRange(x,y-1,w,h) && visited[x][y-1]==0) dfs(visited, x, y-1, 1);
    if(isInRange(x,y+1,w,h) && visited[x][y+1]==0) dfs(visited, x, y+1, 1);
    if(isInRange(x-1,y,w,h) && visited[x-1][y]==0) dfs(visited, x-1, y, 1);
    if(isInRange(x-1,y-1,w,h) && visited[x-1][y-1]==0) dfs(visited, x-1, y-1, 1);
    if(isInRange(x-1,y+1,w,h) && visited[x-1][y+1]==0) dfs(visited, x-1, y+1, 1);
    if(isInRange(x+1,y,w,h) && visited[x+1][y]==0) dfs(visited, x+1, y, 1);
    if(isInRange(x+1,y-1,w,h) && visited[x+1][y-1]==0) dfs(visited, x+1, y-1, 1);
    if(isInRange(x+1,y+1,w,h) && visited[x+1][y+1]==0) dfs(visited, x+1, y+1, 1);
}

int main() {
    while(1) {
        cin >> w >> h;
        if(w==0 || h==0) break;
        
        int** board = new int*[h];
        int** visited = new int*[h];
        queue<pair<int,int>> q;
        
        for(int i=0; i<h; i++) {
            board[i] = new int[w];
            visited[i] = new int[w]();
            
            for(int j=0; j<h; j++) {
                cin >> board[i][j];
                if(board[i][j]==LAND) q.push({i,j});
            }
        }
        
        int ans=0;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(visited[x][y]==1) continue;
            dfs(visited, x, y, 0);
            ans++;
        }
        cout << ans << endl;
    }
}
