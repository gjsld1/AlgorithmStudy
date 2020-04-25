//
//  2.cpp
//  hCard
//
//  Created by 신예지 on 2020/04/25.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <set>
using namespace std;

bool isSame(string s1, string s2) {
    if(s1==s2) return true;
    else if(s1[0]=='C' && s2[0]=='C') return true;
    
    return false;
}

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int answer =0;
    set<string> s;
    int* visit=new int[ip_addrs.size()]();
    for(int i=0; i<ip_addrs.size(); i++) {
        if(visit[i]) continue;;
        visit[i]=1;
        
        if(s.find(ip_addrs[i])==s.end()) s.insert(ip_addrs[i]);
        else {
            vector<int> idx;
            for(int j=0; j<ip_addrs.size(); j++) {
                if(ip_addrs[i]==ip_addrs[j]) idx.push_back(j);
            }
            for(int j=0; j<idx.size(); j++) visit[idx[j]]=1;
            if(idx.size()>=4) answer+=4;
            else if(idx.size()==3) {
                if(isSame(langs[idx[0]], langs[idx[1]]) && isSame(langs[idx[1]], langs[idx[2]])) answer+=3;
            }
            else if(idx.size()==2) {
                if(isSame(langs[idx[0]], langs[idx[1]]) && scores[idx[0]]==scores[idx[1]]) answer+=2;
            }
        }
    }
    
    return ip_addrs.size()-answer;
}

int main() {
    vector<string> ip_addrs;
    vector<string> langs;
    vector<int> scores;
    
    ip_addrs.push_back("5.5.5.5");
    ip_addrs.push_back("155.123.124.111");
    ip_addrs.push_back("10.16.125.0");
    ip_addrs.push_back("155.123.124.111");
    ip_addrs.push_back("5.5.5.5");
    ip_addrs.push_back("155.123.124.111");
    ip_addrs.push_back("10.16.125.0");
    ip_addrs.push_back("10.16.125.0");
    
    langs.push_back("Java");
    langs.push_back("C++");
    langs.push_back("Python3");
    langs.push_back("C#");
    langs.push_back("Java");
    langs.push_back("C");
    langs.push_back("Python3");
    langs.push_back("JavaScript");
    
    scores.push_back(294);
    scores.push_back(197);
    scores.push_back(373);
    scores.push_back(45);
    scores.push_back(294);
    scores.push_back(62);
    scores.push_back(373);
    scores.push_back(373);

    
    cout << solution(ip_addrs, langs, scores) << endl;
}
