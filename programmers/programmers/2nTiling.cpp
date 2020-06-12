//
//  2nTiling.cpp
//  programmers
//
//  Created by 신예지 on 2020/06/12.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

int factorial(int n) {
    if(n==0 || n==1) return 1;
    return n*factorial(n-1);
}

int combination(int a, int b) {
    int temp=1;
    for(int i=0; i<b; i++) {
        temp*=a;
        a--;
    }
    return temp/factorial(b);
}

int solution(int n) {
    vector<int> v;
    for(int i=0; i<n; i++) v.push_back(1);
    
    vector<vector<int>> possible;
    possible.push_back(v);
    for(int i=0; i<n/2; i++) {
        if(v.size()>=2) {
            v.erase(v.begin());
            v.erase(v.begin());
            v.push_back(2);
        }
        possible.push_back(v);
    }

    int answer=0;
    for(int i=0; i<possible.size(); i++) {
        int num1=0;
        for(int j=0; j<possible[i].size(); j++) {
            if(possible[i][j]==1) num1++;
        }
        answer += combination(possible[i].size(), num1);
    }
    
    return answer%1000000007;
}

int main() {
    cout << solution(5) << endl;
}
