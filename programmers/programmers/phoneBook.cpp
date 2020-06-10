//
//  phoneBook.cpp
//  programmers
//
//  Created by 신예지 on 2020/06/10.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer=true;
    
    for(int i=0; i<phone_book.size(); i++) {
        for(int j=0; j<phone_book.size(); j++) {
            if(i==j) continue;
            if(phone_book[i].size()>phone_book[j].size()) continue;
            string temp=phone_book[j].substr(0,phone_book[i].size());
            if(phone_book[i]==temp) return false;
        }
    }
    return answer;
}

int main() {
    vector<string> phone_book;
    phone_book.push_back("119");
    phone_book.push_back("97674223");
    phone_book.push_back("1195524421");
    
    cout << solution(phone_book);
}
