//
//  1249.cpp
//  SWexpert
//
//  Created by 신예지 on 19/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define INF 999999
using namespace std;

int map[101][101];
int n;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int solve() {
    int path[101][101];
    for (int i = 0; i < n; i++) memset(path[i], INF, sizeof(int)*n);
    
    queue<pair<int, int>> q;
    
    pair<int, int> idx;
    int x, y;

    path[0][0] = 0;
    q.push({0,0});
    
    while (!q.empty()) {
        idx = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            x = idx.first + dx[k];
            y = idx.second + dy[k];
            
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (path[x][y] > path[idx.first][idx.second] + map[x][y]) {
                q.push({x,y});
                path[x][y] = path[idx.first][idx.second] + map[x][y];
            }
        }
    }
    
    return path[n - 1][n - 1];
}
int main() {
    int tc;
    scanf("%d", &tc);
    
    for (int q = 1; q<=tc; q++) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%1d", &map[i][j]);
            }
        }
        printf("#%d %d\n", q, solve());
    }
}
