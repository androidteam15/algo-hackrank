//
//  ites.h
//  JH
//
//  Created by lgh on 14. 8. 12..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#ifndef JH_ites_h
#define JH_ites_h

void ites(int sum, int signal){
    
    unsigned int i;
    int result, start, end;
    unsigned int _sum;
    unsigned int signalArr[signal+1];
    unsigned int A[signal+1];
    unsigned int pSum[signal+1];
    
    result = 0;
    start = 0;
    end = 1;
    
    printf("%p",A);
    A[0] = 1983;
    for( i=1; i<=signal; i++){
        A[i] = A[i-1]*214013 + 2531011;
    }
    
    for( i=1; i<=signal; i++){
        signalArr[i] = A[i-1]%10000+1;
        
    }
    
    pSum[0] = 0;
    
    for( i=1; i<=signal; i++){
        pSum[i] = pSum[i-1]+signalArr[i];
    }
    
    while( end <= signal ){
        _sum = pSum[end]-pSum[start];
        
        if( _sum > sum ){
            start++;
        }
        else if( _sum == sum ){
            start++;
            result++;
        }
        else {
            end++;
        }
        
        
    }
    printf("%d\n",result);
}


#endif
