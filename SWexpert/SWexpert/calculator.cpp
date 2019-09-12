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
        
        int sum;
        for(int j=0; j<n; j++) {
            cin >> num[j];
            
            if(j==1) sum = (num[0]*num[1])>(num[0]+num[1])? num[0]*num[1] : num[0]+num[1];
            else if(j>1) {
                if(num[j]==0) continue;
                else if(num[j]==1) sum++;
                else sum*=num[j];
            }
        }
        
        cout << "#"<< i+1 << " " << sum << endl;
    }
}
