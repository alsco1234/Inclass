#include <stdio.h>
#include <string.h>

struct student {
	char  s_id[10];
	char  name[10];
	int major;
} s1, s2;

	void make_sum(struct st_score* a);

void main() {
	struct st_score kim; //��Ʈ�̸� Kim���� ����
	strcpy(kim.name, "Kim"); //Kim ��Ʈ�� �̸��� kim
	printf("Enter 3 scores >");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &kim.score[i]); //kim��Ʈ�� score3��
	}
	make_sum(&Kim); //�ּҸ� ��� �Ѵ�
	printf("Sum : %d\n", kim.sum);
	return 0;
}

void make_sum(struct st_score* a) { //�ּҸ� ī���ؼ� ����
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += a->score[i];
		a->sum = sum;
	}
}