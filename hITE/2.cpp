//
//  2.cpp
//  hITE
//
//  Created by 신예지 on 2020/05/10.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

#define INF 360
using namespace std;

void calcuate(int** dist, int x, int y, int N) {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            dist[i][j] = min(dist[i][j], abs(x-i)+abs(y-j));
        }
    }
}

vector<vector<int>> solution(int N, vector<vector<int>> bus_stop) {
    int** dist = new int* [N+1];
    queue<pair<int,int>> q;
    
    for(int i=1; i<=N; i++) {
        dist[i] = new int[N+1];
        for(int j=1; j<=N; j++) dist[i][j]=INF;
    }

    for(int j=0; j<bus_stop.size(); j++) {
        vector<int> temp=bus_stop[j];
        q.push({temp[0],temp[1]});
        dist[temp[0]][temp[1]]=0;
    }
    
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        calcuate(dist, x, y, N);
    }
    
    vector<vector<int>> answer(N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) answer[i-1].push_back(dist[i][j]);
    }
    return answer;
}

int main() {
    int N=3;
    vector<vector<int>> bus_stop;
    bus_stop.push_back({1,2});
    
    vector<vector<int>> answer=solution(N, bus_stop);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cout << answer[i][j] << " ";
        cout << endl;
    }
}
