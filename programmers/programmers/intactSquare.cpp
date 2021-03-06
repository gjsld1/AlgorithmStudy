//
//  intactSquare.cpp
//  programmers
//
//  Created by 신예지 on 2020/06/11.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

using namespace std;

long long solution(int w,int h) {
    float incline = float(-h)/(float)w;
    long long answer=0;
    for(int i=0; i<w; i++) {
        answer+= (long long)h*i / (long long)w;
        //answer+= (long long)(incline*i+(float)h);
    }
    return answer*2;
}

int main() {
    cout << solution(8,12) << endl;
}
