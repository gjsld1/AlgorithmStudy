//
//  baekjoon 9322
//  securityAlgorithm.cpp
//  DataStructure
//
//  Created by 신예지 on 04/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int l=0; l<tc; l++) {
        int n;
        cin >> n;
        
        string* str1 = new string[n];
        string* str2 = new string[n];
        string* input = new string[n];
        for(int i=0; i<n; i++) cin >> str1[i];
        for(int i=0; i<n; i++) cin >> str2[i];
        for(int i=0; i<n; i++) cin >> input[i];
        
        pair<int,int>* algo = new pair<int,int>[n];
        for(int i=0; i<n; i++) {
            int j=0;
            while(str1[i]!=str2[j]) j++;
            
            algo[i] = {i,j};
        }
        
        for(int i=0; i<n; i++) cout << input[algo[i].second]<<" ";
        cout << endl;
    }
}
