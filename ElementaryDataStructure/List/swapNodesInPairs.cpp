#include "ListNode.h"

class SwapNodesInPairs{
public:
    ListNode * swapPairs(ListNode * head){
        ListNode nil{-1, head};    
        ListNode *first = nil.next;
        
        ListNode *second = first? first->next : first;
        ListNode *iter = & nil;
       
        // Pointer will be revised!!!
        while(first && second){
            iter->next = second;
            iter = first;
            ListNode * temp = second->next;
            second->next = first;
            first->next = temp;
            first = temp;
            second = temp? temp->next : temp;
        }
        iter->next = first; 
        return nil.next;    
    }
};


