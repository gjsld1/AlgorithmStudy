//
//  SWExpertAcademy 1215 D3
//  palindrome.cpp
//  SWexpert
//
//  Created by 신예지 on 18/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isInRange(int n, int i) {
    if(i+4>=n) return false;
    return true;
}

bool isPalindrome(string str) {
    int start=0, end=str.length()-1;
    while(start<end) {
        if(str[start++]!=str[end--]) return false;
    }
    return true;
}

int howManyPalindrome(int board[8][8], int n) {
    int ans=0;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            string chk="";
            if(isInRange(n, i)) {
                for(int k=i; k<i+4; k++) chk+=board[k][j];
                if(isPalindrome(chk)) ans++;
            }
            chk="";
            if(isInRange(n, j)) {
                for(int k=j; k<j+4; k++) chk+=board[i][k];
                if(isPalindrome(chk)) ans++;
            }
        }
    }
    return ans;
}

int main() {
    
    for(int tc=1; tc<=10; tc++) {
        int n;
        cin >> n;
        
        int board[8][8];
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) cin >> board[i][j];
        }
        
        cout << "#" << tc << " " << howManyPalindrome(board, n) << endl;
    }
}
