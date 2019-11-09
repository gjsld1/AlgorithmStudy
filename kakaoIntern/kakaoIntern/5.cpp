//
//  5.cpp
//  kakaoIntern
//
//  Created by 신예지 on 09/11/2019.
//  Copyright © 2019 신예지. All rights reserved.
//
#include <iostream>

#include <string>
#include <vector>

using namespace std;
int n;

int howMany(int cur, int k, int* stones) {
    for(int i=1; i<=k; i++) {
        if(cur+i==n) return 1;
        if(stones[cur+i]!=0) return i;
    }
    return 0;
}

bool reachEnd(int* copy, int k, int cur) {
    while(cur<n) {
        if(howMany(cur, k, copy)==0) return false;
        cur+=howMany(cur, k, copy);
        
        if(cur>=n) return true;
        copy[cur]--;
    }
    
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    n=stones.size();
    int* copy = new int[stones.size()];
    for(int i=0; i<stones.size(); i++) copy[i]=stones[i];
    
    int cur=-1;
    while(howMany(cur, k, copy)) {
        if(reachEnd(copy, k, cur)) answer++;
    }
    
    return answer;
}

int main() {
    vector<int> stones;
    stones.push_back(2);
    stones.push_back(4);
    stones.push_back(5);
    stones.push_back(3);
    stones.push_back(2);
    stones.push_back(1);
    stones.push_back(4);
    stones.push_back(2);
    stones.push_back(5);
    stones.push_back(1);
    
    cout << solution(stones, 3);
}

