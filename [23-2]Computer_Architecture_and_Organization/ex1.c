#include <stdio.h>

int main()
{   
    // input
    int row = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    // triangle
    int cur_row = row;
    for(int i=0; i<row; i++){

        for(int b=0; b<i; b++)
            printf("  ");

        for(int j=cur_row; j<cur_row*2-1; j++)
            printf("%d ", j);

        printf("%d ", cur_row*2-1);

        for(int j=cur_row*2-2; j>cur_row-1; j--)
            printf("%d ", j);
        
        cur_row-=1;
        printf("\n");
    }
    return 0;
}
