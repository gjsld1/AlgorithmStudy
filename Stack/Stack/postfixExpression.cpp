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
    return 0;
}

int main() {
    char c;
    stack<char> operand;
    
    while((c=cin.get())!='\n') {
        if(c>=65 && c<=90) cout << c;
        else if(c=='(') operand.push(c);
        else if(c==')') {
            while(operand.top()!='(') {
                cout << operand.top();
                operand.pop();
            }
            operand.pop();
        }
        else {
            if(operand.empty() || priority(operand.top())<=priority(c)) operand.push(c);
            else {
                while(!operand.empty() && priority(operand.top()) >= priority(c)) {
                    cout << operand.top();
                    operand.pop();
                }
                operand.push(c);
            }
        }
    }
    
    while(!operand.empty()) {
        cout << operand.top();
        operand.pop();
    }
}
