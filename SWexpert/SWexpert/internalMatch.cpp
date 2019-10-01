//
//  SWExpertAcademy 7988 D4
//  internalMatch.cpp
//  SWexpert
//
//  Created by 신예지 on 18/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int l=0; l<tc; l++) {
        int k;
        cin >> k;
        
        queue<pair<string,string>> re;
        vector<string> A, B;
        set<string> participant;
        string a,b;
        string ans = "Yes";
        
        for(int i=0; i<k; i++) {
            cin >> a >> b;
            
            if(i==0) {
                A.push_back(a);
                B.push_back(b);
                continue;
            }
            
            if(find(participant.begin(), participant.end(), a)!=participant.end()) {
                //a 있는데 b 없는경우
                if(find(participant.begin(), participant.end(), b)==participant.end()) {
                    if(find(A.begin(), A.end(), a)!=A.end()) {
                        B.push_back(b);
                    }
                    else {
                        A.push_back(b);
                    }
                }
                //a 있는데 b 있는 경우
                else {
                    if(find(A.begin(), A.end(), a)!=A.end()) {
                        if(find(A.begin(), A.end(), b)!=A.end()) {
                            ans="No";
                            break;
                        }
                    }
                    else {
                        if(find(B.begin(), B.end(), b)!=B.end()) {
                            ans="No";
                            break;
                        }
                    }
                }
            }
            
            else {
                //a가 없는데 b가 있어
                if(find(participant.begin(), participant.end(), b)!=participant.end()) {
                    if(find(A.begin(), A.end(), b)!=A.end()) {
                        B.push_back(a);
                    }
                    else {
                        A.push_back(a);
                    }
                }
                //a도 없고 b도 없어 -> 2가지 경우
                else {
                    re.push({a,b});
                    continue;
                }
            }
            
            participant.insert(a);
            participant.insert(b);
        }
        
        while(!re.empty()) {
            string tmp1 = re.front().first;
            string tmp2 = re.front().second;
            re.pop();
            
            if(find(participant.begin(), participant.end(), a)!=participant.end()) {
                //a 있는데 b 없는경우
                if(find(participant.begin(), participant.end(), b)==participant.end()) {
                    if(find(A.begin(), A.end(), a)!=A.end()) {
                        B.push_back(b);
                    }
                    else {
                        A.push_back(b);
                    }
                }
                //a 있는데 b 있는 경우
                else {
                    if(find(A.begin(), A.end(), a)!=A.end()) {
                        if(find(A.begin(), A.end(), b)!=A.end()) {
                            ans="No";
                            break;
                        }
                    }
                    else {
                        if(find(B.begin(), B.end(), b)!=B.end()) {
                            ans="No";
                            break;
                        }
                    }
                }
            }
            
            else {
                //a가 없는데 b가 있어
                if(find(participant.begin(), participant.end(), b)!=participant.end()) {
                    if(find(A.begin(), A.end(), b)!=A.end()) {
                        B.push_back(a);
                    }
                    else {
                        A.push_back(a);
                    }
                }
                //a도 없고 b도 없어 -> 2가지 경우
                else {
                    A.push_back(a);
                    B.push_back(b);
                }
            }
        }
        cout << "#" << l+1 << " " << ans << endl;
    }
}