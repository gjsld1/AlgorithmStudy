//
//  bestAlbum.cpp
//  programmers
//
//  Created by 신예지 on 2020/05/27.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string,int> m;
    for(int i=0; i<genres.size();  i++) {
        m[genres[i]] += plays[i];
    }
    vector<pair<int,string>> v;
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); ++it) {
        v.push_back({it->second,it->first});
    }
    sort(v.begin(), v.end(), greater<pair<int,string>>());
    
    vector<int> answer;
    for(int i=0; i<v.size(); i++) {
        vector<pair<int,int>> temp;
        for(int j=0; j<genres.size(); j++) {
            if(v[i].second==genres[j]) temp.push_back({plays[j],j});
        }
        if(temp.size()==1) answer.push_back(temp[0].second);
        else {
            sort(temp.begin(), temp.end());
            if(temp[temp.size()-1].first==temp[temp.size()-2].first) {
                answer.push_back(temp[temp.size()-2].second);
                answer.push_back(temp[temp.size()-1].second);
            }
            else {
                answer.push_back(temp[temp.size()-1].second);
                answer.push_back(temp[temp.size()-2].second);
            }
        }
    }
    return answer;
}

int main() {
    vector<string> genres;
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");
    vector<int> plays;
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);
    
    cout << solution(genres, plays)[0]<<solution(genres, plays)[1]<<solution(genres, plays)[2]<<solution(genres, plays)[3] << endl;
}
