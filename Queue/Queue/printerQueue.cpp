//
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
