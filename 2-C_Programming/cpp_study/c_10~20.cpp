data types
(unsigned)

character type
% c //�����̽��� \n ��� ���ڷ� ���
if (ch >= 'a' && ch <= 'z')ch = 'A' + (ch - 'a'); //�ҹ���->�빮��
sizeof(char) = 1, sizeof(int) = 4, sizeof(shortint) = 2
y = (double)x * 25 //x�� double�� ��ȯ��Ų ��..

�迭
int a[10] = { 1,2 } //�������� ��� 0,0,0��

�Լ�
int add(int a, int b); //����
number = add(x, y); //ȣ��
int add(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}

�迭 �Լ�
int a[5] = { 1,2,3,4,5 };
sub(a);
void sub(int b[]) {
	b[2] = 7;   //a[2]=7���� �ݿ���
}

int a[3][4] = { {1,2,3,4} , {1,3,4,7} , {2,4,6,8} };
sub(a)
void sub(int b[][4]) {
	b[2][2]++; //a[2][2]++���� �ݿ���
}
arrat_sum(a[1], 4);
int array_sum(int b[], int n) {
	b[0]++ //a[1][0]++ �� �ݿ���
}

Recursion
int factorial(int n) {
	if (n == 0) return 1;  //base case
	else return (n * factorial(n - 1)); //general case
}

#define	YES	1
#define	NO	0
#define SQR(x)	((x)*(x)) //��ΰ�ȣġ��