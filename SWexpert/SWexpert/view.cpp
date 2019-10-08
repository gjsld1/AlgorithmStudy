//
//  SWExpertAcademy 1206 D3
//  view.cpp
//  SWexpert
//
//  Created by 신예지 on 07/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

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
            
            if(heights[i]-heights[i-1]>0) view = view<heights[i]-heights[i-1] ? view : heights[i]-heights[i-1];
            else continue;
            if(heights[i]-heights[i-2]>0) view = view<heights[i]-heights[i-2] ? view : heights[i]-heights[i-2];
            else continue;
            if(heights[i]-heights[i+1]>0) view = view<heights[i]-heights[i+1] ? view : heights[i]-heights[i+1];
            else continue;
            if(heights[i]-heights[i+2]>0) view = view<heights[i]-heights[i+2] ? view : heights[i]-heights[i+2];
            else continue;
            
            if(view == heights[i]) view=0;
            
            sum += view;
        }
        cout << "#" << c++ << " " << sum << endl;
    }
}
