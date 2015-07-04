#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next_ptr) : val(x), next(next_ptr) {}
};


class MergeKSortedList{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
private:
    ListNode* mergeKListsHelper(int start, int end, vector<ListNode*>& lists);
    ListNode* mergeTwo(ListNode * left, ListNode * right);
};

ListNode* MergeKSortedList::mergeKLists(vector<ListNode*>& lists){
    return mergeKListsHelper(0, lists.size(), lists);    
}

ListNode* MergeKSortedList::mergeKListsHelper(int start, int end, vector<ListNode*>& lists){
    ListNode * result = nullptr;
    // build the base case
    if(start == end - 1){
        result = lists[start];
    } else if (start < end){
        int mid = start + (end - start) / 2;
        ListNode * left = mergeKListsHelper(start, mid, lists);
        ListNode * right = mergeKListsHelper(mid, end, lists);
        result = mergeTwo(left, right);
    }
    return result;    
}

ListNode* MergeKSortedList::mergeTwo(ListNode * left, ListNode * right){
    ListNode dummyNode(-1);
    ListNode * iter = & dummyNode;
    while(left != nullptr && right != nullptr){
        // don't forget to break the original link!!!!
        //assert(iter != nullptr);
        assert(left != nullptr);
        assert(right != nullptr); 
        if(left->val < right->val){    
            iter->next = left;
            iter = left;
            left = left->next;    
            iter->next = nullptr;
        } else {
            iter->next = right;
            iter = right;
            right = right->next;
            iter->next = nullptr;
        }
        //iter = iter->next;
    }   
    // merge the leftover!
    if(left != nullptr){
        iter->next = left;
    } 

    if(right != nullptr){
        iter->next = right;
    }
    return dummyNode.next;
}
int main(){

    ListNode * l1 = new ListNode(1, new ListNode(7, new ListNode(9)));
    ListNode * l2 = new ListNode(2, new ListNode(4, new ListNode(6)));
    ListNode * l3 = new ListNode(3, new ListNode(5, new ListNode(8)));
    vector<ListNode *> test {l1, l2, l3};
    ListNode* result = MergeKSortedList().mergeKLists(test);
    
    for(int i = 1; i <=9; ++i){
        assert(i == result->val);
        result = result->next;
    }
    for(auto & list : test){
        ListNode* iter = list;
        while(iter != nullptr){
            ListNode * victim = iter;
            iter = iter->next;
            delete victim;    
        }
    }

}
