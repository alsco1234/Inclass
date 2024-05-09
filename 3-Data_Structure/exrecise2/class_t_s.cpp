#include <iostream>
using namespace std;

int main(){
const int rows = 3 , cols = 5;
int array2D[rows][cols];
int *array1D = (int *)array2D;
int i = 0, j = 0, n = 0;
for(i = 0; i < rows; i++)
for(j = 0; j < cols; j++)
array2D[i][j] = n++;
for(i = 0; i < rows; i++)
for(j = 0; j < cols; j++)
printf("array2D[%d][%d](%p) = %d, array1D[%d](%p) = %d\n",
i, j, &array2D[i][j], array2D[i][j],
i*cols+j, &array1D[i*cols+j], array1D[i*cols+j]);
}
