#include "ListNode.h"

class PartitionList{
public:
    ListNode * partition(ListNode * head, int x);
};
// 2->1
// p0->1
// p1->2->1
ListNode * PartitionList::partition(ListNode * head, int x){
    ListNode node0(-1);
    ListNode node1(-1);
    ListNode * p0 = & node0;
    ListNode * p1 = & node1;
    while(head){
        if(head->val <= x){
            p0->next = head;
            p0 = head;
        } else {
            p1->next = head;
            p1 = head;
        }
        head = head->next;
    } 
    p0->next = node1.next;
    // Break the link!
    p1->next = nullptr;
    return node0.next;

}
