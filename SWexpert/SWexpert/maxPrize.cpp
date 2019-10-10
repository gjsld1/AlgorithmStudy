//
//  SWExpertAcademy 1244 D3
//  maxPrize.cpp
//  SWexpert
//
//  Created by 신예지 on 10/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string score;
int num, ans;

void dfs(int cur, int n) {
    if(n==num) {
        ans = max(ans, atoi(score.c_str()));
        return;
    }
    else {
        for(int i=cur; i<score.size(); i++) {
            for(int j=i+1; j<score.size(); j++) {
                if(score[i]<=score[j]) {
                    swap(score[i],score[j]);
                    dfs(i,n+1);
                    swap(score[i],score[j]);
                }
            }
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=1; i<=tc; i++) {
        cin >> score >> num;
        ans=0;
        dfs(0,0);
        
        cout << "#" << i << " " << ans << endl;
    }
}
