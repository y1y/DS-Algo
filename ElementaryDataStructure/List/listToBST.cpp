#include "ListNode.h"

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class List2BST{
private:
    ListNode * list;
    TreeNode * listToBST(int size);
    int count(ListNode * head);
public:
    TreeNode * listToBST(ListNode * head);
    ListNode * BSTToList(TreeNode * root);
};

ListNode * BSTToList(TreeNode * root){
   if(!root){
       return nullptr;
   }
   ListNode * left = BSTToList(root->left);
   ListNode * mid = new ListNode{root->val};
   ListNode * right = BSTToList(root->right);
   if(left){
       left->next = mid; 
   }
     
   mid->next = right;
   if(left){
       return left;
   }
   return mid;
}

int List2BST::count(ListNode * head){
    int cnt = 0;
    while(head){
        ++cnt;
        head = head->next;
    }
    return cnt;
}
TreeNode * List2BST::listToBST(ListNode * head){
    int size = count(head);
    list = head;
    return listToBST(size);
}

TreeNode * List2BST::listToBST(int size){
    if(!size){
        return nullptr;
    }
    TreeNode * root = new TreeNode (0);
    root->left = listToBST(size / 2);
    root->val = list->val;
    list = list->next;
    root->right = listToBST(size - size / 2 - 1);
    return root;
}

int main(){
    TreeNode * root = List2BST().listToBST(new ListNode{0});

}
