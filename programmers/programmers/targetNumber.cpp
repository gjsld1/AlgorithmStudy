//
//  targetNumber.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

int answer=0;
int size;
int want;

void dfs(vector<int> numbers, int n, int idx) {
    if(idx==size && n==want) answer++;
    if(idx==size) return;
    
    dfs(numbers,n+numbers[idx],idx+1);
    dfs(numbers,n-numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    size=numbers.size();
    want=target;
    
    dfs(numbers,0,0);
    return answer;
}
