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

pair<int, int> nextCoordinate (int start, int n, int x, int y, int direction, int cnt) {
    while(cnt!=0) {
        cnt--;
        
        switch (direction) {
            case -1:
                if(x==start && y==start) x++;
                else if(x==start && y==n-start-1) x--;
                else if(x==n-start-1 && y==start) y++;
                else if(x==n-start-1 && y==n-start-1) x--;
                
                else if(x==start) y--;
                else if(x==n-start-1) y++;
                else if(y==start) x++;
                else if(y==n-start-1) x--;
                break;
                
            case 1:
                if(x==start && y==start) y++;
                else if(x==start && y==n-start-1) x++;
                else if(x==n-start-1 && y==start) x--;
                else if(x==n-start-1 && y==n-start-1) y--;
                
                else if(x==start) y++;
                else if(x==n-start-1) y--;
                else if(y==start) x--;
                else if(y==n-start-1) x++;
                break;
        }
    }
    
    return {x,y};
}

int main() {
    int n, w;
    cin >> n >> w;
    
    string** board = new string*[n];
    string** ans = new string*[n];
    for(int i=0; i<n; i++) {
        board[i] = new string[n];
        ans[i] = new string[n];
        
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    
    if(n%2==0) {
        int tmp=n;
        int direction = 1;
        
        while(tmp>1) {
            int start=0;
            //how to find n?
            
        }
    }
    
    
    return 0;
}
