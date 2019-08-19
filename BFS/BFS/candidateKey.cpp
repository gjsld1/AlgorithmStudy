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
    int* candidate = new int[colNum]();
    
    for(int i=0; i<colNum; i++) {
        set<string> s;
        for(int j=0; j<rowNum; j++) {
            s.insert(relation[j][i]);
        }
        if(s.size()==rowNum) {
            candidate[i]=1;
            answer++;
        }
    }
    
    
    
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
