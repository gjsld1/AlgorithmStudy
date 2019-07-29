//
//  baekjoon 1966
//  printerQueue.cpp
//  Queue
//
//  Created by 신예지 on 28/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int l=0; l<tc; l++) {
        int n, m;
        cin >> n >> m;
        
        int* doc = new int[n];
        priority_queue<int> pq;
        
        for(int i=0; i<n; i++) {
            cin >> doc[i];
            pq.push(doc[i]);
        }
        
        int out = -1;
        int order = 0;
        int idx = 0;
        while(out!=m) {
            if(idx>=n) idx%=n;
            
            if(doc[idx]<pq.top()) idx++;
            else if(doc[idx]==pq.top()) {
                pq.pop();
                order++;
                out = idx;
                idx++;
            }
            else idx++;
        }
        
        cout << order << endl;
    }
}

/*
int main() {
    int tc;
    cin >> tc;
    for(int k=0; k<tc; k++) {
        int n, m;
        cin >> n >> m;
        
        priority_queue<int> pq;
        int* input = new int[n];
        
        int idx = 0;
        for(int i=0; i<n; i++) {
            cin >> input[i];
            pq.push(input[i]);
        }
        
        int order = 0;
        int index = 0;
        int* print = new int[n]();
        
        while(print[m]==0) {
            if(print[index]==1 || input[index] < pq.top()) {
                index++;
                if(index>=n) index=0;
            }
            else if(input[index] == pq.top()) {
                pq.pop();
                print[index]=1;
                order++;
                index++;
                if(index>=n) index=0;
            }
        }
        cout << order << endl;
    }
}
*/
