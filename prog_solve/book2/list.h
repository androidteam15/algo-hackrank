//
//  list.h
//  JH
//
//  Created by lgh on 14. 8. 5..
//  Copyright (c) 2014년 lgh. All rights reserved.
//

#ifndef JH_list_h
#define JH_list_h

#include <stdlib.h>

typedef struct ListNode{
    int element;
    struct ListNode *next;
    
}NODE;

NODE* deleteNext(NODE* node){
    NODE* delete = node->next;
    node->next = delete->next;
    //free(delete);
    return node->next;
}

NODE* deleteCurrent(NODE* node){
    
    NODE* before;
    before=node;
    while(1){
        if( before->next->element == node->element ){
            break;
        }
        before = before->next;
    }
    return deleteNext(before);
}

#endif
