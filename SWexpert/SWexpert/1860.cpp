//
//  1860.cpp
//  SWexpert D3
//
//  Created by 신예지 on 09/02/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        int n, m, k;
        cin >> n >> m >> k;
        
        string ans = "Possible";
        
        int* wait = new int[n];
        for(int i=0; i<n; i++) {
            cin >> wait[i];
        }
        sort(wait, wait+n);
        
        if(wait[0] < m) ans = "Impossible";
        else {
            int nowBoong=0;
            for(int i=0, before=0; i<n; i++) {
                nowBoong += (wait[i]-before)/m * k;
                if(nowBoong!=0) {
                    nowBoong--;
                    before += m;
                }
                else {
                    ans = "Impossible";
                    break;
                }
            }
            /* time limit
            int timer = 0;
            int time = 0;
            int curBoong = 0;
            int cur=0;
            
            while(++timer) {
                if(cur==n) break;
                
                time++;
                
                if(timer==m) {
                    curBoong=k;
                    timer=0;
                }
                
                if(time==wait[cur]) {
                    if(curBoong==0) {
                        ans="Impossible";
                        break;
                    }
                    cur++;
                    curBoong--;
                }
            }
             */
        }
        
        cout << "#" << q << " " << ans << endl;
    }
}
