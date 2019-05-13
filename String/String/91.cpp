//
//  91.cpp
//  String
//
//  Created by 신예지 on 04/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Time Limit
int numDecodings(string s) {
    if(s[0] == '0') return 0;
    if(s.length() <= 1) return 1;
    int result;
    result = numDecodings(s.substr(1));
    
    if(s[0]=='1' || (s[0]=='2' && s[1]<='6')) result += numDecodings(s.substr(2));
    return result;
}

int numDecodings(string s) {
    if ( s.size() == 0 ) return 1;
    int* ways = new int[s.size()+1]();
    
    ways[0] = 1; // empty string
    ways[1] = ( s[0] != '0' ? 1 : 0 ); //if the first char is 0 return 0
    if ( ways[1] != 1 ) return 0 ;
    
    for ( int i = 2; i <= s.size(); i++ )
    {
        //First check the single digit
        //01 ... 09 can not be the mapping
        if ( s[i-1] != '0' ) //if previous digit was not 0
        { // 23, 6 (if we are at 6) count is previous count
            /// 236 => there will always be 1 count for 2, 3, 6
            /// 12 => 1, 2 count 1
            // 22226 => 2,2,2,6 count 1
            ways[i] = ways[i-1];
        }
        
        //Calculate for 2 digits
        //eg 2336 : 2,336 / 23,36 / 233,6
        // we will only 23,16 into consideration
        //means if we are at '6' then i-2 & i-1 will give us 23
        //result  =  decodeof(23)  + ( decodeof(16) = (decodeof(1)//i-1 + decodeof(3) //i-2 )
        long val = (s[i-2] -'0') * 10 + (s[i-1] - '0');
        if ( val <= 26 && val >= 10 )
            ways[i] += ways[i-2];
    }
    
    return ways[s.size()];
}
*/
int main() {
    string num = "226";
    cout << numDecodings(num);
}
