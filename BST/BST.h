struct Node{
    int key;
    int val;
    Node * left;
    Node * right;
    Node * parent;
};


class BST{
private:
    void copy(const Node * other);
    void destroy();
    void transplant(Node * x, Node * y);
public:
    Node * root;
    BST();
    ~BST();
    BST(const BST & other);
    BST & operator=(const BST & other);
    void inorderTraverse();
    Node * search(int k);
    void insert(int k, int v);
    void del(int k);
    Node * minNode(Node * start);
    Node * maxNode(Node * start);
    Node * successor(Node * node);
    Node * predecessor(Node * node);
    
};
