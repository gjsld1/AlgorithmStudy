//
//  1249.cpp
//  SWexpert
//
//  Created by 신예지 on 19/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int** board;
int n;
int ans = 90000;

bool isInRange(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=n) return false;
    return true;
}

void dfs(int x, int y, int repair, int** visited) {
    if(x==n-1 && y==n-1) {
        ans = ans>repair ? repair : ans;
        return;
    }
    if(ans<repair) return;
    
    if(isInRange(x+1, y) && visited[x+1][y]==0) {
        visited[x+1][y]=1;
        dfs(x+1,y,repair+board[x+1][y],visited);
        visited[x+1][y]=0;
    }
    
    if(isInRange(x-1, y) && visited[x-1][y]==0) {
        visited[x-1][y]=1;
        dfs(x-1,y,repair+board[x-1][y],visited);
        visited[x-1][y]=0;
    }
    
    if(isInRange(x, y+1) && visited[x][y+1]==0) {
        visited[x][y+1]=1;
        dfs(x,y+1,repair+board[x][y+1],visited);
        visited[x][y+1]=0;
    }
    
    if(isInRange(x, y-1) && visited[x][y-1]==0) {
        visited[x][y-1]=1;
        dfs(x,y-1,repair+board[x][y-1],visited);
        visited[x][y-1]=0;
    }
}

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        cin >> n;
        
        board = new int* [n];
        int** visited = new int* [n];
        for(int i=0; i<n; i++) {
            board[i] = new int[n];
            visited[i] = new int[n]();
            
            string s;
            cin >> s;
            
            for(int j=0; j<n; j++) {
                board[i][j] = s[j]-'0';
            }
        }
        
        dfs(0,0,0,visited);
        
        cout << "#" << q << " " << ans << endl;
        ans = 90000;
    }
}
