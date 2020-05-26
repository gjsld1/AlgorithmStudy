//
//  tileDecoration.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/26.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    long long* length = new long long[N+1]();
    length[1]=1;
    length[2]=1;
    for(int i=3; i<=N; i++) {
        length[i]=length[i-1]+length[i-2];
    }
    
    long long a=length[N]+length[N-1];
    long long b=length[N-1]+length[N-2];
    
    long long answer = 2*a+2*b;
    return answer;
}

int main() {
    cout << solution(6) << endl;
}
