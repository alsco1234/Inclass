#include <stdio.h>
int main() {
	return 0;
}

printf("Hello World\n");

int x = 2;  //����/���� ->����
double y = 2.5; //����/�Ǽ� ->�Ǽ�
char z = 'A';
scanf("%d %f", &int, &float);

x++; ++x;
&& ���� ||

printf("%d", x); // 10���� 
printf("%f", x); //�Ǽ� 6������
printf("%8.3f", x);//��8�ڸ�, �Ҽ�������3�ڸ� ->  23.420
printf("%o", x); // 8���� 
printf("%x", x); // 16���� 
	printf("%5d", x); //5���� ū���� �״��, ���ʿ���
	printf("%05d", x); //���鹮�� 0����
	printf("%-5d", x); //������ ����

if ()else() //else�� ���� �ֱٿ� ��ġ
	a = (x > 3) ? x + 1 : x - 1; //true�� ��, �ƴϸ� �ڿ��� �־��

switch (month) {
case 2: ndays = 28;
		break;
case 4 :
case 6 :
case 11: ndays = 30;
		break;
default: ndays = 31; //���� ���� ����Ǵ°ɷ�
		break;
}

while()
if (x==3) {
	continue; //x==3�̸� ++�����ϰ� ���
 }
x++
}

do {} while (); //while�� �Ȱ����� ó���� �ѹ� ������

for(int i=0; i<10; i++){
	if (n == 9)continue;
	n++