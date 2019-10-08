//
//  SWExpertAcademy 1206 D3
//  view.cpp
//  SWexpert
//
//  Created by 신예지 on 07/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//


// 9/10
#include <iostream>
using namespace std;

int main() {
    int tc=10, c=1;
    while(tc--) {
        int n;
        cin >> n;
        
        int* heights = new int[n];
        for(int i=0; i<n; i++) cin >> heights[i];
        
        int sum=0;
        
        for(int i=2; i<n-2; i++) {
            int view = heights[i];
            
            int temp=heights[i]-heights[i-1];
            if(temp>0) view = view<temp ? view : temp;
            else continue;
            
            temp=heights[i]-heights[i-2];
            if(temp>0) view = view<temp ? view : temp;
            else continue;
            
            temp=heights[i]-heights[i+1];
            if(temp>0) view = view<temp ? view : temp;
            else continue;
            
            temp=heights[i]-heights[i+2];
            if(temp>0) view = view<temp ? view : temp;
            else continue;
            
            sum += view;
        }
        cout << "#" << c++ << " " << sum << endl;
    }
}
