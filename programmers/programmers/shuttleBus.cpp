//
//  shuttleBus.cpp
//  programmers
//
//  Created by 신예지 on 2020/04/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> nextTime(pair<int,int> busTime, int t) {
    busTime.second+=t;
    if(busTime.second>=60) {
        busTime.second-=60;
        busTime.first+=1;
    }
    return busTime;
}

bool isInLine(pair<int,int> line, pair<int,int> bus) {
    if(line.first*60+line.second <= bus.first*60+bus.second) return true;
    return false;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<pair<int,int>> time;
    for(int i=0; i<timetable.size(); i++) {
        int h = atoi(timetable[i].substr(0,2).c_str());
        int m = atoi(timetable[i].substr(3,2).c_str());
        time.push_back({h,m});
    }
    sort(time.begin(), time.end());
    
    string answer = "";
    
    pair<int,int> busTime = {9,0};
    for(int i=0; i<n-1; i++) {
        int getBus=0;
        while(getBus!=m && isInLine(time[0], busTime)) {
            getBus++;
            time.erase(time.begin());
        }
        busTime = nextTime(busTime, t);
    }   //마지막 버스 전까지
    
    
    if(time.size()!=0 && isInLine(time[0], busTime)) {
        int getBus=0;
        while(getBus!=m-1) {
            if(isInLine(time[0], busTime)) {
                getBus++;
                time.erase(time.begin());
            }
        }
        if(time.size()!=0) {
            busTime = {time[0].first,time[0].second-1};
            if(busTime.second<0) {
                busTime.second = 60+busTime.second;
                busTime.first-=1;
            }
        }
    }
    
    if(busTime.first<10) answer+='0';
    answer+=to_string(busTime.first)+':';
    if(busTime.second<10) answer+='0';
    answer+=to_string(busTime.second);
    return answer;
}

int main() {
    vector<string> timetable;
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    
    cout << solution(10, 60, 45, timetable) << endl;
}
