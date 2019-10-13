//
//  frequencyQueue.cpp
//  NHN
//
//  Created by 신예지 on 29/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string command;
    int num;
    map<int, int> m;
    
    for(int i=0; i<n; i++) {
        cin >> command;
        
        if(command=="enqueue") {
            cin >> num;
            if(m.find(num)==m.end()) m.insert({num,1});
            else m[num]++;
        }
        else {
            priority_queue<pair<int,int>> pq;
            map<int,int>::const_iterator it;
            for(it=m.begin(); it!=m.end(); it++) pq.push({it->second, it->first});
            
            if(pq.empty()) {
                cout << "-1 ";
                continue;
            }
            
            cout << pq.top().second << " ";
            m[pq.top().second]--;
            if(pq.top().first-1) {
                pq.push({pq.top().first-1, pq.top().second});
            }
            pq.pop();
            
        }
    }
}
