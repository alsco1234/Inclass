data types
(unsigned)

character type
% c //스페이스와 \n 모두 문자로 고려
if (ch >= 'a' && ch <= 'z')ch = 'A' + (ch - 'a'); //소문자->대문자
sizeof(char) = 1, sizeof(int) = 4, sizeof(shortint) = 2
y = (double)x * 25 //x를 double로 변환시킨 후..

배열
int a[10] = { 1,2 } //나머지는 모두 0,0,0됨

함수
int add(int a, int b); //선언
number = add(x, y); //호출
int add(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}

배열 함수
int a[5] = { 1,2,3,4,5 };
sub(a);
void sub(int b[]) {
	b[2] = 7;   //a[2]=7으로 반영됨
}

int a[3][4] = { {1,2,3,4} , {1,3,4,7} , {2,4,6,8} };
sub(a)
void sub(int b[][4]) {
	b[2][2]++; //a[2][2]++으로 반영됨
}
arrat_sum(a[1], 4);
int array_sum(int b[], int n) {
	b[0]++ //a[1][0]++ 로 반영됨
}

Recursion
int factorial(int n) {
	if (n == 0) return 1;  //base case
	else return (n * factorial(n - 1)); //general case
}

#define	YES	1
#define	NO	0
#define SQR(x)	((x)*(x)) //모두괄호치기