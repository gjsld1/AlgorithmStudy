//
//  skillTree.cpp
//  programmers
//
//  Created by 신예지 on 2020/06/11.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer=0;
    map<char,int> m;
    
    for(int i=0; i<skill.size(); i++) {
        m[skill[i]]=i+1;
    }
    
    for(int i=0; i<skill_trees.size(); i++) {
        int flag=1, level=1;
        for(int j=0; j<skill_trees[i].size(); j++) {
            if(skill.find(skill_trees[i][j])!=string::npos) {
                if(m[skill_trees[i][j]]!=level) {
                    flag=0;
                    break;
                }
                else level++;
            }
        }
        if(flag==1) answer++;
    }
    return answer;
}

int main() {
    string skill="CBD";
    vector<string> skill_trees;
    skill_trees.push_back("BACDE");
    skill_trees.push_back("CBADF");
    skill_trees.push_back("AECB");
    skill_trees.push_back("BDA");
    
    cout << solution(skill,skill_trees) << endl;
}
