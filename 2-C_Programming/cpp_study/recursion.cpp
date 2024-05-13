int Factorial(int n) {
	if (n == 1) return 1;
	else return (n * factorial(n - 1)); //n>1인경우
}

int SumtoAll(int n) {
	if (n == 1) return 1;
	else return (n + Sumtoall(n - 1)); //n>1인경우
}

int PrintReverse(int number[], int length) { //역순출력
	//숫자배열, 출력문자수
	printf("%d", number[length - 1]);//가장 마지막 숫자 출력
	if (length > 1) PrintReverse(number, length - 1); //출력 문자수 1개 감소 후 출력
}


