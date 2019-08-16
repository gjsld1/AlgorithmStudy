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

#define safe 0
#define wall 1
#define virus 2

int main() {
    int n, m;
    cin >> n >> m;
    
    int** lab = new int*[n];
    for(int i=0; i<n; i++) lab[i] = new int[m];
    
    vector<pair<int,int>> safeZone;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> lab[i][j];
            if(lab[i][j]==safe) safeZone.push_back({i,j});
            else if(lab[i][j]==virus) q.push({i,j});
        }
    }
    
    int size = safeZone.size();
    int ans = 0;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            for(int k=j+1; k<size; k++) {
                int** temp = new int*[n];
                for(int l=0; l<n; l++) temp[l]=new int[m];
                for(int p=0; p<n; p++) {
                    for(int q=0; q<m; q++) {
                        temp[p][q]=lab[p][q];
                    }
                }
                temp[safeZone[i].first][safeZone[i].second] = 1;
                temp[safeZone[j].first][safeZone[j].second] = 1;
                temp[safeZone[k].first][safeZone[k].second] = 1;
                
                while(!q.empty()) {
                    pair<int,int> front = q.front();
                    int x=front.first;
                    int y=front.second;
                    q.pop();
                    
                    if(x-1>=0 && temp[x-1][y]==safe) {
                        temp[x-1][y]=virus;
                        q.push({x-1,y});
                    }
                    if(x+1<n && temp[x+1][y]==safe) {
                        temp[x+1][y]=virus;
                        q.push({x+1,y});
                    }
                    if(y-1>=0 && temp[x][y-1]==safe) {
                        temp[x][y-1]=virus;
                        q.push({x,y-1});
                    }
                    if(y+1<m && temp[x][y+1]==safe) {
                        temp[x][y+1]=virus;
                        q.push({x,y+1});
                    }
                }
                
                int tmp = 0;
                for(int w=0; w<n; w++) {
                    for(int e=0; e<m; e++) {
                        if(temp[w][e]==0) tmp++;
                    }
                }
                if(ans<tmp) ans=tmp;
            }
        }
    }
    cout << ans;
}
