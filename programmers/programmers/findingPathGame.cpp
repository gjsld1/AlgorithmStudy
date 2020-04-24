//
//  findingPathGame.cpp
//  programmers
//
//  Created by 신예지 on 25/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int index;
    pair<int,int> coordinate;
    struct node* left;
    struct node* right;
};

struct node *x, *z;
vector<int> ans;

vector<int> preorder(struct node *t) {
    if(t!=z) {
        ans.push_back(t->index);
        preorder(t->left);
        preorder(t->right);
    }
    return ans;
}
vector<int> postorder(struct node *t) {
    if(t!=z) {
        postorder(t->left);
        postorder(t->right);
        ans.push_back(t->index);
    }
    return ans;
}

void makeTree (vector<pair<pair<int,int>,int>> nodeinfo, struct node* p) {
    int n =nodeinfo.size();
    if(n==0) return;
    
    struct node* temp = new node;
    temp->coordinate = nodeinfo[0].first;
    temp->index = nodeinfo[0].second;
    temp->left=z;
    temp->right=z;
    int mid = nodeinfo[0].first.second;
    
    if(temp->coordinate.second > p->coordinate.second) p->right=temp;
    else p->left=temp;
    
    if(n==1) return;
    
    vector<pair<pair<int,int>,int>> left, right;
    for(int i=1; i<n; i++) {
        if(nodeinfo[i].first.second > mid) right.push_back(nodeinfo[i]);
        else left.push_back(nodeinfo[i]);
    }
    
    makeTree(left,temp);
    makeTree(right,temp);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<pair<pair<int,int>,int>> order;
    for(int i=0; i<nodeinfo.size(); i++) order.push_back({{nodeinfo[i][1], nodeinfo[i][0]},i+1});
    sort(order.begin(),order.end());
 
    z = new node;
    z->left = z;
    z->right = z;
    
    x = new node;
    x->coordinate=order[order.size()-1].first;
    x->index=order[order.size()-1].second;
    
    vector<pair<pair<int,int>,int>> left, right;
    for(int i=order.size()-2; i>=0; i--) {
        if(order[i].first.second > x->coordinate.second) right.push_back(order[i]);
        else left.push_back(order[i]);
    }
    makeTree(left, x);
    makeTree(right,x);
    
    vector<vector<int>> answer;
    answer.push_back(preorder(x));
    ans.clear();
    answer.push_back(postorder(x));
    return answer;
}

int main() {
    vector<vector<int>> nodeinfo;
    vector<int> temp;
    temp.push_back(5);
    temp.push_back(3);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(11);
    temp.push_back(5);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(13);
    temp.push_back(3);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(3);
    temp.push_back(5);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(6);
    temp.push_back(1);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(3);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(8);
    temp.push_back(6);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(7);
    temp.push_back(2);
    nodeinfo.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(2);
    nodeinfo.push_back(temp);
    
    vector<vector<int>> answer = solution(nodeinfo);
    
    for(int i=0; i<answer[0].size(); i++) cout << answer[0][i] << " ";
    cout << endl;
    for(int i=0; i<answer[1].size(); i++) cout << answer[1][i] << " ";
    cout << endl;
}
