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

/* Time Limit
 
#include <iostream>
using namespace std;

struct node {
    int num;
    struct node* pointer = NULL;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    int* make = new int[n+1]();
    struct node* hash = new struct node[n+1];
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        
        struct node *temp = new node;
        temp->num = b;
        temp->pointer = hash[a].pointer;
        hash[a].pointer = temp;
    }
    
    struct node* head = new node;
    for(int i=1; i<=n; i++) {
        struct node* next = hash[i].pointer;
        if(next == NULL) continue;
        struct node *temp = new node;
        if(make[i]==0) {
            temp->num = i;
            make[i] = 1;
            
            if(head->pointer == NULL) head->pointer = temp;
            else {
                struct node* end = head->pointer;
                while(end->pointer != NULL) {
                    if(end->pointer->num == next->num) break;
                    end = end->pointer;
                }
                temp->pointer = end->pointer;
                end->pointer = temp;
                
            }
        }
        
        struct node* pos = head->pointer;
        while(pos->num != i && pos->pointer != NULL) {
            if(pos->pointer->num == next->num) {
                temp->pointer = pos->pointer;
                pos->pointer = temp;
                next = next->pointer;
                break;
            }
            pos = pos->pointer;
        }
        while(next != NULL) {
            if(make[next->num]==1) {
                next = next->pointer;
                break;
            }
            struct  node* after = new node;
            after->num = next->num;
            make[next->num] = 1;
            after->pointer = pos->pointer;
            
            pos->pointer = after;
            next = next->pointer;
        }
    }
    
    struct node* print = head->pointer;
    while(print != NULL) {
        cout << print->num;
        print = print->pointer;
    }
    for(int i=1; i<=n; i++) {
        if(make[i]==0) cout << i;
    }
}
*/
