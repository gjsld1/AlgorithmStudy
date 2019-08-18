//
//  baekjoon 1987
//  alphabet.cpp
//  DFS
//
//  Created by 신예지 on 18/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int r, c;
char** map;
int** route;

bool isInRange(int x, int y) {
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

void bfs(int* visited, int ans, int x, int y) {
    int temp[26];
     for(int i=0; i<26; i++) temp[i]=visited[i];
    
    temp[map[x][y]-'A']=1;
    ans++;
    route[x][y] = ans<route[x][y]?route[x][y]:ans;
    
    if(isInRange(x+1,y) && temp[map[x+1][y]-'A']==0) bfs(temp,ans,x+1,y);
    if(isInRange(x-1,y) && temp[map[x-1][y]-'A']==0) bfs(temp,ans,x-1,y);
    if(isInRange(x,y+1) && temp[map[x][y+1]-'A']==0) bfs(temp,ans,x,y+1);
    if(isInRange(x,y-1) && temp[map[x][y-1]-'A']==0) bfs(temp,ans,x,y-1);
}

int main() {
    cin >> r >> c;
    
    map = new char* [r];
    route = new int* [r];
    for(int i=0; i<r; i++) {
        map[i] = new char[c];
        route[i] = new int[c]();
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
    
    int visited[26] = {0};
    int ans=0;
    bfs(visited, ans, 0, 0);
    
    int max=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            max = max<route[i][j] ? route[i][j] : max;
        }
    }
    cout << max;
}

/*
 * using unnecessary stack
 *
 
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int r, c;
char** map;
int** route;
stack<pair<int,int>> s;

bool isInRange(int x, int y) {
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

void bfs(int* visited, int ans) {
    int temp[26];
    for(int i=0; i<26; i++) temp[i]=visited[i];
    
    while(!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        
        temp[map[x][y]-'A']=1;
        s.pop();
        ans++;
        route[x][y] = ans<route[x][y]?route[x][y]:ans;
        
        if(isInRange(x+1,y) && temp[map[x+1][y]-'A']==0) {
            s.push({x+1,y});
            bfs(temp,ans);
        }
        if(isInRange(x-1,y) && temp[map[x-1][y]-'A']==0) {
            s.push({x-1,y});
            bfs(temp,ans);
        }
        if(isInRange(x,y+1) && temp[map[x][y+1]-'A']==0) {
            s.push({x,y+1});
            bfs(temp,ans);
        }
        if(isInRange(x,y-1) && temp[map[x][y-1]-'A']==0) {
            s.push({x,y-1});
            bfs(temp,ans);
        }
    }
}

int main() {
    cin >> r >> c;
    
    map = new char* [r];
    route = new int* [r];
    for(int i=0; i<r; i++) {
        map[i] = new char[c];
        route[i] = new int[c]();
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
    
    int visited[26] = {0};
    
    s.push({0,0});
    int ans=0;
    bfs(visited, ans);
    
    int max=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            max = max<route[i][j] ? route[i][j] : max;
        }
    }
    cout << max;
}
*/
