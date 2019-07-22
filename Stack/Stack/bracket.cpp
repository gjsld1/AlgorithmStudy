//
//  baekjoon 9012
//  bracket.cpp
//  Stack
//
//  Created by 신예지 on 21/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        stack<char> s;
        bool isRight = true;
        
        string str;
        cin >> str;
        for(int j=0; j<str.length(); j++) {
            if(str[j]=='(') s.push('(');
            else if(str[j]==')') {
                if(s.empty()) {
                    isRight=false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) isRight=false;
        
        if(isRight) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

/*
string isVPS(string str) {
    string check = "NO";
    stack<char> bracket;
    
    if(str[0]==')' || str.length()%2 == 1) return check;
    
    for(int i=0; i<str.length(); i++) {
        if (str[i]=='(') bracket.push('(');
        else {
            if(bracket.empty()) return check;
            else bracket.pop();
        }
    }
    if(bracket.empty()) check = "YES";
    
    return check;
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        string str;
        cin >> str;
        
        cout << isVPS(str) << endl;
    }
}
*/
