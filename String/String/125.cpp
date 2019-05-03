//
//  125.cpp
//  String
//
//  Created by 신예지 on 03/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    string str = "";
    
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') str += tolower(s[i]);
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) str += s[i];
    }
    
    int front = 0;
    int end = str.length()-1;
    
    while(front<end) {
        if(str[front++] != str[end--]) return false;
    }
    return true;
}

int main() {
    string str = "0P";
    cout << isPalindrome(str);
}
