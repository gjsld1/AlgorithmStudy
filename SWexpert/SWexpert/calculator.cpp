//
//  SWEpxertAcademy 8338
//  main.cpp
//  SWepxert
//
//  Created by 신예지 on 11/09/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tc;
    scanf("%d",&tc);
    
    for(int i=0; i<tc; i++) {
        int n;
        scanf("%d", &n);
        int* num = (int*) malloc(sizeof(int)*n);
        
        int sum;
        scanf("%d", &sum);
        num[0]=sum;
        
        for(int j=1; j<n; j++) {
            scanf("%d", &num[j]);
            
            if(sum==0 || num[j]==0) continue;
            else if(sum==1 || num[j]==1) sum+=num[j];
            else sum*=num[j];
        }
        
        printf("#%d %d",i+1,sum);
    }
}
