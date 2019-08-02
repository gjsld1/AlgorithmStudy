//
//  baekjoon 2252
//  lineup.cpp
//  Queue
//
//  Created by 신예지 on 29/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int* inDegree = new int[n+1]();
    vector<int> connet[n+1];
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        
        connet[a].push_back(b);
        inDegree[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(inDegree[i]==0) q.push(i);
    }
    
    for(int i=1; i<=n; i++) {
        int front = q.front();
        q.pop();
        
        for(int i=0; i<connet[front].size(); i++) {
            if(--inDegree[connet[front][i]]==0) q.push(connet[front][i]);
        }
        cout << front;
    }
}
