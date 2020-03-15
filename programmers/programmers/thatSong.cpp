//
//  thatSong.cpp
//  programmers
//
//  Created by 신예지 on 14/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Music {
private:
    string startTime, endTime, songName, code;
    string playCode;
    int playTime;
    int howLong() {
        int startH = atoi(startTime.substr(0,2).c_str());
        int startM = atoi(startTime.substr(3,2).c_str());
        int endH = atoi(endTime.substr(0,2).c_str());
        int endM = atoi(endTime.substr(3,2).c_str());
        
        if(endM < startM) {
            endH--;
            endM += 60;
        }
        int answer = (endM-startM) + (endH-startH)*60;
        return answer;
    }
    void trimCode() {
        for(int i=0; i<code.size(); i++) {
            if(code[i]=='#') {
                code[i-1] = tolower(code[i-1]);
                code.erase(i,1);
                i--;
            }
        }
    }
    void makeCode() {
        playTime = howLong();
        
        int repeat = playTime/code.size();
        int add = playTime%code.size();
        
        playCode = "";
        for(int i=0; i<repeat; i++) playCode += code;
        for(int i=0; i<add; i++) playCode += code[i];
    }
public:
    Music(string s) {
        startTime = s.substr(0,5);
        endTime = s.substr(6,5);
        int idx = s.find(',',12);
        songName = s.substr(12,idx-12);
        code = s.substr(idx+1);
        
        trimCode();
        makeCode();
    }
    int getPlayTime() {
        return playTime;
    }
    string getSongName() {
        return songName;
    }
    string getPlayCode() {
        return playCode;
    }
};

string solution(string m, vector<string> musicinfos) {
    vector<Music> v;
    
    for(int i=0; i<musicinfos.size(); i++) {
        Music m(musicinfos[i]);
        v.push_back(m);
    }
    
    for(int i=0; i<m.size(); i++) {
        if(m[i]=='#') {
            m[i-1] = tolower(m[i-1]);
            m.erase(i,1);
            i--;
        }
    }
    
    int ans = -1;
    for(int i=0; i<v.size(); i++) {
        string code = v[i].getPlayCode();
        if(code.find(m)!=string::npos) {
            if(ans == -1) ans = i;
            else {
                if(v[ans].getPlayTime() < v[i].getPlayTime()) ans = i;
            }
        }
    }
    if(ans == -1) return "(None)";
    return v[ans].getSongName();
}

int main() {
    string m1 = "CC#BCC#BCC#BCC#B";
    vector<string> info;
    info.push_back("03:00,03:30,FOO,CC#B");
    info.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");
    
    cout << solution(m1, info) << endl;
}
