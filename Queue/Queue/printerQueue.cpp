//
//  printerQueue.cpp
//  Queue
//
//  Created by 신예지 on 28/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int k=0; k<tc; k++) {
        int n, m;
        cin >> n >> m;
        
        priority_queue<pair<int,int>> pq;
        queue<pair<int,int>> q;
        
        int idx = 0;
        for(int i=0; i<n; i++) {
            int priority;
            cin >> priority;
            
            pq.push({priority, idx});
            q.push({priority, idx});
            idx++;
        }
        
        int order = 0;
        while(q.front().second != m || q.front().first<pq.top().first) {
            if(pq.top().first > q.front().first && pq.top().second > q.front().second) {
                q.push({q.front().first, q.front().second});
                q.pop();
            }
            else if(pq.top().second == q.front().second || pq.top().first == q.front().first) {
                pq.pop();
                q.pop();
                order++;
            }
        }
        order++;
        cout << order;
    }
}
