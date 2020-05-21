#include <string>
#include <vector>

using namespace std;

int maxLength=0;
void dfs(string s, vector<int> v, int idx, int cnt, int n) {
  if(cnt==n) {
    int temp=0;

    for(int i=0; i<s.size(); i++) {
      if(s[i]=='1') temp++;
      else {
        maxLength = temp>maxLength ? temp : maxLength;
        temp=0;
      }
    }
  };

  string temp=s;
  dfs(temp,v,idx+1,cnt,n);
  temp[v[idx]]=='1';
  dfs(temp,v,idx+1, cnt+1,n);
}

int solution(string road, int n) {
  vector<int> v;
  for(int i=0; i<road.size(); i++) {
    if(road[i]=='0') v.push_back(i);
  }

  dfs(road, v, 0, 0, n);

    return maxLength;
}
