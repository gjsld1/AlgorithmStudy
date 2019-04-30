//
//  1021.cpp
//  Stack
//
//  Created by 신예지 on 30/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeOuterParentheses(string S) {
    stack<char> stack;
    int openCnt = 0;
    int closeCnt = 0;
    
    int open=0, close;
    
    string last="";
    
    for(int i=0; i<S.length(); i++) {
        if(S[i]=='(') {
            stack.push(S[i]);
            openCnt++;
        }
        else if(S[i]==')') {
            stack.pop();
            closeCnt++;
            if(openCnt==closeCnt) {
                close=i;
                last+=S.substr(open+1, close-open-1);
                open=i+1;
            }
        }
    }
    return last;
}

int main() {
    cout << removeOuterParentheses("(()())(())") << endl;
}
