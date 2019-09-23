//
//  nhnPreTest.cpp
//  test
//
//  Created by 신예지 on 23/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<int, int> nextCoordinate (int n, int x, int y, int direction) {
    pair<int,int> next;
    
    next.first = x;
    next.second = y;
    
    
    return next;
}

int main() {
    int n, w;
    cin >> n >> w;
    
    string** board = new string*[n];
    for(int i=0; i<n; i++) {
        board[i] = new string[n];
        
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    
    if(n%2==0) {
        int tmp=n;
        int start=0;
        while(tmp>1) {
            
        }
    }
    
    
    return 0;
}
