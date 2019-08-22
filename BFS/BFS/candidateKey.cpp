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
            int temp=0;
            for(int j=0; j<candidate[i].size(); j++) {
                if(front.find(candidate[i][j])!=string::npos) temp++;
            }
            if(temp==candidate[i].size()) {
                flag=1;
                break;
            }
        }
        if(flag==1) continue;
        
        set<string> s;
        for(int i=0; i<rowNum; i++) {
            string temp="";
            
            for(int j=0; j<front.size(); j++) temp += relation[i][front[j]-'0'];
            s.insert(temp);
        }
        
        if(s.size()==rowNum) candidate.push_back(front);
        else {
            for(int i=front[front.size()-1]-'0'+1; i<colNum; i++) {
                string tmp = front;
                tmp += to_string(i);
                q.push(tmp);
            }
        }
    }
    
    for(int i=0; i<candidate.size(); i++) cout << candidate[i] << endl;
    answer = candidate.size();
    return answer;
}

int main() {
    vector<vector<string>> v;
    
    v.push_back({"100","ryan","music","2"});
    v.push_back({"200","apeach","math","2"});
    v.push_back({"300","tube","computer","3"});
    v.push_back({"400","con","computer","1"});
    v.push_back({"500","muzi","music","3"});
    v.push_back({"600","apeach","music","2"});
    
    /*
    v.push_back({"100", "C언어", "80", "민서"});
    v.push_back({"200", "Java", "80", "재중"});
    v.push_back({"100", "Java", "80", "민서"});
    v.push_back({"300", "자료구조", "55", "유천"});
    v.push_back({"400", "파일처리", "95", "준수"});
    v.push_back({"500", "데이터베이스", "60", "창민"});
    v.push_back({"600", "C언어", "75", "윤호"});
    */
    cout << solution(v);
}
