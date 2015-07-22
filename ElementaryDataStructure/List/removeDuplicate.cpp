#include "ListNode.h"

class RemoveDuplicate{
public:
    ListNode * deleteDuplicates(ListNode * head);
    ListNode * deleteDuplicates2(ListNode * head);
};

ListNode * RemoveDuplicate::deleteDuplicates(ListNode * head){
    ListNode nil{-1};
    nil.next = head;
    ListNode * prev = head;
    ListNode * next = head? head->next: head;
    while(next){
        if(prev->val == next->val){
            while(next && next->val == prev->val){
                ListNode * victim = next;
                next = next->next;
                delete victim;
            }
            prev->next = next;
            prev = next;
            next = next? next->next: next;
        } else {
            prev = next;
            next = next->next;
        }
    }
    return nil.next;
}

ListNode * RemoveDuplicate::deleteDuplicates2(ListNode * head){
    ListNode nil{-1};
    nil.next = head;
    ListNode * tail = &nil;
    ListNode * prev = head;
    ListNode * next = head? head->next: head;
    while(next){
        if(prev->val == next->val){
            while(next && next->val == prev->val){
                delete prev;
                prev = next;
                next = next->next;
            }
            delete prev;
            tail->next = next;
            prev = next;
            next = next? next->next: next;
        } else {
            tail = prev;
            prev = next;
            next = next->next;
        }
    }
    return nil.next;
}
