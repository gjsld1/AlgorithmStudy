//
//  4.cpp
//  qshell
//
//  Created by 신예지 on 2020/07/04.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> safe;

bool isInRange(int x, int y) {
    return ((x>=0&&x<n) && (y>=0&&y<n));
}

int answer;
pair<int,int> aX;

void dfs(int x, int y, vector<vector<int>> board, int cnt, int** visited) {
    if(visited[x][y]) return;
    
    int** temp = new int*[n];
    for(int i=0; i<n; i++) {
        temp[i]=new int[n];
        for(int j=0; j<n; j++) temp[i][j]=visited[i][j];
    }
    temp[x][y]=1;
    
    
    vector<pair<int,int>>::iterator it=find(safe.begin(),safe.end(),make_pair(x,y));
    if(it!=safe.end()) {
        answer = answer>cnt? cnt:answer;
        aX = {x,y};
        return;
    }
    if(isInRange(x+1,y) && board[x+1][y]==0) dfs(x+1,y,board,cnt+1,temp);
    if(isInRange(x-1,y) && board[x-1][y]==0) dfs(x-1,y,board,cnt+1,temp);
    if(isInRange(x,y+1) && board[x][y+1]==0) dfs(x,y+1,board,cnt+1,temp);
    if(isInRange(x,y-1) && board[x][y-1]==0) dfs(x,y-1,board,cnt+1,temp);
}

int solution(vector<vector<int>> board, int K, int Ax, int Ay, int Bx, int By) {
    n=board.size();
    answer=n*n;
    
    queue<pair<int,int>> bomb;
    vector<vector<int>> temp(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp[i].push_back(board[i][j]);
            if(board[i][j]==1) bomb.push({i,j});
        }
    }
    
    //폭탄 영향 지역
    while(!bomb.empty()) {
        int x=bomb.front().first;
        int y=bomb.front().second;
        bomb.pop();
        
        for(int i=1; i<=K; i++) {
            if(isInRange(x+i,y)) {
                if(temp[x+i][y]==2) break;
                temp[x+i][y]=1;
            }
        }
        for(int i=1; i<=K; i++) {
            if(isInRange(x-i,y)) {
                if(temp[x-i][y]==2) break;
                temp[x-i][y]=1;
            }
        }
        for(int i=1; i<=K; i++) {
            if(isInRange(x,y+i)) {
                if(temp[x][y+i]==2) break;
                temp[x][y+i]=1;
            }
        }
        for(int i=1; i<=K; i++) {
            if(isInRange(x,y-i)) {
                if(temp[x][y-i]==2) break;
                temp[x][y-i]=1;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(temp[i][j]==0) safe.push_back({i,j});
        }
    }
    if(safe.size()<2) return -1;
    
    int** visited = new int*[n];
    for(int i=0; i<n; i++) visited[i]=new int[n]();
    
    dfs(Ax,Ay,board,0,visited);
    int aRoute = answer;
    vector<pair<int,int>>::iterator it=find(safe.begin(),safe.end(),aX);
    safe.erase(it);
    answer=n*n;
    dfs(Bx,By,board,0, visited);
    answer = aRoute>answer? aRoute:answer;
    
    return answer;
}

int main() {
    vector<vector<int>> board;
    /*
    board.push_back({1,2,0,0});
    board.push_back({1,0,2,0});
    board.push_back({1,0,0,0});
    board.push_back({1,0,0,1});*/
    board.push_back({0,0,1,0,0,0});
    board.push_back({0,2,0,0,0,1});
    board.push_back({0,0,2,1,0,0});
    board.push_back({0,0,0,0,0,0});
    board.push_back({0,0,0,0,1,0});
    board.push_back({0,1,0,0,0,0});
    
    cout << solution(board, 2, 1,2, 0,5) <<endl;
}
