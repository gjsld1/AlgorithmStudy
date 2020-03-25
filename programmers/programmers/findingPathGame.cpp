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

vector<int> preorder(struct node *t) {
    vector<int> ans;
    if(t!=z) {
        ans.push_back(t->index);
        preorder(t->left);
        preorder(t->right);
    }
    return ans;
}
vector<int> postorder(struct node *t) {
    vector<int> ans;
    if(t!=z) {
        postorder(t->left);
        postorder(t->right);
        ans.push_back(t->index);
    }
    return ans;
}

void makeTree (vector<pair<pair<int,int>,int>> nodeinfo, struct node* p) {
    if(nodeinfo.empty()) return;
    
    x = new node;
    x->coordinate = nodeinfo[0].first;
    x->index = nodeinfo[0].second;
    
    if(p->right==z || nodeinfo[0].first.second > p->coordinate.second) p->right=x;
    else p->left=x;
    
    if(nodeinfo.size()==1) return;
    
    vector<pair<pair<int,int>,int>> left, right;
    int mid = nodeinfo[0].first.second;
    for(int i=1; i<nodeinfo.size(); i++) {
        if(nodeinfo[i].first.second > mid) right.push_back(nodeinfo[i]);
        else left.push_back(nodeinfo[i]);
    }
    
    makeTree(left,x);
    makeTree(right,x);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<pair<pair<int,int>,int>> order, left, right;
    for(int i=0; i<nodeinfo.size(); i++) order.push_back({{nodeinfo[i][1], nodeinfo[i][0]},i+1});
    
    z = new node;
    z->left = z;
    z->right = z;
    
    x = new node;
    x->right = z;
    
    makeTree(order,x);
    
    vector<vector<int>> answer;
    answer.push_back(preorder(x));
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
