#include <stdio.h>
#include <string.h>

struct student {
	char  s_id[10];
	char  name[10];
	int major;
} s1, s2;

	void make_sum(struct st_score* a);

void main() {
	struct st_score kim; //세트이름 Kim으로 선언
	strcpy(kim.name, "Kim"); //Kim 세트의 이름은 kim
	printf("Enter 3 scores >");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &kim.score[i]); //kim세트의 score3개
	}
	make_sum(&Kim); //주소를 줘야 한다
	printf("Sum : %d\n", kim.sum);
	return 0;
}

void make_sum(struct st_score* a) { //주소를 카피해서 저장
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += a->score[i];
		a->sum = sum;
	}
}