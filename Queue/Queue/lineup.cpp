//
//  baekjoon 2252
//  lineup.cpp
//  Queue
//
//  Created by 신예지 on 29/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

/*
#include <iostream>
#include <queue>
#include <utility>
#define MAX 100001
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int* priority = new int[n+1]();
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        
        if(priority[a]==0 && priority[b]==0) {
            priority[a]=MAX;
            priority[b]=MAX-1;
        }
        else if(priority[a]==0 && priority[b]!=0) {
            priority[a] = priority[b]+1;
        }
        else if(priority[a]!=0 && priority[b]==0) {
            priority[b] = priority[a]-1;
        }
        else {
            priority[a] = priority[b]+1;
        }
    }
    
    priority_queue<pair<int, int>> pq;
    for(int i=1; i<=n; i++) {
        pq.push({priority[i], i});
    }
    
    for(int i=0; i<n; i++) {
        cout << pq.top().second;
        pq.pop();
    }
}
*/

#include <iostream>
#include <queue>
#include <utility>
#define MAX 10
using namespace std;

int main() {
    struct node {
        int n;
        node* pointer = NULL;
    };
    
    int n, m;
    cin >> n >> m;
    
    int* priority = new int[n+1]();
    node* hash = new node[n+1];
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        
        node* temp = new node;
        temp->n = b;
        temp->pointer = hash[a].pointer;
        
        hash[a].pointer = temp;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(priority[i]==0) priority[i]=MAX;
        q.push(i);
        
        while(!q.empty()) {
            node* temp = hash[q.front()].pointer;
            while(temp!=NULL) {
                q.push(temp->n);
                
                if(priority[temp->n]==0) priority[temp->n] = priority[q.front()]-1;
                else priority[temp->n] -= 1;
                
                temp = temp->pointer;
            }
            q.pop();
        }
    }
    for(int i=1; i<=n; i++) cout << priority[i] << endl;
    
    priority_queue<pair<int,int>> pq;
    for(int i=1; i<=n; i++) {
        pq.push({priority[i],i});
    }
    
    for(int i=1; i<=n; i++) {
        cout << pq.top().second;
        pq.pop();
    }
}
