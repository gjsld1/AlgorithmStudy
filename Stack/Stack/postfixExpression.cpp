//
//  baekjoon 1918
//  postfixExpression.cpp
//  Stack
//
//  Created by 신예지 on 28/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    switch (c) {
        case '(':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
    return -1;
}

int main() {
    string input;
    cin >> input;
    
    string ans = "";
    stack<char> s;
    
    for(int i=0; i<input.length(); i++) {
        if(input[i]>='A' && input[i]<='Z') ans+=input[i];
        else if(input[i]=='(') s.push(input[i]);
        else if(input[i]==')') {
            while(s.top()!='(') {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            if(s.empty()) s.push(input[i]);
            else {
                while(!s.empty() && priority(s.top())>=priority(input[i])) {
                    ans+=s.top();
                    s.pop();
                }
                s.push(input[i]);
            }
        }
    }
    while(!s.empty()) {
        ans+=s.top();
        s.pop();
    }
    
    cout<< ans;
}

/*
 * Memory limit
 
int main() {
    char c;
    stack<char> operand;
    string ans = "";
    
    while((c=cin.get())!='\n') {
        if(c>='A' && c<='Z') ans += c;
        else if(c=='(') operand.push(c);
        else if(c==')') {
            while(operand.top()!='(') {
                ans += operand.top();
                operand.pop();
            }
            operand.pop();
        }
        else {
            if(operand.empty()) operand.push(c);
            else {
                while(!operand.empty() && priority(operand.top()) >= priority(c)) {
                    ans += operand.top();
                    operand.pop();
                }
                operand.push(c);
            }
        }
    }
    
    while(!operand.empty()) {
        ans += operand.top();
        operand.pop();
    }
    
    cout << ans;
}
*/
