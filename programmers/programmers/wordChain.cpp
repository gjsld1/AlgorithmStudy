//
//  wordChain.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int* count = new int[n]();
    count[0]=1;
    
    set<string> s;
    s.insert(words[0]);
    
    vector<int> answer;
    
    int idx=1;  //2번째 사람부터
    for(int i=1; i<words.size(); i++) {
        string before=words[i-1];
        int size=s.size();
        s.insert(words[i]);
        if(before[before.size()-1]==words[i][0] && size!=s.size()) {
            count[idx]++;
            idx+=1;
            if(idx>=n) idx=0;
        }
        else {
            answer.push_back(idx+1);
            answer.push_back(count[idx]+1);
            break;
        }
    }
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}

int main() {
    vector<string> words;
    words.push_back("tank");
    words.push_back("kick");
    words.push_back("know");
    words.push_back("wheel");
    words.push_back("land");
    words.push_back("dream");
    words.push_back("mother");
    words.push_back("robot");
    words.push_back("tank");
    
    cout << solution(3, words)[0] << solution(3,words)[1] << endl;
}
