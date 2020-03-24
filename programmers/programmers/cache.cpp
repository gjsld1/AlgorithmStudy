//
//  cache.cpp
//  programmers
//
//  Created by 신예지 on 24/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0) return 5*cities.size();
    
    vector<string> cache;
    int answer = 0;
    
    for(int i=0; i<cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        vector<string>::iterator it = find(cache.begin(), cache.end(), cities[i]);
        if(it!=cache.end()) answer+=1;
        else {
            it = cache.begin();
            answer += 5;
        }

        if(cache.size()==cacheSize) cache.erase(it);
        cache.push_back(cities[i]);
    }
    
    return answer;
}

int main() {
    int cacheSize =3;
    vector<string> cities;
    cities.push_back("Jeju");
    cities.push_back("Pangyo");
    cities.push_back("Seoul");
    cities.push_back("NewYork");
    cities.push_back("LA");
    cities.push_back("Jeju");
    cities.push_back("Pangyo");
    cities.push_back("Seoul");
    cities.push_back("NewYork");
    cities.push_back("LA");
    cout << solution(cacheSize, cities) << endl;
}
