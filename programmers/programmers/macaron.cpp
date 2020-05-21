//
//  macaron.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/06.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int board[7][7] = {0};
int cnt=0;

bool isInBoard(int x, int y) {
    return ((x>=1 && x<=6) && (y>=1 && y<=6));
}

bool nearSame(int x, int y) {
    if(isInBoard(x-1, y) && board[x][y]==board[x-1][y]) return true;
    else if(isInBoard(x+1, y) && board[x][y]==board[x+1][y]) return true;
    else if(isInBoard(x, y-1) && board[x][y]==board[x][y-1]) return true;
    else if(isInBoard(x, y+1) && board[x][y]==board[x][y+1]) return true;
    
    return false;
}

void dfs(int x, int y, int visited[7][7]) {
    if(visited[x][y]) return;
    visited[x][y]=1;
    cnt++;
    
    if(isInBoard(x+1,y) && board[x+1][y]==board[x][y]) dfs(x+1,y,visited);
    if(isInBoard(x-1,y) && board[x-1][y]==board[x][y]) dfs(x-1,y,visited);
    if(isInBoard(x,y+1) && board[x][y+1]==board[x][y]) dfs(x,y+1,visited);
    if(isInBoard(x,y-1) && board[x][y-1]==board[x][y]) dfs(x,y-1,visited);
    return;
}

void eliminate(int x, int y) {
    int origin=board[x][y];
    board[x][y]=0;
    
    if(isInBoard(x+1,y) && board[x+1][y]==origin) eliminate(x+1,y);
    if(isInBoard(x-1,y) && board[x-1][y]==origin) eliminate(x-1,y);
    if(isInBoard(x,y+1) && board[x][y+1]==origin) eliminate(x,y+1);
    if(isInBoard(x,y-1) && board[x][y-1]==origin) eliminate(x,y-1);
    return;
}

void trimBoard() {
    for(int i=1; i<7; i++) {
        for(int j=1; j<6; j++) {
            if(board[j][i]!=0 && board[j+1][i]==0) swap(board[j][i],board[j+1][i]);
        }
    }
    return;
}

vector<string> solution(vector<vector<int>> macaron) {
    
    int top[7] = {6,6,6,6,6,6,6};
    for(int i=0; i<macaron.size(); i++) {
        int pos = macaron[i][0];
        while(board[top[pos]][pos]!=0) top[pos]--;
        board[top[pos]][pos]=macaron[i][1];
        
        int visited[7][7] = {0};
        if(nearSame(top[pos],pos)) dfs(top[pos],pos,visited);
        if(cnt>=3) {
            eliminate(top[pos], pos);
            trimBoard();
        }
        cnt=0;
    }
    
    for(int i=1; i<7; i++) {
        for(int j=1; j<7; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<string> answer;
    
    return answer;
}

int main() {
    vector<vector<int>> macaron;
    macaron.push_back({1,1});
    macaron.push_back({2,1});
    macaron.push_back({1,2});
    macaron.push_back({3,3});
    macaron.push_back({6,4});
    macaron.push_back({3,1});
    macaron.push_back({3,3});
    macaron.push_back({3,3});
    macaron.push_back({3,4});
    macaron.push_back({2,1});
    
    solution(macaron);
}
