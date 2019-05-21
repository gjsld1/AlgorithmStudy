//
//  639.cpp
//  String
//
//  Created by 신예지 on 13/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MOD 1000000007
using namespace std;

int numDecodings(string s) {
    int n = s.length();
    if(n==0) return 1;
    int* memo = new int[n+1]();

    memo[0]=1;
    
    for(int i=1; i<=n; ++i) {
        if(s[i-1]!='*') {
            memo[i] = 0;
            if(s[i-1]!='0') memo[i] += memo[i-2];
            if(i>=2 && (s[i-2]-'0')*10 + s[i-1]-'0'>=10 && (s[i-2]-'0')*10 + s[i-1]-'0'<=26) memo[i] += memo[i-2];
            else if(i>=2 && s[i-2]=='*' && s[i-1]-'0'<=6) memo[i] +=memo[i-2]*2;
            else if(i>=2 && s[i-2]=='*' && s[i-1]-'0'>6) memo[i] += memo[i-2];
        }
        else {
            memo[i] = memo[i-1]*9;
            if(i>=2 && s[i-2]=='1') memo[i] = memo[i-2]*9;
            else if(i>=2 && s[i-2]=='2') memo[i] = memo[i-2]*6;
            else if(i>=2 && s[i-2]=='*') memo[i] = memo[i-2]*15;
        }
    }
    return memo[n] % MOD;
    /*
     if(s[0]=='0') {
     memo[1] = 0;
     return 0;
     }
     else if(s[0]=='*') memo[1] = 9;
     else memo[1] = 1;
     
    int cnt=0;
    for(int i=2; i<=n; i++) {
        if(s[i-1] == '*') {
            memo[i] += 9;
            if(s[i-2]=='1') memo[i] += 9;
            else if(s[i-2]=='2') memo[i] += 6;
        }
        else if(s[i-1] != '0') memo[i] += memo[i-1];
        if(s[i-2] == '*') {
            if(s[i-1]<='6') memo[i] += 2;
            else memo[i] += 1;
        }
        if(s[i-2]=='*' && s[i-1]=='*') {
            memo[i] = memo[i-1]*9 + 15*pow(9,cnt);
            cnt++;
        }
    }
    return memo[n];
     */
}

int main() {
    string num = "1*";
    cout << numDecodings(num);
}
