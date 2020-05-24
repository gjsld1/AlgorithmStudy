//
//  changeWord.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/24.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algrithm>
using namespace std;

int minCnt;

int howManyDiff(string a, string b) {
    int cnt=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) cnt++;
    }
    return cnt;
}

void dfs(int i, string target, vector<string> words, int cnt, int* visit) {
    if(words[i]==target) {
        minCnt = minCnt>cnt? cnt : minCnt;
        return;
    }
    if(cnt>=minCnt) return;
    
    
    int flag=0;
    for(int k=0; k<words.size(); k++) if(visit[k]!=0) flag++;
    if(flag==words.size()) {
        minCnt=0;
        return;
    }
    
    for(int j=0; j<words.size(); j++) {
        if(i==j) continue;
        if(howManyDiff(words[i], words[j])==1 && visit[j]==0) {
            visit[j]=1;
            dfs(j,target,words,cnt+1,visit);
            visit[j]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    minCnt=words.size();
    
    if(find(words.begin(),words.end(),target)==words.end()) return 0;
    
    for(int i=0; i<words.size(); i++) {
        int* visit = new int[minCnt]();
        if(howManyDiff(begin, words[i])==1) {
            visit[i]=1;
            dfs(i,target,words,1,visit);
        }
    }
    return minCnt;
}

int main() {
    string begin="hit";
    string target="cog";
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");
    
    cout << solution(begin,target,words)<<endl;
}
