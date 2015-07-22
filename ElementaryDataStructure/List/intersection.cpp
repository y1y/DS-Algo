
// 1->2
//       iter1
//    iter2
// 
// 2
// iter1
//
class Intersection{
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB){
        if(!headA || !headB){
            return nullptr;
        }
        ListNode * iter1 = headA;
        ListNode * iter2 = headB;
        while(iter1 && iter2){
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        if(iter1){
            iter2 = headA;
            while(iter1){
                iter2 = iter2->next;
                iter1 = iter1->next;
            }
            iter1 = headB;
        } else if(iter2){
            iter1 = headB;
            while(iter2){
                iter2 = iter2->next;
                iter1 = iter1->next;
            }
            iter2 = headA;
        }

        while(iter1 && iter2){
            if(iter1 == iter2){
                return iter1;
            }    
            iter1 = iter1->next;
            iter2 = iter2->next;
        }

        return nullptr;
    }
};



