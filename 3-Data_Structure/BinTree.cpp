#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *left_child, *right_child;
} tree_node;

class BinTree{
    private:
        tree_node *root;
    public:
        BinTree();
        ~BinTree();
        bool IsEmpty();
        void delete_tree(tree_node*ptr);
        void insert_node_left(int data);
        void insert_node_right(int data);
        void inorder(tree_node* ptr); //혹은 postorder 아니면 preorder
        void Print();
};

BinTree::BinTree(){
    root = NULL;
}

BinTree::~BinTree(){
    delete_tree(root);
    root = NULL;
}

bool BinTree::IsEmpty(){
    return (root == NULL);
}

void BinTree::delete_tree(tree_node*ptr){
    if(ptr){
        delete_tree(ptr->left_child);
        delete_tree(ptr->right_child); //postorder방식
        cout << "delete" << ptr->data << endl; //확인
        delete(ptr);
    }
}

void BinTree::insert_node_left(int data){
    tree_node *ptr = new tree_node;
    ptr->data = data;
    ptr->left_child = ptr->right_child = NULL;

    if(IsEmpty()){
        root = ptr;
    }
    else{
        tree_node *cur = root;
        for(;cur->left_child; cur=cur->left_child);
        cur -> left_child = ptr;
    }
}

void BinTree::insert_node_right(int data){
    tree_node *ptr = new tree_node;
    ptr->data = data;
    ptr->right_child = ptr->left_child = NULL;

    tree_node *cur;
    for(cur = root; cur->right_child; cur=cur->right_child);
    cur -> right_child = ptr;
}

void BinTree::inorder(tree_node *ptr){
    //??????
}

void BinTree::Print(){ //private한 root라는 노드에 접근하기 위해 inorder사용
    inorder(root);
    cout << endl;
}

int main(){
    BinTree* tree1 = new BinTree(10);//만듦
    tree1->insert_node_left(3);
    tree1->insert_node_left(1);
    tree1->insert_node_right(5);
    //tree1->inorder(tree->root); 하면 root가 프라이빗이라 안됨
    tree1->Print();
    cout << endl;
    delete tree1; //사실 완전 지워진건 아님. 젤 위 노드 하나 없앰
}
23056       Paul        18      48.5
18920       Daniel      16      65.7
19029       David       19      98.0
29019       Priscilla   24      99.2
19376       Joshua      21      97.1
39487       Moses       19      39.5