//
//  
//  JH
//
//  Created by lgh on 14. 8. 15..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#ifndef JH_kmp_h
#define JH_kmp_h
#include <string.h>

int* getPartialMatch(char* N){
    int m = strlen(N);
    int begin = 1;
    int matched = 0;
    int* pi = calloc(m,sizeof(int));
    
    while(begin + matched < 0){
        if( N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0){
                ++begin;
            }
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int kmp(char* H, char* N){
    int n = strlen(H);
    int m = strlen(N);
    int i;
    int result=0;
    int* pi;
    pi = getPartialMatch(N);
    
    int matched = 0;
    
    for(i=0; i<n; i++){
        
        while( matched>0 && H[i] != N[matched]){
            matched= pi[matched-1];
        }
        
        if(H[i] == N[matched]){
            ++matched;
            if(matched==m){
                return i-matched+1;
            }
        }
    }
    
    free(pi);
    return i-matched+1;
}

void shifts(){
    
    int c,n;
    int i,j;
    char*** str;
    int result;
    char* N;
    char* H;
    int len;
    int* arrN;
    
    scanf("%d",&c);
    str= malloc (c* sizeof(char**));
    arrN = malloc( c* sizeof(int));
    for(i=0; i<c; i++){
        scanf("%d",&n);
        arrN[i]=n;
        str[i] = malloc( (n+1) * sizeof(char*));
        for(j=0; j<=n; j++){
            str[i][j] = malloc( 100* sizeof(char));
            scanf("%s",str[i][j]);
            fflush(stdin);
        }
    }
    
    for(i=0; i<c; i++){
        result = 0;

        N = malloc( (strlen(str[i][0])*2+1 ) * sizeof(char));
        H = malloc( (strlen(str[i][0]) ) * sizeof(char));
        
        for( j=0; j<arrN[i]; j++){
            if(j%2){
                strcpy(N,str[i][j]);
                strcat(N,str[i][j]);
                strcpy(H,str[i][j+1]);
                result += kmp(N,H);
            }
            else{
                strcpy(N,str[i][j+1]);
                strcat(N,str[i][j+1]);
                strcpy(H,str[i][j]);
                result += kmp(N,H);
            }
        }
        
        printf("%d\n",result);
        
        
        for(j=0; j<=n; j++){
            free(str[i][j]);
        }
        free(str[i]);
        free(N);
        free(H);
    }
    free(str);
    
}





#endif
