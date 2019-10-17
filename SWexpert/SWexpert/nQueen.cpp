//
//  SWExpertAcademy 2806 D3
//  nQueen.cpp
//  SWexpert
//
//  Created by 신예지 on 15/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

#define POSSIBLE 0
#define BLOCK 1
#define QUEEN 2

int n, ans=0;

void dfs(int** board, int cur) {
    if(cur==n) return;
    
    //temp=board
    int** temp = new int* [n];
    for(int i=0; i<n; i++) {
        temp[i] = new int[n];
        for(int j=0; j<n; j++) {
            temp[i][j] = board[i][j];
        }
    }
    
    int flag=0;
    for(int j=0; j<n; j++) {
        if(temp[cur][j]==POSSIBLE) {
            temp[cur][j]=QUEEN;
            flag++;
            
            
            int tempX=cur, tempY=j;
            while(--tempX>=0) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;
            tempX=cur; tempY=j;
            while(++tempY<n) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;
            tempX=cur; tempY=j;
            while(--tempY>=0) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;
            tempX=cur; tempY=j;
            while(++tempX<n) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;
            
            tempX=cur; tempY=j;
            while(--tempX>=0 && --tempY>=0) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;   //3사분면 방향
            tempX=cur; tempY=j;
            while(--tempX>=0 && ++tempY<n) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;    //1사분면 방향
            tempX=cur; tempY=j;
            while(++tempX<n && --tempY>=0) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK;    //4사분면 방향
            tempX=cur; tempY=j;
            while(++tempX<n && ++tempY<n) if(temp[tempX][tempY]==POSSIBLE) temp[tempX][tempY]=BLOCK; //2사분면 방향
            
            dfs(temp,cur+1);
            
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) temp[i][j] = board[i][j];
            }
        }
    }
    if(flag==0) return;
    if(flag!=0 && cur==n-1) ans++;
    
    return;
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=1; i<=tc; i++) {
        cin >> n;
        
        int** board = new int*[n];
        for(int j=0; j<n; j++) board[j] = new int[n]();
        
        ans=0;
        dfs(board,0);
        cout << "#" << i << " " << ans << endl;
    }
}
