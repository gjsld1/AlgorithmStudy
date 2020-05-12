//
//  3.cpp
//  hITE
//
//  Created by 신예지 on 2020/05/10.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include<vector>
using namespace std;

int ans;

int findMax(int** map) {
    int max=0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            max=(max<map[i][j])? map[i][j] : max;
        }
    }
    return max;
}

int** move(int** map, int dir) {
    int** moveMap = new int* [4];
    for(int i=0; i<4; i++) {
        moveMap[i]=new int[4]();
    }
    
    if(dir==1) {    //위
        for (int j=0; j<4; j++) {
            int temp=0;
            int index=0;
            for (int i=0; i<4; i++) {
                if(temp==0) temp=map[i][j];
                else if(temp==map[i][j]) {
                    moveMap[index][j]= temp*2;
                    index++;
                    temp=0;
                }
                else {
                    if(map[i][j]!=0) {
                        moveMap[index][j]=temp;
                        index++;
                        temp=map[i][j];
                    }
                }
                if(i==3) moveMap[index][j]=temp;
            }
        }
    }
    else if(dir==2) {   //아래
        for (int j=0; j<4; j++) {
            int temp=0;
            int index=3;
            for (int i=3; i>=0; i--) {
                if(temp==0) temp=map[i][j];
                else if(temp==map[i][j]) {
                    moveMap[index][j]=temp*2;
                    index--;
                    temp=0;
                }
                else {
                    if(map[i][j]!=0) {
                        moveMap[index][j]=temp;
                        index--;
                        temp=map[i][j];
                    }
                }
                if(i==0) moveMap[index][j]=temp;
            }
        }
    }
    else if(dir==3) {   //왼쪽
        for (int i=0; i<4; i++) {
            int temp=0;
            int index=0;
            for (int j=0; j<4; j++) {
                if(temp==0) temp=map[i][j];
                else if(temp==map[i][j]) {
                    moveMap[i][index]=temp*2;
                    index++;
                    temp=0;
                }
                else {
                    if(map[i][j]!=0) {
                        moveMap[i][index]=temp;
                        index++;
                        temp=map[i][j];
                    }
                }
                if(j==3) moveMap[i][index]=temp;
            }
        }
    }
    else if(dir==4) {   //아래쪽
        for (int i=0; i<4; i++) {
            int temp=0;
            int index=3;
            for (int j=3; j>=0; j--) {
                if(temp==0) temp=map[i][j];
                else if(temp==map[i][j]) {
                    moveMap[i][index]=temp*2;
                    index--;
                    temp=0;
                }
                else {
                    if(map[i][j]!=0) {
                        moveMap[i][index]=temp;
                        index--;
                        temp=map[i][j];
                    }
                }
                if(j==0) moveMap[i][index]=temp;
            }
        }
    }
    return moveMap;
}

void dfs(int** map, int cnt) {
    if(cnt==5) {
        ans=max(ans,findMax(map));
        return;
    }
    int** temp = new int* [4];
    for(int i=0; i<4; i++) {
        temp[i] = new int[4];
        for(int j=0; j<4; j++) temp[i][j]=map[i][j];
    }
    for(int i=1; i<=4; i++) dfs(move(temp,i),cnt+1);
}

int solution(vector<vector<int> > board) {
    int** map = new int*[4];
    for(int i=0; i<4; i++) {
        map[i] = new int[4];
        for(int j=0; j<4; j++) {
            map[i][j]=board[i][j];
        }
    }
    ans=0;
    dfs(map,0);
    return ans;
}


int main() {
    vector<vector<int>> board;
    board.push_back({2,4,8,2});
    board.push_back({2,2,2,2});
    board.push_back({0,4,2,4});
    board.push_back({2,2,2,4});
    
    cout << solution(board) << endl;
}
