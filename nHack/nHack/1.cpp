//
//  1.cpp
//  Hack
//
//  Created by 신예지 on 12/10/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> grade) {
    int answer = 0;
    
    for(int i=0; i<grade.size()-1; i++) {
        if(grade[i]>grade[i+1]) answer += grade[i]-grade[i+1];
    }
    
    return answer;
}
