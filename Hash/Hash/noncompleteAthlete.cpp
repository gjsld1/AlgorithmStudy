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
    for(int i=0; i<participant.size(); i++) {
        if(!binary_search(completion.begin(), completion.end(), participant[i])) {
            answer=participant[i];
            break;
        }
    }
    
    return answer;
}

int main() {
    vector<string> participant;
    vector<string> completion;
    
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");
    
    completion.push_back("eden");
    completion.push_back("kiki");
    
    cout << solution(participant, completion);
}
