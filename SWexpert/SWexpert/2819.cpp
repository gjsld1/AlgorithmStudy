//
//  2819.cpp
//  SWexpert
//
//  Created by 신예지 on 18/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

int board[4][4];
set<string> s;

bool isInRange(int x, int y) {
    if(x<0 || x>=4 || y<0 || y>=4) return false;
    return true;
}

void dfs(int x, int y, int cnt, string str) {
    if(cnt==6) {
        s.insert(str);
        return;
    }
    
    if(isInRange(x+1, y)) {
        dfs(x+1, y, cnt+1, str+to_string(board[x+1][y]));
    }
    if(isInRange(x-1, y)) {
        dfs(x-1, y, cnt+1, str+to_string(board[x-1][y]));
    }
    if(isInRange(x, y-1)) {
        dfs(x, y-1, cnt+1, str+to_string(board[x][y-1]));
    }
    if(isInRange(x, y+1)) {
        dfs(x, y+1, cnt+1, str+to_string(board[x][y+1]));
    }
}

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                cin >> board[i][j];
            }
        }
        
        string str="";
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                str = to_string(board[i][j]);
                dfs(i, j, 0, str);
            }
        }
        
        int ans = s.size();
        cout << "#" << q << " " << ans << endl;
        s.clear();
    }
}
