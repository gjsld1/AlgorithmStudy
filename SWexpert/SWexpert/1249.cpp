//
//  1249.cpp
//  SWexpert
//
//  Created by 신예지 on 19/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define INF 90000
using namespace std;

int map[101][101];
int d[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n;

bool isInRange(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=n) return false;
    return true;
}

int dijk() {
    queue<pair<int,int>> pq;
    d[0][0] = 0;
    pq.push({0,0});
    
    while(!pq.empty()) {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        
        if(x==n-1 && y==n-1) break;
        
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(!isInRange(nx, ny)) continue;
            
            if(d[nx][ny] < d[x][y]+map[nx][ny]) continue;
            else {
                d[nx][ny] = d[x][y]+map[nx][ny];
                pq.push({nx,ny});
            }
        }
    }
    
    return d[n-1][n-1];
}

int main() {
    int tc;
    scanf("%d",&tc);
    
    for(int q=1; q<=tc; q++) {
        scanf("%d",&n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%1d", &map[i][j]);
                
                d[i][j] = INF;
            }
        }
        
        cout << "#" << q << " " << dijk() << endl;
    }
}
