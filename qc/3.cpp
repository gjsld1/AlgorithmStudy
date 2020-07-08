//
//  3.cpp
//  qshell
//
//  Created by 신예지 on 2020/07/04.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include<vector>
#include <queue>
using namespace std;

int answer=1;

bool isInRange(int x, int y) {
    return ((x>=0&&x<4) && (y>=0&&y<4));
}

void dfs(vector<vector<int>> board, pair<int,int> p, int** visited, int length) {
    int** temp = new int* [4];
    for(int i=0; i<4; i++) {
        temp[i] = new int[4];
        for(int j=0; j<4; j++) temp[i][j]=visited[i][j];
    }
    int x=p.first;
    int y=p.second;
    temp[x][y]=1;
    length++;
    
    if(isInRange(x+1,y) && board[x][y]==board[x+1][y] && visited[x+1][y]==0) dfs(board,{x+1,y}, temp, length);
    if(isInRange(x-1,y) && board[x][y]==board[x-1][y] && visited[x-1][y]==0) dfs(board,{x-1,y}, temp, length);
    if(isInRange(x,y+1) && board[x][y]==board[x][y+1] && visited[x][y+1]==0) dfs(board,{x,y+1}, temp, length);
    if(isInRange(x,y-1) && board[x][y]==board[x][y-1] && visited[x][y-1]==0) dfs(board,{x,y-1}, temp, length);
    
    answer = answer>length? answer : length;
    
}

int solution(vector<vector<int>> board) {
    vector<queue<pair<int,int>>> v(5);
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            v[board[i][j]].push({i,j});
        }
    }
    
    for(int i=1; i<=4; i++) {
        while(!v[i].empty()) {
            int** visited = new int* [4];
            for(int i=0; i<4; i++) visited[i] = new int[4]();
            
            dfs(board, v[i].front(), visited, 0);
            v[i].pop();
        }
    }
    if(answer==1) return -1;
    return answer;
}

int main() {
    vector<vector<int>> board;
    board.push_back({3,2,3,2});
    board.push_back({2,1,1,2});
    board.push_back({1,1,2,1});
    board.push_back({4,1,1,1});
    
    cout << solution(board);
}
