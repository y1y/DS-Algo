#include "ListNode.h"

class RemoveNthNode{
private:
    int nth;
    ListNode * iter;
    ListNode * getPreNth();

public:
    // Required: n should always be valid
    ListNode * removeNthFromEnd(ListNode * head, int n);
};

ListNode * RemoveNthNode::removeNthFromEnd(ListNode * head, int n){
    ListNode nil{-1, head};
    iter = & nil;
    nth = n;
    ListNode * preIter = getPreNth(); 
    preIter->next = preIter->next->next;
    return nil.next;
}

ListNode * RemoveNthNode::getPreNth(){
    ListNode * ret = iter;
    for(int i = 0; i <= nth; ++i){
        iter = iter->next;
    }
    while(iter){
        iter = iter->next;
        ret = ret->next;
    }
    return ret;
}
