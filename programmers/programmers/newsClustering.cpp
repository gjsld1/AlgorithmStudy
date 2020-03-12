//
//  newsClustering.cpp
//  programmers
//
//  Created by 신예지 on 12/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isChar(char c) {
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

float jacard(vector<string> v1, vector<string> v2) {
    float intersection=0;
    float unionSet=0;
    
    for(int i=0; i<v1.size(); i++) {
        vector<string>::iterator it = find(v2.begin(), v2.end(), v1[i]);
        if(it != v2.end())  {
            intersection++;
            unionSet++;
            v2.erase(it);
        }
        else {
            unionSet++;
        }
    }
    unionSet += v2.size();
    
    return intersection/unionSet;
}

int solution(string str1, string str2) {
    vector<string> v1, v2;
    
    for(int i=0; i<str1.length()-1; i++) {
        string s = str1.substr(i,2);
        if(!isChar(s[0]) || !isChar(s[1])) continue;
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);
        
        v1.push_back(s);
    }
    for(int i=0; i<str2.length()-1; i++) {
        string s = str2.substr(i,2);
        if(!isChar(s[0]) || !isChar(s[1])) continue;
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);
        
        v2.push_back(s);
    }
    
    return jacard(v1,v2)*65536;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    cout << solution(str1,str2) << endl;
}
