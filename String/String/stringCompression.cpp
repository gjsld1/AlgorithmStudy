//
//  stringCompression.cpp
//  Kakao
//
//  Created by 신예지 on 07/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i=1; i<=s.length(); i++) {
        int idx=0;
        int count=1;
        string compression = "";
        
        for(int idx=0; idx+i<s.length(); idx++) {
            while(idx+i < s.length()) {
                string a = s.substr(idx,i);
                string b = s.substr(idx+i,i);
                
                if(a==b) count++;
                else {
                    if(count!=1) compression += to_string(count);
                    compression += a;
                    count = 1;
                }
                idx += i;
            }
            if(count!=1) compression += to_string(count);
            compression += s.substr(idx,i);
            if(answer> compression.length()) answer=compression.length();
        }
    }
    return answer;
}

int main() {
    cout << solution("aabbaccc");
}
