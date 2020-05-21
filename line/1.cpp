#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string inputString) {
    vector<char> v;
    int answer = 0;

    for(int i=0; i<inputString.length(); i++) {
        if(inputString[i]=='(' || inputString[i]=='{' || inputString[i]=='<' || inputString[i]=='[') {
            v.push_back(inputString[i]);
        }
        else if(inputString[i]==')' || inputString[i]=='}' || inputString[i]=='>' || inputString[i]==']') {
          switch (inputString[i]) {
            vector<char>::iterator it;
            case ')':
              it = find(v.begin(),v.end(),'(');
              if(it!=v.end()) v.erase(it);
              answer++;
              break;
            case '}':
              it = find(v.begin(),v.end(),'{');
              if(it!=v.end()) v.erase(it);
              answer++;
              break;
            case '>':
              it = find(v.begin(),v.end(),'<');
              if(it!=v.end()) v.erase(it);
              answer++;
              break;
            case ']':
              it = find(v.begin(),v.end(),'[');
              if(it!=v.end()) v.erase(it);
              answer++;
              break;
            return (-1);
          }
        }
    }
    return answer;
}
