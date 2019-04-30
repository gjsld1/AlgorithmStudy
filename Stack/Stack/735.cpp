//
//  735.cpp
//  Stack
//
//  Created by 신예지 on 28/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    
    for(int i=0; i<asteroids.size(); i++) {
        if(asteroids[i]>0) s.push(asteroids[i]);
        else {
            if(!s.empty()) {
                if(s.top()*asteroids[i]<0) {
                    int sTop = s.top();
                    int flag=0;
                    while(sTop*asteroids[i]<0) {
                        int temp = -asteroids[i];
                        if(sTop==temp) s.pop();
                        else if(sTop<temp) {
                            s.pop();
                            sTop = s.top();
                            flag=1;
                        }
                        if(flag==0) break;
                        if(flag!=0 && sTop>temp) {
                            flag=0;
                            break;
                        }
                    } if(flag==1) s.push(asteroids[i]);
                }
                else s.push(asteroids[i]);
            }
            else s.push(asteroids[i]);
        }
    }
    
    vector<int> temp;
    vector<int> survive;
    int size = s.size();
    
    for(int i=0; i<size; i++) {
        temp.push_back(s.top());
        s.pop();
    }
    for(int i=temp.size()-1; i>=0; i--) {
        survive.push_back(temp[i]);
    }
    
    return survive;
}

int main() {
    int num;
    vector<int> vec;
    
    for(int i=0; i<4; i++) {
        cin >> num;
        vec.push_back(num);
    }
    
    vector<int> survive;
    survive=asteroidCollision(vec);
    for(int i=0; i<survive.size(); i++) {
        cout << survive[i] << " ";
    }
    cout<<endl;
}
