//
//  2.cpp
//  qshell
//
//  Created by 신예지 on 2020/07/04.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int idx, int sum) {
    if(idx==numbers.size()) {
        if(sum==0) answer++;
        return;
    }
    
    /*
    int partSum=0;
    for(int i=idx; i<numbers.size(); i++) {
        partSum+=numbers[i];
    }
    if(sum>partSum) return;*/
    
    dfs(numbers, idx+1, sum+numbers[idx]);
    dfs(numbers, idx+1, sum-numbers[idx]);
}

int solution(vector<int> numbers) {
    //sort(numbers.begin(),numbers.end(),greater<int>());
    dfs(numbers,0,0);
    return answer;
}

int main() {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    
    cout << solution(numbers);
}
