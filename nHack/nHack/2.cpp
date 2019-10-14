//
//  2.cpp
//  Hack
//
//  Created by 신예지 on 12/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<char, set<char>> ans;
int m, n;
int** visited;

bool isInRange(int x, int y) {
    if((x>=0 && x<n) && (y>=0 && y<m)) return true;
    return false;
}

void dfs(vector<string> maps, int cur_x, int cur_y) {
    if(maps[cur_x][cur_y]=='.' || visited[cur_x][cur_y]==1) {
        visited[cur_x][cur_y]=1;
        return;
    }
    visited[cur_x][cur_y]=1;
    
    if(isInRange(cur_x+1, cur_y) && maps[cur_x+1][cur_y]!='.') {
        if(maps[cur_x][cur_y]!=maps[cur_x+1][cur_y]) ans[maps[cur_x][cur_y]].insert(maps[cur_x+1][cur_y]);
        dfs(maps, cur_x+1, cur_y);
    }
    if(isInRange(cur_x-1, cur_y) && maps[cur_x-1][cur_y]!='.') {
        if(maps[cur_x][cur_y]!=maps[cur_x-1][cur_y]) ans[maps[cur_x][cur_y]].insert(maps[cur_x-1][cur_y]);
        dfs(maps, cur_x-1, cur_y);
    }
    if(isInRange(cur_x, cur_y+1) && maps[cur_x][cur_y+1]!='.') {
        if(maps[cur_x][cur_y]!=maps[cur_x][cur_y+1]) ans[maps[cur_x][cur_y]].insert(maps[cur_x][cur_y+1]);
        dfs(maps, cur_x, cur_y+1);
    }
    if(isInRange(cur_x, cur_y-1) && maps[cur_x][cur_y-1]!='.') {
        if(maps[cur_x][cur_y]!=maps[cur_x][cur_y-1]) ans[maps[cur_x][cur_y]].insert(maps[cur_x][cur_y-1]);
        dfs(maps, cur_x, cur_y-1);
    }
    return;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    
    visited = new int*[n];
    for(int i=0; i<n; i++) visited[i]=new int[m]();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dfs(maps,i,j);
        }
    }
    
    int max=0, sum=0;
    for(int i=0; i<ans.size(); i++) {
        sum += ans[i].size();
        if(max<ans[i].size()) max=ans[i].size();
    }
    answer.push_back(sum/2);
    answer.push_back(max);
    return answer;
}
