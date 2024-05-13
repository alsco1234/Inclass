#include <stdio.h>
int main() {
	return 0;
}

printf("Hello World\n");

int x = 2;  //정수/정수 ->정수
double y = 2.5; //정수/실수 ->실수
char z = 'A';
scanf("%d %f", &int, &float);

x++; ++x;
&& 다음 ||

printf("%d", x); // 10진수 
printf("%f", x); //실수 6개까지
printf("%8.3f", x);//총8자리, 소수점이후3자리 ->  23.420
printf("%o", x); // 8진수 
printf("%x", x); // 16진수 
	printf("%5d", x); //5보다 큰수는 그대로, 왼쪽여백
	printf("%05d", x); //여백문자 0으로
	printf("%-5d", x); //오른쪽 여백

if ()else() //else는 가장 최근에 일치
	a = (x > 3) ? x + 1 : x - 1; //true면 앞, 아니면 뒤에거 넣어라

switch (month) {
case 2: ndays = 28;
		break;
case 4 :
case 6 :
case 11: ndays = 30;
		break;
default: ndays = 31; //가장 많이 적용되는걸로
		break;
}

while()
if (x==3) {
	continue; //x==3이면 ++생략하고 계속
 }
x++
}

do {} while (); //while과 똑같은데 처음에 한번 먼저함

for(int i=0; i<10; i++){
	if (n == 9)continue;
	n++