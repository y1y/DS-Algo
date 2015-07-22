#include "ListNode.h"

// Check if nullptr works or single node works!
class reorderList{
public:
    void reorderList(ListNode * head);
private:
    ListNode * root;
    ListNode * secondHead;
    void getSecondHalf();
    void reverseSecondHalf();
    void link();
};

// 1->2->3->4
void reorderList::reorderList(ListNode * head){
    root = head;
    if(!head || !(head->next)){
        return;
    }
    getSecondHalf();
    reverseSecondHalf();
    link();
}
//       
// 1->2
// sH
// 3->4

void reorderList::getSecondHalf(){
    ListNode * slow = root;
    ListNode * fast = root? root->next : root;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    secondHead = slow->next;
    slow->next = nullptr;
}
// 3<-4
// sH next  
void reorderList::reverseSecondHalf(){
    ListNode * next = secondHead? secondHead->next : nullptr;
    secondHead->next = nullptr;
    while(next){
        ListNode * temp = next->next;
        next->next = secondHead;
        secondHead = next; // move both ptrs!
        next = temp;
    }
}

void reorderList::link(){
    ListNode * iter = secondHead;
    while(iter){
        ListNode * temp1 = root->next;
        ListNode * temp2 = iter->next;
        root->next = iter;
        iter->next = temp1;
        root = temp1;
        iter = temp2;
    }
}
