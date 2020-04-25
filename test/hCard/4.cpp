//
//  4.cpp
//  hCard
//
//  Created by 신예지 on 2020/04/25.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int cnt;

bool isInBoard(int x, int y) {
    return ((x>=1 && x<=6) && (y>=1 && y<=6));
}

void dfs(vector<vector<int>> board, int x, int y) {

    if(isInBoard(x+1, y) && board[x][y]==board[x+1][y]) {
        cnt++;
        dfs(board, x+1, y);
    }
    if(isInBoard(x-1, y) && board[x][y]==board[x-1][y]) {
        
    }
    if(isInBoard(x, y+1) && board[x][y]==board[x][y+1]) {
        
    }
    if(isInBoard(x, y-1) && board[x][y]==board[x][y-1]) {
        
    }
    return;
}


vector<string> solution(vector<vector<int>> macaron) {
    
    vector<vector<int>> board(7);
    
    for(int i=0; i<macaron.size(); i++) {
        
        board[macaron[i][0]].push_back(macaron[i][1]);
        
        int x=macaron[i][0];
        int y=board[x].size()-1;
        
        if(isInBoard(x+1, y) && board[x][y]==board[x+1][y]) {
            cnt=2;
            dfs(board, x+1, y);
            if(cnt>=3);
        }
        if(isInBoard(x-1, y) && board[x][y]==board[x-1][y]) {
            
        }
        if(isInBoard(x, y+1) && board[x][y]==board[x][y+1]) {
            
        }
        if(isInBoard(x, y-1) && board[x][y]==board[x][y-1]) {
            
        }
        cnt=0;
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
    macaron.push_back({3,4});
    macaron.push_back({2,1});
    
    solution(macaron);
}
