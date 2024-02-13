#include <stdio.h>

int tree[] = {1, 2, 3, 4, -1, 6, 7};
int max_num_node  = 7;     // maximum number of nodes 

// int tree[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, 12, -1, 14, 15};
// int max_num_node  = 15;     // maximum number of nodes 

void inorder(int index)
{
    if (index >= 0 && index < max_num_node  && tree[index] != -1)
    {
        inorder(2 * index + 1);         // visit left subtree
        printf(" %d ", tree[index]);    // visit root
        inorder(2 * index + 2);         // visit right subtree
    }
}

int main()
{
    printf("Inorder: ");
    inorder(0);     // Inorder traversal
    printf("\n");

    return 0;
}