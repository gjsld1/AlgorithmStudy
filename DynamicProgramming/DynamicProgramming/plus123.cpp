//
//  plus123.cpp
//  DynamicProgramming
//
//  Created by 신예지 on 2020/05/22.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        int num;
        cin >> num;
        
        int* d = new int[11]();
        d[1]=1;
        d[2]=2;
        d[3]=4;
        
        for(int j=4; j<=num; j++) {
            d[j]+=d[j-1]+d[j-2]+d[j-3];
        }
        
        cout << d[num] << endl;
    }
}
