//
//  1.cpp
//  hCard
//
//  Created by 신예지 on 2020/04/25.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> purchase) {
    int mDay[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int pDay[366]={0};
    for(int i=0; i<purchase.size(); i++) {
        int month = atoi(purchase[i].substr(5,2).c_str());
        int day = atoi(purchase[i].substr(8,2).c_str());
        
        int totalDay=0;
        for(int i=0; i<month-1; i++) totalDay+=mDay[i];
        totalDay+=day;
        
        int money = atoi(purchase[i].substr(11).c_str());
        
        pDay[totalDay]=money;
    }
    
    
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    answer.push_back(0);
    answer.push_back(0);
    answer.push_back(0);
    for(int i=1; i<=365; i++) {
        int todayMoney=0;
        if(pDay[i]!=0) todayMoney=pDay[i];
        
        for(int j=1; j<30 && i-j>=1; j++) {
            if(pDay[i-j]!=0) todayMoney+=pDay[i-j];
        }
        
        if(todayMoney<10000) answer[0]++;
        else if(todayMoney>=10000 && todayMoney<20000) answer[1]++;
        else if(todayMoney>=20000 && todayMoney<50000) answer[2]++;
        else if(todayMoney>=50000 && todayMoney<100000) answer[3]++;
        else if(todayMoney>=100000) answer[4]++;
    }
    
    return answer;
}

int main() {
    vector<string> purchase;
    purchase.push_back("2019/01/01 5000");
    purchase.push_back("2019/01/20 15000");
    purchase.push_back("2019/02/09 90000");
    
    vector<int> answer=solution(purchase);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
}
