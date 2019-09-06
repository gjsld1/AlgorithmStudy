//
//  programmers
//  noncompleteAthlete.cpp
//  Hash
//
//  Created by 신예지 on 06/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0; i<completion.size(); i++) {
        if(binary_search(participant.begin(), participant.end(), completion[i])) {
            participant.erase(find(participant.begin(), participant.end(), completion[i]));
        }
    }
    answer = participant[0];
    return answer;
}

int main() {
    vector<string> participant;
    vector<string> completion;
    
    participant.push_back("marina");
    participant.push_back("josipa");
    participant.push_back("nikola");
    participant.push_back("vinko");
    participant.push_back("filipa");
    
    completion.push_back("josipa");
    completion.push_back("filipa");
    completion.push_back("marina");
    completion.push_back("nikola");
    
    cout << solution(participant, completion);
}
