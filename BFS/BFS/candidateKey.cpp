//
//  kakao 2019 1st
//  candidateKey.cpp
//  BFS
//
//  Created by 신예지 on 19/08/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Relation{
    vector<vector<string>> tuples;
public:
    void insert(vector<string> tuple) {
        tuples.push_back(tuple);
    }
};

int solution(vector<vector<string>> relation) {
    int answer=0;
    
    int colNum = relation[0].size();
    int rowNum = relation.size();
    
    queue<string> q;
    vector<string> candidate;
    for(int i=0; i<colNum; i++) q.push(to_string(i));
    
    while(!q.empty()) {
        string front=q.front();
        q.pop();
        
        int flag=0;
        for(int i=0; i<candidate.size(); i++) {
            if(candidate[i].find(front)==string::npos) flag=1;
        }
        if(flag==1) continue;
        
        string temp="";
        for(int i=0; i<front.length(); i++) {
            set<string> s;
            
            for(int j=0; j<rowNum; j++) {
                temp += relation[j][i];
                s.insert(temp);
            }
            if(s.size()==rowNum) {
                candidate.push_back(temp);
            }
        }
        
        for(int i=front[front.size()-1]-'0'+1; i<colNum; i++) {
            temp += to_string(i);
        }
        q.push(temp);
    }
    answer = candidate.size();
    return answer;
}

int main() {
    Relation relation;
    relation.insert({"100","ryan","music","2"});
    relation.insert({"200","apeach","math","2"});
    relation.insert({"300","tube","computer","3"});
    relation.insert({"400","con","computer","1"});
    relation.insert({"500","muzi","music","3"});
    relation.insert({"600","ryan","music","2"});
    
    
}
