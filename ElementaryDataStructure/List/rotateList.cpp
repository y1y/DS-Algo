#include "ListNode.h"


class RotateList{
public:
    ListNode * rotateRight(ListNode * head, int k);
};

ListNode * rotateRight(ListNode * head, int k){
    ListNode * iter = head;
    if(!head){
        return head;
    }
    int n = 1;
    while(iter && iter->next){
        iter = iter->next;
        ++n;
    }
    k = k % n;
    iter->next = head;
    //             
    // 1->2->3->4->5->null
    //       iter 
    while(n > k){
        iter = iter->next;
        --n;
    }
    head = iter->next;
    iter->next = nullptr;
    return head;
}
