//
//  1.cpp
//  kakaoIntern
//
//  Created by 신예지 on 09/11/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> catches;
    
    for(int i=0; i<moves.size(); i++) {
        int position = moves[i]-1;
        for(int j=0; j<board.size(); j++) {
            if(board[j][position]==0) continue;
            else {
                catches.push_back(board[j][position]);
                board[j][position]=0;
                
                int last = catches.size();
                if(last>1) {
                    if(catches[last-1]==catches[last-2]) {
                        catches.pop_back();
                        catches.pop_back();
                        answer+=2;
                    }
                }
                break;
            }
        }
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

