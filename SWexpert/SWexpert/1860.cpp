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
            int now = 0;
            
            
            for(int i=0; i<n; i++) {
                int before;
                if(i==0) before=0;
                now += (wait[i]-before)/m * k;
                if(now!=0) {
                    now--;
                    before = wait[i];
                    continue;
                }
                else {
                    ans = "Impossible";
                    break;
                }
            }
        }
        
        cout << "#" << q << " " << ans << endl;
    }
}
