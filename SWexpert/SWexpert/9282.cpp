//
//  9282.cpp
//  SWexpert
//
//  Created by 신예지 on 2020/04/21.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <cstring>

#define INF 2e9
using namespace std;

int n,m;
int map[51][51];
int sum[51][51];
int memo[51][51][51][51];

int dfs(int x, int y, int _x, int _y) {
    if(x==_x && y==_y) return 0;
    if(memo[x][y][_x][_y]!=-1) return memo[x][y][_x][_y];
    
    memo[x][y][_x][_y]=INF;
    
    int currentSum = sum[_x][_y]-sum[x-1][_y]-sum[_x][y-1]+sum[x-1][y-1];
    for(int i=x; i<_x; i++) {
        int result1 = dfs(x,y,i,_y);
        int result2 = dfs(i+1,y,_x,_y);
        
        memo[x][y][_x][_y]= min(memo[x][y][_x][_y], currentSum+result1+result2);
    }
    for(int i=y; i<_y; i++) {
        int result1 = dfs(x,y,_x,i);
        int result2 = dfs(x,i+1,_x,_y);
        
        memo[x][y][_x][_y]= min(memo[x][y][_x][_y], currentSum+result1+result2);
    }
    
    return memo[x][y][_x][_y];
}

int main() {
    int tc;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        memset(sum,0,sizeof(sum));
        memset(memo,-1,sizeof(memo));
        
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) cin >> map[i][j];
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
            }
        }
        
        int answer=dfs(1,1,n,m);
        cout << "#" << t << " " << answer << endl;
    }
}
