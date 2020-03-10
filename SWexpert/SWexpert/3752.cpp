//
//  3752.cpp
//  SWexpert
//
//  Created by 신예지 on 06/03/2020.
//  Copyright © 2020 신예지. All rights reserved.
//

#include <iostream>
using namespace std;
 
int main(){
    int tc;
    scanf("%d",&tc);
    int c=1;
    
    while(tc--){
        int d[10001] = {0,};
        int arr[101] = {0,};
        
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        
        d[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=10000;j>=0;j--){
                if(d[j]) d[j+arr[i]]=1;
            }
        }
 
        int ans=0;
        for(int i=0;i<=10000;i++) if(d[i]) ans++;
        printf("#%d %d\n",c++,ans);
    }
}
