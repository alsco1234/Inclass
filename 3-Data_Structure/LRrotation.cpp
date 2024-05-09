#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
     int data;
     int bf;
     struct node *left, *right;
} tree_node;

void preorder (tree_node *ptr)
{
   if (ptr) {
      cout << ptr->data << ":" << ptr->bf << '\t' ;
      preorder(ptr->left);
      preorder(ptr->right);
   }
}

void left_rotation(tree_node **parent, bool &unbalanced)
{
	tree_node *grand_child, *child;
	child = (*parent)->left;
	if(child->bf == 1){	// LL rotation
		(*parent)->left = child->right;
		child->right = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	   else {		// LR rotation
	grand_child = child->right;
	child->right = grand_child->left;
	grand_child->left = child;
	(*parent)->left = grand_child->right;
	grand_child->right = *parent;
	switch(grand_child->bf){
	   case 1: (*parent)->bf = -1;
		    child->bf = 0;
		    cout << "Left rotation, case 1" << endl;
		    break;
	   case 0: (*parent)->bf = child->bf = 0;
	   	cout << "Left rotation, case 0" << endl;
		    break;
	   case -1: (*parent)->bf = 0;
		     child->bf = 1;
		     cout << "Left rotation, case -1" << endl;
	}
	*parent = grand_child;
   }
   (*parent)->bf = 0;
   unbalanced = false;
   cout << "In left_rotation: ";
   preorder((*parent));
   cout << endl;
}

void right_rotation(tree_node **parent, bool &unbalanced)
{
	tree_node *grand_child, *child;
	child = (*parent)->left;
	if(child->bf == 1){	// LL rotation
		(*parent)->left = child->right;
		child->right = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	   else {		// LR rotation
	grand_child = child->right;
	child->right = grand_child->left;
	grand_child->left = child;
	(*parent)->left = grand_child->right;
	grand_child->right = *parent;
	switch(grand_child->bf){
	   case 1: (*parent)->bf = 0;
		    child->bf = 1;
		    cout << "Right rotation, case -1" << endl;
			break;
	   case 0: (*parent)->bf = child->bf = 0;
	   	cout << "Right rotation, case 0" << endl;
		    break;
	   case -1: (*parent)->bf = -1;
		    child->bf = 0;
		    cout << "Right rotation, case 1" << endl;
	}
	*parent = grand_child;
   }
   (*parent)->bf = 0;
   unbalanced = false;
   cout << "In left_rotation: ";
   preorder((*parent));
   cout << endl;
}

void avl_insert(tree_node **parent, int x, bool &unbalanced)
{
cout << "1) inserting " << x << endl;
	if(!*parent){            //the node is empty
cout << "2) inserting " << x << endl;
		unbalanced = true; //the height is increased by insertion
		*parent = new tree_node;
		(*parent)->left = NULL;
		(*parent)->right = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if(x < (*parent)->data){                    
		avl_insert(&(*parent)->left, x, unbalanced);
		if(unbalanced){
		  switch((*parent)->bf){
		     case -1: (*parent)->bf = 0;
		     		cout << "L:Unbalanced case -1" << endl;
		  	       unbalanced = false;
		  	       break;
		     case 0:  (*parent)->bf = 1;
		     		cout << "L:Unbalanced case 0" << endl;
		  	       break;
		     case 1:  left_rotation(parent, unbalanced);
			 		cout << "L:Unbalanced case 1" << endl;
		  }
		}
	} else if(x > (*parent)->data){
	    avl_insert(&(*parent)->right, x, unbalanced);
		if(unbalanced){
		  switch((*parent)->bf){
		     case 1: (*parent)->bf = 0;
		     		cout << "R:Unbalanced case 1" << endl;
		  	       unbalanced = false;
		  	       break;
		     case 0:  (*parent)->bf = -1;
		     		cout << "R:Unbalanced case 0" << endl;
		  	       break;
		     case -1:  right_rotation(parent, unbalanced);
			 		cout << "R:Unbalanced case -1" << endl;  
		  }
		}
	} else {
		unbalanced = false;
		cout << "The key is already in the tree" << endl;
	}
} //end of avl_insert


void delete_tree(tree_node* ptr)
{
    if (ptr) {
        delete_tree(ptr->left);
        delete_tree(ptr->right);
        cout << "delete " << ptr->data << endl;
        delete(ptr);
    }
}



int main() {
	bool unbalanced=false;
	//bool *unbalanced = &balanced;
	tree_node * tree1=NULL;
	
	avl_insert(&tree1, 8, unbalanced);
	cout << "After inserting 8" << endl;
	preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 9, unbalanced);
	cout << "After inserting 9" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 10, unbalanced);
	cout << "After inserting 10" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 2, unbalanced);
	cout << "After inserting 2" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1,1, unbalanced);
	cout << "After inserting 1" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 7, unbalanced);
	cout << "After inserting 7" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 3, unbalanced);
	cout << "After inserting 3" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 6, unbalanced);
	cout << "After inserting 6" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 4, unbalanced);
	cout << "After inserting 4" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 5, unbalanced);
	cout << "After inserting 5" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 11, unbalanced);
	cout << "After inserting 11" << endl;
    preorder(tree1);
    cout << endl;
    
	avl_insert(&tree1, 12, unbalanced);
	cout << "After inserting 12" << endl;
	preorder(tree1);
    cout << endl;

}