//
//  3752.cpp
//  SWexpert
//
//  Created by 신예지 on 06/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int q=1; q<=tc; q++) {
        int n;
        cin >> n;
        
        int* score=new int[n+1];
        for(int i=1; i<=n; i++) cin >> score[i];
        
        int* d = new int[n*100+1]();
        d[0]=1;
        
        for(int i=1; i<=n; i++) {
            for(int j=100*n; j>=0; j--) {
                if(d[j]) d[j+score[i]]=1;
            }
        }
        
        int ans=0;
        for(int i=0; i<=100*n; i++) {
            if(d[i]) {
                ans++;
            }
        }
        
        cout << "#" << q << " " << ans << endl;
    }
}
