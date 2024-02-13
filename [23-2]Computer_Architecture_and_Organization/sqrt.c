#include <stdio.h>
int main() {
float n, x;
float y = 1.0; float e = 0.00001;
printf("Enther the number: "); scanf("%f", &n);
x = n;
while (x - y > e) {
x = (x + y) / 2;
y = n / x; 
printf("%f", y);}
printf("Square root: %f \n", y);
return 0; }