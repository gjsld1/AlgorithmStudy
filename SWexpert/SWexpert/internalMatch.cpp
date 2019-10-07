//
//  SWExpertAcademy 7988 D4
//  internalMatch.cpp
//  SWexpert
//
//  Created by 신예지 on 18/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

/*
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
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

map<string, set<string>> m;
map<string, int> s;

bool dfs(string e, string par, int ch) {
    s[e]=ch;
    
    for(auto a : m[e]) {
        if(a==par) continue;
        //한 번도 가지 않은 정점일 경우
        if(!s[a]) {
            //이전 정점이 1일 경우
            if(ch==1) {
                //현재 정점은 2여야만 함
                if(!dfs(a,e,2)) return false;
            }
            else {
                //그 반대
                if(!dfs(a,e,1)) return false;
            }
        }
        //만약 다른 정점이 이미 순회되어 있다면
        else {
            if(ch==s[a]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, c=1;
    cin >> t;
    string root;
    while(t--) {
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;
            if(m.empty()) root=a;
            m[a].insert(b);
            m[b].insert(a);
        }
        
        bool a = dfs(root,"",1);
        s.clear();
        bool b = dfs(root,"",2);
        s.clear();
        cout << "#" << c++ << " ";
        if(a||b) cout << "Yes" << endl; //둘 중에 하나라도 만족하면 yes
        else cout << "No" << endl;  //no
        m.clear();
    }
}
