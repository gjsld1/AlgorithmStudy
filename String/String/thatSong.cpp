//
//  kakao2018 3rd
//  thatSong.cpp
//  String
//
//  Created by 신예지 on 10/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string manageSharp(string str) {
    for(int i=1; i<str.length(); i++) {
        if(str[i]=='#') {
            str[i-1] = tolower(str[i-1]);
            str.erase(i);
            i--;
        }
    }
    return str;
}

class Music {
    string start;
    string end;
    string name;
    string code;
    
    int playTime;
    string playCode;
    
    void disjoint(string s) {
        start = s.substr(0,5);
        end = s.substr(6,5);
        
        int delimiter = s.find(',',12);
        name = s.substr(12,delimiter-12);
        code = s.substr(delimiter+1);
    }
    
    void calculateTime() {
        int sHour = atoi(start.substr(0,2).c_str());
        int sMin = atoi(start.substr(3,2).c_str());
        int eHour = atoi(end.substr(0,2).c_str());
        int eMin = atoi(end.substr(3,2).c_str());
        
        if(sMin<eMin) {
            sHour -= 1;
            sMin += 60;
        }
        
        playTime = (eHour-sHour)*60 + eMin-sMin;
    }
    
    void findPlayCode() {
        playCode = "";
        for(int i=0; i<playTime/code.length(); i++) playCode += code;
        playCode += code.substr(0, playTime%code.length());
    }
    
public:
    Music(string s) {
        disjoint(s);
        calculateTime();
        findPlayCode();
        
        playCode = manageSharp(playCode);
    }
    
    string getName() {
        return name;
    }
    
    string getPlayCode() {
        return playCode;
    }
};

int main() {
    string m = "ABC";
    Music m1("12:00,12:14,HELLO,C#DEFGAB");
    Music m2("13:00,13:05,WORLD,ABCDEF");
    
    vector<Music> Musicinfos = {m1, m2};
    
    m = manageSharp(m);
    
    string ans = "";
    for(int i=0; i<Musicinfos.size(); i++) {
        if(Musicinfos[i].getPlayCode().find(m) != string::npos) {
            if(ans.length()<Musicinfos[i].getName().length()) ans=Musicinfos[i].getName();
        }
    }
    if(ans=="") ans = "(None)";
    cout << ans;
}
