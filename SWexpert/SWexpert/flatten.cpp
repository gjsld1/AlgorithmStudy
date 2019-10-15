//
//  SWExpertAcademy 1208 D3
//  flatten.cpp
//  SWexpert
//
//  Created by 신예지 on 15/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tc=10;
    for(int i=1; i<=tc; i++) {
        int n;
        cin >> n;
        
        int heights[100];
        for(int i=0; i<100; i++) cin >> heights[i];
        
        while(n--) {
            *max_element(heights, heights+100) = *max_element(heights, heights+100)-1;
            *min_element(heights, heights+100) = *min_element(heights, heights+100)+1;
        }
        
        cout << "#" << i << " " << *max_element(heights, heights+100)-*min_element(heights, heights+100) << endl;
    }
}
