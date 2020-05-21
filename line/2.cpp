#include <string>
#include <vector>

using namespace std;

int calculate(vector<int> v1, vector<int> v2) {
    int a=0;
    int b=0,temp=0;
    for(int i=0; i<v1.size(); i++) {
      if(v1[i]!=0 && v2[i]!=0) {
        a++;
        if(v1[i]==v2[i]) temp++;
        else {
          b = temp>b ? temp : b;
          temp=0;
        }
      }
    }

    return a+b*b;
}

int solution(string answer_sheet, vector<string> sheets) {
    vector<vector<int>> v;

    for(int i=0; i<sheets.size(); i++) {
      vector<int> temp;
      for(int j=0; j<answer_sheet.size(); j++) {
          if(answer_sheet[i]==sheets[j][i]) temp.push_back(0);
          else temp.push_back(sheets[j][i]-'0');
      }
      v.push_back(temp);
    }

    int answer = -1;
    for(int i=0; i<sheets.size(); i++) {
      for(int j=i+1; j<sheets.size(); j++) {
        int temp = calculate(v[i],v[j]);
        answer = temp>answer ? temp : answer;
      }
    }
    return answer;
}
