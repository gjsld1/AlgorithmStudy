//
//  1249.cpp
//  SWexpert
//
//  Created by 신예지 on 19/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <queue>

#define INF 90000
using namespace std;

int n;
int map[101][101];
int d[101][101];

int solve() {
    queue<pair<int,int>> q;
    
    d[0][0]=0;
    q.push({0,0});
    
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(d[nx][ny] > d[x][y]+map[nx][ny]) {
                q.push({nx,ny});
                d[nx][ny] = d[x][y]+map[nx][ny];
            }
        }
    }
    
    return d[n-1][n-1];
}

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        cin >> n;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%1d", &map[i][j]);
                d[i][j] = INF;
            }
        }
        
        cout << "#" << q << " " << solve() << endl;
    }
}
