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
#include <vector>
using namespace std;

#define empty 0
#define wall 1
#define virus 2

int main() {
    int n, m;
    cin >> n >> m;
    
    int** lab = new int*[n];
    for(int i=0; i<n; i++) lab[i] = new int[m];
    
    vector<pair<int,int>> safeZone;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> lab[i][j];
            if(lab[i][j]==empty) safeZone.push_back({i,j});
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
                
                for(int p=0; p<n; p++) {
                    for(int q=0; q<m; q++) {
                        if(temp[p][q]==2) {
                            int tempX=p, tempY=q;
                            while(--tempX>=0 && temp[tempX][tempY]!=wall) temp[tempX][tempY]=virus;
                            tempX=p;
                            while(++tempX<n && temp[tempX][tempY]!=wall) temp[tempX][tempY]=virus;
                            tempX=p;
                            while(--tempY>=0 && temp[tempX][tempY]!=wall) temp[tempX][tempY]=virus;
                            tempY=q;
                            while(++tempY<m && temp[tempX][tempY]!=wall) temp[tempX][tempY]=virus;
                        }
                    }
                }
                
                int safe = 0;
                for(int p=0; p<n; p++) {
                    for(int q=0; q<m; q++) {
                        if(temp[p][q]==0) safe++;
                    }
                }
                if(ans<safe) ans=safe;
            }
        }
    }
    cout << ans;
}
