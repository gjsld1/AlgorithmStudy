//
//  4.cpp
//  kakaoIntern
//
//  Created by 신예지 on 09/11/2019.
//  Copyright © 2019 신예지. All rights reserved.
//
#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    map<long long, long long> m;
    long long* charged = new long long[k]();
    for(long long i=0; i<room_number.size(); i++) {
        long long temp = room_number[i];
        if(charged[temp]==0) {
            
            long long t = temp+1;
            if(m[t]==0) m[temp]=t;
            else {
                while(m[t]!=0) t=m[t];
                m[temp]=m[t];
            }
            
            charged[temp]=1;
            answer.push_back(temp);
        }
        else {
            while(charged[m[temp]]==1) {
                temp = m[temp];
            }
            m[m[temp]] = m[temp]+1;
            charged[m[temp]]=1;
            answer.push_back(m[temp]);
            m[temp]=m[m[temp]];
        }
    }
    
    return answer;
}

int main() {
    vector<long long> room_number;
    room_number.push_back(1);
    room_number.push_back(3);
    room_number.push_back(4);
    room_number.push_back(1);
    room_number.push_back(3);
    room_number.push_back(1);
    
    vector<long long> answer = solution(10, room_number);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
}

