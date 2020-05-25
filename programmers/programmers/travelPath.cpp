//
//  travelPath.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/25.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> answer;
int ticketNum;

void dfs(vector<vector<string>> tickets, int idx, int* used, vector<string> possible) {
    int* temp = new int[ticketNum];
    for(int j=0; j<ticketNum; j++) temp[j]=used[j];
    
    if(temp[idx]) return;
    temp[idx]=1;
    possible.push_back(tickets[idx][1]);
    if(possible.size()==ticketNum+1) {
        answer.push_back(possible);
        return;
    }

    for(int i=0; i<ticketNum; i++) {
        if(tickets[idx][1]==tickets[i][0]) {
            dfs(tickets,i,temp,possible);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketNum=tickets.size();
    for(int i=0; i<ticketNum; i++) {
        int* used = new int[ticketNum]();
        vector<string> possible;
        
        if(tickets[i][0]=="ICN") {
            possible.push_back(tickets[i][0]);
            dfs(tickets,i,used,possible);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer[0];
}

int main() {
    vector<vector<string>> tickets;
    //tickets.push_back({"ICN","JFK"});
    //tickets.push_back({"HND","IAD"});
    //tickets.push_back({"JFK","HND"});
    tickets.push_back({"ICN","SFO"});
    tickets.push_back({"ICN","ATL"});
    tickets.push_back({"SFO","ATL"});
    tickets.push_back({"ATL","ICN"});
    tickets.push_back({"ATL","SFO"});
    
    vector<string> answer =solution(tickets);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << " ";
    cout << endl;
}
