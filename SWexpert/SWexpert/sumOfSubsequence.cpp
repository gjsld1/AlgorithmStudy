//
//  SWExpertAcademy 2817 D3
//  sumOfSubsequence.cpp
//  SWexpert
//
//  Created by 신예지 on 23/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;
int ans, n, k;
int* sequence;

void subsequence(int cur, int sum) {
    if(sum==k) {
        ans++;
        return;
    }
    if(sum>k || cur==n) return;
    
    subsequence(cur+1, sum+sequence[cur]);
    subsequence(cur+1, sum);
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=1; i<=tc; i++) {
        cin >> n >> k;
        
        sequence = new int[n];
        for(int j=0; j<n; j++) cin >> sequence[j];
        ans=0;
        subsequence(0, 0);
        
        cout << "#" << tc << " " << ans << endl;
    }
}
