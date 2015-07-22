#include "ListNode.h"

class ReverseList{
public:
    ListNode * reverseList(ListNode * head);
    ListNode * reverseBetween(ListNode * head, int m, int n);
};


/// 1     <-      2     <-    3
//                prev       next
//
// break the first link!
ListNode * ReverseList::reverseList(ListNode * head){
    if(head = nullptr){
        return head;
    }
    ListNode * prev = head;
    ListNode * next = head? head->next: head;
    prev->next = nullptr;
    while(next){
        ListNode * temp = next->next;
        next->next = prev;
        prev = next;
        next = temp;
    }
    return prev;
}

//
// 2, 3
//1   -> 2   -> 3 -> 4 -> 5 
//tail          iter   next
// nil->3<-5 ,   1,2
//        iter, next
// tail
ListNode * ReverseList::reverseBetween(ListNode * head, int m, int n){
    if(m == n){
        return head;
    }
    ListNode nil{-1, head};
    ListNode * iter = & nil;
    for(int i = 0; i < m - 1; ++i){
        iter = iter->next;
    }
    ListNode * tail = iter;
    iter = iter->next;
    ListNode * next = iter->next;

    for(int i = m; i < n; ++i){
        ListNode * temp = next->next;
        next->next = iter;
        iter = next;
        next = temp;
    }
    tail->next->next = next;
    tail->next = iter;
    return nil.next;
}

