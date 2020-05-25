//
//  network.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/25.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

int* visited;
void bfs(vector<vector<int>> computers, int idx) {
    if(visited[idx]) return;
    
    visited[idx]=1;
    for(int i=0; i<computers[idx].size(); i++) {
        if(computers[idx][i]) bfs(computers,i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited = new int[n]();
    
    int answer=0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            bfs(computers,i);
            answer++;
        }
    }
    return answer;
}

int main() {
    int n=3;
    vector<vector<int>> computers;
    computers.push_back({1,1,0});
    computers.push_back({1,1,0});
    computers.push_back({0,0,1});
    
    cout << solution(n,computers) << endl;
}
