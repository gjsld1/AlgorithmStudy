//
//  84.cpp
//  BinarySearch
//
//  Created by 신예지 on 21/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    if(heights.size()==0) return 0;
    
    stack<int> idx;
    
    if(heights[0]!=0) idx.push(0);
    for(int i=1; i<heights.size(); i++) {
        if(heights[i] > heights[i-1]) idx.push(i);
        else if(heights[i] == heights[i-1]) idx.push(i-1);
    }
    
    int area, max = heights[0];
    while(!idx.empty()) {
        int i = idx.top();
        idx.pop();
        int width = 1;
        int height = heights[i];
        area = width*height;
        
        for(int j=i+1; j<heights.size(); j++) {
            width++;
            if(height > heights[j]) height = heights[j];
            
            if(max < width*height) max = width*height;
        }
        max = max > area? max : area;
    }
    return max;
}

int main() {
    vector<int> heights;
    heights.push_back(0);
    heights.push_back(9);
    cout << largestRectangleArea(heights);
}
