//
//  checkWall.cpp
//  programmers
//
//  Created by 신예지 on 2020/04/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int periphery, person;
int temp;


void explore(vector<int> weak, vector<int> dist, int pos, int* visit, int ans) {
    if(visit[pos]) return;
    if(weak.size()==0) {
        if(temp==-1) temp=ans;
        temp = ans>temp? temp : ans;
        return;
    }
    
    if(dist.size()==0) {
        temp=-1;
        return;
    }
    
    int move=dist[dist.size()-1];
    dist.erase(find(dist.begin(),dist.end(),move));
    ans++;
    
    int* tmp = new int[periphery];
    for(int i=0; i<periphery; i++) tmp[i]=visit[i];
    
    if(find(weak.begin(),weak.end(),pos)!=weak.end()) weak.erase(find(weak.begin(),weak.end(),pos));
    tmp[pos]=1;
    
    for(int i=0; i<move; i++) {
        if(++pos==periphery) pos=0;
        if(find(weak.begin(),weak.end(),pos)!=weak.end()) weak.erase(find(weak.begin(),weak.end(),pos));
        tmp[pos]=1;
    }
    
    for(int i=1; i<periphery-person; i++) {
        pos+=i;
        if(pos>=periphery) pos-=periphery;
        explore(weak, dist, pos, tmp, ans);
    }
}


int solution(int n, vector<int> weak, vector<int> dist) {
    temp = dist.size();
    person = temp;
    periphery=n;
   
    for(int i=0; i<n; i++) {
        int* visit = new int[n]();
        explore(weak, dist, i, visit, 0);
    }
    return temp;
}

int main() {
    vector<int> weak, dist;
    weak.push_back(1);
    weak.push_back(3);
    weak.push_back(4);
    weak.push_back(9);
    weak.push_back(10);
    
    //dist.push_back(1);
    //dist.push_back(2);
    dist.push_back(3);
    dist.push_back(5);
    dist.push_back(7);
    
    cout << solution(12, weak, dist) << endl;
}
