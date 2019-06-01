//
//  lineup.cpp
//  Queue
//
//  Created by 신예지 on 29/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

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
            struct  node* after = new node;
            after->num = next->num;
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
}
