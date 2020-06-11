//
//  developFunction.cpp
//  programmers
//
//  Created by 신예지 on 2020/06/11.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> v;
    for(int i=0; i<progresses.size(); i++) {
        int left=100-progresses[i];
        int days = left/speeds[i];
        if(left%speeds[i]!=0) days++;
        
        v.push_back(days);
    }
    
    int start=v[0];
    int submit=1;
    vector<int> answer;
    for(int i=1; i<v.size(); i++) {
        if(start>v[i]) submit++;
        else {
            answer.push_back(submit);
            start=v[i];
            submit=1;
        }
    }
    answer.push_back(submit);
    return answer;
}

int main() {
    vector<int> progresses, speeds;
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);
    
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    
    vector<int> temp=solution(progresses,speeds);
    cout << temp[0] <<" " << temp[1] << endl;
}
