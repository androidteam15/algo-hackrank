//
//  init.h
//  JH
//
//  Created by lgh on 14. 8. 9..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#ifndef JH_init_h
#define JH_init_h

int** initial(int n,int arg){
    int i,j;
    int** para;

    para = malloc(n*sizeof(int));
    for(i=0; i<n; i++){
        para[i] = malloc(arg*sizeof(int));
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<arg; j++){
            scanf("%d",&para[i][j]);
        }
    }
    
    return para;
}


#endif
