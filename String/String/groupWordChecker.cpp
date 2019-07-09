//
// baekjoon 1316
//  groupWordChecker.cpp
//  String
//
//  Created by 신예지 on 09/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int count = 0;
    
    for(int i=0; i<n; i++) {
        int* alpha = new int[26]();
        
        string str;
        cin >> str;
        
        int flag = 0;
        for(int i=0; i<str.length(); i++) {
            if(alpha[str[i]-'a']==0) alpha[str[i]-'a']=1;
            else {
                if(str[i]==str[i-1]) continue;
                flag = 1;
                break;
            }
        }
        if(flag==0) count++;
    }
    cout << count;
}
