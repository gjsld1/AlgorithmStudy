//
//  kakao2018 3rd
//  filenameSort.cpp
//  String
//
//  Created by 신예지 on 13/07/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class file {
    string original;
    string head;
    int number;
    string tail;
    
    void disjoint(string input) {
        for(int i=0; i<input.length(); i++) {
            if(input[i]>=65 && input[i]<=90) input[i]=tolower(input[i]);
        }
        
        int idxS = 0;
        while(!(input[idxS]>='0'&&input[idxS]<='9')) idxS++;
        int idxE = idxS;
        while(input[idxE]>='0' && input[idxE]<='9') idxE++;
        
        head = input.substr(0, idxS);
        string numTemp = input.substr(idxS, idxE-idxS);
        number = atoi(numTemp.c_str());
        tail = input.substr(idxE);
    }
public:
    file(string input) {
        original = input;
        disjoint(input);
    }
    
    pair<string, int> getPair() {
        return {head, number};
    }
    
    string getName() {
        return original;
    }
};

vector<string> sortName(vector<file> fn) {
    vector<pair<pair<string,int>,string>> sorted;
    
    for(int i=0; i<fn.size(); i++) sorted.push_back({fn[i].getPair(), fn[i].getName()});
    sort(sorted.begin(), sorted.end());
    
    vector<string> ans;
    for(int i=0; i<sorted.size(); i++) ans.push_back(sorted[i].second);
    return ans;
}
int main() {
    file f1("img12.png");
    file f2("img10.png");
    file f3("img02.png");
    file f4("img1.png");
    file f5("IMG01.GIF");
    file f6("img2.JPG");
    
    vector<file> fileNames = {f1,f2,f3,f4,f5,f6};
    vector<string> ans = sortName(fileNames);
    
    for(int i=0; i<ans.size(); i++) cout << ans[i] <<" ";
}
