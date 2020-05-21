//
//  buyCard.cpp
//  DynamicProgramming
//
//  Created by 신예지 on 2020/05/21.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int* pack = new int[n+1];
    for(int i=1; i<=n; i++) cin >> pack[i];
    
    int* d = new int[n+1]();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            d[i] = max(d[i],d[i-j]+pack[j]);
        }
    }
    cout << d[n] << endl;
}
