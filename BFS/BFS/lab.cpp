//
//  baekjoon 14502
//  lab.cpp
//  BFS
//
//  Created by 신예지 on 16/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

#define SAFE 0
#define WALL 1
#define VIRUS 2

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> safeZone;
    queue<pair<int,int>> q;
    
    int** lab = new int*[n];
    for(int i=0; i<n; i++) {
        lab[i] = new int[m];
        for(int j=0; j<m; j++) {
            cin >> lab[i][j];
            if(lab[i][j]==SAFE) safeZone.push_back({i,j});
            else if(lab[i][j]==VIRUS) q.push({i,j});
        }
    }
    
    int size = safeZone.size();
    int ans = 0;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            for(int k=j+1; k<size; k++) {
                queue<pair<int,int>> tempQ = q;
                int** temp = new int*[n];
                for(int p=0; p<n; p++) {
                    temp[p]=new int[m];
                    for(int q=0; q<m; q++) {
                        temp[p][q]=lab[p][q];
                    }
                }
                temp[safeZone[i].first][safeZone[i].second] = WALL;
                temp[safeZone[j].first][safeZone[j].second] = WALL;
                temp[safeZone[k].first][safeZone[k].second] = WALL;
                
                while(!tempQ.empty()) {
                    pair<int,int> front = tempQ.front();
                    int x=front.first;
                    int y=front.second;
                    tempQ.pop();
                    
                    if(x-1>=0 && temp[x-1][y]==SAFE) {
                        temp[x-1][y]=VIRUS;
                        tempQ.push({x-1,y});
                    }
                    if(x+1<n && temp[x+1][y]==SAFE) {
                        temp[x+1][y]=VIRUS;
                        tempQ.push({x+1,y});
                    }
                    if(y-1>=0 && temp[x][y-1]==SAFE) {
                        temp[x][y-1]=VIRUS;
                        tempQ.push({x,y-1});
                    }
                    if(y+1<m && temp[x][y+1]==SAFE) {
                        temp[x][y+1]=VIRUS;
                        tempQ.push({x,y+1});
                    }
                }
                
                int tmp = 0;
                for(int w=0; w<n; w++) {
                    for(int e=0; e<m; e++) {
                        if(temp[w][e]==SAFE) tmp++;
                    }
                }
                if(ans<tmp) ans=tmp;
            }
        }
    }
    cout << ans;
}
