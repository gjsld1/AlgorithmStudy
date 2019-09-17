//
//  SWExpertAcademy 8016
//  oddPyramid.cpp
//  SWexpert
//
//  Created by 신예지 on 15/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        int n;
        cin >> n;
        
        int lineOddCount = 2*n-1;
        long int beforeOddCount = pow((lineOddCount-1)/2,2);
        
        long int lineStart = 2*beforeOddCount+1;
        long int lineEnd = lineStart+(2*(lineOddCount-1));
        
        cout << "#" << i+1 << " " << lineStart << " " << lineEnd << endl;
    }
}
