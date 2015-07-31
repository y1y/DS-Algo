#include "BST.h"

int main(){
    BST bst;
    bst.insert(10, 10);
    bst.insert(2, 2);
    bst.insert(6, 6);
    bst.insert(4, 5);
    bst.insert(8, 8);
    bst.inorderTraverse();
    bst.del(4);
    bst.del(8);
    bst.inorderTraverse();
}
