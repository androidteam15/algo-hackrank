//
//  bracket.h
//  JH
//
//  Created by lgh on 14. 8. 13..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#ifndef JH_bracket_h
#define JH_bracket_h

#include <string.h>

typedef enum {false, true} bool;

void bracket(){
    
    int n,i,j;
    int len=0;
    int start=0;
    bool match=false;
    bool result = true;
    char** brace = NULL;
    char* stack[5000];
    
    scanf("%d", &n);
    brace = malloc(n*sizeof(char*));
    for(i=0; i<n; i++){
        brace[i] = malloc(10000*sizeof(char));
        scanf("%s",brace[i]);
        fflush(stdin);
    }
    
    for(i=0; i<n; i++){
        result = true;
        len = strlen(brace[i]);
        start = 0;
        for(j=len-1; j>=0; j--){
            
            if(brace[i][j] == ')' || brace[i][j] == '}' || brace[i][j] == ']'){
                stack[start]=brace[i][j];
                start++;
            }
            else if( brace[i][j] == '(' || brace[i][j] == '{' || brace[i][j] == '['){
                                printf("--%d \n",start);
                start--;
                match = (brace[i][j] =='(') && (stack[start] == ')') ;
                match = match || (brace[i][j] =='{') && (stack[start] == '}') ;
                match = match || (brace[i][j] =='[') && (stack[start] == ']') ;

                if(!match){
                    result = false;
                    break;
                }
            }
            else{
                result = false;
                break;
            }
            
        }
        if(result)
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    
    
    
    
    
    
    
    
    
    
    // free
    for(i=0; i<n; i++){
        free(brace[i]);
    }
    free(brace);
    
}

#endif
