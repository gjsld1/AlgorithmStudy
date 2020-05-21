#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<pair<int,string>> v;
    for(int i=0; i<dataSource.size(); i++) {
      int cnt=0;
      for(int j=0; j<tags.size(); j++) {
        if(find(dataSource[i].begin(), dataSource[i].end(), tags[j])!=dataSource[i].end()) cnt++;
      }
      v.push_back({cnt,dataSource[i][0]});
    }
    sort(v.begin(),v.end());

    vector<string> answer;
    int idx=v.size()-1;
    for(int i=0; i<10; i++) {
      answer.push_back(v[idx].second);
      idx--;
    }
    return answer;
}
