//
//  8741.cpp
//  SWexpert
//
//  Created by 신예지 on 06/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    
    for(int q=1; q<=tc; q++) {
        string s;
        getline(cin,s);
        
        string ans = "";
        
        char c = s[0]-32;
        ans += c;
        
        int i=1;
        for(int i=0; i<s.size(); i++) {
            if(s[i-1]==' ') {
                c = s[i]-32;
                ans += c;
            }
        }
        
        cout << "#" << q << " " << ans << endl;
    }
}
