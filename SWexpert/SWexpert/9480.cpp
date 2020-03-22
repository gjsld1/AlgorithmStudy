//
//  9480.cpp
//  SWexpert
//
//  Created by 신예지 on 22/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int ans, n;
string* word;

void dfs(string str, int idx) {
    if(idx==n-1) {
        for(int i=0; i<26; i++) {
            if(str.find('a'+i) == string::npos) return;
        }
        ans++;
        return;
    }
    
    dfs(str+word[idx],idx+1);
    dfs(str, idx+1);
}

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        cin >> n;
        
        ans=0;
        word = new string[n];
        for(int i=0; i<n; i++) cin >> word[i];
        
        dfs("",0);
        cout << "#" << q << " " << ans << endl;
    }
}
