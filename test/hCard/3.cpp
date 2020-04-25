//
//  3.cpp
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

string solution(vector<string> registered_list, string new_id) {
    
    if(find(registered_list.begin(), registered_list.end(), new_id)==registered_list.end()) return new_id;
    
    int i;
    for(i=0; i<new_id.size(); i++) {
        if(new_id[i]>='0' && new_id[i]<='9') break;
    }
    string S = new_id.substr(0, i);
    int N;
    if(i==new_id.size()-1) N=0;
    else N = atoi(new_id.substr(i).c_str());
    
    string answer = S;
    answer+= to_string(N+1);
    int add=1;
    while(find(registered_list.begin(), registered_list.end(), answer)!=registered_list.end()) {
        answer = S;
        add++;
        answer+=to_string(N+add);
    }
    return answer;
}

int main() {
    vector<string> r;
    r.push_back("bird99");
    r.push_back("bird98");
    r.push_back("bird101");
    r.push_back("banker");
    
    cout << solution(r, "bird98") << endl;
}

