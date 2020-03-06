//
//  2805.cpp
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
        int ans = 0;
        
        int n;
        cin >> n;
        
        int** farm = new int* [n];
        for(int i=0; i<n; i++) {
            farm[i] = new int[n];
            for(int j=0; j<n; j++) scanf("%1d", &farm[i][j]);
        }
        
        int center = (n-1)/2;
        int coverage=0;
        
        for(int i=0; i<= n/2; i++) {
            for(int j=center-coverage; j<=center+coverage; j++) {
                ans += farm[i][j];
            }
            coverage++;
        }
        coverage-=2;
        
        for(int i=n/2+1; i<n; i++){
            for(int j=center-coverage; j<=center+coverage; j++) {
                ans += farm[i][j];
            }
            coverage--;
        }
        
        cout << "#" << q << " " << ans << endl;
    }
}
