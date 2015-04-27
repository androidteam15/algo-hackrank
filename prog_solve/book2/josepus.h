//
//  josepus.h
//  JH
//
//  Created by lgh on 14. 8. 7..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#include "list.h"

#ifndef JH_josepus_h
#define JH_josepus_h

NODE* createNode(int size){
    
    int i;
    NODE* a;
    NODE* head;
    
    a= malloc(size * sizeof(NODE));
    head = a;
    head->element = 1;
    for( i=1; i<size; i++){
        a[i-1].next = &a[i];
        a[i].element = i+1;
    }
    a[size-1].next = head;
    
    return head;
}

void checkNODE(int size){
    int i;
    NODE* step = NULL;
    step = createNode(size);
    for( i=0; i < size*2; i++){
        printf("%d\n",step->element);
        step = step->next;
    }
}

void josepus(int run, int jump){
    
    int i,j;
    NODE* current;
    NODE* start;
    NODE* head = createNode(run);
    start = head;
    head = deleteCurrent(head);
    for(i=0; i<run-3; i++){
        current=head;
        for(j=0; j<jump-2; j++){
            current = current->next;
        }
        head = deleteNext(current);
    }
    
    if( head->element > head->next->element){
        printf("%d %d\n",head->next->element,head->element);
    }
    else{
        printf("%d %d\n",head->element,head->next->element);
    }
    
    free(start);

}


#endif
