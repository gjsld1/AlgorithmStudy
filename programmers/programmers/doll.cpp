//
//  doll.cpp
//  mock
//
//  Created by 신예지 on 28/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n=board[0].size();
    vector<vector<int>> real;
    
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=n-1; j>=0; j--) {
            if(board[j][i]==0) break;
            temp.push_back(board[j][i]);
        }
        real.push_back(temp);
    }
    
    int answer=0;
    vector<int> pick;
    for(int i=0; i<moves.size(); i++) {
        int idx=moves[i]-1;
        if(real[idx].empty()) continue;
        
        if(!pick.empty() && pick.back()==real[idx].back()) {
            answer+=2;
            pick.pop_back();
        }
        else pick.push_back(real[idx].back());
        real[idx].pop_back();
    }
    
    return answer;
}

int main() {
    vector<vector<int>> board;
    board.push_back({0,0,0,0,0});
    board.push_back({0,0,1,0,3});
    board.push_back({0,2,5,0,1});
    board.push_back({4,2,4,4,2});
    board.push_back({3,5,1,3,1});
    
    vector<int> moves;
    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);
    
    cout << solution(board,moves) << endl;
}
