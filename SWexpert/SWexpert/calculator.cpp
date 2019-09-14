//
//  SWEpxertAcademy 8338
//  main.cpp
//  SWepxert
//
//  Created by 신예지 on 11/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        int n;
        scanf("%d", &n);
        int* num = new int[n];
        
        int sum;
        scanf("%d", &sum);
        num[0]=sum;
        
        for(int j=1; j<n; j++) {
            scanf("%d", &num[j]);
            
            if(sum==0 || num[j]==0) continue;
            else if(sum==1 || num[j]==1) sum+=num[j];
            else sum*=num[j];
        }
        
        cout << "#"<< i+1 << " " << sum << endl;
    }
}
