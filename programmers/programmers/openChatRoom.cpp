//
//  openChatRoom.cpp
//  programmers
//
//  Created by 신예지 on 2020/04/23.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    map<string,string> m;
    
    for(int i=0; i<record.size(); i++) {
        if(record[i][0]=='E') {
            string id="", name="";
            int j=6;
            while(record[i][j]!=' ') id+=record[i][j++];
            name=record[i].substr(j+1);
            
            if(m.find(id)!=m.end()) m[id]=name;
            else m.insert({id,name});
        }
        else if(record[i][0]=='C') {
            string id="", name="";
            int j=7;
            while(record[i][j]!=' ') id+=record[i][j++];
            name=record[i].substr(j+1);
            
            m[id]=name;
        }
    }
    
    vector<string> answer;
    for(int i=0; i<record.size(); i++) {
        if(record[i][0]=='E') {
            string id="";
            int j=6;
            while(record[i][j]!=' ') id+=record[i][j++];
            
            answer.push_back(m[id]+"님이 들어왔습니다.");
        }
        else if(record[i][0]=='L') {
            string id=record[i].substr(6);
            
            answer.push_back(m[id] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}

int main() {
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    
    vector<string> answer = solution(record);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
}
