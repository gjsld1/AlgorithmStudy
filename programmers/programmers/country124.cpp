//
//  country124.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    int a;
    while(n>0) {
        a=n%3;
        n=n/3;
        
        if(a==0) {
            a=4;
            n--;
        }
        answer = to_string(a)+answer;
    }
    return answer;
}

int main() {
    cout << solution(10);
}
