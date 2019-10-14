//
//  3.cpp
//  Hack
//
//  Created by 신예지 on 12/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string command, vector<string> buttons, vector<int> scores) {
    int flag=0;
    int answer;
    int max = command.size();
    
    for(int i=0; i<buttons.size(); i++) {
        answer = 0;
        string temp = command;
        
        int start = temp.find(buttons[i]);
        if(start==-1) continue;
        temp = temp.erase(start, buttons[i].size());
        answer+= scores[i];
        answer += solution(temp, buttons, scores);
        
        max = max > answer? max : answer;
    }
    return max;
}

int main() {
    string command = "<v>AB^CYv^XAZ";
    vector<string> buttons;
    buttons.push_back("v>AB^CYv^XA");
    buttons.push_back("<v>A");
    buttons.push_back("^XAZ");
    buttons.push_back("Yv^XA");
    buttons.push_back(">AB^");
    
    vector<int> scores;
    scores.push_back(50);
    scores.push_back(18);
    scores.push_back(20);
    scores.push_back(30);
    scores.push_back(25);
    
    cout << solution(command, buttons, scores) ;
}
