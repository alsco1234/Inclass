int Factorial(int n) {
	if (n == 1) return 1;
	else return (n * factorial(n - 1)); //n>1�ΰ��
}

int SumtoAll(int n) {
	if (n == 1) return 1;
	else return (n + Sumtoall(n - 1)); //n>1�ΰ��
}

int PrintReverse(int number[], int length) { //�������
	//���ڹ迭, ��¹��ڼ�
	printf("%d", number[length - 1]);//���� ������ ���� ���
	if (length > 1) PrintReverse(number, length - 1); //��� ���ڼ� 1�� ���� �� ���
}


