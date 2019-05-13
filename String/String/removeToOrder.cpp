//
//  removeToOrder.cpp
//  String
//
//  Created by 신예지 on 06/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(string S) {
    vector<pair<char,int>> alpha;
    
    for(int i=0; i<S.length(); i++) alpha.push_back(pair<char,int>(S[i], i));
    sort(alpha.begin(), alpha.end());
    int length = alpha.size();
    
    vector<int> sortOrder;
    for(int i=0; i<alpha.size(); i++) sortOrder.push_back(alpha[i].second);
    
    vector<int>::iterator it=sortOrder.begin()+1;
    while(it != sortOrder.end()-1) {
        int before = *it-*(it-1);
        int after = *(it+1)-*it;
        
        if(before>length/2) {
            sortOrder.erase(it);
            continue;
        }
        
        if(before*after < 0) {
            if(before<0) sortOrder.erase(it-1);
            else sortOrder.erase(it+1);
        }
        else {
            if(before<0) sortOrder.erase(it-1);
            else {
                if(abs(before)==abs(after) || after == 1) it++;
                else if(abs(before)>abs(after)) sortOrder.erase(it-1);
                else sortOrder.erase(it+1);
            }
        }
    }
    
    return length-sortOrder.size();
}

int main() {
    string str = "awesome";
    cout << solution(str);
}
