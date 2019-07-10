//
//  kakao 2018 1st
//  dartGame.cpp
//  String
//
//  Created by 신예지 on 10/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define S 1
#define D 2
#define T 3

int main() {
    char c;
    
    int score[3];
    
    int x = 0;
    int index = 0;
    
    while((c=cin.get()) != '\n') {
        if(c=='S' || c=='D' || c=='T') {
            switch (c) {
                case 'S':
                    score[index++] = pow(x,S);
                    x=0;
                    break;
                    
                case 'D':
                    score[index++] = pow(x,D);
                    x=0;
                    break;
                    
                case 'T':
                    score[index++] = pow(x, T);
                    x=0;
                    break;
            }
        }
        
        else if(c>='0' && c<='9') {
            if(x==1) x = 10 +(c-'0');
            else x = c-'0';
        }
        
        else if(c=='*' || c=='#') {
            switch (c) {
                case '*':
                    score[index-1] *= 2;
                    if(index-1 != -1) score[index-2] *= 2;
                    break;
                    
                case '#':
                    score[index-1] *= -1;
            }
        }
    }
    
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;
    cout << score[0]+score[1]+score[2];
}
