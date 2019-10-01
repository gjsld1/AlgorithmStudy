//
//  insectCard.cpp
//  NHN
//
//  Created by 신예지 on 29/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string ans = "Y";
    
    map<string, int> m;
    string temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(m.find(temp)==m.end()) m.insert({temp,1});
        else m[temp]++;
    }
    
    if((n+1)%m.size() != 0) ans="N";
    else {
        map<string,int>::iterator it = m.begin();
        int standard = it->second;
        int flag=0, need=0;
        
        for(it++; it!=m.end(); it++){
            if(flag==1 && standard != it->second) {
                ans="N";
                break;
            }
            if(standard != it->second) {
                need++;
                if(abs(it->second-standard)!=1 || need>=2) {
                    ans="N";
                    break;
                }
                flag=1;
            }
        }
    }
    
    if(ans=="Y") cout << ans << endl << n+1 << endl << m.size();
    else cout << ans << endl << n << endl << m.size();
}
