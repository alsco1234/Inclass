#include <stdio.h>

int tree[] = {1, 2, 3, 4, -1, 6, 7};
int max_num_node = 7;

void inorder(int index)
{
    if (index >= 0 && index < max_num_node && tree[index] != -1)
    {
        int t7 = 0;
        int t1 = max_num_node;
        
        // Check conditions
        if (index < 0)
            t7 += 1;
        if (max_num_node < index)
            t7 += 1;
        if (max_num_node == index)
            t7 += 1;
        
        int s0 = index * 4;
        int* t2 = tree + s0;
        int t3 = *t2;
        int t4 = -1;
        int t0 = (t3 == t4) ? 1 : 0;
        t7 += t0;
        
        // Result
        if (t0 < t7)
        {
            int sp_values[2];
            sp_values[0] = index;
            sp_values[1] = t7;
            
            printf("%d\n", sp_values[0]);  // Print index
            int a1 = 2 * index + 1;
            inorder(a1);
            
            a1 = 2 * index + 2;
            inorder(a1);
        }
    }
}

int main()
{
    printf("Inorder: ");
    inorder(0);
    printf("\n");
    
    return 0;
}
