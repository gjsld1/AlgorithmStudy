#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    sort(transactions.begin(), transactions.end());

    for(vector<vector<string>>::iterator it=transactions.begin(); it!=transactions.end()-1; it++) {
      if(it[0] == it+1[0]) transactions.erase(it);
      it--;
    }

    for(int i=0; i<transactions.size(); i++) {
      switch (transactions[i][1]) {
        case "SAVE":
        for(int j=0; j<snapshots.size(); j++) {
          if(snapshots[j][0]==transactions[i][2]) {
            int a=atoi(snapshots[j][1].c_str());
            int b=atoi(transactions[i][3].c_str());
            snapshots[j][1] = to_string(a+b);
            break;
          }
        }
        break;

        case "WITHDRAW":
        for(int j=0; j<snapshots.size(); j++) {
          if(snapshots[j][0]==transactions[i][2]) {
            int a=atoi(snapshots[j][1].c_str());
            int b=atoi(transactions[i][3].c_str());
            if(a-b>=0) snapshots[j][1]=to_string(a-b);
            break;
          }
        }
        break;
      }
    }

    vector<vector<string>> answer=snapshots;
    sort(answer.begin(), answer.end());
    return answer;
}
