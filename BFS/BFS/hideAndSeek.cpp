//
//  baekjoon 1697
//  hideAndSeek.cpp
//  BFS
//
//  Created by 신예지 on 16/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX 200000

int count(int n, int k) {
    int visited[MAX] = {0};
    
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n]=1;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        
        if(front.first==k) return front.second;
        
        int temp = front.first+1;
        if(visited[temp]==0) {
            q.push({temp, front.second+1});
            visited[temp]=1;
        }
        
        temp = front.first-1;
        if(temp>=0 && visited[temp]==0) {
            q.push({temp, front.second+1});
            visited[temp]=1;
        }
        
        temp = front.first*2;
        if(temp<=MAX && visited[temp]==0) {
            q.push({temp, front.second+1});
            visited[temp]=1;
        }
    }

    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cout << count(n,k);
}
