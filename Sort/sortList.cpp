#include <cassert>


struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}    
};

class sortListSolver{
public:
    ListNode * sortList(ListNode * head);
private:
    ListNode * findMid(ListNode * head);
    ListNode * merge(ListNode * head, ListNode * secondHead);
};

ListNode * sortListSolver::sortList(ListNode * head){
    if(!head|| !(head->next)){
        return head;
    }    

    ListNode * midNode = findMid(head);
    ListNode * secondHead = midNode->next;
    midNode->next = nullptr;
    head = sortList(head);
    secondHead = sortList(secondHead);
    return merge(head, secondHead);
}
ListNode * sortListSolver::findMid(ListNode  * head){  
    assert(head != nullptr);
    assert(head->next != nullptr); 
    ListNode * slowIter = head;
    ListNode * fastIter = head->next;

    while(fastIter->next != nullptr && fastIter->next->next != nullptr){
        slowIter = slowIter->next;
        fastIter = fastIter->next->next;    
    } 
    return slowIter;
}

ListNode * sortListSolver::merge(ListNode * head, ListNode * secondHead){
    ListNode dummy(-1);
    ListNode * iter = & dummy;
    while(head != nullptr && secondHead != nullptr){
        if(head->val < secondHead->val){
            iter->next = head;
            iter = head;
            head = head->next;
            //iter->next = nullptr;    
        } else {
            iter->next = secondHead;
            iter = secondHead;
            secondHead = secondHead->next;
            //iter->next = nullptr;    
        }
    }    
    
    if(head != nullptr){
        iter->next = head;    
    } else if (secondHead != nullptr) {
        iter->next = secondHead;    
    } else {
        iter->next = nullptr;    
    }
    return dummy.next;
}

int main(){
    
}
