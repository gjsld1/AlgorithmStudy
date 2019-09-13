//
//  SWEpxertAcademy 8338
//  main.cpp
//  SWepxert
//
//  Created by 신예지 on 11/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        int n;
        cin >> n;
        int* num = new int[n];
        
        cin >> num[0];
        int sum = num[0];
        
        for(int j=1; j<n; j++) {
            cin >> num[j];
            
            if(sum==0 || num[j]==0) continue;
            else if(sum==1 || num[j]==1) sum+=num[j];
            else sum*=num[j];
        }
        
        cout << "#"<< i+1 << " " << sum << endl;
    }
}
