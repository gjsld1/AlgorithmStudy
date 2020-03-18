//
//  traffic.cpp
//  programmers
//
//  Created by 신예지 on 15/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isProcessing(pair<int,int> p, int current) {
    return (current>=p.first && current<=p.second) || (current+999>=p.first && current+999<=p.second);
}

int solution(vector<string> lines) {
    int h, m, s, ms, processTime;
    vector<pair<int,int>> process;
    
    for(int i=0; i<lines.size(); i++) {
        string str="";
        for(int j=11; j<13; j++) str+=lines[i][j];
        h = atoi(str.c_str());
        
        str="";
        for(int j=14; j<16; j++) str+=lines[i][j];
        m = atoi(str.c_str());
        
        str="";
        for(int j=17; j<19; j++) str+=lines[i][j];
        s = atoi(str.c_str());
        
        str="";
        for(int j=20; j<23; j++) str+=lines[i][j];
        ms = atof(str.c_str());
        
        str="";
        for(int j=24; lines[i][j]!='s'; j++) str+=lines[i][j];
        processTime = atof(str.c_str())*1000;
        
        int endTime = h*3600*1000 + m*60*1000 + s*1000 + ms;
        int startTime = endTime - processTime + 1;

        process.push_back({startTime,endTime});
    }
    
    int answer=0;
    
    for(int i=0; i<process.size(); i++) {
        int temp=1;
        for(int j=0; j<process.size(); j++) {
            if(i==j) continue;
            if(isProcessing(process[j], process[i].first)) temp++;
        }
        answer = answer>temp ? answer : temp;
        
        temp=1;
        for(int j=0; j<process.size(); j++) {
            if(i==j) continue;
            if(isProcessing(process[j], process[i].second)) temp++;
        }
        answer = answer>temp ? answer : temp;
    }
    
    return answer;
}

int main() {
    vector<string> lines;
    /*
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");
    */
    /*
    lines.push_back("2016-09-15 01:00:04.002 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    */
    lines.push_back("2016-09-15 01:00:04.001 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    
    cout << solution(lines) << endl;
}
